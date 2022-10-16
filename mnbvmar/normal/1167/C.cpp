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

const int MaxN = 5e5+100;

int fu_parent[MaxN];
int fu_count[MaxN];

int Find(int x) {
  if (x == fu_parent[x]) { return x; }
  return fu_parent[x] = Find(fu_parent[x]);
}

void Union(int u, int v) {
  u = Find(u); v = Find(v);
  if (u != v) {
    fu_parent[u] = v;
    fu_count[v] += fu_count[u];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n, m;
  cin >> n >> m;
  iota(fu_parent, fu_parent + n + 1, 0);
  fill_n(fu_count, n + 1, 1);

  for (int j = 0; j < m; ++j) {
    int cnt, fst;
    cin >> cnt;
    if (!cnt) { continue; }
    cin >> fst;

    for (int k = 0; k < cnt-1; ++k) {
      int nxt;
      cin >> nxt;
      Union(fst, nxt);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << fu_count[Find(i)] << " ";
  }
  cout << "\n";
}