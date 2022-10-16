//#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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

//constexpr int N = ;
//int a[N];

#include <chrono>
struct Hash {
  static uint64_t& global_seed() { static uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count(); return global_seed; }

  Hash(uint64_t seed = 0) : seed{seed += global_seed() += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint32_t x) const {
    x += seed;
    return x ^ (x >> 3 & 0xbf58476d1ce4e5b9) ^ (x << 5 & 0x94d049bb133111eb);
  }

  const uint64_t seed;
};

int main() {
//  cin.tie(0)->sync_with_stdio(!online_judge);
//  ios::sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, x = $, ans = n;
    unordered_map<int, int, Hash> m;
    m.reserve(2 * n);
    constexpr int S = 1 << 18;
    for (int i = 0; i < n; ++i) {
      auto v = $();
      auto& mref = ++m[v];
      int d = 0;
      if (x != 2) {
        while (v % x == 0) {
          v /= x;
          ++d;
        }
      } else {
        d = __builtin_ctz(v);
        v >>= d;
      }
      (d? m[v]: mref) |= S << d % 2;
    }
    constexpr int mx = 1e9;
    const int premx = mx / x;
    for (auto [k, vv]: m) if (vv >= 3 * S) {
      int kk = k, v = vv & S - 1;
      auto it = m.end();
      while (kk <= premx) {
        int nv = (it = m.find(kk *= x)) == m.end()? 0: it->second, take = min(v, nv);
        ans -= 2 * take, v = nv - take;
      }
    }
    print(ans);
  }
}