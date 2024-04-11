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
int v[20];
int main()
{
    long long i,j,n,a,b,mx1=-1,mx2=-1,rez=-1,rezi,cr,init=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        init+=v[i];
    }
    if(n==1 || n==2 && v[1]==v[2])
    {
        cout<<-1;
        return 0;
    }
    else
    if(n==2)
    {
        cout<<1<<'\n'<<1;
        return 0;
    }
    else
    {
        for(i=1;i<=n;++i)
        {
            cr=init-v[i];
            if(v[i]!=cr)
            {
                cout<<1<<'\n'<<i;
                return 0;
            }
        }
        cout<<-1;
    }
    return 0;
}