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
long long v[200003];
int main()
{
    long long i,j,n,a,b,c,mx=-9999999999999,mn=9999999999999,k,mnpz=1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        v[i+n]=v[i];
    }
    for(i=1;i<=2*n;++i)
        v[i]+=v[i-1];
    cin>>b>>c;
    a=c-b;
    for(i=1;i<=n;++i)
    {
        if(v[(n-i+b)%n+a]-v[(n-i+b)%n]>mx)
        {
            mx=v[(n-i+b)%n+a]-v[(n-i+b)%n];
            mnpz=i;
        }
    }
    cout<<mnpz;
    return 0;
}