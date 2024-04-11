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

const int MaxN = 512;
const int mod = 998244353;

int n, m;
int dp[MaxN][MaxN];

void Add(int &x, int y) {
  x += y; if (x >= mod) { x -= mod; }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> n >> m;

  vi cols(m);
  for (int &x : cols) { cin >> x; }

  for (int i = 0; i < m; ++i) {
    dp[i][i+1] = 1;
  }

  for (int d = 2; d <= m; ++d) {
    for (int L = 0; L + d <= m; ++L) {
      const int R = L + d;
      int mid = L;
      for (int i = L; i < R; ++i) {
        if (cols[i] < cols[mid]) { mid = i; }
      }

      int nleft = 0, nright = 0;
      for (int i = L; i <= mid; ++i) {
        int coef = 1;
        if (i > L) { coef = dp[L][i]; }
        if (i < mid) { coef = (ll)coef * dp[i][mid] % mod; }
        Add(nleft, coef);
      }
      for (int i = mid; i < R; ++i) {
        int coef = 1;
        if (i < R - 1) { coef = dp[i + 1][R]; }
        if (i > mid) { coef = (ll)coef * dp[mid + 1][i + 1] % mod; }
        Add(nright, coef);
      }

      dp[L][R] = (ll)nleft * nright % mod;
      debug(L, R, mid, nleft, nright, dp[L][R]);
    }
  }

  cout << dp[0][m] << "\n";

}