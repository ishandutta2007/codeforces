//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>

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

constexpr int N = 31;

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcases = $, testcase = 0; testcase++ < testcases; ) {
    bool vis[2][N]{};
    int a[2][N]{};
    int r{}, c{};
    string ans;
    string rotl_, rotL_, rotr_, rotR_, rotm_, rotM_;
    string rotl = "K", rotL = "L", rotr = "T", rotR = "R", rotm = "N", rotM = "M";
    int n = 2 * $ + 1;
    for (auto cr: {0, 1})
    for (int cc = 0; cc < n; ++cc) {
      while (isspace(cin.peek())) cin.get();
      if (cin.peek() == 'E') {
        cin.get();
        r = cr, c = cc;
        a[cr][cc] = 2 * n - 1;
      } else {
        a[cr][cc] = $ - 1;
      }
    }
    bool parity = r + c + n & 1;
    for (auto cr: {0, 1})
    for (int cc = 0; cc < n; ++cc) if (change(vis[cr][cc], 1))
    for (int nr = cr, nc = cc; tie(nr, nc) = pair{a[nr][nc] / n, a[nr][nc] % n}, change(vis[nr][nc], 1); parity ^= 1) {
    }
    if (parity) {
      print("SURGERY FAILED");
      continue;
    }
    print("SURGERY COMPLETE");
    auto srotr = [](int* l, int* r) { rotate(l, r - 1, r); };
    auto srotl = [](int* l, int* r) { rotate(l, l + 1, r); };
    if (c != n - 1) {
      ans += string(n - 1 - c, 'r');
      srotl(a[r] + c, a[r] + n);
    }
    if (r == 0) {
      ans += 'd';
      swap(a[0][n - 1], a[1][n - 1]);
    }
    ans += string(n / 2, 'l');
    srotr(a[1] + n / 2, a[1] + n);
    rotl_ = 'u' + string(n / 2, 'l') + 'd' + string(n / 2, 'r');
    rotR_ = 'u' + string(n / 2, 'r') + 'd' + string(n / 2, 'l');
    rotL_ = string(n - 1, rotl[0]);
    rotr_ = string(n - 1, rotR[0]);
    rotm_ = rotL + rotr + rotl + rotR;
    rotM_ = rotm + rotm;
    auto perform = [&](string cmd, int cnt = 1) {
      while (cnt--) {
        ans += cmd;
        if (cmd == rotr) {
          srotr(a[0] + n / 2, a[0] + n);
          swap(a[0][n / 2], a[1][n / 2 + 1]);
          srotl(a[1] + n / 2 + 1, a[1] + n);
        } else if (cmd == rotR) {
          srotl(a[0] + n / 2, a[0] + n);
          swap(a[0][n - 1], a[1][n - 1]);
          srotr(a[1] + n / 2 + 1, a[1] + n);
        } else if (cmd == rotl) {
          srotr(a[0], a[0] + n / 2 + 1);
          swap(a[0][0], a[1][0]);
          srotl(a[1], a[1] + n / 2);
        } else if (cmd == rotL) {
          srotl(a[0], a[0] + n / 2 + 1);
          swap(a[0][n / 2], a[1][n / 2 - 1]);
          srotr(a[1], a[1] + n / 2);
        } else if (cmd == rotm) {
          rrotate(a[1][n / 2 - 1], a[0][n / 2], a[1][n / 2 + 1]);
        } else if (cmd == rotM) {
          lrotate(a[1][n / 2 - 1], a[0][n / 2], a[1][n / 2 + 1]);
        }
      }
    };
    auto findval = [&](string cmd, int val) {
      assert(cmd == rotL || cmd == rotr);
      int ops = 0;
      while (1) {
        if (a[0][n / 2] == val) {
          break;
        } else if (a[1][n / 2 - 1] == val) {
          perform(rotm);
          break;
        } else if (a[1][n / 2 + 1] == val) {
          perform(rotM);
          break;
        } else if (ops == n) {
          ans.resize(ans.size() - cmd.size() * n);
          return 0;
        }
        ++ops;
        perform(cmd);
      }
      perform(cmd == rotL? rotm: rotM);
      perform(cmd == rotL? rotl: rotR, ops);
      perform(cmd == rotL? rotM: rotm);
      return 1;
    };
    for (int i = n + n / 2; ++i < 2 * n - 1; ) {
      assert(findval(rotr, i) || findval(rotL, i));
      perform(rotr);
    }
    for (int i = n; --i > n / 2; ) {
      assert(findval(rotr, i) || findval(rotL, i));
      perform(rotr);
    }
    for (int i = n + n / 2 - 1; --i > n - 1; ) {
      assert(findval(rotr, i) || findval(rotL, i));
      perform(rotL);
    }
    for (int i = -1; ++i < n / 2; ) {
      assert(findval(rotr, i) || findval(rotL, i));
      perform(rotL);
    }
    assert(findval(rotr, n / 2));
    ans += string(n / 2, 'r');
    srotl(a[1] + n / 2, a[1] + n);
    assert(is_sorted(a[0], a[0] + n));
    assert(is_sorted(a[1], a[1] + n));
    assert(a[1][0] == n);
    print(ans);
    print(rotl, rotl_);
    print(rotR, rotR_);
    print(rotL, rotL_);
    print(rotr, rotr_);
    print(rotm, rotm_);
    print(rotM, rotM_);
    print("DONE");
  }
}