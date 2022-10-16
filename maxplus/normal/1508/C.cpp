//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <bitset>
#include <vector>
#include <array>
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
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 2e5 + 1;

#include <utility>
struct DSU {
  static constexpr int N = ::N;

  DSU() {
    for (int i = 0; i < N; ++i) {
      p[i] = -1;
    }
  }

  auto operator[](int v) { return -p[getp(v)]; }
  auto operator[](pair<int, int> vu) { return getp(vu.first) == getp(vu.second); }
  auto operator()(int v) { return getp(v); }
  auto operator()(int v, int u) { return uni(v, u); }

private:
  int p[N];

  int getp(int v) {
    return p[v] < 0? v: p[v] = getp(p[v]);
  }

  bool uni(int u, int v) {
    if (p[v = getp(v)] < p[u = getp(u)]) {
      swap(u, v);
    }
    if (u == v) {
      return 0;
    }
    p[u] += p[v];
    p[v] = u;
    return 1;
  }
} unassigned, assigned;

#include <chrono>
struct Hash {
  static uint64_t& global_seed() { static uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count(); return global_seed; }

  Hash(uint64_t seed = 0) : seed{seed += global_seed() += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint64_t x) const {
    x += seed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  const uint64_t seed;
};

struct piihash {
  Hash h;

  auto operator()(const auto& pii) const {
    return h(int64_t(pii.first) << 32 ^ pii.second);
  }
};

struct Bloom {
  static constexpr int am = 2;
  static constexpr int sz = 1e7 + 13;
  using T = pair<int, int>;
  using H = piihash;

  bitset<sz> a[am];
  H h[am];

  void insert(const T& v) {
    for (int i = 0; i < am; ++i) {
      a[i][h[i](v) % sz] = 1;
    }
  }

  bool contains(const T& v) const {
    return a[0][h[0](v) % sz] && a[1][h[1](v) % sz];
  }
};

struct EList {
  int nxt[N];
  DSU dsu;

  void fill(int n) { iota(nxt, nxt + n + 1, 0); }

  int getnext(int x) { return nxt[dsu(x)]; }

  void rm(int x) { auto t = nxt[dsu(x + 1)]; dsu(x, x + 1); nxt[dsu(x)] = t; }
} tovis;

Bloom nei;
vector<array<int, 3>> edges;
int n;

void dfs(int v) {
  for (int u = 0; (u = tovis.getnext(u)) < n; ) {
    if (!nei.contains({min(u, v), max(u, v)})) {
      tovis.rm(u);
      unassigned(u, v);
      dfs(u);
    } else {
      ++u;
    }
  }
}

int main() {
  int n = ::n = $, m = $, x = 0;
  tovis.fill(n);
  for (int i = 0; i < m; ++i) {
    int a = $ - 1, b = $ - 1, w = $;
    if (a > b) {
      swap(a, b);
    }
    nei.insert({a, b});
    edges.push_back(array{w, a, b});
    x ^= w;
  }
  sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
  int c = 0;
  for (int i = 0; i < n; i = tovis.getnext(i)) {
    tovis.rm(i);
    dfs(i);
    ++c;
  }
  if (n - c < n * (n - 1ll) / 2 - m) {
    x = 0;
  }
  int64_t ans = 0;
  for (auto [w, u, v]: edges) {
    if (unassigned(u, v)) {
      ans += w;
      assigned(u, v);
    } else if (w < x && assigned(u, v)) {
      x = w;
    }
  }
  cout << ans + x << '\n';
}