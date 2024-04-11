#include <algorithm>
#include <cinttypes>
#include <cstring>

using namespace std;

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
  void operator()(Ts&... xs) {
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


bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> auto operator ()() const { T t; reader(t); return t; } operator X() const { return this->operator()<X>(); } template <typename T> operator T() const { return this->operator()<T>(); } } $;
template <typename T, typename S> bool mini(T& a, const S& b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, const S& b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }

constexpr int N = 1 << 17;

struct max2 {
  int a, b;

  void update(int c) {
    if (a < c) {
      b = a;
      a = c;
    } else {
      maxi(b, c);
    }
  }

  void update(max2 c) {
    if (a > c.a) {
      maxi(b, c.a);
    } else {
      if (a < c.a) {
        swap(a, b = c.a);
      }
      maxi(b, c.b);
    }
  }
};

max2 a[N];

int main() {
  for (int testcase = $; testcase; --testcase) {
    int n = $, k = $, m = 1 << (32 - __builtin_clz(n));
    int64_t ans = -k * m;
    memset(a, 0, m * sizeof *a);
    for (int i = 1; i <= n; ++i) {
      a[$].update(i);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = i - 1; j > -1; --(j &= j + 1)) {
        a[i].update(a[i & j]);
      }
      if (a[i].a && a[i].b) {
        maxi(ans, a[i].a * (int64_t)a[i].b - k * i);
      }
    }
    printf("%lld\n", ans);
  }
}