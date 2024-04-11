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
vector<int>v[200005];
vector<int>v1[200005];
vector<int>ord;
int viz[200005];
int pzs[200005];
int dp[200005];
int timp=0;
void dfs (int pz)
{
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
            dfs(v[pz][i]);
    }
    pzs[pz]=++timp;
    ord.push_back(pz);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,r,s,j,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            v1[i].clear();
            viz[i]=0;
        }
        timp=0;
        ord.clear();
        for(i=1;i<=n;++i)
        {
            int c;
            cin>>c;
            for(j=1;j<=c;++j)
            {
                int a;
                cin>>a;
                v[a].push_back(i);
                v1[i].push_back(a);
            }
        }
        for(i=1;i<=n;++i)
            if(!viz[i])
                dfs(i);
        int ok=1;
        for(i=1;i<=n;++i)
        {
            for(j=0;j<v[i].size();++j/**FK*/)
            {
                if(pzs[i]<pzs[v[i][j]])
                    ok=0;
            }
        }
        if(!ok)
        {
            cout<<"-1\n";
            continue;
        }
        int rz=1;
        for(i=n-1;i>=0;--i)
        {
            int pzc=ord[i];
            int mxc=1;
            for(j=0;j<v1[pzc].size();++j)
            {
                int pr=v1[pzc][j];
                mxc=max(mxc,dp[pr]+(pzc<pr));
            }
            dp[pzc]=mxc;
            rz=max(rz,dp[pzc]);
        }
        cout<<rz<<'\n';
    }
    return 0;
}