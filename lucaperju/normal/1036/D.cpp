#include <bits/stdc++.h>
using namespace std;
/*long long cmmdc(long long a,long long b)
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
}*/
int a[300015],b[300015];
int main()
{
    ios_base::sync_with_stdio (0);
   // long long l,r,n,m,t,i,j,ca=0,cb=0,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,ck,pzx,pzn,k,x,y,z,ok=0,cur,cn,cnt=0,q,cj;
    long long n,m,i,j,ca=0,cb=0,s=1;
    int ok=0;
    char cc;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        ca+=a[i];
    }
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>b[i];
        cb+=b[i];
    }
    if(ca!=cb)
    {
        cout<<-1;
        ok=1;
    }
    i=j=1LL;
    ca=a[1];
    cb=b[1];
    if(ok==0)
    while(i<n && j<m)
    {
        if(ca==cb)
        {
            ++s;
            ++i,ca+=a[i];
            ++j,cb+=b[j];
        }
        else
        if(ca<cb)
            ++i,ca+=a[i];
        else
            ++j,cb+=b[j];
    }
    if(ok==0)
        cout<<s;
    return 0;
}