//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <vector>
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
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class NoErrorPls = void> string operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 2e5, mod = 1e9 + 7;

int ft[N], a[N], bdp[N], n, m;
bool bad[N];

int& add(int& a, int b) {
  return (a += b) %= mod;
}

void upd(int i, int d) {
  for (; i < m; i |= i + 1) {
    add(ft[i], d);
  }
}

int ask(int i) {
  int res = 1;
  for (; i; i &= i - 1) {
    add(res, ft[i - 1]);
  }
  return res;
}

vector<int> gr[N], sm;

int main() {
  for (int testcase = $; testcase; --testcase) {
    n = $, m = n;
    reader(a, n);
    memcpy(ft, a, n * sizeof *a);
    sort(ft, ft + n);
    m = unique(ft, ft + n) - ft;
    for (auto& i: range{a, n}) {
      i = lower_bound(ft, ft + m, i) - ft;
    }
    sm.clear();
    for (int i = n, ma = -1; i--; ) {
      if (maxb(ma, a[i])) {
        gr[sm.size()].clear();
        sm.push_back(a[i]);
        bad[i] = 1;
      } else if (auto grn = upper_bound(sm.begin(), sm.end(), a[i]) - sm.begin(); grn != sm.size()) {
        gr[grn].push_back(i);
        bad[i] = 0;
      } else {
        bad[i] = 1;
      }
    }
    memset(ft, 0, m * sizeof *ft);
    for (int i = n; i--; ) {
      upd(m - a[i] - 1, bdp[i] = ask(m - a[i] - 1));
    }
    memset(ft, 0, m * sizeof *ft);
    for (int grn = 0; grn < sm.size(); ++grn) {
      for (auto i: gr[grn]) {
        int t = ask(m - a[i] - 1);
        upd(m - a[i] - 1, t);
        add(bdp[i], mod - t);
      }
    }
    int ans = 0;
    memset(ft, 0, m * sizeof *ft);
    for (int i = 0; i < n; ++i) if (!bad[i]) {
      int t = ask(a[i]);
      upd(a[i], t);
      ans = (ans + t * int64_t(bdp[i])) % mod;
    }
    print(ans);
  }
}