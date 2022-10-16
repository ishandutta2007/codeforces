#include <iostream>

using namespace std;

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

constexpr uint32_t N = 14, masks = 1 << N, mod = 1e9 + 7, mod_ = pow(-mod, -1u >> 1);

uint32_t REDC(uint64_t a) {
  uint32_t ah = (uint32_t) (a >> 32), al = (uint32_t) a, d = -1, m = -1;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (ah), "a" (al), "r" (mod)
  );
  return m;
//  uint32_t t = (a + uint32_t(a * mod_) * (uint64_t)mod) >> 32;
//  return t >= mod? t - mod: t;
}

constexpr uint64_t rs = 1;//pow((1ull << 32) % mod, 2) % mod;
constexpr uint32_t r = 1;//REDC(rs);

struct ModProb {
  uint32_t val;

  ModProb(uint32_t val = 0) : val{REDC(val * rs)} {}

  ModProb(bool, uint32_t val) : val{val} {}

  ModProb& operator+=(const ModProb& other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
    return *this;
  }

  friend ModProb operator+(ModProb lhs, const ModProb& rhs) {
    return lhs += rhs;
  }

  ModProb& operator*=(const ModProb& other) {
    if constexpr (INTPTR_MAX == INT64_MAX) {
      val = (uint64_t)val * other.val % mod;
    } else {
      uint32_t junk;
      asm(
        "mul %0\n\t"
        "divl %3\n\t"
        : "+d" (val), "=a" (junk)
        : "a" (other.val), "rm" (mod)
        : "cc"
      );
    }
    return *this;
  }

  friend ModProb operator*(ModProb lhs, const ModProb& rhs) {
    return lhs *= rhs;
  }

//  friend ModProb operator&(const ModProb& lhs, const ModProb& rhs) {
//    uint64_t x = (uint64_t) lhs.val * rhs.val;
//    uint32_t xh = (uint32_t) (x >> 32), xl = (uint32_t) x, d, m;
//    asm(
//      "divl %4; \n\t"
//      : "=a" (d), "=d" (m)
//      : "d" (xh), "a" (xl), "r" (mod)
//    );
//    return m;
//  }

  ModProb operator~() const {
    return pow(*this, mod - 2);
  }

  ModProb operator!() const {
    return ModProb{0, val >= r? mod + r - val: r - val};
  }

  explicit operator uint32_t() const {
    return REDC(val);
  }

//  friend ModProb operator|(const ModProb& lhs, const ModProb& rhs) {
//    return !(!lhs & !rhs);
//  }
};

uint32_t bin2tern[masks];

uint32_t join(uint32_t maskl, uint32_t maskr) {
  return bin2tern[maskr] + bin2tern[maskl | maskr];
}

void precalc() {
  for (uint32_t i = 0, tern = 1; i < N; ++i, tern *= 3) {
    bin2tern[1 << i] = tern;
  }
  for (uint32_t i = 0; i < masks; ++i) {
    bin2tern[i] = bin2tern[i & ~-i] + bin2tern[i & -i];
  }
}

constexpr uint32_t tmasks = pow(3, N);

uint32_t a[N];
ModProb pwin[tmasks];
ModProb ploss[tmasks];
ModProb pwinner[tmasks];

int main()
{
  precalc();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  uint32_t cmasks = 1 << n;
  for (int i = 0; i < n; ++i) {
    ploss[join(0, 1 << i)] = 1;
    for (int j = 0; j < n; ++j) if (i != j) {
      ploss[join(1 << i, 1 << j)] = !(pwin[join(1 << i, 1 << j)] = a[i] * ~ModProb{a[i] + a[j]});
    }
  }
  for (uint32_t maski = 0; maski < cmasks; ++maski) {
    pwin[join(maski, 0)] = ploss[join(maski, 0)] = 1;
    for (int j = 0; j < n; ++j) if ((1 << j) & ~maski) {
      pwin[join(maski, 1 << j)] = !(ploss[join(maski, 1 << j)] = ploss[join(maski & ~-maski, 1 << j)] * ploss[join(maski & -maski, 1 << j)]);
    }
    for (uint32_t compli = ~maski & ~-cmasks, complj = compli; ; complj = compli & ~-complj) {
      uint32_t maskj = compli & ~complj;
      pwin[join(maski, maskj)] = pwin[join(maski, maskj & ~-maskj)] * pwin[join(maski, maskj & -maskj)];
      ploss[join(maski, maskj)] = ploss[join(maski, maskj & ~-maskj)] * ploss[join(maski, maskj & -maskj)];
      if (!complj) {
        break;
      }
    }
  }
  pwinner[join(cmasks - 1, 0)] = 1;
  for (uint32_t maski = cmasks - 1; maski != -1u; --maski) {
    for (uint32_t compli = ~maski & ~-cmasks, maskj = compli; maskj; maskj = compli & ~-maskj) {
      for (uint32_t maskij = maski | maskj, complij = ~maskij & ~-cmasks, maskk = complij; ; maskk = complij & ~-maskk) {
        pwinner[join(maski, maskj)] += pwinner[join(maskij, maskk)] * pwin[join(maskj, maskk)] * ploss[join(maskj, complij & ~maskk)];
        if (!maskk) {
          break;
        }
      }
    }
  }
  ModProb ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += pwinner[join(0, 1 << i)];
  }
  cout << unsigned(ans) << '\n';
  return 0;
}