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
    for(i=2; i*i<=n; ++i)
    {
        if(n%i==0)
            return i;
    }
    return -1;
}
int main()
{
    long long a,b,l,r,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,ck,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    char cc;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b>>k;
        ck=k;
        k-=min(a,b);
        a=max(a,b)-min(a,b);
        if(a%2==1)
        {
            if(k>=a)
                cout<<ck-1<<'\n';
            else
                cout<<-1<<'\n';
        }
        else
        {
            if(k>=a)
            {
                k=k-a+1;
                if(k%2==1)
                    cout<<ck<<'\n';
                else
                    cout<<ck-2<<'\n';
            }
            else
            cout<<-1<<'\n';
        }
    }
    return 0;
}