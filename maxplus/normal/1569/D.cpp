#include <initializer_list>
#include <memory.h>
#include <cstdio>

using namespace std;

constexpr int N = 2e5, K = 3e5, T = 1001, P = 1e6 + 1;

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

int storage[(N + K) * 16], allocated;
struct Storage {
  int *start;

  int& operator[](int x) {
    return start[x];
  }

  void push_back(int x) {
    realloc();
    start[size()++] = x;
  }

  int clear() {
    return size() = 0;
  }

  int* begin() {
    return start;
  }

  int* end() {
    return begin() + size();
  }

  int& capacity() {
    return start[-1];
  }

  int& size() {
    return start[-2];
  }

  bool empty() {
    return !start;
  }

  void realloc() {
    if (empty()) {
    } else if (capacity() == size()) {
      memcpy(storage + allocated, start - 2, (capacity() + 2) * sizeof *storage);
    } else {
      return;
    }
    start = storage + allocated + 2;
    (capacity() *= 2) += 2;
    allocated += capacity() + 2;
  }
};

int x[2][N], p[K][2], xstart[2][T], pstart[T], xpos[2][T], tt;
Storage xm[P];

void load() {
  int n, m, k;
  reader(tt);
  for (int t = 0; t < tt; ++t) {
    long long ans = 0;
    reader(n, m, k);
    xstart[0][t + 1] = xstart[0][t] + n;
    xstart[1][t + 1] = xstart[1][t] + m;
    pstart[t + 1] = pstart[t] + k;
    reader(x[0] + xstart[0][t], n);
    reader(x[1] + xstart[1][t], m);
    reader(&*p[pstart[t]], 2 * k);
    for (auto c: {0, 1}) {
      for (int i = pstart[t]; i < pstart[t + 1]; ++i) {
        xm[p[i][c]].push_back(c + t * 2 + (i + 1 << 11));
      }
      for (int i = xstart[c][t]; i < xstart[c][t + 1]; ++i) {
        xm[x[c][i]].push_back(c + t * 2);
      }
    }
  }
}

void compress() {
  for (int i = 0; i < P; ++i) if (!xm[i].empty())
  for (auto val: xm[i]) {
    int c = val & 1;
    int t = val / 2 & 01777;
    int pos = val >> 11;
    if (pos == 0) {
//      x[c][xpos[c][t] + xstart[c][t]] = xpos[c][t];
      ++xpos[c][t];
    } else {
      p[pos - 1][c] = xpos[c][t] * 2 + (x[c][xpos[c][t] + xstart[c][t]] != i);
    }
  }
}

int tp[N], cnt[N];
Storage px[2][N];

void solve() {
  int e = 1;
  for (int t = 0; t < tt; ++t) {
    long long ans = 0;
    for (int i = pstart[t]; i < pstart[t + 1]; ++i)
    for (auto c: {0, 1}) {
      if (p[i][c] & 1) {
        px[c][p[i][c] / 2].push_back(p[i][!c] / 2);
      }
    }
    for (auto c: {0, 1})
    for (int i = xpos[c][t]; --i; px[c][i].empty() || px[c][i].clear()) if (!px[c][i].empty() && px[c][i].size() > 1) {
      if (px[c][i].size() == 2) {
        ans += px[c][i][0] != px[c][i][1];
      } else {
        for (int& j: px[c][i]) {
          if (cnt[j] < e) {
            cnt[j] = e;
            ans += &j - px[c][i].begin();
          } else {
            ans += &j - px[c][i].begin() - ++cnt[j] + e;
          }
        }
        e += px[c][i].size();
      }
    }
    printf("%lld\n", ans);
  }
}

int main() {
  load();
  compress();
  solve();
}