#include <iostream>
#include <cstring>

#include <cstdio>
struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf, 1, sizeof buf, stdin);
    bufptr = buf - 1;
  }

  void upread() {
    ++bufptr;
    int rem = buf + bufsz - bufptr;
    memcpy(buf, bufptr, rem);
    fread(buf + rem, 1, bufsz - rem, stdin);
    bufptr = buf - 1;
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
    T c{};
    while (1) {
      do {
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') c = c * 10 + *bufptr - '0';
        else                  break;
        if (*++bufptr >= '0') __builtin_unreachable();
      } while (0);
      *b++ = c, c = {};
      if (__builtin_expect(buf + bufsz - bufptr < 9, 0)) {
        upread();;
      }
      if (__builtin_expect(b == e, 0)) break;
    }
  }
} reader;

using namespace std;

constexpr int N = 2e6;

int cnt[N], a[N];

int main() {
  for (int t = (reader(t), t + 1); --t; ) {
    int n; reader(n);
    memset(cnt, 0, n * sizeof *cnt);
    reader(a, n);
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i] - 1];
    }
    int mi = 1e9, m = 0;
    for (int i = 0; i < n; ++i) if (cnt[i]) {
      mi = min(mi, cnt[i]);
      a[m++] = cnt[i];
    }
    int ans = 1e9;
    for (int s = 2; s <= mi + 1; ++s) {
      int cans = 0;
      for (int i = 0; i < m; ++i) {
        int r = (a[i] - 1) / s + 1;
        if (r * (s - 1) > a[i]) {
          cans = 1e9;
        } else {
          cans += r;
        }
      }
      ans = min(ans, cans);
    }
    cout << ans << '\n';
  }
}