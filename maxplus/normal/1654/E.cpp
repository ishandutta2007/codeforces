//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <utility>
#include <random>
#include <cmath>

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

constexpr int N = 1e5, B = sqrt(N) / 3, S = N * (B + 1), S2 = S * 2;
uint16_t cnt[S];;
uint8_t cnt2[S];

int a[N + 7];

__attribute((cold)) int rndcheck(int n, int ans) {
  if (n < 3) {
    return n;
  }
  mt19937 rng(7);
  for (int it = 0; it < 1000; ++it) {
    int x = rng() % n, y = rng() % (n - 1);
    y += y == x;
    if ((a[x] - a[y]) % (x - y)) {
      continue;
    }
    it += 9;
    int cur = 0;
    int64_t d = (a[x] - a[y]) / (x - y), s = a[x] - x * d;
    for (int i = 0; i < n; ++i, s += d) {
      cur += a[i] == s;
    }
    maxi(ans, cur);
  }
  return ans;
}

int smoothcheck(int n, int ans) {
  for (int d: {0,0}) if (reverse(a, a + n), 1)
  for (int s = 0; s <= B && s * ans < N; ++s) {
    for (int i = 0, d = 0; i < n; ++i, d += s) {
      __builtin_prefetch(cnt2 + a[i + 7] + d + s, 1);
      if (__builtin_expect(cnt2[a[i] + d] == 255, 0)) {
        ++cnt[a[i] + d];
      } else {
        ++cnt2[a[i] + d];
      }
    }
    int mx = 0;
    for (int i = 0, d = 0; i < n; ++i, d += s) {
      __builtin_prefetch(cnt2 + a[i + 7] + d + s, 1);
      if (__builtin_expect(cnt2[a[i] + d] == 255, 0)) {
        maxi(mx, exchange(cnt[a[i] + d], 0) + exchange(cnt2[a[i] + d], 0));
      } else {
        maxi(mx, exchange(cnt2[a[i] + d], 0));
      }
    }
    maxi(ans, mx);
  }
  return ans;
}

int sharpcheck(int n, int ans) {
  for (int i = 0; i < n; ++i) {
    for (int j = unz(i - N / B); j < i; ++j) if ((a[i] - a[j]) % (i - j) == 0) {
      ++cnt[(a[i] - a[j]) / (i - j) + N];
    }
    int mx = 0;
    for (int j = unz(i - N / B); j < i; ++j) {
      maxi(mx, exchange(cnt[(a[i] - a[j]) / (i - j) + N], 0));
    }
    maxi(ans, mx + 1);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $;
  cin >> range{a, n};
  int ans = rndcheck(n, 0);
  if (__builtin_expect(ans <= n / 8, 1)) {
    ans = smoothcheck(n, ans);
  }
  if (__builtin_expect(ans <= N / B, 1)) {
    ans = sharpcheck(n, ans);
  }
  cout << n - ans;
}