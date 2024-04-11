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

constexpr int MaxN = 705;

int N;
int vals[MaxN];

bool rleft[MaxN][MaxN], rright[MaxN][MaxN];
bool good_gcd[MaxN][MaxN];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> vals[i];

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      good_gcd[i][j] = __gcd(vals[i], vals[j]) > 1;

  for (int d = 0; d < N; ++d)
    for (int l = 0; l + d < N; ++l) {
      const int r = l + d;

      for (int mid = l; mid <= r; ++mid) {
        if (mid > l && !rright[l][mid - 1]) { continue; }
        if (mid < r && !rleft[mid + 1][r]) { continue; }
        if (l == 0 || good_gcd[l - 1][mid])
          rleft[l][r] = true;
        if (r == N - 1 || good_gcd[mid][r + 1])
          rright[l][r] = true;
      }
    }

  cout << (rleft[0][N - 1] || rright[0][N - 1] ? "Yes\n" : "No\n");
}