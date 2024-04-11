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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, bytes;
  cin >> n >> bytes;

  vi transl(n + 1);
  for (int i = 2; i <= n; ++i) {
    transl[i] = transl[i - 1];
    if (!((i - 1) & (i - 2))) { ++transl[i]; }
  }

  debug(transl);
  int bits = 8 * bytes;

  vi values(n);
  for (int &x : values) { cin >> x; }
  sort(ALL(values));

  int max_k = 0;
  while (max_k <= n) {
    if (transl[max_k] * n > bits) { --max_k; break; }
    ++max_k;
  }
  debug(max_k);

  int ans = 1e9;

  int R = 0, K = 0;
  for (int L = 0; L < n; ++L) {
    if (L == R) { R = L + 1; K = 1; }
    while (R < n) {
      if (values[R] != values[R - 1]) {
        if (K == max_k) { break; }
        ++K;
      }
      ++R;
    }
    debug(L, R);

    const int same = R - L;
    mini(ans, n - same);

    if (L == R - 1) { continue; }
    if (values[L] != values[L + 1]) { --K; }
  }

  cout << ans << "\n";


}