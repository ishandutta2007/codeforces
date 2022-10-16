#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
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

const int MaxN = 3e5 + 100;

vector<int> adj[MaxN];
int depth[MaxN];
int parent[MaxN];
int who_max_depth;
bool is_leaf[MaxN];
bool visited[MaxN];

int N, M, K;

void Dfs(int v, int p) {
  visited[v] = true;
  parent[v] = p;
  is_leaf[v] = true;
  for (int s : adj[v]) {
    if (visited[s]) { continue; }
    depth[s] = depth[v] + 1;
    Dfs(s, v);
    is_leaf[v] = false;
  }
  if (depth[v] > depth[who_max_depth]) {
    who_max_depth = v;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> K;

  if (N == 1) {
    cout << "PATH\n1\n1\n";
    return 0;
  }

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  who_max_depth = 1;
  depth[1] = 1;
  Dfs(1, -1);

  const int bound = (N + K - 1) / K;

  if (depth[who_max_depth] >= bound) {
    vector<int> path{who_max_depth};
    while (path.back() != 1) {
      path.PB(parent[path.back()]);
    }
    assert(SZ(path) >= bound);
    cout << "PATH\n";
    cout << SZ(path) << "\n";
    for (int v : path) { cout << v << " "; }
    cout << "\n";
    return 0;
  }

  vector<VI> cycles;
  for (int v = 1; v <= N; ++v) {
    if (!is_leaf[v]) { continue; }
    vector<int> edges_up;
    for (int s : adj[v]) {
      if (s == parent[v]) { continue; }
      edges_up.PB(s);
    }

    debug(v, edges_up);
    assert(SZ(edges_up) >= 2);
    edges_up.resize(2);

    bool found = false;
    for (int s : edges_up) {
      const int len = depth[v] - depth[s] + 1;
      if (len % 3 == 0) { continue; }

      found = true;
      vector<int> cyc{v};
      while (cyc.back() != s) {
        cyc.PB(parent[cyc.back()]);
      }
      cycles.PB(cyc);
      break;
    }

    if (!found) {
      int a = edges_up[0];
      int b = edges_up[1];
      if (depth[a] < depth[b]) { swap(a, b); }
      vector<int> cyc{v, a};
      while (cyc.back() != b) {
        cyc.PB(parent[cyc.back()]);
      }
      cycles.PB(cyc);
    }
  }

  debug(cycles);
  assert(SZ(cycles) >= K);
  cycles.resize(K);
  cout << "CYCLES\n";
  for (auto &cyc : cycles) {
    cout << SZ(cyc) << "\n";
    for (int v : cyc) { cout << v << " "; }
    cout << "\n";
  }
}