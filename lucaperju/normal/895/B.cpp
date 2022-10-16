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
int v[100005];
int main()
{
    long long t,i,j=1,n,a,b,c,dif,ok,rad,s=0,x,k,jdr=1;
    cin>>n>>x>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
 //   for(i=1;i<=n;++i)
 //       v[i]/=x;
  /*  while(j<=n)
    {
        while(v[j]/x-(v[i]-1)/x<k && j<=n)
            ++j;
        while(v[j]/x-(v[i]-1)/x>k && i<=n)
            ++i;
        a=1;
        b=1;
        while(v[j+1]/x-(v[i]-1)/x==k && j+1<=n)
            ++j,++a;
        while(v[j]/x-(v[i+1]-1)/x==k && i+1<=n)
            ++i,++b;
        if(v[j]/x-(v[i]-1)/x==k)
            s+=a*b;
        ++i;
        ++j;
    }*/
    for(i=1;i<=n;++i)
    {
        while((v[j]/x-(v[i]-1)/x<k || j<i && v[j]<v[i]) && j+1<=n)
            ++j;
        while(v[jdr+1]/x-(v[i]-1)/x<=k && jdr+1<=n)
            ++jdr;
        if(v[j]/x-(v[i]-1)/x==k)
            s+=jdr-j+1;
    }
    cout<<s;
    return 0;
}