#include <stdio.h>
#include <memory.h>

constexpr int N = 3e5 + 1;

int x;
long long a[N];
int edgorig[N][2];

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

struct UnsafeOutput {
  void YES() {
    *bufptr++ = 'Y';
    *bufptr++ = 'E';
    *bufptr++ = 'S';
    *bufptr++ = '\n';
  }

  void NO() {
    *bufptr++ = 'N';
    *bufptr++ = 'O';
    *bufptr++ = '\n';
  }

  void clear() {
    bufptr = buf;
  }

  template <typename T>
  void operator()(T b, char sep) {
    char* __restrict end = bufptr + 38, * __restrict dst = end;
    do {
      *--dst = b % 10 + '0';
      b /= 10;
    } while (b);
    memcpy(bufptr, dst, end - dst);
    *(bufptr += end - dst)++ = sep;
  }

  template <typename ...Ts>
  void operator()(Ts... xs) {
    ((*this)(xs, ' '), ...);
  }

  template <typename T>
  void operator()(T* b, size_t n, char sep = ' ') {
    for (size_t i = 0; i < n; ++i) {
      (*this)(b[i], sep);
    }
    *bufptr++ = '\n';
  }

  ~UnsafeOutput() {
    fwrite(buf, 1, bufptr - buf, stdout);
  }

private:
  char buf[1 << 21], * __restrict bufptr = buf;
} writer;

struct DSU {
  auto operator()(int v) {return getp(v);}
  auto operator()(int v, int u) {return uni(v, u);}

private:
  int p[N], w[N];

  int getp(int v) {
    return p[v] == 0? v: p[v] = getp(p[v]);
  }

  void uni(int u, int v) {
    if (w[v = getp(v)] > w[u = getp(u)]) {
      v ^= u, u ^= v, v ^= u;
    }
    p[v] = u;
    a[u] += a[v] - x;
    w[u] += w[v] + 1;
  }
} dsu;

int main() {
  int n, m, ans = 0;
  reader(n, m, x);
  reader(a + 1, n);
  reader(&**edgorig, 2 * m);
  writer.YES();
  for (bool changed = 1; changed && ans != n - 1u && (changed = 0, 1); )
  for (int j = -m + 1; j < m; ++j) {
    int i = j < 0? -j: j;
    if (dsu(edgorig[i][0]) != dsu(edgorig[i][1])) {
      if (a[dsu(edgorig[i][0])] + a[dsu(edgorig[i][1])] >= x) {
        writer(i + 1);
        ++ans;
        dsu(edgorig[i][0], edgorig[i][1]);
        changed = 1;
      }
    }
  }
  if (ans != n - 1u) {
    writer.clear();
    writer.NO();
  }
  return 0;
}