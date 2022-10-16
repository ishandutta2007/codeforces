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
//long long v[100005];
char v[100005];
int main()
{
    long long t,i,j=0,c,dif,ok,rad,s0=0,x,k,jdr=1,s1=0,mx=0,d,a,b,y,m,cur,n,poz;
    cin>>v;
    n=strlen(v);
    for(i=0;i<n;++i)
    {
        if(v[i]=='2')
        {
            if(j==0)
                poz=i;
            j=1;
        }
        if(v[i]=='1')
            ++s1;
        if(v[i]=='0' && j==0)
            ++s0;
    }
    for(i=1;i<=s0;++i)
        cout<<0;
    for(i=1;i<=s1;++i)
        cout<<1;
    for(i=poz;i<n;++i)
        if(v[i]!='1')
            cout<<v[i];
    return 0;
}