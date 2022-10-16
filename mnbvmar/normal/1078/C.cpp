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

const int Mod = 998'244'353;
const int MaxN = 3e5 + 100;

int N;
vector<int> adj[MaxN];
int dp_with[MaxN];
int dp_without[MaxN];
int dp_single[MaxN];

void Dfs(int v, int p) {
  dp_with[v] = 0;
  dp_without[v] = 1;
  dp_single[v] = 1;

  for (int s : adj[v]) {
    if (p == s) { continue; }
    Dfs(s, v);

    const LL coef = dp_with[s] * 2LL + dp_single[s];

    tie(dp_with[v], dp_without[v], dp_single[v]) = make_tuple(
        ((LL)dp_with[v] * coef + dp_without[v] * dp_without[s]) % Mod,
        ((LL)dp_without[v] * coef) % Mod,
        ((LL)dp_single[v] * (dp_with[s] + dp_single[s])) % Mod);
  }

  debug(v, dp_without[v], dp_with[v], dp_single[v]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  Dfs(1, 1);

  cout << (dp_with[1] + dp_single[1]) % Mod << "\n";
}