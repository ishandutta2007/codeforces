//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

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
struct { using X = int; template <typename T = X> T operator()() const { T t; reader(t); return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
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
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

constexpr int L = 18, N = 1 << L;

struct Node {
  int64_t mi, ma, d, s;

  inline __attribute__((always_inline)) void update(const Node& l, const Node& r) {
    mi = min(l.mi, l.s + r.mi);
    ma = max(l.ma, l.s + r.ma);
    d = max({l.d, r.d, r.ma + l.s - l.mi});
    s = l.s + r.s;
  }
};

int a[N];
Node t[2 * N];

void build(int i, int L, int R, int key) {
  if (R == L + 1) {
    t[i] = {min(a[L], 0), max(a[L], 0), max(a[L], 0), a[L]};
    return;
  }
  build(2 * i + 1, L, (L + R) / 2, key / 2);
  build(2 * i + 2, (L + R) / 2, R, key / 2);
  bool which = key & 1;
  t[i].update(t[2 * i + 1 + which], t[2 * i + 1 + !which]);
}

template <int d, int i, int L, int R, int key>
inline __attribute__((always_inline)) void rebuild() {
  if (R == L + 1) {
    t[i] = {min(a[L], 0), max(a[L], 0), max(a[L], 0), a[L]};
    return;
  } else if constexpr (d) {
    rebuild<d - 1, 2 * i + 1, L, (L + R) / 2, key / 2>();
    rebuild<d - 1, 2 * i + 2, (L + R) / 2, R, key / 2>();
  }
  bool which = key & 1;
  t[i].update(t[2 * i + 1 + which], t[2 * i + 1 + !which]);
}

template <int d, int i, int L, int R>
inline __attribute__((always_inline)) void rebuild(int key) {
  if (R == L + 1) {
    t[i] = {min(a[L], 0), max(a[L], 0), max(a[L], 0), a[L]};
    return;
  } else if constexpr (d) {
    rebuild<d - 1, 2 * i + 1, L, (L + R) / 2>(key / 2);
    rebuild<d - 1, 2 * i + 2, (L + R) / 2, R>(key / 2);
  }
  bool which = key & 1;
  t[i].update(t[2 * i + 1 + which], t[2 * i + 1 + !which]);
}

template <int d>
inline __attribute__((always_inline)) void rebuild_(int i, int L, int R, int key) {
  if constexpr (d >= 0) {
    rebuild_<d - 1>(2 * i + 1, L, (L + R) / 2, key / 2);
    rebuild_<d - 1>(2 * i + 2, (L + R) / 2, R, key / 2);
    bool which = key & 1;
    t[i].update(t[2 * i + 1 + which], t[2 * i + 1 + !which]);
  }
}

template <int d>
void rebuild(int i, int L, int R, int key) {
  if constexpr (d >= 6) {
    rebuild<d - 1>(2 * i + 1, L, (L + R) / 2, key / 2);
    rebuild<d - 1>(2 * i + 2, (L + R) / 2, R, key / 2);
    bool which = key & 1;
    t[i].update(t[2 * i + 1 + which], t[2 * i + 1 + !which]);
  } else {
    return rebuild_<d>(i, L, R, key);
  }
}

template <int D, int K = 1 << D + 1>
inline  __attribute__((always_inline)) void rebuild_(int key) {
  if constexpr (K) {
    if (key == K) {
      return rebuild<D, 0, 0, N, K>();
    }
    return rebuild_<D, K - 1>(key);
  }
}

template <int D = L + 1>
void rebuild(int i, int L, int R, int key, int d) {
  if constexpr (D >= 0) if (D == d) {
    if constexpr (D <= 2) {
      if (R == N) {
        return rebuild_<D>(key & (1 << D + 1) - 1);
      }
      return rebuild<D>(i, L, R, key);
    } if constexpr (D <= 5) {
      if (R == N) {
        return rebuild<D, 0, 0, N>(key);
      }
      return rebuild<D>(i, L, R, key);
    } else {
      return rebuild<D>(i, L, R, key);
    }
  } else {
    return rebuild<D - 1>(i, L, R, key, d);
  }
}

array<int, 3> qs[N];
int64_t ans[N];

int main() {
  int l = $, n = 1 << l;
  reader(a, n);
  int q = $;
  for (int i = 0; i < q; ++i) {
    qs[i][0] = $;
    qs[i][0] = (i? qs[i - 1][0]: 0) ^ 1 << qs[i][0];
    int j = 0;
    for (int k = 0, t = qs[i][0]; k < l; ++k) {
      j += j + t % 2;
      t /= 2;
    }
    qs[i][1] = j;
    qs[i][2] = i;
  }
  sort(qs, qs + q, Ordering<3, 2>{});
  build(0, 0, n, 0);
  int last = 0;
  for (auto [k, i, j]: range{qs, q}) {
    if (last != k) {
      rebuild(0, 0, n, i, l - __builtin_ctz(last ^ k) - 1);
      last = k;
    }
    ans[j] = t[0].d;
  }
  print(range{ans, q});
}