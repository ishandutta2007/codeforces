#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
ULL gcd(ULL a,ULL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ULL t,a,b,g,ans;
int main()
{
    scanf("%I64u%I64u%I64u",&t,&a,&b);
    g=gcd(a,b);
    double x=(double)a/(double)g*(double)b;
    if(x>6e18) ans=min(t,min(a,b)-1);
    else
    {
        ULL lcm=a/g*b;
        ULL d=t/lcm,r=t%lcm;
        ans=d*min(a,b)+min(r,min(a,b)-1);
    }
    g=gcd(ans,t);
    t/=g,ans/=g;
    printf("%I64u/%I64u\n",ans,t);
    return 0;
}