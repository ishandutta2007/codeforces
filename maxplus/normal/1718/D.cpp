#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"

#include <cstdio>
#include <cstring>

#include <iterator>
#include <type_traits>

#include "immintrin.h"

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

struct { using X = int; template <typename T = X> T operator()() const { T t; reader(t); return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } } $;
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } constexpr auto reversed() const { return range<reverse_iterator<It>>{reverse_iterator(end()), reverse_iterator(begin())}; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_same_v<decay_t<decltype(a)>, int>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return maxi(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }

constexpr int N = 3e5, B = 1e6;
int n, par[N], a[N];

struct Arr2 {
  int a, b;

  int& operator[](int i) {
    return i? b: a;
  }
};

Arr2 bounds[N];

template <typename T>
struct StaticVector {
  T body[N];
  int sz;

  T& operator[](int i) { return body[i]; }
  auto begin() { return body; }
  auto end() { return body + sz; }
  auto rbegin() { return reverse_iterator(end()); }
  auto rend() { return reverse_iterator(begin()); }
  int size() { return sz; }
  void clear() { sz = 0; }
  void push_back(T x) { body[sz++] = x; }
  void pop_back() { --sz; }
  T& back() { return body[sz - 1]; }
};

StaticVector<Arr2> todo;
constexpr auto& ch = todo.body;

void calcbounds(int v) {
  bounds[v][1] = B;
  int u = ch[v][0];
  while (1) {
    if (u != -1) {
      bounds[u][1] = min(bounds[v][1], a[v]?:B);
      v = u;
      u = ch[v][0];
    } else if (int p = par[v]; p != -1) {
      maxi(bounds[p][0], max(bounds[v][0], a[v]));
      u = v == ch[p][1]? -1: ch[p][1];
      v = p;
    } else {
      break;
    }
  }
}

StaticVector<int> s;

struct DSU {
  static constexpr int N = ::N + 1;

  void reset(int n) {
    memset(p, -1, n * sizeof *p);
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
};

struct EList {
  int nxt[N];
  DSU dsu;

  void fill(int n) { for (int i = 0; i <= n; ++i) nxt[i] = i; dsu.reset(n + 1); }

  int getnext(int x) { return nxt[dsu(x)]; }

  void rm(int x) { auto t = nxt[dsu(x + 1)]; dsu(x, x + 1); nxt[dsu(x)] = t; }
} available;

int compress[B + 1];
StaticVector<int> expand;

int mind() {
  available.fill(s.size());
  expand.sz = s.size();
  for (int i = 0; i < s.size(); ++i) {
    expand[s.size() - i - 1] = s[i];
  }
  if (int i = s.size())
  for (auto [l, r]: range{bounds, todo.size()}) {
    while (i && r >= expand[i - 1]) --i;
    compress[r] = i;
  }
  for (auto [l, r]: todo) {
    if (auto it = available.getnext(compress[r]); it == s.size() || expand[it] < l) {
      return l;
    } else {
      available.rm(it);
    }
  }
  __builtin_unreachable();
}

bool f;

int maxd() {
  available.fill(s.size());
  expand.sz = s.size();
  for (int i = 0; i < s.size(); ++i) {
    expand[i] = s[i];
  }
  if (int i = s.size())
  for (auto [l, r]: todo) {
    while (i && l <= expand[i - 1]) --i;
    compress[l] = i;
  }
  int res = -1;
  for (auto [l, r]: range{bounds, todo.size()}) {
    if (auto it = available.getnext(compress[l]); it == s.size() || expand[it] > r) {
      f = res == -1;
      res = r;
    } else {
      available.rm(it);
    }
  }
  return res;
}

template <int dir>
void connect() {
  constexpr auto& st = expand;
  st.clear();
  for (int i = dir == 1? 0: n - 1, e = n - 1 - i + dir; i != e; i += dir) {
    while (st.size() && s[st.back()] < s[i]) {
      st.pop_back();
    }
    if (st.size() && (par[i] == -1 || s[st.back()] < s[par[i]])) {
      par[i] = st.back();
    }
    st.push_back(i);
  }
}

void buildheap() {
  connect<1>();
  connect<-1>();
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    if (par[i] == -1) {
      mx = i;
    } else {
      ch[par[i]][ch[par[i]][0] != -1] = i;
    }
  }
  calcbounds(mx);
}

template <bool rev, int radix = 1 << 10, int mx = 1 << 20, int presorted = 1, typename It>
void radix_sort_lsb(range<It> src, range<It> dst, auto key) {
  static_assert(__builtin_popcount(radix) == 1);
  static_assert(__builtin_popcount(mx) == 1);
  static_assert(__builtin_popcount(presorted) == 1);
  int cnt[1024]{};
  for (const auto& x: src) {
    int k = key(x) / presorted % radix;
    if (rev) k = radix - 1 - k;
    ++cnt[k];
  }
  if (int p = 0; 1)
  for (int i = 0; i < radix; ++i) {
    int t = p;
    p += cnt[i];
    cnt[i] = t;
  }
  for (const auto& x: src) {
    int k = key(x) / presorted % radix;
    if (rev) k = radix - 1 - k;
    dst[cnt[k]++] = x;
  }
  if constexpr (presorted * radix < mx) {
    return radix_sort_lsb<rev, radix, mx, presorted * radix>(dst, src, key);
  }
}

char ans_[4 * N], *ans = ans_;

void NO() {
  *(ans++) = 'N';
  *(ans++) = 'O';
  *(ans++) = ' ';
}

void YES() {
  *(ans++) = 'Y';
  *(ans++) = 'E';
  *(ans++) = 'S';
  *(ans++) = ' ';
}

int main() {
  for (int testcases = $, testcase = 0; testcase++ < testcases; ) {
    n = $;
    int q = $, k = 0;
    s.sz = n;
    reader(&s[0], n);
    reader(a, n);
    memset(ch, -1, n * sizeof *ch);
    memset(par, -1, n * sizeof *par);
    for (int i = 0; i < n; ++i) {
      bounds[i] = {1, 0};
      k += !a[i];
    }
    buildheap();
    s.sz = k - 1;
    reader(&s[0], k - 1);
    bool ok = 1;
    todo.sz = 0;
    for (int i = 0; i < n; ++i) {
      auto [lb, ub] = bounds[i];
      if (a[i]) {
        maxi(lb, a[i]);
        mini(ub, a[i]);
      } else {
        todo.push_back({lb, ub});
      }
      ok &= lb <= ub;
    }
    if (!ok) {
      reader(par, q);
      while (q--) {
        NO();
      }
      continue;
    }
    radix_sort_lsb<0>(range{s}, range{par, s.size()}, GetField<1, 1>{});
    radix_sort_lsb<1>(range{todo}, range{bounds, todo.size()}, GetField<2, 1>{});
    radix_sort_lsb<0>(range{bounds, todo.size()}, range{(Arr2*)min(a, par), todo.size()}, GetField<2, 2>{});
    f = 1;
    int l = mind();
    int r = maxd();
    reader(a, q);
    for (auto d: range{a, q}) {
      l <= d && d <= r && f? YES(): NO();
    }
  }
  fwrite(ans_, 1, ans - ans_, stdout);
}