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
int v[100];
int main()
{
    long long a,b,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    cin>>n>>k;
    j=k*2+1;
    for(j=min(n,2*k+1);j>=k+1;--j)
    {
        if((n-j)%(k*2+1)>=k+1 || (n-j)%(k*2+1)==0)
            break;
    }
    if(n<=k*2+1)
    {
        cout<<1<<'\n'<<(n+1)/2;
        return 0;
    }
    cout<<2+(n-j-1)/(k*2+1)<<'\n';
    for(i=k+1-(k*2+1-j);i<=n;i+=k*2+1)
        cout<<i<<' ';
    return 0;
}