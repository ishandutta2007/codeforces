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

map<int, int> fu_parent;
map<int, unsigned> fu_edge;

void FuIntroduce(int v) {
  if (!fu_parent.count(v)) {
    fu_parent[v] = v;
    fu_edge[v] = 0;
  }
}

int FuFind(int v) {
  if (fu_parent[v] == v)
    return v;
  const int p = fu_parent[v];
  const int root = FuFind(p);

  fu_edge[v] ^= fu_edge[p];
  fu_parent[v] = fu_parent[p];
  return root;
}

void FuMerge(int u, int v, unsigned x) {
  debug("Merge", u, v, x);
  const int pu = FuFind(u);
  const int pv = FuFind(v);

  if (pu == pv) { return; }
  fu_parent[pv] = pu;
  fu_edge[pv] = fu_edge[v] ^ fu_edge[u] ^ x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int Q;
  cin >> Q;

  unsigned last = 0;

  for (int idx = 0; idx < Q; ++idx) {
    int t;
    cin >> t;
    int l, r;
    unsigned x;

    if (t == 1) {
      cin >> l >> r >> x;
      l ^= last;
      r ^= last;
      x ^= last;
      if (l > r) { swap(l, r); }

      debug(l, r, x);

      ++r;
      FuIntroduce(l);
      FuIntroduce(r);
      FuMerge(l, r, x);
    } else {
      cin >> l >> r;
      l ^= last;
      r ^= last;

      if (l > r) { swap(l, r); }
      debug("?", l, r);

      ++r;
      FuIntroduce(l);
      FuIntroduce(r);

      if (FuFind(l) != FuFind(r)) {
        cout << "-1\n";
        last = 1;
      } else {
        const unsigned ans = fu_edge[l] ^ fu_edge[r];
        cout << ans << "\n";
        last = ans;
      }
    }
  }
}