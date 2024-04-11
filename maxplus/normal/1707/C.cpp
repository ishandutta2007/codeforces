//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
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
struct { using X = int; template <typename T = X> T operator()() const { T t; reader(t); return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } } $;
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

constexpr int N = 1e5 + 1;
int tin[N], tout[N], goodness[N], t;
vector<int> nei[N];
vector<int> bads[N];
int p[N];

void calct(int v, int p = -1) {
  ::p[v] = p;
  tin[v] = t++;
  for (auto u: nei[v]) if (u != p) {
    calct(u, v);
  }
  tout[v] = t;
}

struct DSU {
  int p[N], w[N];

  DSU() {
    iota(p, p + N, 0);
    fill(w, w + N, 1);
  }

  int getp(int v) { return v == p[v]? v: p[v] = getp(p[v]); }

  bool uni(int u, int v) {
    u = getp(u), v = getp(v);
    if (w[u] < w[v]) {
      swap(u, v);
    }
    if (u == v) {
      return 0;
    }
    p[v] = u;
    w[u] += w[v];
    return 1;
  }
} dsu;

int main() {
  int n = $, m = $;
  vector<array<int, 2>> edges;
  for (int i = 0; i < m; ++i) {
    int a = $ - 1, b = $ - 1;
    if (dsu.uni(a, b)) {
      nei[a].push_back(b);
      nei[b].push_back(a);
    } else {
      edges.push_back({a, b});
    }
  }
  calct(0);
  for (auto [a, b]: edges) {
    if (tin[a] > tin[b]) {
      swap(a, b);
    }
    ++goodness[tin[b]], --goodness[tout[b]];
    if (tout[a] >= tout[b]) {
      bads[a].push_back(tin[b]);
    } else {
      ++goodness[tin[a]], --goodness[tout[a]];
      --goodness[0];
    }
  }
  vector<array<int, 2>> loc;
  for (int i = 0; i < n; ++i) if (bads[i].size()) {
    loc.clear();
    auto lb = [&](int x) { return lower_bound(loc.begin(), loc.end(), array{x, 0}); };
    auto get = [&](int x) -> auto& { return lb(x)[0][1]; };
    for (auto j: bads[i]) {
      loc.push_back({j, 1});
    }
    sort(loc.begin(), loc.end());
    auto w = loc.begin(), r = w;
    while (++r != loc.end()) {
      if (w[0][0] == r[0][0]) {
        ++w[0][1];
      } else {
        w++[1][0] = r[0][0];
      }
    }
    loc.erase(w + 1, loc.end());
    loc.push_back({N, 0});
    for (int tc: {0})
    for (auto& [k, v]: loc) {
      tc += exchange(v, tc);
    }
    for (auto u: nei[i]) if (u != p[i]) {
      int d = get(tout[u]) - get(tin[u]);
      goodness[tin[u]] -= d;
      goodness[tout[u]] += d;
    }
  }
  partial_sum(goodness, goodness + n + 1, goodness);
  for (int i = 0; i < n; ++i) {
    cout << !goodness[tin[i]];
  }
  print();
}