#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}*/

map<int,int>newval;
struct segment
{
    int i,l,r;
}v[300005];
vector<int>vall;
/// 600000 * 4
int dp[300005];
int prec[300005];
int aint[2400003],lazy[2400003];
int ok[300005];
void upd (int nod, int l, int r, int ql, int qr, int val)
{
    if(r<l)
        return;
    if(ql<=l && r<=qr)
    {
        if(dp[val]>dp[lazy[nod]])
            lazy[nod]=val;
        if(dp[lazy[nod]]>dp[aint[nod]])
            aint[nod]=lazy[nod];
        return;
    }
    if(r<ql || qr<l)
        return;
    int mid=(l+r)/2;
    upd(nod*2,l,mid,ql,qr,val);
    upd(nod*2+1,mid+1,r,ql,qr,val);
    if(dp[aint[nod*2]]>dp[aint[nod]])
        aint[nod]=aint[nod*2];
    if(dp[aint[nod*2+1]]>dp[aint[nod]])
        aint[nod]=aint[nod*2+1];
}
int query (int nod, int l, int r, int ql, int qr)
{
    if(r<l)
        return 0;
    if(ql<=l && r<=qr)
    {
        return aint[nod];
    }
    if(r<ql || qr<l)
        return 0;
    int mid=(l+r)/2;
    int a=query(nod*2,l,mid,ql,qr);
    int b=query(nod*2+1,mid+1,r,ql,qr);
    if(dp[a]<dp[b])
        a=b;
    if(dp[a]>dp[lazy[nod]])
        return a;
    else
        return lazy[nod];
}
bool cmp (segment a, segment b)
{
    return a.i<b.i;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>v[i].i>>v[i].l>>v[i].r;
        vall.push_back(v[i].l);
        vall.push_back(v[i].r);
    }
    sort(vall.begin(),vall.end());
    int vlc=0;
    for(i=0;i<vall.size();++i)
    {
        if(i==0 || vall[i]!=vall[i-1])
            ++vlc;
        newval[vall[i]]=vlc;
    }
    for(i=1;i<=m;++i)
    {
        v[i].l=newval[v[i].l];
        v[i].r=newval[v[i].r];
    }
    sort(v+1,v+m+1,cmp);
    int pz=1;
    for(i=1;i<=n;++i)
    {
        dp[i]=1;
        prec[i]=i;
        while(v[pz].i==i)
        {
            int a=query(1,1,600000,v[pz].l,v[pz].r);
            if(1+dp[a]>dp[i])
            {
                dp[i]=1+dp[a];
                prec[i]=a;
            }
            ++pz;
        }
        j=pz-1;
        while(v[j].i==i)
        {
            upd(1,1,600000,v[j].l,v[j].r,i);
            --j;
        }
    }
    int mx=1;
    pz=1;
    for(i=1;i<=n;++i)
    {
        if(dp[i]>mx)
            mx=dp[i],pz=i;
    }
    cout<<n-dp[pz]<<'\n';
    ok[pz]=1;
    while(prec[pz]!=pz)
    {
        pz=prec[pz];
        ok[pz]=1;
    }
    for(i=1;i<=n;++i)
        if(!ok[i])
            cout<<i<<' ';
    return 0;
}