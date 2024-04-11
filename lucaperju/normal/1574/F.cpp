#include <bits/stdc++.h>

using namespace std;

//*
const long long mod = 998244353;
/*
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
vector<int>v[300005];
int nxt[300005],pre[300005];
void add (int a, int b)
{
    if(a!=b){
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if((nxt[a]==0 || nxt[a]==b) && a!=b)
        nxt[a]=b;
    else
        nxt[a]=-1;
    if((pre[b]==0 || pre[b]==a) && a!=b)
        pre[b]=a;
    else
        pre[b]=-1;
}
int viz[300005];
int sz;
void dfs (int pz, int vlc)
{
    ++sz;
    viz[pz]=vlc;
    for(int i=0;i<v[pz].size();++i)
    {
        if(viz[v[pz][i]]==vlc)
            continue;
        dfs(v[pz][i],vlc);
    }
}
int cnt[300005];
int dp[300005];
int viz1[300005];
map<int,int>fvc;
vector<pair<int,int> >vc;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,r,m,s,k,j,q,n;
    cin>>k>>m>>n;
    for(i=1;i<=k;++i)
    {
        int nc;
        cin>>nc;
        int prec;
        cin>>prec;
        ++fvc[prec];
        for(j=2;j<=nc;++j)
        {
            int a;
            cin>>a;
            ++fvc[a];
            if(fvc[a]==2)
                nxt[a]=pre[a]=-1;
            add(prec,a);
            prec=a;
        }
        fvc.clear();
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
            if(nxt[i]==-1 || pre[i]==-1)
                dfs(i,1);
    for(i=1;i<=n;++i)
    {
        if(!viz[i] && !viz1[i])
        {
            int pz=i;
            while(nxt[pz] && nxt[pz]!=i)
            {
                viz1[pz]=1;
                pz=nxt[pz];
            }
            if(nxt[pz]==i || nxt[pz]==-1)
                dfs(i,1);
        }
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
        {
            sz=0;
            dfs(i,2);
            ++cnt[sz];
        }
    for(i=1;i<=m;++i)
        if(cnt[i])
            vc.push_back(make_pair(i,cnt[i]));
    dp[0]=1;
//    for(i=0;i<vc.size();++i)
//    {
//        pair<int,int>a=vc[i];
//        for(j=a.first;j<=m;++j)
//            dp[j]=(dp[j]+dp[j-a.first]*1LL*a.second%mod)%mod;
//    }
    for(i=1;i<=m;++i)
    {
        for(j=0;j<vc.size();++j)
        {
            if(i-vc[j].first>=0)
                dp[i]=(dp[i]+dp[i-vc[j].first]*1LL*vc[j].second%mod)%mod;
        }
    }
    cout<<dp[m];
    return 0;
}