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

const int kMaxN = 1024;

int n;
vi adj[kMaxN];
int tree_size[kMaxN];
int val_vert[kMaxN], curv;

void DfsSizes(int v, int p) {
  tree_size[v] = 1;
  for (int s : adj[v]) {
    if (s == p) { continue; }
    DfsSizes(s, v);
    tree_size[v] += tree_size[s];
  }
}

void DfsRes(int v, int p, int inc) {
  curv += inc;
  val_vert[v] = curv;
  cout << v << " " << p << " " << curv - val_vert[p] << "\n";
  for (int s : adj[v]) {
    if (s == p) { continue; }
    DfsRes(s, v, inc);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  for (int x = 1; x <= 1000; ++x) {
    const int bnd = 2ll * x * x / 9;

    int y = x - 1;
    int a = y / 3; y -= a;
    int b = y / 2; y -= b;
    int c = y;

    assert((c + 1) * (a + b + 1) - 1 >= bnd);
  }

  cin >> n;
  if (n == 1) { return 0; }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  DfsSizes(1, -1);
  int centr = 1;
  for (int i = 1; i <= n; ++i) {
    if (tree_size[i] * 2 >= n && tree_size[i] < tree_size[centr]) {
      centr = i;
    }
  }

  DfsSizes(centr, -1);
  vector<pii> trees;
  for (int s : adj[centr]) {
    assert(tree_size[s] * 2 <= n);
    trees.emplace_back(tree_size[s], s);
  }

  sort(ALL(trees)); reverse(ALL(trees));
  debug(centr, trees);

  int SA = 1, SB = n;
  while ((ll)SA * SB - 1 < 2LL * n * n / 9) {
    ++SA; --SB;
  }
  int bnd = SA;

  SA = 1; SB = n; int ptr = 0;
  while (SA < bnd) {
    const int sz = trees[ptr].st;
    SA += sz;
    SB -= sz;
    ++ptr;
  }
  assert((ll)SA * SB - 1 >= 2LL * n * n / 9);

  for (int i = 0; i < ptr; ++i) {
    DfsRes(trees[i].nd, centr, 1);
  }
  assert(curv == SA - 1);
  curv = 0;
  for (int i = ptr; i < SZ(trees); ++i) {
    DfsRes(trees[i].nd, centr, SA);
  }
}