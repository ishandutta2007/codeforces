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
int weights[MaxN];

vector<PII> adj[MaxN];
int N;

LL dp_up[MaxN];
LL answer;

void Dfs(int v, int p) {
  dp_up[v] = weights[v];
  vector<LL> ws;

  for (auto [s, c] : adj[v]) {
    if (s == p) { continue; }
    Dfs(s, v);
    ws.PB(dp_up[s] - c);
  }

  sort(ALL(ws), greater<LL>());
  if (SZ(ws) > 2)
    ws.resize(2);

  LL acand = dp_up[v];
  for (int b = 0; b < 2 && b < SZ(ws); ++b) {
    if (ws[b] > 0)
      acand += ws[b];
    if (b == 0)
      maxi(dp_up[v], weights[v] + ws[b]);
  }
  debug(v, p, ws, dp_up[v]);
  maxi(answer, acand);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> weights[i];

  for (int i = 0; i < N - 1; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    --u; --v;
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
  }

  Dfs(0, 0);
  cout << answer << "\n";

}