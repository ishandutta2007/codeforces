#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
    else
    if(cnt<0)
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
int main()
{
    long long a,b,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        if(a>mx)
            mx1=mx,mx=a,pzx=i;
        else
            if(a>mx1)
                mx1=a;
        if(b<mn)
            mn1=mn,mn=b,pzn=i;
        else
            if(b<mn1)
                mn1=b;
    }
    if(pzx==pzn)
        cout<<max(0LL,mn1-mx1);
    else
    cout<<max(0LL,max(mn1-mx,mn-mx1));
    return 0;
}