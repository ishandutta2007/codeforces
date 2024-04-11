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

const int MaxN = 1024;
const int mod = 998244353;

int n, k;
int tab[MaxN];
int dp[MaxN][MaxN];

void Add(int &x, int y) {
  x += y; if (x >= mod) { x -= mod; } 
}

int32_t main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) { scanf("%d", &tab[i]); }
  sort(tab, tab + n);

  const int max_diff = (tab[n-1] - tab[0]) / (k - 1);

  vi ans_at(max_diff + 1);

  for (int d = 0; d <= max_diff; ++d) {
    int L = -1;
    memset(dp[0], 0, sizeof(dp[0]));
    dp[0][0] = 1;

    for (int R = 0; R < n; ++R) {
      while (L+1 < R && tab[R] - tab[L + 1] >= d) { ++L; }
      
      for (int curk = 0; curk <= k; ++curk) {
        dp[R+1][curk] = dp[R][curk];
      }

      for (int curk = 1; curk <= k; ++curk) {
        Add(dp[R+1][curk], dp[L+1][curk-1]);
      }
    }

    ans_at[d] = dp[n][k];
  }

  debug(ans_at);

  for (int d = 0; d < max_diff; ++d) {
    ans_at[d] = (ans_at[d] - ans_at[d+1] + mod) % mod;
  }

  int total = 0;
  for (int d = 0; d <= max_diff; ++d) {
    total = (total + (ll)d * ans_at[d]) % mod;
  }
  printf("%d\n", total);
}