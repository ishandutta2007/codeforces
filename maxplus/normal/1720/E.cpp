#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
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
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_scalar_v<decay_t<decltype(a)>>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

constexpr int N = 500;

int a[N][N];
array<int, 2> coord[N * N];
vector<int> spawn[N];
using Rot = int[2 * N + 1][N + 1];
Rot d[4], t;
int buf[N];

int& get(Rot d, int r, int c) {
  return d[r + c][(r - c + N) / 2];
}

int main() {
  int n = $, k = $;
  for (int i = 0; i < n * n; ++i) {
    coord[i][0] = n << 9 | n;
  }
  int cntdif = 0;
  for (int i = 0; i < n && (reader(a[i], n), 1); ++i)
  for (int j = 0; j < n; ++j) {
    auto v = --a[i][j];
    cntdif += coord[v][0] == (n << 9 | n);
    auto lc = coord[v][0] >> 9, lr = coord[v][0] & 0777;
    auto rr = coord[v][1] >> 9, rc = coord[v][1] & 0777;
    coord[v] = {min(lc, j) << 9 | min(lr, i), max(rr, i) << 9 | max(rc, j)};
  }
  cntdif -= k;
  if (cntdif <= 0) {
    print(-cntdif);
    return 0;
  }
  for (int i = 0; i < n * n; ++i) if (coord[i][0] != (n << 9 | n)) {
    auto lc = coord[i][0] >> 9, lr = coord[i][0] & 0777;
    auto rr = coord[i][1] >> 9, rc = coord[i][1] & 0777;
    spawn[max(rr - lr, rc - lc)].push_back(i);
  }
  for (int l = 0; l < n; ++l) {
    if (l) {
      for (int i = 0; i < n - l; ++i) {
        get(d[3], i + l, l) += get(d[3], i + l, l - 1);
      }
      for (int j = 0; j < n - l; ++j) {
        get(d[3], l, j + l) += get(d[3], l - 1, j + l);
      }
      get(d[3], l, l) += get(d[3], l - 1, l - 1);
      for (int j = 0; j < n - l; ++j) {
        get(d[2], l, j) += get(d[2], l - 1, j);
      }
      for (int i = 0; i < n - l; ++i) {
        get(d[1], i, l) += get(d[1], i, l - 1);
      }
    }
    for (auto v: spawn[l]) {
      auto [col, cor] = coord[v];
      auto lc = col >> 9, lr = col & 0777;
      auto rr = cor >> 9, rc = cor & 0777;
      ++get(d[0], lr + 1, lc + 1);
      --get(d[1], lr + 1, max(rc, l));
      --get(d[2], max(rr, l), lc + 1);
      ++get(d[3], max(rr, l), max(rc, l));
    }
    constexpr int C = 1u << 31 | 1;
    t[0][N / 2] = C - 1 - cntdif + d[0][0][N / 2] + d[1][l][(N - l) / 2] + d[2][l][(N + l) / 2] + d[3][2 * l][N / 2];
    buf[N / 2] |= t[0][N / 2] <= C;
    for (int j = 1; j < n - l; ++j) {
      #pragma GCC ivdep
      for (int i = 1, su = i + j - 1, di = (i - j + N + 1) / 2, pdi = (i - j + N) / 2 + 1, sud = su + l, did = (i - j + N - l + 1) / 2; i < j; ++di, ++did, ++pdi, ++i) {
        auto cur = d[0][su][di];
        cur += d[1][sud][did];
        cur += d[2][sud][did + l];
        cur += d[3][su + 2 * l][di];
        cur += t[su - 1][pdi];
        cur += t[su - 1][pdi - 1];
        cur -= t[su - 2][di];
        buf[di] += cur <= C;
        t[su][di] = cur;
      }
      if (int i = 0, su = i + j, di = (i - j + N) / 2, pdi = (i - j + N + 1) / 2, sud = su + l, did = (i - j + N - l) / 2; 1) {
        auto cur = d[0][su][di];
        cur += d[1][sud][did];
        cur += d[2][sud][did + l];
        cur += d[3][su + 2 * l][di];
        cur += t[su - 1][pdi];
        buf[di] += cur <= C;
        t[su][di] = cur;
      }
      if (int i = j, su = i + 0, di = (i - 0 + N) / 2, pdi = (i - 0 + N + 1) / 2, sud = su + l, did = (i - 0 + N - l) / 2; 1) {
        auto cur = d[0][su][di];
        cur += d[1][sud][did];
        cur += d[2][sud][did + l];
        cur += d[3][su + 2 * l][di];
        cur += t[su - 1][pdi - 1];
        buf[di] += cur <= C;
        t[su][di] = cur;
      }
    }
    for (int i = 1; i < n - l; ++i)
    #pragma GCC ivdep
    for (int j = n - l - 1, su = i + j, di = (i - j + N) / 2, pdi = (i - j + N + 1) / 2, sud = su + l, did = (i - j + N - l) / 2; j >= i; ++di, ++did, ++pdi, --j) {
      auto cur = d[0][su][di];
      cur += d[1][sud][did];
      cur += d[2][sud][did + l];
      cur += d[3][su + 2 * l][di];
      cur += t[su - 1][pdi];
      cur += t[su - 1][pdi - 1];
      cur -= t[su - 2][di];
      buf[di] += cur <= C;
      t[su][di] = cur;
    }
  }
  print(1 + !reduce(buf, buf + N));
}