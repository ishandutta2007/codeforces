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
int v[5005];
int main()
{
    long long t,i,j=1,n,a,b,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0,mx;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    s=mx=0;
    for(i=1;i<=n;++i)
    {
        a=v[i];
        if(s==0 || mx==a && s1==s)
        {
            ++s;
            mx=max(mx,a);
        }
        else
        if(a>mx)
        {
            mx=a;
            s1=0;
        }
        if(a==mx)
            ++s1;
    }
    cout<<s;
    return 0;
}