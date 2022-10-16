#include <type_traits>
#include <algorithm>
#include <cinttypes>
#include <vector>
#include <cstdio>
#include <chrono>
#include <unordered_set>

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

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
auto& mini(auto& a, const auto& b) { return b < a? a = b: a; } bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; }
auto& maxi(auto& a, const auto& b) { return a < b? a = b: a; } bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; }
auto unneg(auto a) { return max(a, {}); }

constexpr int P = 1e6 + 2, N = 15e4 + 1;


struct Eratosthenes {
  int d[P];

  Eratosthenes() {
    for (int i = 2; i < P; ++i) if (d[i] == 0) {
      for (int j = i; j < P; j += i) if (d[j] == 0) {
        d[j] = i;
      }
    }
  }
} sieve;

struct DSU {
  int p[N + P], w[N + P];

  int getp(int v) { return p[v] == 0? v: p[v] = getp(p[v]); }

  void uni(int v, int u) {
    if (w[v = getp(v)] < w[u = getp(u)]) {
      swap(v, u);
    }
    if (v == u) {
      return;
    }
    p[u] = v;
    w[v] += w[u] + 1;
  }
} dsu;

uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count();

struct hasher {
  hasher(uint64_t seed = 0) : seed{seed += global_seed += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint64_t x) const {
    x += seed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  const uint64_t seed;
};

int a[N];

unordered_set<uint64_t> bs;

void bsinsert(int u, int v) {
  if (u < v) {
    swap(u, v);
  }
  uint64_t val = u * uint64_t(N + P) + v;
  bs.insert(val);
//  for (int i = 0; i < size(hsh); ++i) {
//    bs[hsh[i](val) % mod] = 1;
//  }
}

bool bscontains(int u, int v) {
  if (u < v) {
    swap(u, v);
  }
  uint64_t val = u * uint64_t(N + P) + v;
  return bs.count(val);
//  for (int i = 0; i < size(hsh); ++i) {
//    if (!bs[hsh[i](val) % mod]) {
//      return 0;
//    }
//  }
//  return 1;
}

int main() {
  int n = $, q = $;
  reader(a, n);
  for (int i = 0; i < n; ++i) {
    for (int j = a[i]; j > 1; j /= sieve.d[j]) {
      dsu.uni(i + 1, N + sieve.d[j]);
    }
  }
  vector<int> pd;
  for (int i = 0; i < n; ++i) {
    pd.clear();
    for (int j = a[i] + 1; j > 1; ({for (int t = j; sieve.d[t] == sieve.d[j]; j /= sieve.d[t]);})) if (dsu.getp(N + sieve.d[j]) != dsu.getp(i + 1)) {
      pd.push_back(dsu.getp(N + sieve.d[j]));
    }
    sort(pd.begin(), pd.end());
    pd.erase(unique(pd.begin(), pd.end()), pd.end());
    int pi = dsu.getp(i + 1);
    for (const auto& j: pd) if (j != pi) {
      for (const auto& k: pd) if (&k < &j && k != pi) {
        bsinsert(j, k);
      }
      bsinsert(j, pi);
    }
  }
  while (q--) {
    int v = dsu.getp($), u = dsu.getp($);
    puts(v == u? "0": bscontains(v, u)? "1": "2");
  }
}