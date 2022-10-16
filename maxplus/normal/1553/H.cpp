#include <algorithm>
#include <iostream>
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
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { ((cout << ts << ' '), ...) << '\n'; }
auto& mini(auto& a, const auto& b) { return b < a? a = b: a; } bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; }
auto& maxi(auto& a, const auto& b) { return a < b? a = b: a; } bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; }
auto unneg(auto a) { return max(a, {}); }

constexpr int L = 19, N = 1 << L;

int a[N], ans_[N * 2], * ans[L]{ans_}, lb[N];

bool missing(int d, int& pr) {
  return (a[lb[pr]] & -(1 << d + 1)) != pr? pr ^= 1 << d + 1, 1: 0;
}

template <int p, int d>
void solve2(int x, int pr1, int pr2) {
  if ((missing(d, pr1) | missing(d, pr2)) && d == p - 1) {
    return;
  }
  if constexpr (d != -1) {
    for (auto c: {0, 1}) {
      solve2<p, d - 1>(x | c << d, pr1 | !c << d, pr2 | c << d);
    }
  } else {
    mini(ans[p][x], (pr2 ^ x) - (pr1 ^ x));
    return;
  }
}

template <int d>
void solve(int x, int pr) {
  if (missing(d, pr)) {
    return;
  }
  if constexpr (d) {
    solve<d - 1>(x, pr);
    solve<d - 1>(x, pr | 1 << d);
  }
  for (auto c: {0, 1}) {
    solve2<d, d - 1>(x | c << d, pr | c << d, pr | !c << d);
  }
}

int main() {
  memset(ans_, 127, sizeof ans_);
  for (int p = 1; p < L; ++p) {
    ans[p] = ans[p - 1] + (1 << p);
  }
  int n = $, k = $;
  reader(a, n);
  sort(a, a + n);
  a[n] = 1 << k;
  for (int i = 0; i < 1 << k; ++i) {
    lb[i] = lb[i? i - 1: 0];
    while (lb[i] < n && a[lb[i]] < i) {
      ++lb[i];
    }
  }
  solve<L - 1>(0, 0);
  for (int i = 0; i < 1 << k; ++i)
  for (int p = 0; p < k; ++p) {
    mini(ans[k - 1][i], ans[p][i & (1 << p + 1) - 1]);
  }
  for (int i = 0; i < 1 << k; ++i) {
    cout << ans[k - 1][i] << ' ';
  }
  cout << '\n';
}