//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <bitset>
#include <random>
#include <array>
#include <cassert>
#include <cstring>

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
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto&& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 15e4 + 2;

vector<int> to[N];
array<int, 2> eto[N];
int rght[N];
int8_t vis[N];

void markreachr(int s, int n, bool ord = 0) {
  vis[s] = 1 << !ord;
  for (int i = s; i < n; ++i)
  for (auto ord: {0, 1}) if (vis[i] & 1 << !ord)
  for (auto v: to[i]) if (rght[i + 1] >= v && !(vis[v] & 1 << ord)) {
    vis[v] |= 1 << ord;
  }
}

void markreachl(int s, bool ord = 0) {
  vis[s] = 1 << !ord;
  for (int i = s - 1; i; --i)
  for (auto ord: {0, 1}) {
    bool vi = 0;
    for (auto v: to[i]) if (rght[i + 1] >= v && (vis[v] & 1 << ord)) {
      vi = 1;
      break;
    }
    if (vi) {
      vis[i] |= 1 << !ord;
    }
  }
}

int main() {
  for (int testcase = $; testcase; --testcase) {
    int n = $ + 2, m = $;
    for (int i = 0; i < n; ++i) {
      rght[i] = i + (i == 0 || i == n - 2);
      to[i].clear();
    }
    memset(vis, 0, sizeof vis);
    reader(&eto[0][0], 2 * m);
//    assert(m < 30 || is_sorted(eto, eto + m));
    for (int i = 0; i < m; ++i) {
      auto [a, b] = eto[i];
      if (b == a + 1) {
        rght[a] = b;
      } else {
        to[a].push_back(b - 1);;
      }
    }
    int s = -1;
    for (int i = n - 1; i--; ) {
      rght[i] = rght[i] == i + 1? rght[i + 1]: rght[s = i];
    }
    if (s == -1) {
      print((n - 2) * (n - 3ll) / 2);
      continue;
    }
    markreachl(s);
    markreachr(s, n);
    int cnt[2][4]{};
    for (int i = 1; i <= rght[0]; ++i) {
      ++cnt[0][vis[i]];
    }
    {
      int lb = s;
      while (rght[lb + 1] < n - 1) {
        ++lb;
      }
      for (int i = lb; i < n - 2; ++i) {
        ++cnt[1][vis[i]];
      }
    }
    cnt[0][1] += cnt[0][3];
    cnt[0][2] += cnt[0][3];
    cnt[1][1] += cnt[1][3];
    cnt[1][2] += cnt[1][3];
    print((cnt[0][1] + !!cnt[0][2]) * int64_t(cnt[1][1] + !!cnt[1][2]) +
          (cnt[0][2] + !!cnt[0][1]) * int64_t(cnt[1][2] + !!cnt[1][1]) -
          (cnt[0][3] + !!cnt[0][1] * !!cnt[0][2]) * int64_t(cnt[1][3] + !!cnt[1][1] * !!cnt[1][2]) -
          (rght[0] == s && rght[s + 1] == n - 1));
  }
}