#include <bits/stdc++.h>
 
using namespace std;
 
/*
const long long mod = 998244353;
//*
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
/*/
const int mod=1000000007;
int lsb (int x)
{
    return x&-x;
}
int aib[400005];
void upd (int pz, int val)
{
    for(int i=pz;i<=400000;i+=lsb(i))
    {
        aib[i]+=val;
        if(aib[i]>=mod)
            aib[i]-=mod;
    }
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
    {
        rz+=aib[i];
        if(rz>=mod)
            rz-=mod;
    }
    return rz;
}
void reset ()
{
    for(int i=1;i<=400000;++i)
        aib[i]=0;
}
struct ura
{
    int a,b,i;
}v[200005];
bool cmp (ura a, ura b)
{
    return a.b<b.b;
}
int npz[200005];
int dp[200005];
int pzs[200005];
struct ura1
{
    int a,b;
};
vector<ura1>vc;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].b;
        v[i].i=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;++i)
        npz[v[i].i]=i;
    long long sc=0;
    for(i=1;i<=n;++i)
    {
        dp[i]=(1LL+sc-(long long)query(v[i].a)+mod)%mod;
        upd(v[i].a,dp[i]);
        sc+=dp[i];
        if(sc>=mod)
            sc-=mod;
    }
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>pzs[i];
        pzs[i]=npz[pzs[i]];
    }
    sort(pzs+1,pzs+t+1);
    long long s=1;
    for(i=1;i<pzs[t];++i)
    {
        s+=dp[i];
        if(s>=mod)
            s-=mod;
    }
    int pz=t;
    while(pz>1)
    {
        for(i=pz-1;i>=1;--i)
            if(v[pzs[i]].a>v[pzs[pz]].a)
                break;
        if(i==0)
            break;
        vc.push_back({v[pzs[pz]].a,v[pzs[i]].b-1});
        ++s;
        if(s>=mod)
            s-=mod;
        pz=i;
    }
    reset();
    sc=0;
    j=(int)vc.size()-1;
    for(i=1;i<=n;++i)
    {
        //cout<<vc.size()<<' '<<j; well this is dumb af
        while(j>=0 && vc[j].b<v[i].b)
        {
            s=s+(sc-query(vc[j].a-1)+mod)%mod;
            if(s>=mod)
                s-=mod;
            --j;
        }
        upd(v[i].a,dp[i]);
        sc+=dp[i];
    }
    cout<<s;
}