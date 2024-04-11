#include <algorithm>
#include <array>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 16;

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
  void operator()(Ts&... xs) {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

private:
  char buf[bufsz], *bufptr = buf;

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

template <typename T, typename S> bool mini(T& a, S b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < b? a = b, 1: 0; }

constexpr int N = 10, C = 2e5, M = 1e5;

using Build = array<int, N>;

int n, m, c[N], ans;
int a_[C], *a[N];
Build b[M];

Build ansb;

int power(const Build& build) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += a[i][build[i] - 1];
  }
  return res;
}

int main() {
  reader(n);
  for (int i = 0, *ae = a_; i < n; ++i) {
    reader(c[i]);
    a[i] = ae;
    ae += c[i];
    reader(&*a[i], c[i]);
  }
  reader(m);
  for (int i = 0; i < m; ++i) {
    reader(b[i].begin(), n);
  }
  sort(b, b + m);
  {
    Build bb{};
    memcpy(bb.begin(), c, n * sizeof *c);
    if (auto it = lower_bound(b, b + m, bb); it == b + m || *it != bb) {
      ans = -1;
      ansb = move(bb);
    }
  }
  if (!ans)
  for (int i = m - 1; i > -1; --i) {
    auto build = b[i];
    int p = power(build);
    for (int i = 0; i < n && p > ans; ++i) if (build[i] > 1) {
      p -= a[i][build[i] - 1];
      p += a[i][--build[i] - 1];
      if (p > ans)
      if (!binary_search(b, b + m, build)) {
        ans = p;
        ansb = build;
      }
      p -= a[i][build[i] - 1];
      p += a[i][++build[i] - 1];
      if (build[i] != c[i]) {
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ansb[i]);;
  }
  return 0;
}