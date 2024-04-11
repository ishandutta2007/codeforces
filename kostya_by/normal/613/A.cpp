#include <bits/stdc++.h>

using namespace std;

const double INF = 1e18;
const int MAX_N = 100100;
const int IT = 100;
const double PI = acos(-1.0);

int x[MAX_N];
int y[MAX_N];

long long dist(int a, int b) {
  long long dx = x[a] - x[b];
  long long dy = y[a] - y[b];

  return dx * dx + dy * dy;
}

double dist1(double xx, double yy) {
  xx -= x[0];
  yy -= y[0];

  return xx * xx + yy * yy;
}

double fun(int a, int b) {
  double l = 0.0, r = 1.0;

  for (int i = 0; i < IT; i++) {
    double ml = l + (r - l) / 3.0;
    double mr = r - (r - l) / 3.0;

    double x1 = x[a] * ml + (1.0 - ml) * x[b];
    double y1 = y[a] * ml + (1.0 - ml) * y[b];

    double x2 = x[a] * mr + (1.0 - mr) * x[b];
    double y2 = y[a] * mr + (1.0 - mr) * y[b];

    if (dist1(x1, y1) > dist1(x2, y2)) {
      l = ml;
    } else {
      r = mr;
    }
  }

  double xx = x[a] * l + (1.0 - l) * x[b];
  double yy = y[a] * l + (1.0 - l) * y[b];


  return dist1(xx, yy);
} 

void solve() {
  int n;
  scanf("%d%d%d", &n, &x[0], &y[0]);

  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }

  double mn = INF;
  double mx = 0;

  for (int i = 1; i <= n; i++) {
    int j = (i == n ? 1 : i + 1);

    mx = max(mx, (double)dist(0, i));
    mx = max(mx, (double)dist(0, i));

    mn = min(mn, fun(i, j));
  }

  double answer = PI * (mx - mn);
  printf("%.18lf\n", answer);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}

// 566370614359172464