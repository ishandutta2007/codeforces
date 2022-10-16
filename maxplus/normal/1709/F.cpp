//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } string operator~() const { return *this; } char operator!() const { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }
//template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

template <typename T>
struct GenerateOperators {
  template <typename LowPriority = void>
  constexpr friend T operator+(T lhs, const auto& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator-(T lhs, const auto& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator*(T lhs, const auto& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  constexpr friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  constexpr friend T operator/(T lhs, const auto& rhs) { return lhs /= rhs; }
  template <typename LowPriority = void>
  constexpr friend bool operator==(const T& lhs, const auto& rhs) { return !(lhs < rhs || lhs > rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator!=(const T& lhs, const auto& rhs) { return !(lhs == rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator>(const T& lhs, const auto& rhs) { return rhs < lhs; }
  template <typename LowPriority = void>
  constexpr friend bool operator<=(const T& lhs, const auto& rhs) { return !(lhs > rhs); }
  template <typename LowPriority = void>
  constexpr friend bool operator>=(const T& lhs, const auto& rhs) { return !(lhs < rhs); }
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

struct ModNum: GenerateOperators<ModNum> {
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

  constexpr static ModNum primitive_root() {
    array<int, 64> primes{};
    int phi = mod - 1, cprimes = 0;
    for (int i = 2; i * i <= phi; ++i) if (phi % i == 0) {
      primes[cprimes++] = i;
      do {
        phi /= i;
      } while (phi % i == 0);
    }
    if (phi != 1) {
      primes[cprimes++] = phi;
    }
    for (int root = 2; ; ++root) {
      bool bad = 0;
      for (auto p: range{primes.begin(), cprimes}) {
        bad |= fpow<ModNum>(root, mod / p).val == 1;
      }
      if (!bad) {
        return root;
      }
    }
  }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

using Poly = vector<ModNum>;
struct NTT {
  static constexpr auto primitive = ModNum::primitive_root();
  static constexpr int root_pw = ~-mod & -~-mod;
  static constexpr auto root = fpow(primitive, (mod - 1) / root_pw), iroot = fpow(root, root_pw - 1);

  void operator()(Poly& a, bool invert) { ntt(a, invert); }
  void ntt(Poly& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1) {
        j ^= bit;
      }
      j ^= bit;
      if (i < j) {
        swap(a[i], a[j]);
      }
    }
    for (int len = 2; len <= n; len <<= 1) {
      auto wlen = fpow(invert? iroot: root, root_pw / len);
      for (int i = 0; i < n; i += len) {
        auto w = 1m;
        for (int j = 0; j < len / 2; j++) {
          auto u = a[i + j], v = a[i + j + len / 2] * w;
          a[i + j] = u + v;
          a[i + j + len / 2] = u - v;
          w *= wlen;
        }
      }
    }
    if (invert) {
      auto invn = ~ModNum(n);
      for (auto& x : a) {
        x *= invn;
      }
    }
  }

  Poly pow(Poly a, int p, int trunc = -1) {
    int sz = (a.size() - 1) * p + 1;
    if (trunc == -1) {
      trunc = sz;
    }
    int n = sz > 1? 1 << (32 - __builtin_clz(sz - 1)): 1;
    a.resize(n);
    ntt(a, 0);
    for (auto& i: a) {
      i = fpow(i, p);
    }
    ntt(a, 1);
    a.resize(sz);
    return a;
  }

  auto prod(Poly a, Poly b, int trunc = -1) {
    int sz = a.size() + b.size() - 1;
    if (trunc == -1) {
      trunc = sz;
    }
    int n = sz > 1? 1 << (32 - __builtin_clz(sz - 1)): 1;
    a.resize(n);
    b.resize(n);
    ntt(a, 0), ntt(b, 0);
    for (int i = 0; i < n; ++i) {
      a[i] *= b[i];
    }
    ntt(a, 1);
    a.resize(trunc);
    return a;
  }
} ntt;

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, k = $, f = $, sz = max(k + 1, f + 2);
  Poly a(sz);
  a[f + 1] = 1;
  while (n--) {
    ModNum ss = 0;
    for (int i = a.size(); i--; ) {
      ss += a[i];
      a[i] = unz(k - i) * a[i] + (k >= i) * ss;
    }
    a.resize(sz);
    a = ntt.pow(a, 2);
  }
  print(a[f]);
}