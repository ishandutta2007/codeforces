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

const int mod = 1e9 + 7;

int PowMod(int a, int n) {
  int r = 1;
  while (n) {
    if (n & 1) { r = (ll)r * a % mod; }
    n >>= 1;
    a = (ll)a * a % mod;
  }
  return r;
}

vi Primes(int x) {
  vi ans;
  for (int p = 2; p * p <= x; ++p) {
    if (x % p == 0) {
      ans.PB(p);
      while (x % p == 0) { x /= p; }
    }
  }
  if (x > 1) { ans.PB(x); }
  return ans;
}

int Cnt(int R, int sum) {
  mini(R, sum - 1);
  const int min_val = max(1, sum - R);
  const int max_val = R;

  vi primes = Primes(sum);
  const int S = SZ(primes);
  int ans = 0;
  for (int m = 0; m < (1 << S); ++m) {
    int coef = __builtin_popcount(m) % 2 == 0 ? 1 : -1;
    int d = 1;
    for (int i = 0; i < S; ++i) {
      if ((m >> i) & 1) { d *= primes[i]; }
    }

    const int mind = (min_val + d - 1) / d;
    const int maxd = max_val / d;
    if (mind <= maxd) {
      ans += coef * (maxd - mind + 1);
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n, sigma;
  cin >> n >> sigma;

  /*int Ef = 0;
  for (int k = 1; k < n; ++k) {
    Ef = (Ef + PowMod(sigma, k)) % mod;
  }*/

  vll counts(n);

  for (int g = 1; g < n; ++g) {
    for (int h = 2 * g; h < 2 * n; h += g) {
      // TODO faster
      int num_pairs = 0;
      /*for (int a = g; a < n; a += g) {
        for (int b = g; b < n; b += g) {
          if (a/g + b/g == h/g && gcd(a/g, b/g) == 1) { ++num_pairs; }
        }
      }

      debug(g, h, num_pairs, Cnt((n-1)/g, h/g));
      assert(num_pairs == Cnt((n-1)/g, h/g));*/
      num_pairs = Cnt((n-1)/g, h/g);

      if (n >= h - g) {
        counts[g] += num_pairs;
      } else {
        counts[h - n] += num_pairs;
      }
    }
  }

  int ans = 0;

  for (int g = 1; g < n; ++g) {
    counts[g] %= mod;
    ans = (ans + (ll)counts[g] * PowMod(sigma, g)) % mod;
  }

  ans = (ll)ans * PowMod(sigma, mod - 1 - n) % mod;

  cout << ans << "\n";
}