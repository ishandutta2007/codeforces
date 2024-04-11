#pragma GCC target "avx2"
#include <iostream>
#include <utility>
#include <bitset>
#include <cstring>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }


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

constexpr int mod = 31607, phi = mod - 1, pr = 5;

struct ModNum: ArithmeticOperators<ModNum> {
  uint16_t val;

  constexpr ModNum(uint16_t val = 0) : val{val} {}

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
      val = val * other.val % mod;
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
  constexpr ModNum operator!() { return mod + 1 - *this; }
  constexpr ModNum operator~() { return fpow(*this, mod - 2); }
  friend ostream& operator<<(ostream& out, const ModNum& a) { return out << a.val; }
  constexpr explicit operator uint16_t() const { return val; }
};constexpr ModNum operator "" m (unsigned long long v) { return v; }

constexpr int N = 21, M = 1 << N, D = 1 << 2;

int n;
ModNum pp[phi];

struct ModLog : ArithmeticOperators<ModLog> {
  uint16_t val;

  ModLog(uint16_t val = 0) : val{val} {}
  ModLog(ModNum p);

  ModLog& operator+=(const ModLog& oth) {
    val += oth.val;
    val = min(val, uint16_t{val - phi});
    return *this;
  }

  operator ModNum();
};

ModLog a[N][N];
ModLog pl[mod], anti[mod];

ModLog::ModLog(ModNum p) : ModLog{pl[p.val]} {}
ModLog::operator ModNum() { return pp[val]; }

__attribute__((optimize("O3"))) auto pwin(int n, int m) {
  constexpr int V = 8;
  alignas(V * 4) static ModLog prloss[M], pw[D][M];
  alignas(V * 4) static bitset<M> nan[D];
  for (int r = 0, rr = n - 1; r < n; ++r, --rr) {
    prloss[0] = 0;
    for (int i = 0, pi = 1; i < n; ++i, pi <<= 1)
    for (auto* p0 = prloss, * p1 = p0 + pi, * const p2 = p1 + pi; p1 != p2; ) {
      *p1++ = *p0++ + a[r][i];
    }
    for (auto* p0 = prloss, * p1 = p0 + m; p0 != p1; ) {
      if (__builtin_expect(!(--p1)->val, 0)) {
        int cm = p0 - prloss;
        for (int dm = 0; dm < D; ++dm) {
          int rm = dm % 2 << r | dm / 2 << rr, m = rm;
          if ((cm & rm) == rm)
          do {
            nan[dm][cm ^ m] = 1;
          } while (m && (m = (m - 1) & rm, 1));
        }
      }
      if (__builtin_expect(!p0->val, 0)) {
        int cm = p1 - prloss;
        for (int dm = 0; dm < D; ++dm) {
          int rm = dm % 2 << r | dm / 2 << rr, m = rm;
          if ((cm & rm) == rm)
          do {
            nan[dm][cm ^ m] = 1;
          } while (m && (m = (m - 1) & rm, 1));
        }
      }
      auto f = *p0;
      *p0++ += anti[(p1)->val];
      *p1 += anti[f.val];
    }

    for (int dm = 0; dm < D; ++dm) {
      int rm = dm % 2 << r | dm / 2 << rr, rl = rm? 1 << __builtin_ctz(rm): m;
      if (rl & V - 1) {
        for (int cm = 0; cm < m; ++cm) {
          pw[dm][cm] += prloss[cm | rm];
        }
      } else {
        for (int cm = 0; cm < m; cm += rl)
        for (auto* p0 = prloss + (cm | rm), * p1 = pw[dm] + cm, * const p2 = p1 + rl; p1 != p2; ) {
          *p1++ += *p0++;
        }
      }
    }
  }
  ModNum res{};
  for (int i = 0; i < phi; i += 32) {
    __builtin_prefetch(pp + i, 0, 3);
  }
  if (n >= 3)
  for (int dm = 0; dm < D; ++dm)
  for (int cm = 0; cm < m; cm += 8) {
    int lres = 0;
    if (uint8_t c = ~reinterpret_cast<char*>(&nan[dm])[cm / 8]; __builtin_expect(c != 255, 0)) {
      if (c &   1) lres  = uint16_t{ModNum{pw[dm][cm    ]}};
      if (c &   2) lres -= uint16_t{ModNum{pw[dm][cm + 1]}};
      if (c &   4) lres -= uint16_t{ModNum{pw[dm][cm + 2]}};
      if (c &   8) lres += uint16_t{ModNum{pw[dm][cm + 3]}};
      if (c &  16) lres -= uint16_t{ModNum{pw[dm][cm + 4]}};
      if (c &  32) lres += uint16_t{ModNum{pw[dm][cm + 5]}};
      if (c &  64) lres += uint16_t{ModNum{pw[dm][cm + 6]}};
      if (c & 128) lres -= uint16_t{ModNum{pw[dm][cm + 7]}};
    } else {
      lres  = uint16_t{ModNum{pw[dm][cm    ]}};
      lres -= uint16_t{ModNum{pw[dm][cm + 1]}};
      lres -= uint16_t{ModNum{pw[dm][cm + 2]}};
      lres += uint16_t{ModNum{pw[dm][cm + 3]}};
      lres -= uint16_t{ModNum{pw[dm][cm + 4]}};
      lres += uint16_t{ModNum{pw[dm][cm + 5]}};
      lres += uint16_t{ModNum{pw[dm][cm + 6]}};
      lres -= uint16_t{ModNum{pw[dm][cm + 7]}};
    }
    lres %= mod;
    if (lres < 0) {
        lres += mod;
    }
    res += __builtin_parity(cm ^ dm)? mod - lres: lres;
  }
  else
  for (int dm = 0; dm < D; ++dm)
  for (int cm = 0; cm < m; ++cm) if (!as_const(nan[dm])[cm]) {
    auto t = uint16_t{ModNum{pw[dm][cm]}};
    res += __builtin_parity(cm ^ dm)? mod - t: t;
  }
  return !res;
}

int main() {
  for (int i = 0, d = 1; i < phi; ++i, (d *= pr) %= mod) {
    pp[i] = d;
    pl[d] = i;
  }
  for (int i = 0; i < phi; ++i) {
    anti[i] = 1 - pp[i];
  }
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  n = $;
  int m = 1 << n;
  for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) {
    a[i][j] = $() * ~10000m;
  }
  cout << pwin(n, m);
}