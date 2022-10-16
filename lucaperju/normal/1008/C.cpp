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
long long v[100005],v12[100005];
int main()
{
    long long t,i,j=0,n,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0,mx=0,d,a,b,y,sc;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v12[i];
    sort(v12+1,v12+n+1);
    for(i=1;i<=n;++i)
    {
        if(v12[i]!=v12[i-1] && i!=1)
        {
            v[++j]=s;
            s=1;
        }
        else
            ++s;
    }
    v[++j]=s;
    s=0;
    s1=n;
    for(i=1;i<=j;++i)
        v12[i]=v[i];
    n=j;
    j=2;
    for(i=1;i<=n;++i)
    {
        a=v[i];
        sc=0;
        if(j==i)
            ++j;
        while(sc<v[i] && j<=n)
            sc+=v12[j++];
        if(sc>v[i])
        {
            --j;
            v12[j]=(sc-v[i]);
        }
        s+=min(v[i],sc);
    }
    cout<<s;
    return 0;
}