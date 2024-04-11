#include <iostream>
#include <memory.h>
#include <map>

using namespace std;

struct UnsafeInput {
  UnsafeInput() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    memset(b, 0, sizeof *b * n);
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  void operator()(Ts&... xs) {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

private:
  char buf[1 << 23], *bufptr = buf;

  template <typename T>
  void operator()(T* b, T* e) {
    while (b != e) {
      if (*++bufptr < '0') {
        ++b;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

int a[200000];

int main() {
  int t;
  reader(t);
  while (t--) {
    int n, l, r;
    reader(n, l, r);
    map<int, int> b;
    reader(&*a, n);
    for (int i = 0; i < l + r; ++i) {
      b[a[i]] += (i < l) - (i >= l);
    }
    int s[2]{}, ans = 0;
    for (auto [_, cnt]: b) {
      s[cnt < 0] += abs(cnt);
    }
    for (auto [_, cnt]: b) {
      int mv = max(min(s[cnt < 0] - s[cnt > 0], abs(cnt)) / 2, 0);
      s[cnt < 0] -= mv * 2;
      ans += mv;
    }
    cout << ans + max(s[0], s[1]) << '\n';
  }
  return 0;
}