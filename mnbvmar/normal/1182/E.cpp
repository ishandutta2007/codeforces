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
using LL = ll;

const int Mod = 1e9 + 7;

template<class T, class U, class Op> T fastop(T a, U b, T r, const Op &op) {
  while (b > 0) {
    if (b % 2 == 1) { r = op(r, a); }
    a = op(a, a);
    b /= 2;
  }
  return r;
}

// BABY STEP - GIANT STEP
// Returns dicrete log_a val (mod mod); -1 if no such exponent exists
LL disc_log(LL a, LL val, LL mod) {
  LL d = __gcd(a, mod);
  if(d != 1 && d != mod) { return -1; }
  LL sq = sqrt(mod) + 2;
  auto mulmod = [&](LL a, LL b) { return ((ll)a * b) % mod; };
  auto powmod = [&](LL a, LL b) { return fastop(a, b, 1LL, mulmod); };
  map<LL, int> M;
  LL b = val, c = powmod(a, sq);
  for(int i = 0; i <= sq; ++i) {
    M[b] = i; b = mulmod(b, a);
  }
  b = c;
  for(int i = 1; i <= sq; ++i) {
    if (M.count(b)) { return i * sq - M[b]; }
    b = mulmod(b, c);
  }
  return -1;
}

const int g = 5;

const int ExpMod = 1e9 + 6;

const int S = 5;

struct Matrix {
  vector<vi> data;

  Matrix() :data(S, vi(S)) {}

  Matrix Mul(const Matrix&rhs) const {
    Matrix ans;
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        for (int k = 0; k < S; ++k) {
          ans.data[i][k] = (ans.data[i][k]
              + (ll)data[i][j] * rhs.data[j][k]) % ExpMod;
        }
      }
    }
    return ans;
  }

  Matrix Pow(ll n) const {
    Matrix ans;
    Matrix exp = *this;
    for (int i = 0; i < S; ++i) { ans.data[i][i] = 1; }

    while (n) {
      if (n & 1) { ans = ans.Mul(exp); }
      n >>= 1;
      exp = exp.Mul(exp);
    }
    return ans;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  ll n;
  int f1, f2, f3, c;
  scanf("%lld%d%d%d%d", &n, &f1, &f2, &f3, &c);

  f1 = disc_log(g, f1, Mod);
  f2 = disc_log(g, f2, Mod);
  f3 = disc_log(g, f3, Mod);
  c = disc_log(g, c, Mod);

  Matrix mat;
  mat.data[0][1] = 1;
  mat.data[1][2] = 1;
  mat.data[2][0] = mat.data[2][1] = mat.data[2][2] = mat.data[2][3] = 1;
  mat.data[3][3] = mat.data[3][4] = 1;
  mat.data[4][4] = 1;

  mat = mat.Pow(n - 1);

  ll ans = 0;
  c = (c * 2) % ExpMod;
  vi base{f1, f2, f3, c, c};

  for (int i = 0; i < S; ++i) {
    ans = (ans + (ll)base[i] * mat.data[0][i]) % ExpMod;
  }

  auto mulmod = [&](LL a, LL b) { return ((ll)a * b) % Mod; };
  auto powmod = [&](LL a, LL b) { return fastop(a, b, 1LL, mulmod); };

  ans = powmod(g, ans);
  printf("%lld\n", ans);


  

}