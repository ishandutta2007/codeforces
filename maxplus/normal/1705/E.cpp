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

constexpr int N = 2e5, M = 3126;
uint64_t a[M + 9], b[N];

void carryadd(int r) {
  while (1) {
    if (++a[++r]) break;
    if (++a[++r]) break;
    if (++a[++r]) break;
    if (++a[++r]) break;
  }
  brk:;
}

void carrysub(int r) {
  while (1) {
    if (a[++r]--) break;
    if (a[++r]--) break;
    if (a[++r]--) break;
    if (a[++r]--) break;
  }
  brk:;
}

bool add(int pos) {
  uint64_t r = pos / 64, t = a[r];
  return (a[r] += 1ull << pos) < t;
}

bool sub(int pos) {
  uint64_t r = pos / 64, t = a[r];
  return (a[r] -= 1ull << pos) > t;
}

int getans() {
  int pos = M;
  while (1) {
    if (a[--pos]) break;
    if (a[--pos]) break;
    if (a[--pos]) break;
    if (a[--pos]) break;
  }
  return (pos + 1) * 64 - __builtin_clzll(a[pos]);
}

int main() {
  int n, q, x, prv, nxt, fa, fs; reader(n, q);
  reader(b, n);
  for (int i = 0; i < n; ++i) {
    if (add(--b[i])) {
      carryadd(b[i] / 64);
    }
  }
  for (int i = 0; i < q; ++i) {
    reader(x), fs = sub(prv = b[--x]);
    if (fs) carrysub(prv / 64);
    reader(b[x]), fa = add(nxt = --b[x]);
    if (fa) carryadd(nxt / 64);
    cout << getans() << '\n';
  }
}