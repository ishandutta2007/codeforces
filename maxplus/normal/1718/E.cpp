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
#include <random>
#include <unordered_map>

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

constexpr int N = 2e5 + 1, W = __builtin_sqrt(N), h = 2e5 + 3;
constexpr uint64_t mod = 61489146912377;

uint64_t splimix(uint64_t x) {
  static auto seed = 0x9e3779b97f4a7c15 + uint64_t(new char);
  x += seed;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x;
}

struct Table {
  int body[N];
  int w;

  int* operator[](int i) { return body + w * i; }
} a[2], ta[2];

bool uc[2][W];
int rmap[N], cmap[W];
uint64_t hp[N];
uint64_t fp[N];
uint64_t ruh[2][N], roh[2][N], rth[2][N];
vector<pair<uint64_t, int>> cfp[2];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int r = $, c = $;
  bool swp = r < c;
  a[0].w = a[1].w = swp? r: c;
  ta[0].w = ta[1].w = r ^ c ^ a[0].w;
  for (auto t: {0, 1})
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    (swp? a[t][j][i]: a[t][i][j]) = $;
  }
  if (swp) {
    swap(r, c);
  }
  if (uint64_t cp = 1)
  for (int i = 0; i < N; ++i) {
    hp[i] = (cp *= h) % mod;
  }
  generate(fp + 1, fp + N, mt19937_64{uint64_t(new char)});
  for (auto t: {0, 1})
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    ruh[t][i] ^= fp[a[t][i][j]];
    ta[t][j][i] = fp[a[t][i][j]] * 2;
  }
  bool ok = 1;
  int mc = 0;
  while (mc < c) {
    for (auto t: {0, 1})
    for (int j = 0; j < c; ++j) if (!uc[t][j]) {
      uint64_t d[8]{};
      for (int i = 0; i < r; )
      #pragma GCC ivdep
      for (int k = 0, e = min(8, r - i); k < e; ++k, ++i) {
        d[k] += rth[t][i] ^ ta[t][j][i];
      }
      cfp[t].emplace_back(accumulate(d, end(d), 0ull), j);
    }
    sort(cfp[0].begin(), cfp[0].end());
    sort(cfp[1].begin(), cfp[1].end());
    vector<int> u[2];
    uint64_t ms = 0, mk = -1, cnt = 0;
    if (uint64_t lk = cfp[0][0].first; 1)
    for (int i = 1, cnt = 1; i <= c - mc; ++i) {
      if (i == c - mc) {
        if (cnt == 1) {
          u[0].push_back(cfp[0][i - 1].second);
          u[1].push_back(cfp[1][i - 1].second);
        } else if (maxb(ms, cnt)) {
          mk = lk;
        }
        break;
      }
      auto ck = cfp[0][i].first;
      if (ck != cfp[1][i].first) {
        ok = 0;
        break;
      } else if (lk == ck) {
        ++cnt;
        continue;
      } else if (cnt == 1) {
        u[0].push_back(cfp[0][i - 1].second);
        u[1].push_back(cfp[1][i - 1].second);
      } else if (maxb(ms, cnt)) {
        mk = lk;
      }
      lk = ck;
      cnt = 1;
    }
    if (u[0].empty()) {
      for (int i = 0; i < c - mc; ++i) if (cfp[0][i].first == mk) {
        u[0].push_back(cfp[0][i].second);
        u[1].push_back(cfp[1][i].second);
      }
    }
    cfp[0].clear(), cfp[1].clear();
    if (u[0].empty() || !ok) {
      break;
    }
    mc += u[0].size();
    for (int i = 0; i < u[0].size(); ++i) {
      int j[2]{u[0][i], u[1][i]};
      cmap[j[0]] = j[1];
      uc[0][j[0]] = uc[1][j[1]] = 1;
      for (auto t: {0, 1})
      for (int i = 0; i < r; ++i) {
        ruh[t][i] ^= fp[a[t][i][j[t]]];
        (roh[t][i] += a[t][i][j[t]] * hp[j[1]]) %= mod;
        rth[t][i] = ruh[t][i] ^ roh[t][i];
      }
    }
  }
  for (auto t: {0, 1})
  for (int i = 0; i < r; ++i) {
    cfp[t].emplace_back(rth[t][i], i);
  }
  sort(cfp[0].begin(), cfp[0].end());
  sort(cfp[1].begin(), cfp[1].end());
  for (int i = 0; i < r; ++i) {
    ok &= cfp[0][i].first == cfp[1][i].first;
    rmap[cfp[0][i].second] = cfp[1][i].second;
  }
  if (!ok) {
    print(-1);
    return 0;
  }
  vector<pair<int, int>> rswap, cswap;
  for (int i = 0; i < r; ++i) if (rmap[i] != -1) {
    int j = i;
    while (rmap[j] != -1) {
      rswap.emplace_back(j, rmap[j]);
      j = exchange(rmap[j], -1);
    }
    rswap.pop_back();
  }
  for (int i = 0; i < c; ++i) if (cmap[i] != -1) {
    int j = i;
    while (cmap[j] != -1) {
      cswap.emplace_back(j, cmap[j]);
      j = exchange(cmap[j], -1);
    }
    cswap.pop_back();
  }
  print(rswap.size() + cswap.size());
  reverse(rswap.begin(), rswap.end());
  reverse(cswap.begin(), cswap.end());
  for (auto [r1, r2]: rswap) {
    print(1 + swp, r1 + 1, r2 + 1);
  }
  for (auto [c1, c2]: cswap) {
    print(2 - swp, c1 + 1, c2 + 1);
  }
}