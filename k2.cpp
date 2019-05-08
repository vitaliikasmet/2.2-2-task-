#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
 
class Matrix3D
{
public:
    double** k;
 
    Matrix3D(){
        k = new double* [3];
 
        for (int i = 0; i < 3; i++)
            k[i] = new double [3];
 
 
    }
 
    ~Matrix3D(){
        for (int i = 0; i < 3; i++)
            delete [] k[i];
        delete[] k;}
 
 
 
    Matrix3D operator+ (const Matrix3D& v){
        Matrix3D result;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                result.k[i][j]=v.k[i][j]+k[i][j];
 
        return result;
    }
    Matrix3D operator- (const Matrix3D& v){
        Matrix3D result;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                result.k[i][j]=k[i][j]-v.k[i][j];
        return result;
    }
 
   Matrix3D operator* (double a) const {
        Matrix3D result;
 
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                result.k[i][j] = k[i][j] * a;
 
        return result;
 
    }
 
    Matrix3D operator* (const Matrix3D& v){
        Matrix3D result;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                result.k[i][j] = 0;
        for (unsigned int j = 0; j < 3; j++){
            for (unsigned int i = 0; i < 3; i++)
            	for (int d=0; d<3; d++)
                result.k[i][j]+=v.k[d][j]*k[i][d];}
        return result;
    }
 
 
 
    void setValue(unsigned int i, unsigned int j, double value){
        k[i][j]=value;
    }
 
    double getValue(unsigned int i, unsigned int j) const{
        return k[i][j];
    }
    double Det()
    {
    	cout<<(k[0][0]*(k[1][1]*k[2][2]-k[1][2]*k[2][1])- k[0][1]*(k[1][0]*k[2][2]-k[2][0]*k[1][2])+ k[0][2]*(k[1][0]*k[2][1]-k[2][0]*k[1][1]));
    	return (k[0][0]*(k[1][1]*k[2][2]-k[1][2]*k[2][1])- k[0][1]*(k[1][0]*k[2][2]-k[2][0]*k[1][2])+ k[0][2]*(k[1][0]*k[2][1]-k[2][0]*k[1][1]));
    }
};
Matrix3D operator* (int a, const Matrix3D& v){
    return v * a;
}
 
 
class Vector3D
{
public:
 
    double* k;
 
    Vector3D(){
        k=new double[3];
    }
 
 
 
    ~Vector3D(){
        delete[] k;}
 
    double operator* (const Vector3D& v) {
        double resultk=0;
        for (unsigned int i = 0; i < 3; i++ )
           resultk += v.k[i]*k[i];
        return resultk;
    }
 
    Vector3D operator- (const Vector3D& v){
        Vector3D result;
        for (unsigned int i = 0; i < 3; i++)
            result.k[i]=k[i]-v.k[i];
        return result;
    }
 
    Vector3D operator+ (const Vector3D& v){
        Vector3D result;
        for (unsigned int i = 0; i < 3; i++)
            result.k[i]=v.k[i]+k[i];
        return result;
    }
 
    Vector3D operator* (double a) const {
        Vector3D result;
        for (unsigned int i = 0; i < 3; i++)
            result.k[i] = k[i] * a;
        return result;
 
    }
    Vector3D operator* (const Matrix3D& b) const {
        Vector3D result;
        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                result.k[i]+= b.k[j][i]*k[j];
        return result;
    }
 
    void setValue(unsigned int i, double value){
        k[i]=value;
    }
    double getValue(unsigned int i) const{
        return k[i];
    }
};
Vector3D operator* (double a, const Vector3D& v){
    return v * a;
}
 
 
 
int main()
{
    Vector3D a;
    a.setValue(0, 4);
    a.setValue(1, 2);
    a.setValue(2, 2);
 
    Vector3D b;
    b.setValue(0, 3);
    b.setValue(1, -1);
    b.setValue(2, 0);
 
 
    Vector3D c = a + b;
    Vector3D d = a * 5;
    Vector3D e = a - b;
    float sk = a * b;
 
    for(unsigned int i = 0; i < 3; ++i)
        cout << c.getValue(i) << endl;
    cout<<endl;
 
    for(unsigned int i = 0; i < 3; ++i)
        cout << d.getValue(i) << endl;
    cout<<endl;
 
    for(unsigned int i = 0; i < 3; ++i)
        cout << e.getValue(i) << endl;
    cout<<endl;
 
    cout<<sk<<endl;
 
 
    Matrix3D x;
    x.setValue(0, 0, 6);
    x.setValue(0, 1, 2);
    x.setValue(0, 2, 2);
    x.setValue(1, 0, 7);
    x.setValue(1, 1, 3);
    x.setValue(1, 2, 8);
    x.setValue(2, 0, 9);
    x.setValue(2, 1, 6);
    x.setValue(2, 2, 1);
 
 
    Matrix3D y;
    y.setValue(0, 0, 1);
    y.setValue(0, 1, 0);
    y.setValue(0, 2, 2.5);
    y.setValue(1, 0, 9);
    y.setValue(1, 1, 4);
    y.setValue(1, 2, 6);
    y.setValue(2, 0, 3);
    y.setValue(2, 1, 1.5);
    y.setValue(2, 2, 0);
 
 
    printf("x\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (x.k[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;
 
    printf("y\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (y.k[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;
 
 
    Matrix3D q = x + y;
    Matrix3D w = x - y;
    Matrix3D z = x * y;
    Vector3D o = a * x;
    Matrix3D u = y * 2;
 
    printf("+\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << q.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;
 
 
    printf("-\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << w.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;
 
 
    for(unsigned int i = 0; i < 3; ++i)
        cout << o.getValue(i) << " ";
    cout<<endl;
 
    printf("*2\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << u.getValue(i,j) << " ";
        cout<<endl;
    }
    cout<<endl;
 
 
    printf("x\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (x.k[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;
 
    printf("y\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (y.k[i][j]) << " ";
        cout<<endl;
    }
    cout<<endl;
 
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << (z.k[i][j]) << " ";
        cout<<endl;
    }
    x.Det();
 
}
