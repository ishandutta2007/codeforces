#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
bool v[60005];
int main()
{
    long long i,j,n,a,b,mx=-9999999999999,mn=9999999999999,k=0,s1=0,s2=0;
    cin>>n;
    for(i=n;i>=1;--i)
    {
        if(s1<=s2)
        {
            ++k;
            s1+=i;
            v[i]=1;
        }
        else
            s2+=i;
    }
    cout<<max(s1-s2,s2-s1)<<'\n'<<k<<' ';
    for(i=1;i<=n;++i)
        if(v[i])
            cout<<i<<' ';
    return 0;
}