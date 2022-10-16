#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
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
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        ++b;
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
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_scalar_v<decay_t<decltype(a)>>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }
void lshift(auto& first, auto& second, auto&... args) { first = second; if constexpr (sizeof...(args)) lshift(second, args...); } void rshift(auto& first, auto& second, auto&... args) { if constexpr (sizeof...(args)) rshift(second, args...); second = first; }
void lrotate(auto& arg, auto&... args) { auto t = arg; lshift(arg, args...); ([](auto&t)->auto&{return t;}(args), ...) = t; } void rrotate(auto& arg, auto&... args) { auto t = ([](auto&t)->auto&{return t;}(args), ...); rshift(arg, args...); arg = t; }
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;

constexpr int N = 1e5, L = 17;

int a[N];
int binupl[L + 1][N], binupr[L + 1][N];
array<int, 3> qbyr[N];
int tl[N], tr[N], st[N];

struct DSU {
  static constexpr int N = ::N;

  void reset(int n, int* a) {
    fill_n(p, n, -1);
    copy_n(a, n, aggr);
  }

  auto operator[](int v) { return -p[getp(v)]; }
  auto operator[](pair<int, int> vu) { return getp(vu.first) == getp(vu.second); }
  auto operator()(int v) { return getp(v); }
  auto operator()(int v, int u, auto cmp) { return uni(v, u, cmp); }
  auto getaggr(int v) { return aggr[getp(v)]; }

//private:
  int p[N], aggr[N];

  int getp(int v) {
    return p[v] < 0? v: p[v] = getp(p[v]);
  }

  bool uni(int u, int v, auto cmp) {
    if (p[v = getp(v)] < p[u = getp(u)]) {
      swap(u, v);
    }
    if (u == v) {
      return 0;
    }
    p[u] += p[v];
    p[v] = u;
    aggr[u] = aggr[cmp(aggr[u], aggr[v])? u: v];
    return 1;
  }
} dsu;

int cnt[1 << 9];
template <bool rev = 0, int radix = 1 << 9, uint64_t mx = N + 1, uint64_t presorted = 1, typename It, typename Key = GetField<1, 1>>
void radix_sort_lsb(range<It> src, range<It> dst, Key key = {}) {
  if constexpr (radix < mx) {
    static_assert(__builtin_popcount(radix) == 1);
    static_assert(__builtin_popcount(presorted) == 1);
  }
  constexpr bool last = presorted > mx / radix || presorted == mx / radix && mx % radix == 0;
  auto extract = [&key, last](auto x) {
    auto k = key(x) / presorted;
    !last? k %= radix: k;
    return rev? k = radix - 1 - k: k;
  };
  fill_n(cnt, radix, 0);
  for (const auto& x: src) {
    ++cnt[extract(x)];
  }
  for (int i = 0, p = 0; i < radix; ++i) {
    p += exchange(cnt[i], p);
  }
  for (const auto& x: src) {
    dst[cnt[extract(x)]++] = x;
  }
  if constexpr (!last) {
    return radix_sort_lsb<rev, radix, mx, presorted * radix>(dst, src, key);
  } else {
//    copy(dst.begin(), dst.end(), src.begin());
  }
}

template <bool bykey = 0>
void arpa(int* ans, int* a, int nqs, int n, auto cmp) {
  dsu.reset(n, a);
  int cq = 0, stsz = 0;
  for (int i = 0; i < n; ++i) {
    while (stsz && cmp(dsu.aggr[i], dsu.aggr[st[stsz - 1]])) {
      dsu(i, st[--stsz], cmp);
    }
    st[stsz++] = i;
    while (cq < nqs && qbyr[cq][1] == i + 1) {
      ans[bykey? qbyr[cq][2]: cq] = dsu.getaggr(qbyr[cq][0]);
      ++cq;
    }
  }
}

int main() {
  int n, q;
  reader(n, q);
  reader(a, n);
  for (int i = (--a[0], 0); i < n - 1 && (--a[i + 1], 1); ++i) {
    binupl[0][i] = min(a[i], a[i + 1]);
    binupr[0][i] = max(a[i], a[i + 1]);
  }
  for (int l = 0; l < L; ++l) {
    int nqs = 0;
    for (int i = 0; i < n - 1; ++i) {
      qbyr[nqs++] = {binupl[l][i], binupr[l][i], i};
    }
    radix_sort_lsb(range{qbyr, nqs}, range{decltype(+qbyr)(min(tl, st)), nqs}, GetField<3, 2>{});
    arpa<1>(binupl[l + 1], binupl[l], nqs, n - 1, less<>{});
    arpa<1>(binupr[l + 1], binupr[l], nqs, n - 1, greater<>{});
  }
  if (auto tmp = (array<int, 2>*)min(tl, st); reader(&tmp[0][0], 2 * q), 1)
  for (int i = 0; i < q; ++i) {
    qbyr[i] = {tmp[i][0] - 1, tmp[i][1] - 1, i};
    a[i] = -(qbyr[i][0] == 0 && qbyr[i][1] == n - 1);
  }
  int nqs = partition(qbyr, qbyr + q, [](auto q) { return a[q[2]] != -1; }) - qbyr;
  for (int d = L + 1, step = 1 << d; step /= 2, d--; ) {
    nqs = partition(qbyr, qbyr + nqs, [](auto q) { return q[1] > q[0]; }) - qbyr;
    radix_sort_lsb(range{qbyr, nqs}, range{decltype(+qbyr)(min(tl, st)), nqs}, GetField<3, 2>{});
    arpa(tl, binupl[d], nqs, n - 1, less<>{});
    arpa(tr, binupr[d], nqs, n - 1, greater<>{});
    for (int i = 0; i < nqs; ++i) if (int j = qbyr[i][2]; tl[i] || tr[i] < n - 1) {
      a[j] += step;
      qbyr[i] = {tl[i], tr[i], j};
    }
  }
  radix_sort_lsb(range{qbyr, q}, range{decltype(+qbyr)(min(tl, st)), q}, GetField<3, 3>{});
  for (int i = 0; i < q; ++i) {
    print(qbyr[i][1] == qbyr[i][0] && n > 1 || a[i] >= N * 2? -1: a[i] + 1);
  }
}