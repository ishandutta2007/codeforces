#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;
template <typename T, typename S> bool mini(T& a, S b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }


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
    if constexpr (INTPTR_MAX == INT64_MAX) {
      val = x % mod;
    } else {
      uint32_t xh = (uint32_t) (x >> 32), xl = (uint32_t) x, d;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (val)
        : "d" (xh), "a" (xl), "r" (mod)
      );
    }
    return *this;
  }

  ModNum& operator-=(const ModNum& rhs) { return *this += mod - rhs.val; }
  ModNum operator-() const { return val > 0? mod - val: -val; }
  ModNum operator!() { return 1 - *this; }
  ModNum operator~() { return fpow(*this, mod - 2); }
  explicit operator uint32_t() const { return val; }
};

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  ModNum two = 2;
  for (int testcase = $; testcase; --testcase) {
    int n = $, k = $;
    if (n % 2) {
      cout << (uint32_t)fpow(fpow(two, n - 1) + 1, k) << '\n';
      continue;
    }
    auto t = fpow(two, n - 1) - 1, pt = ModNum{1};
    auto u = ~fpow(two, n), pu = fpow(two, n * (int64_t)k % (mod - 1));
    auto ans = fpow(t, k);
    for (int i = 0; i < k; ++i) {
      pu *= u;
      ans += pt * pu;
      pt *= t;
    }
    cout << (uint32_t)ans << '\n';
  }
}