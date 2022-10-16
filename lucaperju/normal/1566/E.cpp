#include <bits/stdc++.h>

using namespace std;

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
vector<int>v[200003];
int dp[200003];
int dp1[200003];
void dfs (int pz, int t)
{
    int cnt=0;
    dp[pz]=0;
    dp1[pz]=0;
    int nrf=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
        dp[pz]+=dp[v[pz][i]];
        dp1[pz]=max(dp1[pz],dp1[v[pz][i]]);
        cnt+=1-dp1[v[pz][i]];
        ++nrf;
    }
    dp1[pz]=1-dp1[pz];
    if(pz!=1 && nrf==0)
    dp[pz]+=dp1[pz];
    if(cnt==nrf)
        dp[pz]=dp[pz]-max(0,cnt-1);
    else
        dp[pz]=dp[pz]-cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,j,k,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            dp[i]=0;
            dp1[i]=0;
            v[i].clear();
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        cout<<dp[1]<<'\n';
    }
    return 0;
}