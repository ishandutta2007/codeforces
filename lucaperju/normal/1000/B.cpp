#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
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
long long v[100005],si[100005],sp[100005];
int main()
{
    long long n,m,i,j=-2,a,b,c,cat=0,cat1=0,mx=-99999999999,mn=99999999999,nrm=0,nrs=0,nrl=0,nrxs=0,nrxl=0,nrxxs=0,nrxxl=0,nrxxxs=0,nrxxxl=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(i%2==1)
            si[i]=si[i-1]+v[i]-v[i-1],sp[i]=sp[i-1];
        else
            sp[i]=sp[i-1]+v[i]-v[i-1],si[i]=si[i-1];
    }
    i=n+1;
    if(i%2==1)
        si[i]=si[i-1]+m-v[i-1],sp[i]=sp[i-1];
    else
        sp[i]=sp[i-1]+m-v[i-1],si[i]=si[i-1];
    mx=si[n+1];
    for(i=1;i<=n;++i)
    {
        if(i%2==1)
            mx=max(mx,si[i]+sp[n+1]-sp[i]-1);
    }
    cout<<mx;
    return 0;
}