#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ar array

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename T>
struct modnum {
  using Int = typename T::type;
  using Int2 = typename T::prod_type;
  Int val;

  modnum() = default;
  modnum(const Int &_val) : val((_val%T::MOD+T::MOD)%T::MOD) {}

  modnum &operator++() { if (++val == T::MOD) val = 0; return *this; }
  modnum &operator--() { if (val-- == 0) val += T::MOD; return *this; }
  modnum &operator++(int) { auto ret = *this; ++*this; return ret; }
  modnum &operator--(int) { auto ret = *this; --*this; return ret; }

  modnum &operator+=(const modnum &o) { if ((val += o.val) >= T::MOD) val -= T::MOD; return *this; }
  modnum &operator-=(const modnum &o) { if ((val -= o.val) < 0) val += T::MOD; return *this; }
  modnum &operator*=(const modnum &o) { val = Int((Int2)val*o.val%T::MOD); return *this; }
  modnum &operator/=(const modnum &o) { *this *= o.inv(); return *this; }

  friend modnum operator+(const modnum &a, const modnum &b) { auto ret = a; return ret += b; }
  friend modnum operator-(const modnum &a, const modnum &b) { auto ret = a; return ret -= b; }
  friend modnum operator*(const modnum &a, const modnum &b) { auto ret = a; return ret *= b; }
  friend modnum operator/(const modnum &a, const modnum &b) { auto ret = a; return ret /= b; }

  friend bool operator==(const modnum &a, const modnum &b) { return a.val == b.val; }
  friend bool operator!=(const modnum &a, const modnum &b) { return a.val != b.val; }

  modnum pow(ll e) const {
    modnum b = *this, a = 1;
    while (e) {
      if (e&1) a *= b;
      b *= b;
      e >>= 1;
    }
    return a;
  }

  modnum inv() const { return pow(T::MOD-2); }

  friend istream &operator>>(istream &is, modnum &x) { Int v; is >> v; x = v; return is; }
  friend ostream &operator<<(ostream &os, const modnum &x) { return os << x.val; }
};

struct _static_mod_t {
  using type = int;
  using prod_type = ll;
  static constexpr type MOD = 1'000'000'007;
};

struct _var_mod_t {
  using type = ll;
  using prod_type = __int128;
  static type MOD;
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typename _var_mod_t::type _var_mod_t::MOD = uniform_int_distribution<ll>(1e17, 1e18)(rng);

using mint = modnum<_static_mod_t>;
using hmint = modnum<_var_mod_t>;

const vector<string> banned {"0011", "0101", "1110", "1111"};
bool check(const string &ss) {
  for (auto &bs : banned)
    if (ss == bs)
      return false;
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  string s(n, '?');
  for (int i = 0; i < n; ++i)
    cin >> s[i];

  vector<mint> dp0(n*n);

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (j-i+1 <= 4)
        if ((j-i+1)!=4 || check(s.substr(i, 4)))
          dp0[i*n+j] = 1;

      if (j >= i + 1) dp0[i*n+j] += dp0[i*n+j-1];
      if (j >= i + 2) dp0[i*n+j] += dp0[i*n+j-2];
      if (j >= i + 3) dp0[i*n+j] += dp0[i*n+j-3];
      if (j >= i + 4)
        if (check(s.substr(j-3, 4)))
          dp0[i*n+j] += dp0[i*n+j-4];
    }
  }

  unordered_set<ll> seen;
  seen.max_load_factor(1.5);
  seen.reserve(n * n / 2);

  mint ans = 0;
  for (int j = 0; j < n; ++j) {
    hmint h = 0;
    for (int i = j; i >= 0; --i) {
      h *= 3;
      h += s[i]-'0'+1;
      if (seen.insert(h.val).second) {
        ans += dp0[i*n+j];
      }
    }
    cout << ans << '\n';
  }
}