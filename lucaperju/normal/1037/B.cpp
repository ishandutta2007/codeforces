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
long long v[200005];
int main()
{
    long long n,m,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,s=0,k,x,y,z,ok=1,cur,cn,cnt=0,q,a,b,c;
    cin>>n>>s;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    cn=(n+1)/2;
    if(v[cn]<s)
    {
        for(i=cn;i<=n;++i)
            cnt+=max(0LL,s-v[i]);
    }
    else
    if(v[cn]>s)
    {
        for(i=cn;i>=1;--i)
            cnt+=max(0LL,v[i]-s);
    }
    cout<<cnt;
    return 0;
}