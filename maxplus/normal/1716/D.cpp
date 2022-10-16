#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <bitset>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
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

constexpr int N = 2e5 + 1, mod = 998244353;
int ways[N * 2];
int64_t ans[N];

int& add(int& a, int b) {
  return a -= (a += b) >= mod? mod: 0;
}

constexpr int p10[10]{1, 10, 100, 1000, (int)1e4, (int)1e5, (int)1e6, (int)1e7, (int)1e8, (int)1e9};

template <int len, int j>
inline void write_(char*__restrict__&__restrict__ c, unsigned val) {
  if constexpr (j == len) {
    c[j] = ' ';
    c += len + 1;
  } else {
    c[j] = val % p10[len - j] / p10[len - j - 1] + '0';
    write_<len, j + 1>(c, val);
  }
}

template <int srch = 8>
inline void write(char*& buf, unsigned val) {
  if (val >= p10[srch] || !srch) {
    return write_<srch + 1, 0>(buf, val);
  } else if constexpr (srch > 0) {
    return write<srch - 1>(buf, val);
  }
}

int main() {
  int n = $, k = $;
  int start = 0;
  ways[N] = 1;
  int offset = N;
  while (start + k <= n) {
    start += k;
    if (k >= 8)
    #pragma GCC ivdep
    for (int i = start, d = offset - start; i <= n; ++i) {
      add(ways[i + d], ways[i - k + d]);
    } else
    for (int i = start, d = offset - start; i <= n; )
    #pragma GCC unroll 8
    for (int j = 0; j < 4 && i <= n; ++j, ++i) {
      add(ways[i + d], ways[i - k + d]);
    }
    #pragma GCC ivdep
    for (int i = start, d = offset - start; i <= n; ++i) {
      ans[i] += ways[i + d];
    }
    ++k;
  }
  static char gbuf[N * 10], *c = gbuf;
  for (auto i: range{ans + 1, n}) {
    write(c, i % mod);
  }
  fwrite(gbuf, 1, c - gbuf, stdout);;
}