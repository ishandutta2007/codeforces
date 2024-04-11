#include "bits/stdc++.h"
#include <unistd.h>
using namespace std;

template <typename T>
using V = vector<T>;

struct Scanner {
  FILE* fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T>
  bool read_single(V<T>& ref) {
    for (auto& d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fp(fp) {}
};

Scanner scanner(stdin);

void solve() {
  int N;
  scanner.read(N);
  vector<vector<int>> A(N, vector<int>(N));
  vector<vector<int>> B(N, vector<int>(N));

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) scanner.read(A[i][j]);

  int ANS = 0;

  const int H = N, W = N;
  auto isin = [&](int x, int y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W);
  };
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};

  auto push = [&](int x, int y) -> void {
    ANS ^= A[x][y];
    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d], ny = y + dy[d];
      if (isin(nx, ny)) B[nx][ny] ^= 1;
    }
  };

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i && !B[i - 1][j]) push(i, j);

  cout << ANS << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  int T;
  scanner.read(T);
  for (int t = 0; t < T; ++t) solve();

  return 0;
}