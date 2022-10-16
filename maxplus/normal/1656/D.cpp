#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <class T = string> T operator~() const { return *this; } } $;
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

struct Eratosthenes {
  static constexpr int N = 1e5;

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

  int totient(int n) const {
    int res = 1;
    while (n > 1) {
      res *= dpr[n].d - 1;
      for (int d = dpr[n].d, i = dpr[n].p; n = dpr[n].r, --i; ) {
        res *= d;
      }
    }
    return res;
  }

private:
  struct {
    int d, p, r;
  } dpr[N];
} sieve;

uint64_t fgcd(uint64_t a, uint64_t b) {
  a >>= __builtin_ctzll(a);
  while (a) {
    do {
      b -= a;
      b >>= __builtin_ctzll(b);
    } while (b >= a);
    swap(a, b);
  }
  return b;
}

uint32_t fgcd(uint32_t a, uint32_t b) {
  a >>= __builtin_ctz(a);
  while (a) {
    do {
      b -= a;
      b >>= __builtin_ctz(b);
    } while (b >= a);
    swap(a, b);
  }
  return b;
}

mt19937 rng(14124);

struct Primality {
//  auto& mul(uint64_t& a, uint64_t b, uint64_t m) {
//    auto mu = __uint128_t(a) * b;
//    asm("divq %[v]\n\t"
//        : "=a" (b), "=d" (a)
//        : "a" (uint64_t(mu)), "d" (uint64_t(mu >> 64)), [v] "rm" (m));
//    return a;
//  }
//
//  auto& sqr(uint64_t& a, uint64_t m) {
//    auto mu = __uint128_t(a) * a;
//    asm("divq %[v]\n\t"
//        : "=a" (m), "=d" (a)
//        : "a" (uint64_t(mu)), "d" (uint64_t(mu >> 64)), [v] "rm" (m));
//    return a;
//  }
//
//  auto& sqrp1(uint64_t& a, uint64_t m) {
//    auto mu = __uint128_t(a) * a + 1;
//    asm("divq %[v]\n\t"
//        : "=a" (m), "=d" (a)
//        : "a" (uint64_t(mu)), "d" (uint64_t(mu >> 64)), [v] "rm" (m));
//    return a;
//  }
//
//  auto& mul(uint32_t& a, uint32_t b, uint32_t m) {
//    return a = a * (uint64_t)b % m;
//  }
//
//  auto& sqr(uint32_t& a, uint32_t m) {
//    return a = a * (uint64_t)a % m;
//  }
//
//  auto& sqrp1(uint32_t& a, uint32_t m) {
//    return a = (a * (uint64_t)a + 1) % m;
//  }
//
//  template <typename T>
//  auto pow(T a, T b, T m) {
//    T res = 1;
//    do if (b & 1) mul(res, a, m);
//    while ((b /= 2) && (sqr(a, m), 1));
//    return res;
//  }
//
//  template <typename T>
//  bool miller_test(T n, T r, T d, T a) {
//    if (n % a == 0) {
//      return n == a;
//    }
//    auto x = pow(a, d, n);
//    if (x == 1 || x == n - 1) {
//      return 1;
//    }
//    for (int i = 1; i < r; ++i) {
//      sqr(x, n);
//      if (x == 1) {
//        return 0;
//      } else if (x == n - 1) {
//        return 1;
//      }
//    }
//    return 0;
//  }
//
//  template <typename T, typename... As>
//  bool miller_test(T n, T r, T d, As... A) {
//    return (miller_test(n, r, d, (T)A) && ...);
//  }
//
//  template <typename T>
//  bool miller(T n) {
//    if (n <= 2) {
//      return n - 1;
//    }
//    T r = __builtin_ctzll(n - 1), d = (n - 1) >> r;
//    bool res;
//    if (n < 4759123141) {
//      res = miller_test(n, r, d, 2, 7, 61);
//    } else if (n < 1122004669633) {
//      res = miller_test(n, r, d, 2, 13, 23, 1662803);
//    } else if (n < 341550071728321) {
//      res = miller_test(n, r, d, 2, 3, 5, 7, 11, 13, 17);
//    } else if (n < 3825123056546413051) {
//      res = miller_test(n, r, d, 2, 3, 5, 7, 11, 13, 17, 19, 23);
//    } else {
//      res = miller_test(n, r, d, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37);
//    }
//    return res;
//  }
//
//  template <typename T>
//  T pol_rho(T n) {
//    T a = 0;
//    auto step = [&](auto& x) { if ((sqr(x, n) += a) >= n) x -= n; };
////    auto step = [&](auto& x) { ++sqr(x, n); };
////    auto step = [&](auto& x) { sqrp1(x, n); };
//    constexpr int steps = 7;
//    T prods[steps];
//    auto fullstep = [&](auto& x, auto& y) { return step(x), step(y), step(y), x > y? x - y: y - x; };
//    while (1) {
//      ++a;
//      T x = rng() % n, y = x, d = 1, prod, pprod;
//      T savex, savey;
//      while (d == 1) {
//        savex = x, savey = y;
//        prods[0] = prod = fullstep(x, y);
//        #pragma GCC unroll 99
//        for (int i = 1; i < steps; ++i) {
//          prods[i] = mul(prod, fullstep(x, y), n);
//        }
//        d = fgcd(prod, n);
//      }
//      if (d == n) {
//        int l = -1, r = steps - 1;
//        while (r > l + 1) {
//          int m = (r + l) / 2;
//          d = fgcd(prods[m], n);
//          if (d == 1) {
//            l = m;
//          } else if (d == n) {
//            r = m;
//          } else {
//            break;
//          }
//        }
//      }
//      if (d != n && d != 1) {
//        return d;
//      }
//    }
//  }
//
//  template <typename T>
//  T minpdiv(T n) {
//    if (miller(n)) {
//      return n;
//    }
//    auto divi = pol_rho(n);
//    return min(minpdiv(divi), minpdiv(n / divi));
//  }
} primality;


struct PrimalityMontgomery32 {
  auto& mul(uint32_t& a, uint32_t b, uint32_t m) {
    return a = (uint64_t)a * b % m;
  }

  auto& sqr(uint32_t& a, uint32_t m) {
    return a = (uint64_t)a * a % m;
  }

  struct Montgomery32 {
    Montgomery32(uint32_t n): mod(n), inv(1), p1(-n % n), m1(n - p1), r2(p1) {
      for (int i = 0; i < 5; i++) {
        inv *= 2 - n * inv;
      }
      for (int i = 0; i < 4; i++) {
        r2 <<= 1;
        if (r2 >= mod) {
          r2 -= mod;
        }
      }
      for (int i = 0; i < 3; i++) {
        r2 = mult(r2, r2);
      }
    }

    uint32_t init(uint32_t x) const {
      return mult(x, r2);
    }

    uint32_t reduce(uint64_t x) const {
      uint32_t xlow = x, xhigh = x >> 32;
      uint32_t q = xlow * inv;
      int32_t a = xhigh - (q * uint64_t(mod) >> 32);
      if (a < 0) {
        a += mod;
      }
      return a;
    }

    uint32_t mult(uint32_t a, uint32_t b) const {
      return reduce(a * uint64_t(b));
    }

    uint32_t mod, inv, p1, m1, r2;
  };

  auto& mul(uint32_t& a, uint32_t b, Montgomery32 m) {
    return a = m.mult(a, b);
  }

  auto& sqr(uint32_t& a, Montgomery32 m) {
    return a = m.mult(a, a);
  }

  template <typename T, typename U>
  auto pow(T a, T b, U m) {
    T res = m.p1;
    do if (b & 1) mul(res, a, m);
    while ((b /= 2) && (sqr(a, m), 1));
    return res;
  }

  bool miller_test(Montgomery32 m, uint32_t r, uint32_t d, uint32_t A) {
    uint32_t a = m.init(A);
    auto x = pow(a, d, m);
    if (x == m.p1 || x == m.m1) {
      return 1;
    }
    for (int i = 1; i < r; ++i) {
      sqr(x, m);
      if (x == m.p1) {
        return 0;
      } else if (x == m.m1) {
        return 1;
      }
    }
    return 0;
  }

  template <typename... As>
  bool miller_test(Montgomery32 m, uint32_t r, uint32_t d, As... A) {
    return (miller_test(m, r, d, (uint32_t)A) && ...);
  }

  bool miller(Montgomery32 m) {
    using T = uint32_t;
    auto n = m.mod;
    if (n <= 2) {
      return n - 1;
    }
    T r = __builtin_ctzll(n - 1), d = (n - 1) >> r;
    bool res;
    if (n < 4759123141) {
      res = miller_test(m, r, d, 2, 7, 61);
    } else if (n < 1122004669633) {
      res = miller_test(m, r, d, 2, 13, 23, 1662803);
    } else if (n < 341550071728321) {
      res = miller_test(m, r, d, 2, 3, 5, 7, 11, 13, 17);
    } else if (n < 3825123056546413051) {
      res = miller_test(m, r, d, 2, 3, 5, 7, 11, 13, 17, 19, 23);
    } else {
      res = miller_test(m, r, d, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37);
    }
    return res;
  }

  uint32_t pol_rho(Montgomery32 m) {
    using T = uint32_t;
    static mt19937 rng(1);
//    ++rhos;
    auto n = m.mod;
    uint32_t a = 0, ai;
//    auto step = [&](auto& x) { if ((sqr(x, m) += m.p1) >= n) x -= n; };
    auto step = [&](auto& x) { if ((sqr(x, m) += ai) >= n) x -= n; };
//    auto step = [&](auto& x) { sqr(x, m); };
//    auto step = [&](auto& x) { auto t = sqr(x, n); mul(x, sqr(t, n), n); if (++x == n) x = 0; };
//    auto step = [&](auto& x) { ++sqr(x, n); };
//    auto step = [&](auto& x) { sqrp1(x, n); };
    constexpr int steps = 13;
//    T prods[steps];
    auto fullstep = [&](auto& x, auto& y) { return step(x), step(y), step(y), x > y? x - y: y - x; };
    while (1) {
//      ++rerhos;
      ai = m.init(++a);
      T x = m.init(rng()), y = x, d, prod;
      T savex, savey;
      do {
        savex = x, savey = y;
        prod = fullstep(x, y);
        #pragma GCC unroll 99
        for (int i = 1; i < steps; ++i) {
          mul(prod, fullstep(x, y), m);
        }
        d = fgcd(prod, n);
      } while (d == 1);
      if (d == n) {
        x = savex, y = savey;
        do {
          d = fgcd(fullstep(x, y), n);
        } while (d == 1);
      }
//      if (d == n) {
//        int l = -1, r = steps - 1;
//        while (r > l + 1) {
//          int m = (r + l) / 2;
//          d = fgcd(prods[m], n);
//          if (d == 1) {
//            l = m;
//          } else if (d == n) {
//            r = m;
//          } else {
//            break;
//          }
//        }
//      }
      if (d != n && d != 1) {
//        rhoclck += clock() - start;
        return d;
      }
    }
  }

//  uint64_t maxpdiv(uint64_t n, uint64_t cur = 1) {
//    if (n <= cur) {
//      return cur;
//    } else if (miller(n)) {
//      return n;
//    }
//    auto divi = pol_rho(n);
//    do {
//      n /= divi;
//    } while (n % divi == 0);
//    maxi(cur, maxpdiv(n, cur));
//    maxi(cur, maxpdiv(divi, cur));
//    return cur;
//  }

  template <typename T>
  T minpdiv_(T n, uint64_t n0) {
    if (miller(n)) {
      return n;
    }
    auto divi = pol_rho(n);
    if (uint64_t t = divi, u = t * (t + 1) / 2; n0 >= u) {
      return t;
    } else if (uint64_t t = n / divi, u = t * (t + 1) / 2; n0 >= u) {
      return t;
    }
    auto d0 = minpdiv(divi, n0);
    if (d0 != divi) if (uint64_t t = d0, u = t * (t + 1) / 2; n0 >= u) {
      return t;
    }
    return min(d0, minpdiv(n / divi, n0));
  }

  template <typename T>
  T minpdiv(T n, uint64_t n0) {
    if (n == 1) {
      return -1;
    }
    #pragma GCC unroll 99
    for (auto k: {7, 61}) if (n % k == 0) {
      return min((T)k, minpdiv(n / k, n0));
    }
    return minpdiv_(n, n0);
  }
} mprimality;

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int64_t n = $, d = __builtin_ctzll(n), t = 1ll << d + 1, u = t * (t + 1ull) / 2;
    if (d < 30 && n >= u) {
      print(t);
//      res = t;
      continue;
    }
    if (n >> d > 1 && (t = mprimality.minpdiv(uint32_t(n >> d), n), u = t * (t + 1) / 2, t >= 2) && n >= u) {
      print(t);
//      res = t;
    } else {
      print(-1);
//      res = -1;
    }
  }
}