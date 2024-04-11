#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
const int pp=10000019;
const int qq=1000000007;
long long putp[1003];
int v[150005],w[150005];
int k;
int dp[1003];
int oldDp[30004][1003];
int Q=0;
void add (int val)
{
    ++Q;
    for(int i=k;i>=0;--i)
    {
        oldDp[Q][i]=dp[i];
        if(i>=w[val])
            dp[i]=max(dp[i],v[val]+dp[i-w[val]]);
    }
}
void undo ()
{
    assert(Q>0);
    for(int i=0;i<=k;++i)
        dp[i]=oldDp[Q][i];
    --Q;
}
int getAns ()
{
    int s=0;
    for(int m=1;m<=k;++m)
        s=(s+dp[m]*1LL*putp[m-1]%qq)%qq;
    return s;
}
struct query
{
    int tip,a,b;
};
vector<query>qs;
int l[150005],r[150005];
int hasq[150005];
int ans[150005];
vector<int>aint[120005];
void upd (int nod, int l, int r, int ql, int qr, int val)
{
    if(ql<=l && r<=qr)
    {
        aint[nod].push_back(val);
        return;
    }
    if(qr<l || r<ql)
        return;
    int mid=((l+r)>>1);
    upd(nod<<1,l,mid,ql,qr,val);
    upd((nod<<1)|1,mid+1,r,ql,qr,val);
}
void solve (int nod, int l, int r)
{
    for(int i=0;i<aint[nod].size();++i)
        add(aint[nod][i]);
    if(l==r)
    {
        if(hasq[l])
            ans[l]=getAns();
    }
    else
    {
        int mid=(l+r)/2;
        solve(nod<<1,l,mid);
        solve((nod<<1)|1,mid+1,r);
    }
    for(int i=0;i<aint[nod].size();++i)
        undo();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,n;
    putp[0]=1;
    for(i=1;i<=1000;++i)
        putp[i]=pp*1LL*putp[i-1]%qq;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        l[i]=1;
        cin>>v[i]>>w[i];
    }
    cin>>q;
    j=n;
    for(i=1;i<=q;++i)
    {
        query qc;
        cin>>qc.tip;
        if(qc.tip==3)
        {
            hasq[i]=1;
        }
        else
        if(qc.tip==2)
        {
            cin>>qc.a;
            r[qc.a]=i;
        }
        else
        if(qc.tip==1)
        {
            cin>>qc.a>>qc.b;
            l[++j]=i;
            v[j]=qc.a;
            w[j]=qc.b;
        }
        qs.push_back(qc);
    }
    n=j;
    for(i=1;i<=n;++i)
    {
        if(r[i]==0)
            r[i]=q;
        upd(1,1,q,l[i],r[i],i);
    }
    solve(1,1,q);
    for(i=1;i<=q;++i)
    {
        if(hasq[i])
            cout<<ans[i]<<'\n';
    }
    return 0;
}