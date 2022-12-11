//#define _GLIBCXX_DEBUG
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
#define vvll vector <vll>
#define vsi vector <si>
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
vector <int> d;
vector <int> dp;
vvi g;
vector <int> good;
void dfs(int s,int ok,int p)
{
    d[s]=ok;
    dp[s]=1;
    for (auto to:g[s])
    {
       if (to==p)
           continue;
       dfs(to,ok+1,s);
       dp[s]+=dp[to];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
        int n,k;
        cin>>n>>k;
        g=vvi(n);
        good=vi(n,0);
        dp=vi(n,0);
        for (int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        d=vi(n,0);
        dfs(0,0,-1);
        vector <pair <int,int> > a(n);
        for (int i=0;i<n;i++)
            a[i]={d[i]-dp[i]+1,i};
        sort(all(a));
        ll ans=0;
        reverse(all(a));
        for (int i=0;i<k;i++)
            ans+=a[i].fi;
        cout<<ans<<'\n';





}