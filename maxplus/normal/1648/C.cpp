//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

template <typename T>
struct ArithmeticOperators {
  template <typename LowPriority = void>
  constexpr friend T operator+(T lhs, const T& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator-(T lhs, const T& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator*(T lhs, const T& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator/(T lhs, const T& rhs) { return lhs /= rhs; }
};

template <typename T>
constexpr T fpow(T a, uint32_t p) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
    }
    a *= a;
    p >>= 1;
  }
  return res;
}

constexpr int mod = 998244353;

struct ModNum: ArithmeticOperators<ModNum> {
  uint32_t val;

  constexpr ModNum(uint32_t val = 0) : val{val} {}

  constexpr ModNum& operator+=(const ModNum& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  template <bool constexpr_friendly = true>
  constexpr ModNum& operator*=(const ModNum& other) {
    if constexpr (constexpr_friendly || INTPTR_MAX == INT64_MAX) {
      val = (uint64_t)val * other.val % mod;
//    } else if consteval {
//      val = (uint64_t)val * other.val % mod;
    } else {
      asmmul(other);
    }
    return *this;
  }

  void asmmul(const ModNum& other) {
    uint32_t junk;
    asm("mul %0\n\tdivl %3\n\t" : "+d" (val), "=a" (junk) : "a" (other.val), "rm" (mod) : "cc");
  }

  constexpr ModNum& operator-=(const ModNum& rhs) { return *this += mod - rhs.val; }
  constexpr ModNum operator-() const { return val > 0? mod - val: -val; }
  constexpr ModNum operator!() const { return val > 1? mod + 1 - val: 1 - val; }
  constexpr ModNum operator~() const { return fpow(*this, mod - 2); }
  friend ostream& operator<<(ostream& out, const ModNum& a) { return out << a.val; }
  constexpr explicit operator uint32_t() const { return val; }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

constexpr int N = 2e5 + 1;

struct Factorial {
  constexpr static int N = ::N;

  Factorial() {
    ModNum cur = fact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = cur *= i;
    }
    cur = nfact[N - 1] = ~fact[N - 1];
    for (int i = N; --i; ) {
      nfact[i - 1] = cur *= i;
    }
  }

  ModNum operator[](int n) { return fact[n]; }
  ModNum operator()(int n) { return nfact[n]; }
  ModNum inv(int n) { return nfact[n] * fact[n - 1]; }
  ModNum a(int n, int k) { return fact[n] * nfact[n - k]; }
  ModNum inva(int n, int k) { return nfact[n] * fact[n - k]; }
  ModNum operator()(int n, int k) { return a(n, k) * nfact[k]; }
  ModNum invc(int n, int k) { return inva(n, k) * fact[k]; }
  ModNum cat(int n, int k = -1) { return k > n? 0: k == -1 || k == n? a(n + n, n) * nfact[n + 1]: a(n + k, n) * nfact[n + 1] * (n - k + 1); }
  ModNum s(int n) { return (*this)(n, n / 2); }

private:
  ModNum fact[N], nfact[N];
} fact;

struct FT {
  using T = int;
  static constexpr int N = ::N;

  T& op(T& val, const T& arg) {
    return val += arg;
  }

  void build() {
    for (int i = 0; i < N; ++i) if ((i | (i + 1)) < N) {
      op(ft[i | (i + 1)], ft[i]);
    }
  }

  void update(int i, T val = 1) {
    for (; i < N; i |= i + 1) {
      op(ft[i], val);
    }
  }

  T query(int i) {
    T res{};
    for (; i; i &= i - 1) {
      op(res, ft[i - 1]);
    }
    return res;
  }

  void rupdate(int i, T val = 1) { return update(N - 1 - i, val); }

  T rquery(int i) { return query(N - 1 - i); }

private:
  T ft[N];
} ft;

int s[N], t[N], cnt[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, m = $;
  cin >> range{s, n} >> range{t, m};
  for (auto i: range{s, n}) {
    ++cnt[i];
  }
  ModNum comb = fact[n];
  for (auto& i: range{cnt, N}) if (i) {
    comb *= fact(i);
    ft.update(&i - cnt, i);
  }
  ModNum ans{};
  for (int i = 0, c = n; ; ++i, --c) {
    if (i == n) {
      ans += m > n;
      break;
    }
    ans += ft.query(t[i]) * (comb *= fact.inv(c));
    comb *= cnt[t[i]];
    if (!cnt[t[i]]--) {
      break;
    }
    ft.update(t[i], -1);
  }
  print(ans);
}