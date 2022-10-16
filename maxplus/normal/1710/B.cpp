//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>
#include <array>
#include <map>
#include <cmath>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } string operator~() const { return *this; } char operator!() const { return *this; } } $;
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
//template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

constexpr int N = 2e5 + 5, L = 18;
int64_t sptl[L][N], sptm[L][N], sptr[L][N], n, m;
array<int, 2> xp[N];

template <auto a>
void spt() {
  for (int l = 0; l < L - 1; ++l)
  for (int i = 0; i < n; ++i) {
    a[l + 1][i] = max(a[l][i], i + (1 << l) < n? a[l][i + (1 << l)]: 0);
  }
}

template <auto a>
int64_t getmx(int l, int r) {
  if (r == l) {
    return -4e9;
  }
  int L = 31 - __builtin_clz(r - l);
  return max(a[L][l], a[L][r - (1 << L)]);
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  for (int testcases = $, testcase = 0; testcase++ < testcases; ) {
    n = $, m = $;
    int n0 = n;
    cin >> range{&xp[0][0], 2 * n};
    map<int, int64_t> delta;
    map<int, int64_t> val;
    map<int, int> id;
    for (auto [x, p]: range{xp, n}) {
      ++delta[x - p];
      ----delta[x];
      ++delta[x + p];
      val[x];
    }
    int64_t cur = 0, last = -1e9, cd = 0;
    for (auto [x, d]: delta) {
      cur += cd * change(last, x);
      cd += d;
      if (val.count(x)) {
        val[x] = cur;
      }
    }
    int idx = 1;
    for (auto [x, v]: val) {
      sptl[0][idx] = v - x;
      sptm[0][idx] = v;
      sptr[0][idx] = v + x;
      id[x] = idx++;
    }
    sptl[0][0] = sptl[0][idx] = 0;
    sptm[0][0] = sptm[0][idx] = 0;
    sptr[0][0] = sptr[0][idx] = 0;
    id[(int)-1e9] = 0;
    id[(int)2e9 + 1] = idx++;
    n = idx;
    spt<sptl>();
    spt<sptm>();
    spt<sptr>();
    auto getid = [&](int x) { return id.lower_bound(x)->second; };
    for (auto [x, p]: range{xp, n0}) {
      int l = getid(x - p);
      int i = id[x];
      int r = getid(x + p);
      int64_t cur = 0;
      maxi(cur, getmx<sptm>(0, l));
      maxi(cur, getmx<sptm>(r, n));
      maxi(cur, getmx<sptl>(l, i) + x - p);
      maxi(cur, getmx<sptr>(i, r) - x - p);
      cout << (cur <= m);
    }
    print();
  }
}