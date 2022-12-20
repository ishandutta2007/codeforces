#include<bits/stdc++.h>
using namespace std;
int main()
{
int s,a,b,c;
scanf("%i%i%i%i",&s,&a,&b,&c);
if(a==0&&b==0&&c==0)
{
    printf("0 0 0\n");
    return 0;
}
double x=1.0*s*a/(a+b+c);
double y=1.0*s*b/(a+b+c);
double z=1.0*s*c/(a+b+c);
printf("%.18f %.18f %.18f\n",x,y,z);
return 0;
}