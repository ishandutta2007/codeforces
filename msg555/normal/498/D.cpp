#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN (1 << 17)

struct agg {
  agg() {
    //memset(R, 0, sizeof(R));
  }

  agg(int off, int t) {
    off = (t - off % t) % t;
    memset(R, 0, sizeof(R));
    for (int i = off; i < 60; i += t) {
      R[i] = 1;
    }
  }

  int R[60];
};

agg comb(const agg& x, const agg& y) {
  agg r;
  int base = x.R[0] / 60 * 60;
  for (int i = 0; i < 60; i++) {
    int yi = i + x.R[i] - base;
    if (yi >= 60) yi -= 60;
    if (yi < 0) yi += 60;
    r.R[i] = x.R[i] + y.R[yi];
  }
  return r;
}

agg X[2 * MAXN];

agg query(int x, int A, int B, int a, int b) {
  if (a <= A && B <= b) {
    return X[x];
  }

  int M = (A + B) / 2;
  if (b <= M) {
    return query(2 * x + 0, A, M, a, b);
  } else if (M <= a) {
    return query(2 * x + 1, M, B, a, b);
  }
  return comb(query(2 * x + 0, A, M, a, b),
              query(2 * x + 1, M, B, a, b));
}

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    X[MAXN + i] = agg(i, t);
  }
  for (int i = MAXN - 1; i > 0; i--) {
    X[i] = comb(X[2 * i + 0], X[2 * i + 1]);
  }

  int M; cin >> M;
  for (int i = 0; i < M; i++) {
    string cmd;
    int x, y;
    cin >> cmd >> x >> y;
    if (cmd == "C") {
      x--;
      X[MAXN + x] = agg(x, y);
      for (x = (MAXN + x) / 2; x > 0; x /= 2) {
        X[x] = comb(X[2 * x + 0], X[2 * x + 1]);
      }
    } else {
      x--; y--;
      int off = (60 - x % 60) % 60;
      cout << y - x + query(1, 0, MAXN, x, y).R[off] << '\n';
    }
  }

  return 0;
}