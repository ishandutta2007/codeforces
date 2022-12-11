#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
vector <vpii> g;
vector <int> col;
bool dfs(int s,int ok)
{
    bool ko=true;
    col[s]=ok+1;
    for (auto to:g[s])
    {
        if (col[to.fi]==0)
            ko&=dfs(to.fi,1-ok);
        else if (col[to.fi]==ok+1)
        {
            return false;
        }
    }
    return ko;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    col=vi(n);
    g=vvpii(n);
    vector <vector <int> >dp(n,vi(n,INF));
    for (int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        if (w==1)
        {
            dp[u][v]=1;
            dp[v][u]=-1;
            g[u].pb({v,1});
            g[v].pb({u,-1});
        }
        else
        {
            dp[u][v]=1;
            dp[v][u]=1;
            g[u].pb({v,1});
            g[v].pb({u,1});
        }
    }
    if (!dfs(0,0))
    {
        cout<<"NO\n";
        return;
    }
    for (int i=0;i<n;i++)
        dp[i][i]=0;
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (dp[i][k]==INF||dp[j][k]==INF)
                    continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    vector <vector <int> > dpp=dp;
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (dp[i][k]==INF||dp[j][k]==INF)
                    continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (dp[i][j]!=dpp[i][j])
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    int ind1=-1,ind2=-1;
    int mx=-1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mx<dp[i][j])
            {
                mx=dp[i][j],ind1=i,ind2=j;
            }
        }
    }
    cout<<"YES\n";
    cout<<mx<<'\n';
    for (int i=0;i<n;i++)
        cout<<dp[ind1][i]<<" ";
    cout<<'\n';
}

int main() {
    #ifdef Mip182
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}