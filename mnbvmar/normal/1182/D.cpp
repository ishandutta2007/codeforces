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
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

const int kMaxN = 1e5 + 100;

vi adj[kMaxN];
int dist[kMaxN];
int cur_deg[kMaxN];
int n;

void DfsDist(int v, int p) {
  for (int s : adj[v]) {
    if (s == p) { continue; }
    dist[s] = dist[v] + 1;
    DfsDist(s, v);
  }
}

void Check(int cand) {
  fill_n(dist, n, 0);
  fill_n(cur_deg, n + 1, 0);

  DfsDist(cand, -1);
  
  for (int i = 0; i < n; ++i) {
    const int d = dist[i];
    if (cur_deg[d] && cur_deg[d] != SZ(adj[i])) {
      return;
    }
    cur_deg[d] = SZ(adj[i]);
  }
  printf("%d\n", cand + 1);
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  scanf("%d", &n);
  if (n == 1) { printf("1\n"); return 0; }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  vi degs(n);
  queue<int> leaf_queue;
  for (int i = 0; i < n; ++i) {
    degs[i] = SZ(adj[i]);
    if (degs[i] == 1) { leaf_queue.push(i); }
  }

  vi order;
  while (!leaf_queue.empty()) {
    const int v = leaf_queue.front(); leaf_queue.pop();
    order.PB(v);

    for (int s : adj[v]) {
      if ((--degs[s]) == 1) {
        leaf_queue.push(s);
      }
    }
  }

  const int cand = order.back();
  Check(cand);
  debug(cand);

  map<int, int> nxt_cands;

  for (int s : adj[cand]) {
    int cur = s, pnt = cand, d = 1;
    bool ok = true;
    while (true) {
      if (SZ(adj[cur]) > 2) { ok = false; break; }
      if (SZ(adj[cur]) == 1) { break; }
      
      const int nxt = adj[cur][0] + adj[cur][1] - pnt;
      ++d;
      pnt = cur;
      cur = nxt;
    }

    if (ok) { debug(d, cur); nxt_cands[d] = cur; }
  }

  int num_proc = 0;
  for (auto &info : nxt_cands) {
    if (num_proc > 2) { continue; }
    Check(info.nd);
    ++num_proc;
  }

  printf("-1\n");


}