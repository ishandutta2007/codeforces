#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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


const int MaxN = 1e6 + 100;
int dp[MaxN][3][3][3];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, M;
  cin >> N >> M;

  vector<int> counts(M + 5);

  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    ++counts[v];
  }

  debug(counts);

  const int U = M + 1;
  for (int mval = 1; mval <= U; ++mval) {
    for (int t0 : {0, 1, 2}) {
      for (int t1 : {0, 1, 2}) {
        for (int t2 : {0, 1, 2}) {
          if (t0 + t1 + t2 > counts[mval]) { continue; }
          const int rem = counts[mval] - t0 - t1 - t2;
          for (int p : {0, 1, 2}) {
            maxi(dp[mval][t0][t1][t2], dp[mval - 1][p][t0][t1] + rem / 3 + t2);
          }
        }
      }
    }
  }

  cout << dp[U][0][0][0] << "\n";
}