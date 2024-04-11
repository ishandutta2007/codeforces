#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define maxn 100100
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, int> PLI;
typedef pair <int, ll> PIL;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
#define LOG 19
int skok[maxn][LOG], pre[maxn], post[maxn], DL = 0;
vector <PII> v[maxn];
bool odw[maxn];
vector <PII> queries;
int dol[maxn], gora[maxn]; //dol to sciezka idaca w dol
int KRAW[maxn];
ll potmod(ll a, ll b)
{
    if (!b) return 1;
    if (b & 1) return a%mod*potmod(a*a%mod, b>>1)%mod;
    return potmod(a*a%mod, b>>1) % mod;
}

void dfs(int x)
{
    odw[x] = true;
    pre[x] = ++DL;
    for (auto u:v[x])
      if (!odw[u.e1])
      {
          dfs(u.e1);
          skok[u.e1][0] = x;
      }
    post[x] = ++DL;
}

inline bool parent(int x, int y) //czy x jest ojcem y
{
    if (pre[x] <= pre[y] && post[x] >= post[y]) return true;
    return false;
}
int lca(int x, int y)
{
    if (parent(x, y)) return x;
    if (parent(y, x)) return y;
    for (int j=LOG - 1; j>=0; --j)
      if (parent(skok[x][j], y) == false) x = skok[x][j];
    return skok[x][0];
}

void wyndfs(int x)
{
    odw[x] = true;
    int ile = 0, iledol = 0;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i].e1]) 
      {
          wyndfs(v[x][i].e1);
          if (v[x][i].e2 == -1) KRAW[v[x][i].e1] += gora[v[x][i].e1];
          if (v[x][i].e2 == 1) KRAW[v[x][i].e1] += dol[v[x][i].e1];
          ile += gora[v[x][i].e1];
          iledol += dol[v[x][i].e1];
      }
    gora[x] += ile;
    dol[x] += iledol;
}
int main() 
{
    scanf("%d", &n);
    for (int i=1; i<n; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (c) v[a].pb({b, -1}), v[b].pb({a, 1});
        else v[a].pb({b, 0}), v[b].pb({a, 0});
    }
    dfs(1);
    skok[1][0] = 1;
    for (int j=1; j<LOG; ++j)
      for (int i=1; i<=n; ++i) skok[i][j] = skok[skok[i][j-1]][j-1];

    int zap, skad = 1;
    scanf("%d", &zap);
    for (int z=1; z<=zap; ++z)
    {
       int nowy;
       scanf("%d", &nowy);
       a = skad; b = nowy;
       int LCA = lca(a, b);
       queries.pb({a, LCA});
       queries.pb({LCA, b});
       skad = nowy;
    } 
    fill(odw, odw+n+1, false);
    for (auto tmp:queries)
    {
        if (tmp.e1 == tmp.e2) continue;
        int x = tmp.e1, y = tmp.e2;
        assert(parent(x,y) || parent(y, x));
        if (parent(x, y)) dol[y]++, dol[x]--;
        else gora[x]++, gora[y]--;
    }

    wyndfs(1);

    ll wyn = 0;
    for (int i=2; i<=n; ++i) wyn += (potmod(2, KRAW[i]) - 1 + mod) % mod;
    cout << wyn % mod;
}