#include <bits/stdc++.h>
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
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n;
int a[MAXN];
int dp[MAXN];
vector <int> used;
int ans[MAXN];
vvi g;
void dfs(int s)
{
   // cout<<s<<'\n';
  used[s]=1;
  int sum=0;
  for (auto to:g[s])
  {
      if (used[to]==0)
      {
          dfs(to);
          sum+=max(dp[to],0);
      }
  }
  dp[s]=sum+a[s];
}
void dfss(int s)
{
    ans[s]=dp[s];
    used[s]=1;
    for (auto to:g[s])
    {
        if (used[to]==0)
        {
            dp[s]-=max(dp[to],0);
            dp[to]+=max(dp[s],0);
            dfss(to);
            dp[to]-=max(dp[s],0);
            dp[s]+=max(dp[to],0);
        }
    }
}
int main() {
  //  ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    cin>>n;
    used=vi(n);
    g=vvi(n);
    rep(i,n) {
        cin >> a[i];
        if (a[i]==0)
            a[i]=-1;
    }
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
  //  rep(i,n)
  //  cout<<dp[i]<<'\n';

    used=vi(n);
    dfss(0);
    for (int i=0;i<n;i++)
        cout<<ans[i]<<" ";

}