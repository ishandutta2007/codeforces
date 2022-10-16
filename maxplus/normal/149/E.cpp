//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <set>

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

constexpr int N = 1e5 + 1, L = 9;
int spt[L][N], rspt[L][N];
int sa[N], rsa[N];
vector<int> c(N), rc(N);

void calcsa(auto sa, auto& c, string s) {
  s += '$';
  vector<int> c_(N), cnt(N), sa_(N);
  fill_n(cnt.begin(), 'Z' - '$' + 1, 0);
  for (int i = 0; i < s.size(); ++i) {
    ++cnt[s[i] - '$'];
  }
  for (int i = 0, p = 0; i <= 'Z' - '$'; ++i) {
    p = cnt[i] += p;
  }
  for (int i = 0; i < s.size(); ++i) {
    sa[--cnt[s[i] - '$']] = i;
  }
  int nc = -1;
  for (int i = 0, pc = -1; i < s.size(); ++i) {
    c[sa[i]] = nc += !!change(pc, s[sa[i]]);
  }
  ++nc;
  for (int l = 0; 1 << l < s.size() && nc < s.size(); ++l) {
    for (int i = 0; i < s.size(); ++i) {
      int t = sa[i] - (1 << l);
      if (t < 0) {
        t += s.size();
      }
      sa_[i] = t;
    }
    fill_n(cnt.begin(), nc, 0);
    for (int i = 0; i < s.size(); ++i) {
      ++cnt[c[i]];
    }
    for (int i = 0, p = 0; i < nc; ++i) {
      p = cnt[i] += p;
    }
    for (int i = s.size(); i--; ) {
      sa[--cnt[c[sa_[i]]]] = sa_[i];
    }
    pair<int, int> prv{-1, -1};
    auto pnc = nc;
    nc = -1;
    for (int i = 0; i < s.size(); ++i) {
      int r = sa[i] + (1 << l);
      if (r >= s.size()){
        r -= s.size();
      }
      if (prv != pair{c[sa[i]], c[r]}) {
        prv = pair{c[sa[i]], c[r]};
        ++nc;
      }
      c_[sa[i]] = nc;
    }
    swap(c, c_);
    ++nc;
    if (nc == pnc) break;
  }
  copy(sa + 1, sa + s.size(), sa);
}

template <auto src, auto dst>
void calcspt(int n) {
  copy(src, src + n, dst[0]);
  for (int l = 0; 1 << 2 * l + 2 <= n; ++l)
  for (int i = 0; i <= n - (3 << 2 * l); ++i) {
    dst[l + 1][i] = min(min(dst[l][i], dst[l][i + (1 << 2 * l)]), min(dst[l][i + (2 << 2 * l)], dst[l][i + (3 << 2 * l)]));
  }
}

template <auto spt>
int queryspt(int l, int r) {
  int L = 31 - __builtin_clz(r - l) >> 1;
  int d = 1 << L * 2;
  int res = min(spt[L][l], spt[L][r - d]);
  if (r - l > d * 2) {
    mini(res, min(spt[L][l + d], spt[L][r - 2 * d]));
  }
  return res;
}

auto lazy_partition_left(auto l, auto r, auto pfunc) {
  int s = 1;
  #pragma GCC unroll 8
  while (l + s < r) {
    if (pfunc(l[s])) {
      s *= 2;
    } else {
      r = l + s;
      break;
    }
  }
  return partition_point(l, r, pfunc);
}

auto lazy_partition_right(auto l, auto r, auto pfunc) {
  int s = 1;
  #pragma GCC unroll 8
  while (l + s < r) {
    if (pfunc(r[-s])) {
      l = r - s;
      break;
    } else {
      s *= 2;
    }
  }
  return partition_point(l, r, pfunc);
}

int tmp[N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  string t = $, rt{t.rbegin(), t.rend()};
  calcsa(sa, c, t);
  calcspt<sa, spt>(t.size());
  calcsa(rsa, rc, {t.rbegin(), t.rend()});
  calcspt<rsa, rspt>(t.size());
  int n = $, ans = 0;
  while (n--) {
    string p = $, rp{p.rbegin(), p.rend()};
    if (p.size() == 1) {
      continue;
    }
    for (int i = 0, l = 0, r = t.size(), nol = 0, nor = 0; i < p.size() - 1; ++i) {
      if (r <= l) {
        tmp[i] = 1e9;
        continue;
      }
      if (!change(nol, 0)) {
        l = lazy_partition_left(sa + l, sa + r, [&](int k) {
          return k >= t.size() - i || t[k + i] < p[i];
        }) - sa;
      }
      if (!change(nor, 0)) {
        r = lazy_partition_right(sa + l, sa + r, [&](int k) {
          return k < t.size() - i && t[k + i] == p[i];
        }) - sa;
      }
      if (r <= l) {
        tmp[i] = 1e9;
        continue;
      }
      auto cur = queryspt<spt>(l, r);
      int j = i;
      while (i < p.size() - 2 && cur < t.size() - i - 1 && t[cur + i + 1] == p[i + 1]) {
        tmp[i++] = cur;
      }
      tmp[i] = cur;
      if (cur < t.size() - i - 1 && t[cur + i + 1] > p[i + 1]) {
        r = c[cur] - 1;
        while (l < r && ++j <= i) {
          l = lazy_partition_left(sa + l, sa + r, [&](int k) {
            return k >= t.size() - j || t[k + j] < p[j];
          }) - sa;
        }
      } else if (cur >= t.size() - i - 1 || t[cur + i + 1] < p[i + 1]) {
        l = c[cur];
        while (l < r && ++j <= i) {
          r = lazy_partition_right(sa + l, sa + r, [&](int k) {
            return k < t.size() - j && t[k + j] == p[j];
          }) - sa;
        }
      }
    }
    bool ok = 0;
    for (int i = 0, mn = 1e9, l = 0, r = t.size(), nol = 0, nor = 0; i < p.size() - 1; ++i) {
      if (r <= l) {
        break;
      }
      if (!change(nol, 0)) {
        l = lazy_partition_left(rsa + l, rsa + r, [&](int k) {
          return k >= t.size() - i || rt[k + i] < rp[i];
        }) - rsa;
      }
      if (!change(nor, 0)) {
        r = lazy_partition_right(rsa + l, rsa + r, [&](int k) {
          return k < t.size() - i && rt[k + i] == rp[i];
        }) - rsa;
      }
      if (r <= l) {
        break;
      }
      auto cur = queryspt<rspt>(l, r);
      int j = i;
      while (i < p.size() - 2 && cur < t.size() - i - 1 && rt[cur + i + 1] == rp[i + 1]) {
        mini(mn, tmp[p.size() - i++ - 2]);
      }
      mini(mn, tmp[p.size() - i - 2]);
      ok |= cur + mn + p.size() <= t.size();
      if (cur < rt.size() - i - 1 && rt[cur + i + 1] > rp[i + 1]) {
        r = rc[cur] - 1;
        while (l < r && ++j <= i) {
          l = lazy_partition_left(rsa + l, rsa + r, [&](int k) {
            return k >= rt.size() - j || rt[k + j] < rp[j];
          }) - rsa;
        }
      } else if (cur >= rt.size() - i - 1 || rt[cur + i + 1] < rp[i + 1]) {
        l = rc[cur];
        while (l < r && ++j <= i) {
          r = lazy_partition_right(rsa + l, rsa + r, [&](int k) {
            return k < rt.size() - j && rt[k + j] == rp[j];
          }) - rsa;
        }
      }
    }
    ans += ok;
  }
  print(ans);
}