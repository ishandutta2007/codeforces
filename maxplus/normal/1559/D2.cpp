#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>

struct UnsafeInput {
  UnsafeInput() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
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
  char buf[3 << 20], *bufptr = buf;

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (*++bufptr == '-') {
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

constexpr int N = 1e5 + 1;

struct DSU {
  DSU() {
    for (int i = 0; i < N; ++i) {
      p[i] = i;
      w[i] = 1;
    }
  }

  auto operator[](int v) {return w[getp(v)];}
  auto operator[](pair<int, int> vu) {return getp(vu.first) == getp(vu.second);}
  auto operator()(int v) {return getp(v);}
  auto operator()(int v, int u) {return uni(v, u);}

private:
  int p[N], w[N];

  int getp(int v) {
    return p[v] == v? v: p[v] = getp(p[v]);
  }

  void uni(int u, int v) {
    if (w[v = getp(v)] > w[u = getp(u)]) {
      v ^= u, u ^= v, v ^= u;
    }
    p[v] = u;
    w[u] += w[v];
  }
} dsu1, dsu2;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m1, m2, a[2];
  reader(n, m1, m2);
  for (int i = 0; i < m1; ++i) {
    reader(&*a, 2);
    dsu1(--a[0], --a[1]);
  }
  for (int i = 0; i < m2; ++i) {
    reader(&*a, 2);
    dsu2(--a[0], --a[1]);
  }
  int ans = n - max(m1, m2) - 1;
  cout << ans << '\n';
  for (int i = 1, j = 1; i < n && j < n; ) {
    if (dsu1[{0, i}]) {
      ++i;
    } else if (dsu2[{0, j}]) {
      ++j;
    } else if (i >= j && !dsu2[{0, i}]) {
      dsu1(0, i);
      dsu2(0, i);
      cout << "1 " << ++i << '\n';
    } else if (i < j && !dsu1[{0, j}]) {
      dsu1(0, j);
      dsu2(0, j);
      cout << "1 " << ++j << '\n';
    } else {
      dsu1(i, j);
      dsu2(i, j);
      cout << ++i << ' ' << ++j << '\n';
    }
  }
  return 0;
}