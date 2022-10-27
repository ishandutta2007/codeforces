#include<bits/stdc++.h>
using namespace std;
const double pi=3.14159265358979;
double n,r,h;
int main()
{
    scanf("%lf%lf",&n,&r);
    h=cos(2*pi/n);
    h=sqrt(2-2*h);
    h=2/h-1;
    printf("%.6f",r/h);
}