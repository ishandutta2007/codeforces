#include <iostream>
#include <math.h>
#include <iomanip>
 using namespace std; 
 int main() {
     int a1,a2,a3,a4,a5,a6;
     cin>> a1>> a2>> a3 >> a4>> a5>> a6 ; 
    double  p,S1,S2,S3,S4;
    double c12;
    c12= sqrt(a1*a1 + a2*a2+ (a1*a2));
    p=(a1+a2+c12)/2;
    S1=sqrt( p*(p-a1)*(p-a2)*(p-c12)) ;
    double c34;
    c34= sqrt(a3*a3+ a4*a4+ (a3*a4));
    double k;
    k = (a3 + a4 + c34)/2;
    S2=sqrt( k*(k-a3)*(k-a4)*(k-c34));
    double c56;
    c56=sqrt(a5*a5+a6*a6+a5*a6);
    double l;
    l=(a5+a6+c56)/2;
    S3=sqrt(l*(l-a5)*(l-a6)*(l-c56));
    double q;
    q=(c12+ c34 + c56)/2 ;
    S4= sqrt( q*(q-c12)*(q-c34)*(q-c56));
    double S,R;
    S=S1+S2+S3+S4;
    R= (4* S/sqrt(3)) ;
   
    cout<<int(R);
    
    
 
     return 0;
}