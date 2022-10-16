#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>

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
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 15e4 + 1, L = 30, mod = 998244353;

int p2[N];
int a[N + 7], n, x;

auto lower_bound(int l, int r, int x) {
  x = a[l] & -x | x;
  if (__builtin_expect(r - l > 8, 0))
  while (l + 8 < r && a[l + 8] < x) {
    l += 8;
  }
  l += a[l] < x;;
  if (a[l] < x) {++l;
  if (a[l] < x) {++l; l += a[l] < x;
  if (a[l] < x) {++l; l += a[l] < x; l += a[l] < x; l += a[l] < x;
  }}}
  return min(l, r);
}

template <int l>
int solve(int la, int ra, int lb, int rb) {
  if constexpr (l == -1) {
    return la + ra == lb + rb? p2[ra - la]: p2[ra + rb - la - lb];
  } else {
    if (ra == la || rb == lb) {
      return la + ra == lb + rb? p2[ra - la]: p2[ra + rb - la - lb];
    }
    if (~x & 1 << l) {
      if (la == lb) {
        auto ma = lower_bound(la, ra, 1 << l);
        int res = solve<l - 1>(la, ma, la, ma) + solve<l - 1>(ma, ra, ma, ra) - 1;
        if (res >= mod) {
          res -= mod;
        }
        return res;
      } else {
        auto ma = lower_bound(la, ra, 1 << l), mb = lower_bound(lb, rb, 1 << l);
        int64_t res = solve<l - 1>(la, ma, lb, mb) + solve<l - 1>(ma, ra, mb, rb) + 1;
        res += p2[ra - la] - p2[ra - ma] - p2[ma - la];
        res += p2[rb - lb] - p2[rb - mb] - p2[mb - lb];
        return (res + mod * 4ll) % mod;
      }
    } else if (la == lb) {
      auto ma = lower_bound(la, ra, 1 << l);
      return solve<l - 1>(la, ma, ma, ra);
    } else {
      auto ma = lower_bound(la, ra, 1 << l), mb = lower_bound(lb, rb, 1 << l);
      return solve<l - 1>(ma, ra, lb, mb) * (int64_t)solve<l - 1>(la, ma, mb, rb) % mod;
    }
  }
}

int main() {
  for (int i = 0, cp = 1; i < N; ++i) {
    p2[i] = cp;
    cp += cp;
    if (cp >= mod) {
      cp -= mod;
    }
  }
  reader(n, x);
  reader(a, n);
  sort(a, a + n);
  print(solve<L - 1>(0, n, 0, n) - 1);
}