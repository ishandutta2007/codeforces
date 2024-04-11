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
vector<int>v[200005];
int dp[200005][2];
long long cat[200005][2];
void dfs (int pz, int t)
{
    dp[pz][1]=1;
    dp[pz][0]=0;
    cat[pz][1]=v[pz].size();
    cat[pz][0]=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        int nn=v[pz][i];
        dfs(v[pz][i],pz);
        dp[pz][1]+=dp[v[pz][i]][0];
        cat[pz][1]+=cat[v[pz][i]][0];
        if(dp[nn][1]>dp[nn][0] || dp[nn][1]==dp[nn][0] && cat[nn][1]<cat[nn][0])
            dp[pz][0]+=dp[nn][1],cat[pz][0]+=cat[nn][1];
        else
            dp[pz][0]+=dp[nn][0],cat[pz][0]+=cat[nn][0];
    }
}
int ans[200005];
void dfs1 (int pz, int t, bool forced)
{
    if(forced)
    {
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]==t)
                continue;
            dfs1(v[pz][i],pz,false);
        }
        return;
    }
    if(dp[pz][1]>dp[pz][0] || dp[pz][1]==dp[pz][0] && cat[pz][1]<cat[pz][0])
    {
        ans[pz]=1;
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]==t)
                continue;
            dfs1(v[pz][i],pz,true);
        }
    }
    else
    {
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]==t)
                continue;
            dfs1(v[pz][i],pz,false);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,x,i,y,k,m,j=0,n,tt,p;
    cin>>n;
    if(n==2)
    {
        cout<<"2 2\n1 1";
        return 0;
    }
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1])<<' ';
    dfs1(1,-1,false);
    long long s=0;
    for(i=1;i<=n;++i)
    {
        if(ans[i]==1)
            ans[i]=v[i].size();
        else
            ans[i]=1;
        s+=ans[i];
    }
    cout<<s<<'\n';
    for(i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    return 0;
}