#include <bits/stdc++.h>
#pragma GCC optimize("fast-math")
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n;
vector <int> g[MAXN];
int par[MAXN];
int dp[MAXN][17];
vector <int> d;
void dfs(int s,int p)
{
    par[s]=p;
    for (auto to:g[s])
    {
        if (to==p)
            continue;
        dfs(to,s);
    }
}
void bfs(int s)
{
    d=vector <int> (n,INF);
    d[s]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int f=q.front();
        q.pop();
        for (auto to:g[f])
        {
            if (d[to]==INF)
            {
                q.push(to);
                d[to]=d[f]+1;
            }
        }
    }
}
void build()
{
    for (int i=0;i<n;i++)
        dp[i][0]=par[i];
    for (int i=1;i<17;i++)
    {
        for (int j=0;j<n;j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];
    }
}

int lca(int u,int v)
{
    if (d[u]<d[v])
        swap(u,v);
    for (int i=16;i>=0;i--)
    {
        if (d[u]-d[v]>=(1<<i))
            u=dp[u][i];
    }
    if (u==v)
        return u;
    for (int i=16;i>=0;i--)
    {
        if (dp[u][i]!=dp[v][i])
            u=dp[u][i],v=dp[v][i];
    }
    return par[u];
}
int dist(int u,int v)
{
    return d[u]+d[v]-(d[lca(u,v)]<<1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    bfs(0);
    build();
    int q;
    cin>>q;
    while (q--)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        x--,y--,a--,b--;
        int xa=dist(x,a),xb=dist(x,b),ya=dist(y,a),yb=dist(y,b),ab=dist(a,b);
        bool ok=false;
        if (k>=ab&&!((ab-k)&1))
            ok=true;
        if (xa+yb+1<=k&&!((xa+yb+1-k)&1))
            ok=true;
        if (xb+ya+1<=k&&!((xb+ya+1-k)&1))
            ok=true;
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }



}