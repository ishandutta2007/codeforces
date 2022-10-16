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

const int MaxN = 1e5 + 100;

int N, M, K;
vector<int> special;
bool is_special[MaxN];

int fu_parent[MaxN];
int num_special[MaxN];

int Find(int v) {
  if (fu_parent[v] == v) { return v; }
  return fu_parent[v] = Find(fu_parent[v]);
}

bool Union(int a, int b) {
  a = Find(a); b = Find(b);
  if (a == b) { return false; }
  fu_parent[a] = b;
  num_special[b] += num_special[a];
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> K;
  special.resize(K);
  for (int &s : special) {
    cin >> s;
    is_special[s] = true;
    num_special[s] = 1;
  }

  vector<tuple<int, int, int>> edges;

  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.emplace_back(c, u, v);
  }

  sort(ALL(edges));
  iota(fu_parent, fu_parent + N + 1, 0);

  int which = -1;

  for (auto &&[c, u, v] : edges) {
    if (!Union(u, v)) { continue; }
    const int p = Find(u);
    if (num_special[p] == K) {
      which = c;
      break;
    }
  }

  for (int i = 0; i < K; ++i)
    cout << which << " ";
  cout << "\n";

}