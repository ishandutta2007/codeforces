#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod=998244353;
long long v[1003],d[1003],n;
int lgput (long long a, long long exp)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}
long long cazan (int poz)
{
    long long i,s=0,cmb=1,sc=0;
    i=poz;
    if(d[i]!=-1)
        return d[i];
    if(v[poz]<=0)
    {
        d[i]=0;
        return 0;
    }
    if(poz+v[poz]>n)
    {
        d[i]=0;
        return 0;
    }
    long long jos=1;
    for(i=n-poz;i>=n-poz-v[poz]+1;--i)
        cmb=(cmb*1LL*i)%mod;
    for(i=1;i<=v[poz];++i)
        jos=(jos*1LL*i)%mod;
    cmb=(cmb*1LL*lgput(jos,mod-2))%mod;
    long long y=v[poz],x=n-poz;
    for(i=n;i>=poz+v[poz];--i)
    {
        sc=cazan(i+1);
        s=(s+(cmb*1LL*sc)%mod)%mod;
        cmb=(cmb*1LL*(x-y)%mod)%mod;
        cmb=(cmb*1LL*lgput(x,mod-2))%mod;
        --x;
    }
    d[poz]=s;
    return d[poz];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,h,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    d[n+1]=1;
    for(i=1;i<=n;++i)
        d[i]=-1;
    for(i=1;i<=n;++i)
        a=cazan(i);
    long long s=0;
    for(i=1;i<=n;++i)
        s=(s+d[i])%mod;
    cout<<s;
    return 0;
}