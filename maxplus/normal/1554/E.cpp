#include <iostream>
#include <cstring>
#include <vector>

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


using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { using X = int; template <typename T = X> auto operator ()() const { T t; reader(t); return t; } operator X() const { return this->operator()<X>(); } template <typename T> operator T() const { return this->operator()<T>(); } } $;
template <typename T, typename S> bool mini(T& a, const S& b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, const S& b) { return a < b? a = b, 1: 0; }
template <typename T> T unneg(T a) { return max(T{}, a); }

constexpr int mod = 998244353, N = 1e5;

vector<int> nei[N];

int assign_edges(int v, int p, int g) {
  int dg = 1;
  #pragma GCC unroll 10
  for (auto u: nei[v]) if (u != p) {
    if (auto t = nei[u].size() == 1? 1: assign_edges(u, v, g)) {
      dg += 2 - t;
    } else {
      return t;
    }
  }
  while (dg >= g) {
    dg -= g;
  }
  return !dg + (dg < 2);
}

int ans[N + 1];

int main() {
  for (int testcase = $; testcase; --testcase) {
    int n = $;
    for (int i = 0; i < n; ++i) {
      nei[i].clear();
    }
    ans[1] = 1;
    for (int i = 1; i < n; ++i) {
      (ans[1] *= 2) %= mod;
      int v = $ - 1, u = $ - 1;
      nei[v].push_back(u);
      nei[u].push_back(v);
    }
    for (int i = 2; i <= n; ++i) {
      if ((n - 1) % i || ans[i] == -1) {
        ans[i] = 0;
      } else {
        ans[i] = assign_edges(0, 0, i) == 1;
        if (ans[i] == 0) {
  #pragma GCC unroll 10
          for (int j = i * 2; j < n; j += i) if (ans[j] != -1) {
            ans[j] = -1;
          }
        }
      }
    }
    for (int i = n; i; --i) if ((n - 1) % i == 0)
  #pragma GCC unroll 10
    for (int j = i * 2; j < n; j += i) {
      ans[i] -= ans[j];
    }
    for (int i = 1; i <= n; ++i) {
      cout << (ans[i] + mod) % mod << ' ';
    }
    cout << '\n';
  }
}