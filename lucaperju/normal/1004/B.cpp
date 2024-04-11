#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*
for(i=1;i<=n;++i)
*/
long long v[5005],fv[5005];
int main()
{
    long long t,i,j=0,n,c,dif,ok,rad,s=2,x,k,jdr=1,s1=0,mx=0,d,a,b,y;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        if(i%2==1)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}