#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
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

constexpr int N = 1e5, L = 17;

struct PersistentDsu {
  array<int, 3> data[N];
  int t;

  void fill(int n) {
    t = 0;
    for (int i = 0; i < n; ++i) {
      data[i] = {N * 3, i, 1};
    }
  }

  int getp(int v, int t = -1) {
    if (t == -1) {
      t = this->t;
    }
    if (t < data[v][0]) {
      return v;
    }
    return getp(data[v][1], t);
  }

  bool uni(int v, int u) {
    v = getp(v), u = getp(u);
    ++t;
    if (v == u) {
      return 0;
    }
    if (data[v][2] < data[u][2]) {
      swap(u, v);
    }
    data[v][2] += data[u][2];
    data[u] = {t, v, -1};
    return 1;
  }
} dsu;

int spt[L][N];

int main() {
  int t; reader(t);
  while (t--) {
    int n, m, q; reader(n, m, q);
    dsu.fill(n);
    while (m--) {
      int a, b; reader(a, b);
      dsu.uni(--a, --b);
    }
    for (int i = 1; i < n; ++i) {
      int t = 0, u = i - 1, v = i;
      while (u != v) {
        if (dsu.data[u][0] < dsu.data[v][0]) {
          t = dsu.data[u][0];
          u = dsu.data[u][1];
        } else {
          t = dsu.data[v][0];
          v = dsu.data[v][1];
        }
      }
      spt[0][i - 1] = t;
    }
    for (int l = 0; l < L - 1; ++l)
    for (int i = 0; i < n - 1; ++i) {
      spt[l + 1][i] = max(spt[l][i], i + (1 << l) < n? spt[l][i + (1 << l)]: 0);
    }
    while (q--) {
      int l, r; reader(l, r); --l, --r;
      cout << (l == r? 0: ({ int L = 31 - __builtin_clz(r - l); max(spt[L][l], spt[L][r - (1 << L)]); })) << ' ';
    }
    cout << '\n';
  }
}