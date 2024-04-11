#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { ((cout << ts << ' '), ...) << '\n'; }
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unneg(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

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

constexpr int N = 2e5 + 1;

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

  ModNum operator[](int n) { return fact[n]; }
  ModNum operator()(int n) { return nfact[n]; }
  ModNum inv(int n) { return nfact[n] * fact[n - 1]; }
  ModNum a(int n, int k) { return fact[n] * nfact[n - k]; }
  ModNum operator()(int n, int k) { return a(n, k) * nfact[k]; }
  ModNum cat(int n, int k = -1) { return k > n? 0: k == -1 || k == n? a(n + n, n) * nfact[n + 1]: a(n + k, n) * nfact[n + 1] * (n - k + 1); }
  ModNum s(int n) { return (*this)(n, n / 2); }

private:
  ModNum fact[N], nfact[N];
} fact;

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    cout << uint32_t(fact[$ * 2] * fact(2)) << '\n';
  }
}