#include <iterator>
#include <iostream>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <vector>

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
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 100001, L = 18;

int ph[N];
int64_t f[L][N], ps[N];
int m[L][N];

int64_t C(int l, int r) {
  int64_t ans = 0;
  for (int i = r; i >= l; ) {
    int t = r / i;
    int ni = max(r / (t + 1), l - 1);
    ans -= int64_t(ps[t]) * change(i, ni);
  }
  return ans;
}

int queries[N][2];

int main() {
  iota(ph, ph + N, 0);
  ps[1] = 1;
  for (int i = 2; i < N; ps[i] = ph[i] + ps[i - 1], ++i) if (ph[i] == i) {
    for (int j = i; j < N; j += i) {
      ph[j] -= ph[j] / i;
    }
  }
  memset(f, 63, sizeof f);
  iota(f[1], f[2], 0);
  partial_sum(f[1], f[2], f[1]);
  for (int k = 2; k < L; ++k) {
    for (int n = N - 1; n > -1; --n) {
      int m = ::m[k][n] = max(::m[k - 1][n], n != N - 1? ::m[k][n + 1] - 1000: 0);
      int64_t c = C(m + 1, n);
      while (m <= min(n == N - 1? N: ::m[k][n + 1], n / 2)) {
        if (minb(f[k][n], f[k - 1][m] + c)) {
          ::m[k][n] = m;
        }
        c -= ps[n / ++m];
      }
    }
  }
  int q = $;
  reader(*queries, 2 * q);
  for (auto [n, k]: range{queries, q}) {
    print(k >= L? n: f[k][n]);
  }
}