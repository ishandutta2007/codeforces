#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
long long x[300005],w[300005];
long long ans[300005];
int st[300005];
struct qry
{
    int l,r,pz;
}qs[300005];
bool cmp (qry a, qry b)
{
    return a.l>b.l;
}
struct ura
{
    int l,r;
    long long val;
};
vector<ura>idk;
long long cst (int a, int b)
{
    return (x[b]-x[a])*1LL*(w[a]+w[b]);
}
bool cmp1 (ura a, ura b)
{
    return a.l>b.l;
}
int lsb(int x)
{
    return x&-x;
}
long long aib[300005];
void upd (int pz, long long val)
{
    for(int i=pz;i<=300000;i+=lsb(i))
        aib[i]=min(aib[i],val);
}
long long qry (int pz)
{
    long long rz=4000000000000000000LL;
    for(int i=pz;i>0;i-=lsb(i))
        rz=min(rz,aib[i]);
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,y,k,m,j=0,n,tt,p;
    cin>>n>>q;
    for(i=1;i<=300000;++i)
        aib[i]=4000000000000000000LL;
    for(i=1;i<=n;++i)
    {
        cin>>x[i]>>w[i];
    }
    for(i=1;i<=q;++i)
    {
        cin>>qs[i].l>>qs[i].r;
        qs[i].pz=i;
    }
    sort(qs+1,qs+q+1,cmp);
    k=0;
    for(i=1;i<=n;++i)
    {
        while(k>0 && w[st[k]]>w[i])
            --k;
        if(k>0)
            idk.push_back({st[k],i,cst(st[k],i)});
        st[++k]=i;
    }
    k=0;
    for(i=n;i>=1;--i)
    {
        while(k>0 && w[st[k]]>w[i])
            --k;
        if(k>0)
            idk.push_back({i,st[k],cst(i,st[k])});
        st[++k]=i;
    }
    sort(idk.begin(),idk.end(),cmp1);
    j=1;
    i=0;
    while(j<=q)
    {
        int lc=qs[j].l;
        while(i<idk.size() && idk[i].l>=lc)
        {
            upd(idk[i].r,idk[i].val);
            ++i;
        }
        ans[qs[j].pz]=qry(qs[j].r);
        ++j;
    }
    for(i=1;i<=q;++i)
        cout<<ans[i]<<'\n';
    return 0;
}