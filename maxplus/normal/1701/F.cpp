//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <bitset>
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
      #pragma GCC unroll 4
      for (int iter = 0; iter < 4; ++iter) if (b != e)
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
 
constexpr int N = 2e5, S = 1 << 18;

struct Node {
  int lazy, alive;
  int64_t sum;

  int64_t eval() { return sum + lazy * (int64_t)alive; }
};

Node t[N + S];

int getAlive(int l, int r) {
  int res = 0;
  l += S, r += S;
  #pragma GCC unroll 19
  for (int L = 0; L < 18 && r != l; ++L) {
    if (l & 1) res += t[l++].alive;
    if (r & 1) res += t[--r].alive;
    l /= 2, r /= 2;
  }
  return res;
}

auto getSum(int l, int r) {
  int la = 0, ra = 0;
  int64_t ls = 0, rs = 0;
  l += S, r += S;
  while (r != l) {
    if (l & 1) la += t[--l].alive, ls -= t[l].eval();
    if (r & 1) ra += t[--r].alive, rs += t[r].eval();
    l /= 2, r /= 2;
    ls -= la * (int64_t)t[l].lazy;
    rs += ra * (int64_t)t[r].lazy;
  }
  int a = ra - la;
  int64_t s = rs + ls;
  while (r /= 2) {
    s += a * t[r].lazy;
  }
  return s;
}

template <int dir>
void changeLazy(int l, int r) {
  l += S, r += S;
  int dl = 0, dr = 0;
  #pragma GCC unroll 19
  for (int L = 0; L < 18 && r; ++L) {
    t[l].sum += dl, t[r].sum += dr;
    if (l & 1) t[--l].lazy -= dir, dl -= dir * t[l].alive;
    if (r & 1) t[--r].lazy += dir, dr += dir * t[r].alive;
    l /= 2, r /= 2;
  }
}

template <int dir>
void changeAlive(int pos, int val) {
  #pragma GCC unroll 19
  for (int i = 1, l = 0; l <= 18; ++l) {
    val -= t[i].lazy;
    t[i].alive += dir;
    t[i].sum += dir * val;
    i *= 2;
    i += pos >> 17 - l & 1;
  }
}

bool alive[N];
 
int main() {
  int q = $, d = $;
  int64_t ans = 0;
  while (q--) {
    int a = $ - 1;
    int l = unz(a - d), r = min(N, a + d + 1);
    auto val = getAlive(l, a);
    if (alive[a] ^= 1) {
      ans += val * (val - 1ll) / 2 + getSum(a + 1, r);
      changeAlive<1>(a, val);
      changeLazy<1>(a + 1, r);
    } else {
      changeAlive<-1>(a, val);
      changeLazy<-1>(a + 1, r);
      ans -= val * (val - 1ll) / 2 + getSum(a + 1, r);
    }
    print(ans);
  }
}