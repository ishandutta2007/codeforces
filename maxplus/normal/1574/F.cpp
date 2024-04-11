#include <vector>
#include <unordered_map>

struct UnsafeInput {
  static constexpr int bufsz = 1 << 17;

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
    return ((*this)(xs), ...);
  }

  template <typename T>
  void operator()(T& x) {
    x = {};
    while (1) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        break;
      } else {
        x = x * 10 + *bufptr - '0';
      }
    }
  }

private:
  char buf[bufsz], *bufptr = buf;

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
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; reader(t); return t; } } $;

constexpr int N = 3e5 + 1, mod = 998244353;

struct DSU {
  int p[N], w[N];
  bool bad[N];

  int getp(int v) { return p[v]? p[v] = getp(p[v]): v; }

  bool uni(int u, int v) {
    if (w[u = getp(u)] < w[v = getp(v)]) {
      swap(u, v);
    }
    if (u == v) {
      return 0;
    }
    p[v] = u;
    bad[u] |= bad[v];
    w[u] += w[v] + 1;
    return 1;
  }

  void tag(int v) { bad[getp(v)] = 1; }
} dsu;

int prv[N], nxt[N];

unordered_map<int, int> lencnt;

int dp[N];

int main() {
  int n = $, m = $, k = $;
  while (n--) {
    int c = $, p = $;
    while (--c) {
      int a = $;
      if (prv[a] != p && (!dsu.uni(a, p) || prv[a]) || nxt[p] != a && nxt[p]) {
        dsu.tag(a);
      }
      prv[a] = p;
      nxt[p] = a;
      p = a;
    }
  }
  for (int i = 1; i <= k; ++i) if (dsu.getp(i) == i && !dsu.bad[i]) {
    ++lencnt[dsu.w[i] + 1];
  }
  dp[0] = 1;
  for (int l = 1; l <= m; ++l) {
    int64_t res = 0;
    for (auto [len, cnt]: lencnt) if (len <= l) {
      res += dp[l - len] * int64_t(cnt);
    }
    dp[l] = res % mod;
  }
  printf("%d\n", dp[m]);
}