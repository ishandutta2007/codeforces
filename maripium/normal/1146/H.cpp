#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point(int x = 0,int y = 0) : x(x), y(y) {}
  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }
  long long operator * (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }
};

long long ccw(point o,point u,point v) {
  return (u - o) * (v - o);
}

const int N = 305;

point a[N];
bitset<N> f[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].x, &a[i].y);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        f[i][j][k] = (ccw(a[i], a[j], a[k]) > 0);
      }
    }
  }
  long long ans = (long long) n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = i + 1; k < n; ++k) {
        if (f[i][j][k]) {
          int cur = (f[i][j] & f[j][k] & f[k][i]).count();
          sum += cur * (n - 4);
          ans += cur * (cur - 1) / 2;
        }
      }
    }
  }
  printf("%lld\n", ans - sum / 2);
}