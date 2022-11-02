#include<bits/stdc++.h>
using namespace std;
double pi=3.14159265358979;
double n,r,h,l,j;
int main()
{
    cin>>n>>r;
    h=cos(2*pi/n);
    h=sqrt(2-2*h);
    h=2/h-1;
    //cout<<h;
    l=r/h;
    printf("%10f",l);
}