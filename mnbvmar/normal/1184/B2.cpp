#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug & operator<<
#define eni(x) sim>typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim> struct rge { c b, e; };
sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim> auto dud(c*x) -> decltype(cerr<<*x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor (pair<b,c> d) {
  ris<<"("<<d.first<<", "<<d.second<<")";
}
sim dor(rge<c> d) {
  *this<<"[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris <<" ]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MaxN = 105;
const int MaxItems = 1024;

int n, m;
vi adj[MaxN];
int s, b, k, h;
int dist[MaxN][MaxN];

int sp_loc[MaxItems], sp_atk[MaxItems], sp_fuel[MaxItems];
int bs_loc[MaxItems], bs_def[MaxItems];

int match_left[MaxItems], match_right[MaxItems];
bool vis[MaxItems];
vi item_adj[MaxItems];

bool DfsMatch(int v) {
  if (vis[v]) { return false; }
  vis[v] = true;
  
  for (int s : item_adj[v]) {
    if (match_right[s] == -1 || DfsMatch(match_right[s])) {
      match_left[v] = s;
      match_right[s] = v;
      return true;
    }
  }
  return false;
}

int Match() {
  fill_n(match_left, s, -1);
  fill_n(match_right, b, -1);
  
  int ans = 0;
  bool any;
  do {
    any = false;
    fill_n(vis, s, false);
    for (int v = 0; v < s; ++v) {
      if (!vis[v] && match_left[v] == -1 && DfsMatch(v)) {
        any = true;
        ++ans;
      }
    }
  } while (any);
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = 1e9;
    }
    dist[i][i] = 0;
  }
  
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    dist[u][v] = dist[v][u] = 1;
  }
  
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  scanf("%d%d%d%d", &s, &b, &k, &h);
  
  ll ans = (ll)h * s;
  
  for (int i = 0; i < s; ++i) {
    scanf("%d%d%d", &sp_loc[i], &sp_atk[i], &sp_fuel[i]);
  }
  for (int i = 0; i < b; ++i) {
    scanf("%d%d", &bs_loc[i], &bs_def[i]);
  }
  
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < b; ++j) {
      if (dist[sp_loc[i]][bs_loc[j]] <= sp_fuel[i] && sp_atk[i] >= bs_def[j]) {
        item_adj[i].push_back(j);
      }
    }
  }
  
  const int match = Match();
  debug() << imie(match);
  ans = min(ans, (ll)k * match);
  
  printf("%lld\n", ans);
}