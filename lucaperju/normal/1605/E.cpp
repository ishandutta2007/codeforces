#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
const long long mod = 998244353;

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
*/
long long a[200005],ca[200005],delta[200005],cat[200005],b[200005],rz[200005];
struct ura
{
    int val,pz;
}qs[200005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
struct ura1
{
    long long val,delta;
    int cand;
}v[200005];
bool cmp1 (ura1 a, ura1 b)
{
    return a.cand<b.cand;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,n,i,j,t;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;++i)
    {
        cin>>b[i];
        ca[i]=a[i];
    }
    cin>>q;
    for(i=1;i<=q;++i)
    {
        cin>>qs[i].val;
        qs[i].pz=i;
    }
    sort(qs+1,qs+q+1,cmp);
    long long s0=0;
    b[1]=0;
    for(i=1;i<=n;++i)
    {
        if(i!=1)
        s0+=max(ca[i]-b[i],b[i]-ca[i]);
        cat[i]=b[i]-ca[i];
        for(j=i+i;j<=n;j+=i)
            ca[j]+=(b[i]-ca[i]);
        ca[i]=b[i];
    }
    for(i=1;i<=n;++i)
        ca[i]=1;
    for(i=2;i<=n;++i)
    {
        delta[i]=ca[i];
        for(j=i+i;j<=n;j+=i)
            ca[j]-=ca[i];
        ca[i]=0;
    }
    for(i=2;i<=n;++i)
    {
        v[i-1].val=cat[i];
        v[i-1].delta=delta[i];
    }
    --n;
    long long ds=0;
    for(i=1;i<=n;++i)
    {
        if(v[i].val<0)
        {
            v[i].val=-v[i].val;
            v[i].delta=-v[i].delta;
        }
        if(v[i].delta<=0)
            v[i].cand=1000006;
        else
            v[i].cand=(v[i].val-1)/v[i].delta+1;
        ds-=v[i].delta;
    }
    long long sc=s0,lst=0,cds;
    sort(v+1,v+n+1,cmp1);
    j=1;
    for(i=1;i<=q;++i)
    {
        int vlc=qs[i].val;
        cds=ds;
        while(j<=n && v[j].cand<=vlc)
        {
            sc=sc-abs(v[j].delta*1LL*lst-v[j].val)+abs(v[j].delta*1LL*vlc-v[j].val);
            cds=cds+v[j].delta+v[j].delta;
            ds=ds+v[j].delta;
            ++j;
        }
        sc=sc+ds*1LL*(vlc-lst);
        lst=vlc;
        ds=cds;
        rz[qs[i].pz]=sc+abs(vlc-a[1]);
    }
    for(i=1;i<=q;++i)
        cout<<rz[i]<<'\n';
    return 0;
}