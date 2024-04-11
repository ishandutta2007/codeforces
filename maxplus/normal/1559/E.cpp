#include <iostream>
#include <numeric>
#include <vector>
#include <array>

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
constexpr T pow(T a, uint32_t p) {
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
  ModNum operator~() { return pow(*this, mod - 2); }
  explicit operator uint32_t() const { return val; }
};

constexpr int N = 50, M = 1e5 + 1;

struct Eratosthenes {
  static constexpr int N = ::M;

  auto operator[](int x) { return dpr[x]; }

  Eratosthenes() {
    for (int i = 2; i < N; ++i) {
      if (dpr[i].d == 0) {
        dpr[i] = {i, 1, 1};
      }
      if (dpr[i].d != i || i > N / i) {
        continue;
      }
      for (int j = i * i, cj = i; j < N; j += i, ++cj) if (dpr[j].d == 0) {
        dpr[j] = {i, dpr[cj].d == i? dpr[cj].p + 1: 1, cj};
      }
    }
  }

private:
  struct {
    int d, p, r;
  } dpr[N];
} sieve;

ModNum dp[2][M];

ModNum solve_anygcd(const array<int, N>& stars, int n, int m) {
  for (int i = 0; i <= m; ++i) {
    dp[0][i] = dp[1][i] = 0;
  }
  dp[1][0] = 1;
  for (int i = 0; i < n; ++i) {
    bool cur = i % 2, prv = !cur;
    int max_brightness = stars[i];
    ModNum psum = 0;
    for (int j = 0; j <= m; ++j) {
      psum += dp[prv][j] - (j > max_brightness? dp[prv][j - max_brightness - 1]: 0);
      dp[cur][j] = psum;
    }
  }
  return accumulate(dp[n - 1 & 1], dp[n - 1 & 1] + m + 1, ModNum{});
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  array<int, 2> stars[N];
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> stars[i][0] >> stars[i][1];
  }
  ModNum ans = 0;
  array<int, N> subtask_stars;
  for (int i = 1; i <= m; ++i) {
    int sgn = 1;
    for (int j = i; sgn && j > 1; j = sieve[j].r) {
      sgn *= -(sieve[j].p == 1);
    }
    int subtask_m = m / i;
    for (int j = 0; subtask_m >= 0 && j < n; ++j) {
      int l = (stars[j][0] + i - 1) / i, r = stars[j][1] / i;
      subtask_m -= l;
      subtask_stars[j] = r - l;
    }
    ans += (mod + sgn) * solve_anygcd(subtask_stars, n, max(-1, subtask_m));
  }
  cout << ans.val << '\n';
  return 0;
}