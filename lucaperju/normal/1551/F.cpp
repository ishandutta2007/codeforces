#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
}

vector<int>v[103];
int ok[103];
vector<int>vc[103];
int dp[103];

void dfs (int pz, int dst, int t)
{
    ++ok[dst];
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],dst+1,pz);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,i,j,k,cnt=0;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(k==2)
        {
            cout<<n*1LL*(n-1)/2<<'\n';
            continue;
        }
        long long ans=0;
        for(i=1;i<=n;++i)
        {
            for(j=0;j<v[i].size();++j)
            {
                dfs(v[i][j],1,i);
                for(int jj=1;jj<=n;++jj)
                {
                    if(ok[jj])
                        vc[jj].push_back(ok[jj]);
                    else
                        break;
                    ok[jj]=0;
                }
            }
            for(j=1;j<=n;++j)
            {
                for(int jj=0;jj<=n;++jj)
                    dp[jj]=0;
                dp[0]=1;
                for(int jj=0;jj<vc[j].size();++jj)
                {
                    int vlc=vc[j][jj];
                    for(int idk=k;idk>=1;--idk)
                        dp[idk]=(dp[idk]+(dp[idk-1]*1LL*vlc)%mod)%mod;
                }
                vc[j].clear();
                ans=(ans+dp[k])%mod;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}