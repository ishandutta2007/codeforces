#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
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

constexpr int mod = 1e9 + 7;

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
  constexpr ModNum operator!() const { return 1 - *this; }
  constexpr ModNum operator~() const { return fpow(*this, mod - 2); }
  friend ostream& operator<<(ostream& out, const ModNum& a) { return out << a.val; }
  constexpr explicit operator uint32_t() const { return val; }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

constexpr int N = 100, S = N * N, Q = 1e5;

int b[N], bs[N], c[N], n;
ModNum ans[S + 1], psans[S + 1];
bool ok = 1;

__attribute__((optimize("O3"))) ModNum solve(int x) {
  int mins = unz(x);
  for (int i = mins; i <= c[0]; ++i) {
    ans[i] = 1;
  }
  int maxs = c[0];
  for (int i = 1; i < n; ++i) {
    maxs += c[i];
    int mins0 = mins;
    maxi(mins, x * (i + 1) + bs[i]);
    if (maxs < mins) {
      ok = 0;
      if (i > 1) {
        memset(psans + mins0 + 1, 0, sizeof *psans * (maxs - mins0));
      }
      break;
    }
    partial_sum(ans + mins0, ans + maxs, psans + mins0 + 1);
    for (int s = mins; s <= c[i] + mins0; ++s) {
      ans[s] += psans[s];
    }
    for (int s = max(mins, c[i] + mins0 + 1); s <= maxs; ++s) {
      ans[s] += psans[s] - psans[s - c[i]];
    }
    memset(psans + mins0 + 1, 0, sizeof *psans * (mins - mins0));
  }
  auto cans = ok? accumulate(ans + mins, ans + maxs + 1, 0m): 0;
  memset(ans, 0, sizeof *ans * (maxs + 1));
  if (ok) {
    memset(psans + mins + 1, 0, sizeof *psans * (maxs - mins));
  }
  return cans;
}

int main() {
  reader(n);
  reader(c, n);
  reader(b, n - 1);
  for (int i = 1, ps = 0, cbs = 0; i < n; ++i) {
    bs[i] = cbs += ps += b[i - 1];
  }
  vector<int> gx;
  for (int i = 1, maxs = c[0]; i < n && (maxs += c[i]); ++i)
  for (int s = maxs + 1; s--; ) {
    gx.push_back((s - bs[i] + (i + 1) * S * N) / (i + 1) - S * N);
  }
  sort(gx.begin(), gx.end());
  gx.erase(unique(gx.begin(), gx.end()), gx.end());
  gx.resize(min(gx.size(), N + 1uz));
  for (int i = gx.size(); i--; )
  for (int j = 0; j < i; ++j) {
    gx.push_back(gx[i]);
  }
  sort(gx.begin(), gx.end());
  gx.push_back(unz(gx.back()) + 2e5);
  vector<int> gxans(gx.size());
  for (int i = 0; i < gx.size(); ++i) {
    gxans[i] = solve(gx[i]).val;
  }
  for (int q = $; q--; ) {
    print(gxans[lower_bound(gx.begin(), gx.end(), $()) - gx.begin()]);
  }
}