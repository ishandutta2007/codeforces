#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
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
    else if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
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
long long verif (long long n)
{
    long long i;
    if(n==1)
        return -1;
    for(i=2;i*i<=n;++i)
    {
        if(n%i==0)
            return i;
    }
    return -1;
}
int v[500003];
int main()
{
    long long l,r,a=0,b=0,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    char cc;
    cin>>n;
    if(n==1)
    {
        cin>>a;
        cout<<a;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]>0)
        {
            a=1;
            if(v[i]<mn)
                mn=v[i],ca=i;
        }
        if(v[i]<=0)
        {
            b=1;
            if(0-v[i]<mn)
                mn=0-v[i],ca=i;
        }
    }
    if(a==0 || b==0)
        s=-mn,v[ca]=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]>0)
            s+=v[i];
        else
            s-=v[i];
    }
    cout<<s;
    return 0;
}