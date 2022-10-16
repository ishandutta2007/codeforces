#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

const int MaxN = 5e5 + 100;

vi adj[MaxN];
int tree_size[MaxN];
//ll sum_pairs[MaxN];
//int parent[MaxN];
int n;

//vector<pii> wei_adj[MaxN];

void Dfs(int v, int p) {
  //parent[v] = p;
  tree_size[v] = 1;
  for (int s : adj[v]) {
    if (s == p) { continue; }
    Dfs(s, v);
    tree_size[v] += tree_size[s];
    //sum_sq_sizes[v] += (ll)tree_size[s] * (tree_size[s] - 1);
  }
}

ll best_paths[MaxN][2];
ll ans = 1e18;

void DpDfs(int v, int p) {
  ll sum_sq = 0;
  tree_size[v] = 1;
  best_paths[v][0] = best_paths[v][1] = 1e18;

  bool any = false;

  for (int s : adj[v]) {
    if (s == p) { continue; }
    any = true;
    DpDfs(s, v);
    tree_size[v] += tree_size[s];
    sum_sq += (ll)tree_size[s] * (tree_size[s] + 1) / 2;
  }

  if (!any) {
    best_paths[v][0] = 0;
    return;
  }

  for (int s : adj[v]) {
    if (s == p) { continue; }
    ll cost = best_paths[s][0];
    int coef = tree_size[v] - tree_size[s];
    cost += (ll)coef * (coef - 1) / 2;
    /*ll cost = sum_sq;
    cost -= (ll)tree_size[s] * (tree_size[s] + 1) / 2;
    cost += best_paths[s][0];*/

    if (cost < best_paths[v][0]) {
      best_paths[v][1] = best_paths[v][0];
      best_paths[v][0] = cost;
    } else if (cost < best_paths[v][1]) {
      best_paths[v][1] = cost;
    }
  }

  map<int, vi> sizes;
  for (int s : adj[v]) {
    if (s == p) { continue; }
    sizes[tree_size[s]].PB(s);
  }

  for (auto &x : sizes) {
    sort(ALL(x.nd), [&](int lhs, int rhs) {
          return best_paths[lhs][0] < best_paths[rhs][0];
        });
  }

  int cur = v;


  for (auto &a : sizes) { 
    for (auto &b : sizes) {
      if (a.st >= b.st) { continue; }
      int x = a.nd[0];
      int y = b.nd[0];
      int others = n - tree_size[x] - tree_size[y];
      ll cand = best_paths[x][0] + best_paths[y][0] + (ll)others * (others - 1) / 2;
      debug(cur, x, y, cand, tree_size[x], tree_size[y], others);
      mini(ans, cand);
    }

    if (SZ(a.nd) >= 2) {
      int x = a.nd[0];
      int y = a.nd[1];
      int others = n - tree_size[x] - tree_size[y];
      ll cand = best_paths[x][0] + best_paths[y][0] + (ll)others * (others - 1) / 2;
      debug(cur, x, y, cand, tree_size[x], tree_size[y], others);
      mini(ans, cand);
    }
  }

  if (SZ(adj[v]) == 1) {
    mini(ans, best_paths[adj[v][0]][0]);
  }
}

int32_t main() {
  scanf("%lld", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].PB(v);
    adj[v].PB(u);
  }

  DpDfs(1, 1);


  ll total = (ll)n * (n - 1);

  total -= ans;
  printf("%lld\n", total);

  /*int centroid = 1;
  for (int v = 2; v <= n; ++v) {
    if (tree_size[v] * 2 >= n && tree_size[v] < tree_size[centroid]) {
      centroid = v;
    }
  }

  DpDfs(centroid, centroid);*/
}