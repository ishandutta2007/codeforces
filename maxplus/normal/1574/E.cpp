#include <unordered_map>

#include <cstdio>
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
    ((*this)(&(xs = {}), &xs + 1), ...);
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
struct { operator int() { int t; reader(t); return t; } } $;

constexpr int N = 1e6 + 1, mod = 998244353;
using Coord = array<int, 2>;

int p2[N], fl[2][N][2], cntl[2][2], f[2];
unordered_map<int64_t, int8_t> cells;

int64_t c2h(Coord cell) {
  return cell[0] * (int64_t)N + cell[1];
}

void reset(int t, Coord cell) {
  auto& val = cells.emplace(c2h(cell), -1).first->second;
  for (auto dir: {-1, 1}) {
    if (val != -1) {
      bool p = (cell[0] ^ cell[1] ^ val) & 1;
      f[p] += dir;
      for (auto l: {0, 1}) {
        cntl[l][!fl[l][cell[l]][!p]] += dir &-! ((fl[l][cell[l]][p] += dir) - (dir == 1));
      }
    }
    val = t;;
  }
}

int main() {
  for (int i = p2[0] = 1; i < N; ++i) {
    p2[i] = p2[i - 1] * 2 % mod;
  }
  int nl[2]{$, $}, k = $;
  cells.reserve(k * 2);
  while (k--) {
    reset($, {$, $});
    int ans = -!f[0] - !f[1];
    for (auto l: {0, 1}) {
      ans += p2[nl[l] - cntl[l][1]] &-! cntl[l][0];
    }
    printf("%d\n", ans % mod);
  }
}