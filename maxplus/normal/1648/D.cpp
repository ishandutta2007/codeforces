//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <tuple>
#include <set>
#include <cassert>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
struct Less { bool operator()(const auto& a, const auto& b) const { return a <  b; } }; struct Greater { bool operator()(const auto& a, const auto& b) const { return b <  a; } }; struct Equals { bool operator()(const auto& a, const auto& b) const { return a == b; } };
template <int from, int which, typename Cmp> bool comparefields(const auto& a, const auto& b) { static_assert(1 <= which && which <= from && from <= 5); if constexpr (from == 1) { const auto& [a1] = a; const auto& [b1] = b; if constexpr (which == 1) return Cmp{}(a1, b1); } else if constexpr (from == 2) { const auto& [a1, a2] = a; const auto& [b1, b2] = b; if constexpr (which == 1) return Cmp{}(a1, b1); if constexpr (which == 2) return Cmp{}(a2, b2); } else if constexpr (from == 3) { const auto& [a1, a2, a3] = a; const auto& [b1, b2, b3] = b; if constexpr (which == 1) return Cmp{}(a1, b1); if constexpr (which == 2) return Cmp{}(a2, b2); if constexpr (which == 3) return Cmp{}(a3, b3); } else if constexpr (from == 4) { const auto& [a1, a2, a3, a4] = a; const auto& [b1, b2, b3, b4] = b; if constexpr (which == 1) return Cmp{}(a1, b1); if constexpr (which == 2) return Cmp{}(a2, b2); if constexpr (which == 3) return Cmp{}(a3, b3); if constexpr (which == 4) return Cmp{}(a4, b4); } else if constexpr (from == 5) { const auto& [a1, a2, a3, a4, a5] = a; const auto& [b1, b2, b3, b4, b5] = b; if constexpr (which == 1) return Cmp{}(a1, b1); if constexpr (which == 2) return Cmp{}(a2, b2); if constexpr (which == 3) return Cmp{}(a3, b3); if constexpr (which == 4) return Cmp{}(a4, b4); if constexpr (which == 5) return Cmp{}(a5, b5); } }
template <int from, int which, int... whichs>
struct Ordering { bool operator()(const auto& a, const auto& b) const { if (!comparefields<from, labs(which), Equals>(a, b)) { return which > 0? comparefields<from, labs(which), Less>(a, b): comparefields<from, labs(which), Less>(b, a); } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

template <typename Node, Node(*combine)(const Node&, const Node&), typename Update = void>
struct ST {
  ST(int n, Node dflt): n{n}, dflt{dflt}, t(n * 2, dflt) {
  }

  void update(int pos, const auto& val) {
    UpdateEnv{pos, val, t}.update(0, 0, n);
  }

  Node query(int l, int r) const {
    return query(0, 0, n, l, r);
  }

private:
  int n;
  Node dflt;
  vector<Node> t;

  static int midl(int l, int r) {
//    int step = 1 << (31 - __builtin_clz(r - l));
//    return min(l + step, r - step / 2);
    return (l + r) / 2;
  }

  struct UpdateEnv {
    int pos;
    Node val;
    vector<Node>& t;

    Node update(int i, int L, int R) {
      if (R <= pos || L > pos) {
        return t[i];
      } else if (R == L + 1) {
        if constexpr (is_same_v<Update, void>) {
          return t[i] = val;
        } else {
          return Update::operator()(t[i], val);
        }
      }
      int M = midl(L, R);
      return t[i] = combine(update(2 * i + 1, L, M), update(2 * i + 2, M, R));
    }
  };

  Node query(int i, int L, int R, int l, int r) const {
    if (R <= l || L >= r) {
      return dflt;
    } else if (l <= L && R <= r) {
      return t[i];
    }
    int M = midl(L, R);
    return combine(query(2 * i + 1, L, M, l, r), query(2 * i + 2, M, R, l, r));
  }
};

int64_t combine(const int64_t& a, const int64_t& b) {
  return max(a, b);
}

struct Node {
  int64_t maxa, maxb, maxab;
};

inline Node combinen(const Node& l, const Node& r) {
  return {max(l.maxa, r.maxa), max(l.maxb, r.maxb), max({l.maxab, r.maxab, l.maxa + r.maxb})};
}

constexpr int N = 5e5 + 1, M = 3;
int64_t ps[M][N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, q = $;
  for (int i: {0, 1, 2})
  for (auto [j, cur] = pair{1, 0ll}; j <= n; ++j) {
    ps[i][j] = cur += $;
  }
  vector<array<int, 3>> offers(q);
  cin >> offers;
  sort(offers.begin(), offers.end(), Ordering<3, 2>{});
  int64_t minf = -1e18;
  ST<int64_t, combine> pst(1 << 19, minf);
  ST<int64_t, combine> dp(1 << 19, minf);
  ST<Node, combinen> st(1 << 19, {minf, minf, minf});
  ST<Node, combinen> abst(1 << 19, {minf, minf, minf});
  auto up = [](int i) { return ps[0][i + 1] - ps[1][i]; };
  auto down = [&n](int i) { return ps[1][i + 1] + ps[2][n] - ps[2][i]; };
  auto it = offers.begin();
  auto cur = [&it](int i) { return (*it)[i]; };
  for (int i = 0; i < n; ++i) {
    int64_t val = minf;
    auto cup = up(i), cdown = down(i);
    pst.update(i, cup);
    while (it != offers.end() && cur(1) == i + 1) {
      maxi(val, max(dp.query(cur(0) - 2, n), pst.query(cur(0) - 1, n)) - cur(2));
      ++it;
    }
    dp.update(i, val);
    st.update(i, Node{val, cdown, minf});
    abst.update(i, Node{cup, cdown, cup + cdown});
  }
  int64_t ans = minf;
  for (auto [l, r, k]: offers) {
    maxi(ans, max(st.query(l - 2, r).maxab, abst.query(l - 1, r).maxab) - k);
  }
  print(ans);
}