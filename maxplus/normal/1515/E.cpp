#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 401;

uint32_t mod;

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

struct ModNum {
  uint32_t val;

  ModNum(uint32_t val = 0) : val{val} {}

  ModNum& operator+=(const ModNum& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  friend ModNum operator+(ModNum lhs, const ModNum& rhs) {
    return lhs += rhs;
  }

  ModNum& operator*=(const ModNum& other) {
    uint64_t x = (uint64_t) val * other.val;
    uint32_t xh = (uint32_t) (x >> 32), xl = (uint32_t) x, d;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (val)
      : "d" (xh), "a" (xl), "r" (mod)
    );
    return *this;
  }

  friend ModNum operator*(ModNum lhs, const ModNum& rhs) {
    return lhs *= rhs;
  }

  ModNum operator~() const {
    return pow(*this, mod - 2);
  }

  explicit operator uint32_t() const {
    return val;
  }
};

ModNum fact[N], ifact[N], p2[N], coef[N][N];

void precalc() {
  fact[0] = ifact[0] = p2[0] = 1;
  for (int i = 1; i < N; ++i) {
    p2[i] = p2[i - 1] * 2;
    fact[i] = fact[i - 1] * i;
    ifact[i] = ~fact[i];
    for (int k = 1; k <= i; ++k) {
      coef[i][k] = fact[i] * ifact[i - k] * ifact[k] * p2[k - 1];
    }
  }
}

ModNum cnk(int n, int k) {
  return fact[n] * ifact[n - k] * ifact[k];
}

ModNum dp[N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n >> mod;
  precalc();
  ModNum ans = 0;
  for (int off = 0; off <= n; ++off) {
    for (int on = off; on + off <= n; ++on) {
      *dp[on] = on + off == 0;
      for (int l = 1; l <= on - off + !!off; ++l) {
        *dp[on] += dp[on][l];
      }
      for (int l = 1; l <= on - off; ++l) {
        dp[on][l] = *dp[on - l] * coef[on][l];
        if (off + on == n) {
          ans += dp[on][l];
        }
      }
    }
  }
  cout << (uint32_t)ans;
  return 0;
}