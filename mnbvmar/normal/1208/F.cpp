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

  int n; cin >> n;
  vi nums(n);
  for (int &x : nums) { cin >> x; }

  const int M = 1 << 21;
  vi pref_has(M, 1e9);
  vi suf_has1(M, -1e9), suf_has2(M, -1e9);
  for (int i = 0; i < n; ++i) {
    mini(pref_has[nums[i]], i);
    suf_has2[nums[i]] = suf_has1[nums[i]];
    suf_has1[nums[i]] = i;
  }
  debug(suf_has2[14]);


  for (int bit = 0; bit < 21; ++bit) {
    for (int i = 0; i < M; ++i) {
      if (i & (1 << bit)) {
        const int j = i ^ (1 << bit);
        mini(pref_has[j], pref_has[i]);
        if (j == 14) { debug(suf_has1[i], suf_has2[i]); }

        if (suf_has1[j] > suf_has1[i]) {
          maxi(suf_has2[j], suf_has1[i]);
        } else {
          int old = suf_has1[i];
          swap(suf_has1[j], suf_has1[i]);
          suf_has2[j] = max(suf_has1[i], suf_has2[i]);
          suf_has1[i] = old;
        }
      }
    }
    debug(bit, suf_has1[14], suf_has2[14]);
  }
  debug(suf_has1[14], suf_has2[14]);

  debug(pref_has[0]);

  int ans = 0;

  for (int num = 0; num < M; ++num) {
    int best_rgt = suf_has2[num];
    if (best_rgt <= 0) { continue; }
    int need_lft = 0;

    for (int i = 20; i >= 0; --i) {
      if ((num >> i) & 1) { continue; }
      const int nxt = need_lft | (1 << i);
      if (pref_has[nxt] < best_rgt) {
        need_lft = nxt;
      }
    }

    maxi(ans, num | need_lft);
  }

  cout << ans << "\n";
}