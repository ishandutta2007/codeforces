#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
long long dist (long long a, long long b)
{
    if(a>b)
        return a-b;
    return b-a;
}
long long v[200005];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nr0=0,nrb,ok=0,poz,cur=0,m,cn,cnt=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]==0)
        {
            ++nr0;
            continue;
        }
        a=v[i];
        b=sqrt(a);
        mx=9999999999;
        for(j=b-2;j<=b+5;++j)
            if(dist(j*j,a)<mx)
                mx=dist(j*j,a);
        v[i]=mx;
    }
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        if(v[i]==0)
            ++cnt;
    if(cnt>n/2)
    {
        nrb=cnt-nr0;
        s+=min(cnt-n/2,nrb);
        cnt-=min(cnt-n/2,nrb);
        s+=(cnt-n/2)*2;
    }
    else
    for(i=1;i<=n/2 && cnt<n/2;++i)
         if(v[i])
            s+=v[i],++cnt;
    cout<<s;
    return 0;
}