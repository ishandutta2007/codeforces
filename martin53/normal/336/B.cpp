#include<bits/stdc++.h>
using namespace std;
int main()
{
int m,r;
scanf("%i%i",&m,&r);
double ans=0,sum;
for(long long p=2;p<=m;p++)
{
    sum=(2+sqrt(2));
    sum=sum=sum+2*sqrt(2)*(p-2);
    sum=sum+(p-2)*(p-1);
    //sum=sum+2;
    sum=sum*r;
    ans=ans+sum;
}
ans=ans*2;
ans=ans+2*r*m;
ans=ans/m/m;
printf("%.18f\n",ans);
return 0;
}