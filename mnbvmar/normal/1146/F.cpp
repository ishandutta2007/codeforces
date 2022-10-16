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

const int MaxN = 200005;
const int Mod = 998244353;

vector<int> children[MaxN];
int dp_leaf[MaxN];
int dp_root[MaxN];

void Dfs(int v) {
  dp_leaf[v] = dp_root[v] = 1;
  if (children[v].empty()) {
    return;
  }

  vector<int> dr;
  vector<int> dl;
  vector<int> dlpref, dlsuf;

  for (int s : children[v]) {
    Dfs(s);
    dp_leaf[v] = (LL)dp_leaf[v] * (dp_leaf[s] + dp_root[s]) % Mod;

    dr.PB(dp_root[s]);
    dl.PB(dp_leaf[s]);
  }

  dp_root[v] = dp_leaf[v];

  dlpref.PB(1);
  dlsuf.PB(1);
  for (int x : dl) {
    dlpref.PB((LL)dlpref.back() * x % Mod);
  }
  reverse(ALL(dl));
  for (int x : dl) {
    dlsuf.PB((LL)dlsuf.back() * x % Mod);
  }
  reverse(ALL(dl));

  const int S = SZ(children[v]);
  for (int i = 0; i < S; ++i) {
    int sub = dlpref[i];
    sub = (LL)sub * dlsuf[S - i - 1] % Mod;
    sub = (LL)sub * dr[i] % Mod;
    dp_leaf[v] = ((LL)dp_leaf[v] - sub + Mod) % Mod;
  }

  /*int root_coef = 1;
  for (int i = 0; i < S; ++i) { root_coef = (root_coef * 2) % Mod; }
  dp_root[v] = (LL)dp_root[v] * root_coef % Mod;*/
  int rsub = 1;
  for (int i = 0; i < S; ++i) {
    rsub = (LL)rsub * dl[i] % Mod;
  }
  dp_root[v] = (dp_root[v] + Mod - rsub) % Mod;

  debug(v, dp_leaf[v], dp_root[v]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N;
  cin >> N;

  for (int i = 2; i <= N; ++i) {
    int p;
    cin >> p;
    children[p].PB(i);
  }

  Dfs(1);
  cout << dp_leaf[1] << "\n";
}