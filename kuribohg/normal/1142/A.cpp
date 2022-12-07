#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INF=1000000000000000000LL;
LL n,k,a,b,mx=-INF,mn=INF;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
LL solve(LL step)
{
    if(step<0) step=-step;
    return n*k/gcd(step,n*k);
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
    LL a1=-a-b,a2=a-b,a3=b-a,a4=a+b;
    while(a1<=0) a1+=k;
    while(a2<=0) a2+=k;
    while(a3<=0) a3+=k;
    while(a4<=0) a4+=k;
    for(int i=0;i<n;i++)
    {
        LL step,x;
        step=(LL)i*k+a1;
        x=solve(step);
        mx=max(mx,x),mn=min(mn,x);
		step=(LL)i*k+a2;
        x=solve(step);
        mx=max(mx,x),mn=min(mn,x);
		step=(LL)i*k+a3;
        x=solve(step);
        mx=max(mx,x),mn=min(mn,x);
		step=(LL)i*k+a4;
        x=solve(step);
        mx=max(mx,x),mn=min(mn,x);
    }
    printf("%lld %lld\n",mn,mx);
    return 0;
}