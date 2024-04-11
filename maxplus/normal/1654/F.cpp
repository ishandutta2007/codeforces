//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <tuple>

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

constexpr int N = 1 << 18, M = 1 << 12;
string s;

template <int lvl>
string trans(int l, int j) {
  string res(lvl, '\0');
  auto s = ::s.begin() + l;
  for (int i = 0; i < lvl; ++i) {
    res[i] = s[i ^ j];
  }
  return res;
}

template <int lvl>
int transcmp(int l, int j1, int j2) {
  auto s = ::s.begin() + l;
  j1 %= lvl, j2 %= lvl;
  for (int i = 0; i < lvl; ++i) if (auto d = s[i ^ j1] - s[i ^ j2]) {
    return d >> 31 << 1 | 1;
  }
  return 0;
}

template <int lvl, int sz = lvl? N / lvl: 0>
auto storage() {
  static bool graded[sz];
  static array<int16_t, lvl> grade[sz];
  static array<int16_t, lvl> sorted[sz];
  return tie(graded, grade, sorted);
}

template <int lvl>
const auto& maybe_grade(int l) {
  auto [graded, grade, sorted] = storage<lvl>();
  int idx = l / lvl;
  if (graded[idx] || lvl == 1) {
    return grade[idx];
  }
  graded[idx] = 1;
  static array<int, lvl / 2> csorted0, csorted1, cgrade0, cgrade1;
  auto resort = [&](auto& gradef, auto& grades, auto& sorted, auto& csorted, auto& cgrade) {
    for (int i = 0, lst = 0, pgf = 0; ; ++i) {
      if (i == lvl / 2 || gradef[sorted[i]] != pgf) {
        sort(&csorted[lst], &csorted[i], [&](int a, int b) { return grades[a] < grades[b]; });
        if (i == lvl / 2) {
          break;
        }
        pgf = gradef[sorted[i]];
        lst = i;
      }
      csorted[i] = sorted[i];
    }
    for (int i = 0, cg = -1, pgf = 0, pgs = -1; i < lvl / 2; ++i) {
      int j = csorted[i];
      if (gradef[j] != pgf || grades[j] != pgs) {
        pgf = gradef[j];
        pgs = grades[j];
        ++cg;
      }
      cgrade[j] = cg;
    }
  };
  {
    auto& grade0 = maybe_grade<lvl / 2>(l), & grade1 = maybe_grade<lvl / 2>(l + lvl / 2);
    auto& sorted0 = get<2>(storage<lvl / 2>())[idx * 2], & sorted1 = get<2>(storage<lvl / 2>())[idx * 2 + 1];
    resort(grade0, grade1, sorted0, csorted0, cgrade0);
    resort(grade1, grade0, sorted1, csorted1, cgrade1);
  }
  {
    auto& cgrade = grade[idx], & csorted = sorted[idx];
    for (int i0 = 0, i1 = 0, i = 0, cg = 0; i < lvl; ) {
      auto grab = [&](const auto& grade, const auto& sorted, int& start, int offset) {
        int tg = grade[sorted[start]];
        do {
          csorted[i++] = sorted[start] + offset;
          cgrade[sorted[start++] + offset] = cg;
        } while (start < lvl / 2 && grade[sorted[start]] == tg);
      };
      auto grab0 = [&]() { return grab(cgrade0, csorted0, i0, 0); };
      auto grab1 = [&]() { return grab(cgrade1, csorted1, i1, lvl / 2); };
      if (i0 == lvl / 2) {
        grab1();
      } else if (i1 == lvl / 2) {
        grab0();
      } else {
        auto cmp = transcmp<lvl>(l, csorted0[i0], csorted1[i1] + lvl / 2);
        if (cmp <= 0) grab0();
        if (cmp >= 0) grab1();
      }
      ++cg;
    }
    return cgrade;
  }
}

using Range = range<int*>;

template <int lvl>
Range gradebest(int l, Range from) {
  auto& cgrade = maybe_grade<lvl>(l);
  int best = cgrade[from[0] % lvl], ch = 0;
  for (auto j: from) if (cgrade[j % lvl] != best) {
    mini(best, cgrade[j % lvl]);
    ch = 1;
  }
  if (ch) from.last = remove_if(from.begin(), from.end(), [&](int j) { return cgrade[j % lvl] != best; });;
  return from;
}

template <int lvl>
Range askbest(int l, Range from) {
  if (from.size() <= 1) {
    return from;
  }
  if constexpr (lvl <= M) {
    return gradebest<lvl>(l, from);
  } else {
    auto mid = partition_point(from.begin(), from.end(), [](int j) { return !(j & lvl / 2); });
    auto bl = askbest<lvl / 2>(l + lvl / 2, askbest<lvl / 2>(l, {from.begin(), mid}));
    auto br = askbest<lvl / 2>(l, askbest<lvl / 2>(l + lvl / 2, {mid, from.end()}));
    switch (mid == from.begin()? 1: mid == from.end()? -1: transcmp<lvl>(l, bl[0], br[0])) {
    case  1: return br;
    case  0: bl.last = br.begin() != bl.end()? copy(br.begin(), br.end(), bl.end()): br.end(); [[fallthrough]];
    default: return bl;
    }
  }
}

template <int lvl = N>
string solve() {
  if (s.size() == lvl) {
    vector<int> js(lvl);
    iota(js.begin(), js.end(), 0);
    return trans<lvl>(0, askbest<lvl>(0, {js.data(), lvl})[0]);
  } else {
    return solve<lvl / 2>();
  }
}

int main() {
  s.resize(1 << $);
  getchar();
  fread(s.data(), 1, s.size(), stdin);
  cout << solve();
}