#include<stdio.h>
#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
int i,f;
double a,b,j,n;
int main(){
    cin>>f;
    for(i=1;i<=f;i++)
    {
        cin>>n;
            if(n>0 && n<4)
    {
        cout<<"N\n";
    }
    else if (n==0)
    {
        cout<<"Y "<<"0 "<<"0"<<"\n";
    }
    else
    {
        j=n*n-4*n;
        a=n+sqrt(j);
        a=a/2;
        b=sqrt(j);
        b=n-b;
        b=b/2;
        cout.precision(20);
        cout<<"Y ";
        cout << fixed << a <<" " <<b << endl;
    }
    }
}