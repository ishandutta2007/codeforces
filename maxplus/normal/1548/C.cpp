#include <cmath>
#include <cstdio>
#include <cstdint>

struct UnsafeInput {
  static constexpr int bufsz = 1 << 17;

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
  void operator()(Ts&... xs) {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

private:
  char buf[bufsz], *bufptr = buf;

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

template <typename T>
struct ArithmeticOperators {
  template <typename LowPriority = void>
  friend T operator+(T lhs, const T& rhs) { return lhs += rhs; }
  template <typename LowPriority = void>
  friend T& operator-=(T& lhs, const T& rhs) { return lhs += -rhs; }
  template <typename LowPriority = void>
  friend T operator-(T lhs, const T& rhs) { return lhs -= rhs; }
  template <typename LowPriority = void>
  friend T operator*(T lhs, const T& rhs) { return lhs *= rhs; }
  template <typename LowPriority = void>
  friend T& operator/=(T& lhs, const T& rhs) { return lhs *= ~rhs; }
  template <typename LowPriority = void>
  friend T operator/(T lhs, const T& rhs) { return lhs /= rhs; }
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

  ModNum(uint32_t val = 0) : val{val} {}

  ModNum& operator+=(const ModNum& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  ModNum& operator*=(const ModNum& other) {
    uint64_t x = (uint64_t)val * other.val;
//    if constexpr (INTPTR_MAX == INT64_MAX) {
      val = x % mod;
//    } else {
//      uint32_t xh = (uint32_t) (x >> 32), xl = (uint32_t) x, d;
//      asm(
//        "divl %4; \n\t"
//        : "=a" (d), "=d" (val)
//        : "d" (xh), "a" (xl), "r" (mod)
//      );
//    }
    return *this;
  }

  ModNum& operator-=(const ModNum& rhs) { return *this += mod - rhs.val; }
  ModNum operator-() const { return val > 0? mod - val: -val; }
  ModNum operator!() { return 1 - *this; }
  ModNum operator~() { return fpow(*this, mod - 2); }
  explicit operator uint32_t() const { return val; }
};

constexpr int N = 3e6 + 1;

struct Factorial {
  constexpr static int N = ::N;

  Factorial() {
    for (int i = 0; i < N; ++i) {
      fact[i] = i? fact[i - 1] * i: 1;
    }
    for (int i = N; i; --i) {
      nfact[i - 1] = i != N? nfact[i] * i: ~fact[N - 1];
    }
  }

  ModNum inv(int n) { return nfact[n] * fact[n - 1]; }
  ModNum a(int n, int k) { return fact[n] * nfact[n - k]; }
  ModNum operator()(int n, int k) { return a(n, k) * nfact[k]; }

private:
  ModNum fact[N], nfact[N];
} fact;

ModNum dp_[N + 2], *dp = dp_ + 2;

int main() {
  int n, q, a;
  reader(n, q);
  auto n3 = fact.inv(3);
  for (int i = 0; i < 3 * n; ++i) {
    dp[i] = (fact(3 * n, i + 1) - dp[i - 2]) * n3 - dp[i - 1];
  }
  while (q--) {
    reader(a);
    printf("%d\n", dp[a] + fact(3 * n, a));
  }
  return 0;
}