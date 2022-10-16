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
int fv[30];
int main()
{
    long long l,r,a,b,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    char cc;
    cin>>n;
    a=n*1LL*(n+1)/2;
    b=verif(a);
    if(b!=-1)
        cout<<"Yes\n";
    else
    {
        cout<<"No";
        return 0;
    }
    a=b;
    for(i=a;i<=n;i+=a)
        ++s;
    cout<<s<<' ';
    for(i=a;i<=n;i+=a)
        cout<<i<<' ';
    cout<<'\n';
    cout<<n-s<<' ';
    for(i=1;i<=n;++i)
        if(i%a)
            cout<<i<<' ';
    return 0;
}