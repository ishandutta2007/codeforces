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
int v[100005],r[100005],rezf[100005];
int main()
{
    long long i,j,n,a,b,mx1=-1,mx2=-1,rez=-1,rezi,cr,init=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        if(v[i]>mx1)
            mx1=v[i],r[i]=1,++init;
    }
    mx1=-1;
    for(i=1;i<=n;++i)
    {
        if(v[i]>mx1)
        {
            pz=i;
            mx2=mx1;
            mx1=v[i];
        }
        else
        if(v[i]>mx2)
        {
            rezf[pz]++;
            mx2=v[i];
        }
    }
    mx1=-1;
    for(i=1;i<=n;++i)
    {
        if(rezf[i]-r[i]>mx1 ||rezf[i]-r[i]==mx1 && v[i]<pz)
        {
            mx1=rezf[i]-r[i];
            pz=v[i];
        }
    }
    cout<<pz;
    return 0;
}