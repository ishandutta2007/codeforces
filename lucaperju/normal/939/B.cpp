#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
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
int main()
{
    long long i,j,n,a,b,c,mx=-9999999999999,mn=9999999999999,k,mnpz=1;
    cin>>n>>k;
    for(i=1;i<=k;++i)
    {
        cin>>a;
        if(i==1)
        {
            mn=a;
            continue;
        }
        if(n%a<n%mn)
        {
            mn=a;
            mnpz=i;
        }
    }
    cout<<mnpz<<' '<<n/mn;
    return 0;
}