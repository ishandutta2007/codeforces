//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int N = 228'228;
using ld = double;
using ll = int64_t;
 
ll sqr(int x) {
  return 1ll * x * x;
}
 
ld sqr(ld x) {
  return x * x;
}
 
struct line {
  line(int xc, int yc, int xd, int yd) {
    A = (yc - yd);
    B = (xd - xc);
    C = (1ll * xc * yd - 1ll * xd * yc);
  }
 
  ll f(int x, int y) {
    return A * x + B * y + C;
  }
 
  ld f(ld x, ld y) {
    return A * x + B * y + C;
  }
 
  ll A;
  ll B;
  ll C;
};
 
double det(ld a11, ld a12, ld a21, ld a22) {
  return a11 * a22 - a21 * a12;
}
 
pair<double, double> interserct(const line& A, const line& B) {
  double x, y;
  ld D = det(A.A, A.B, B.A, B.B);
  x = det(-A.C, A.B, -B.C, B.B) / D;
  y = det(A.A, -A.C, B.A, -B.C) / D;
  return {x, y};
}
 
ld dist(ld xa, ld ya, ld xb, ld yb) {
  return sqrt(sqr(xa - xb) + sqr(ya - yb));
}
 
ld dist(int xa, int ya, int xb, int yb) {
  return sqrt(sqr(xa - xb) + sqr(ya - yb));
}
 
int x[N], y[N];
 
void solve() {
  int n, H;
  cin >> n >> H;
  ld ans = 0;
  ld tot_dist = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (i > 0) {
      tot_dist += sqrt(sqr(x[i] - x[i - 1]) + sqr(y[i] - y[i - 1]));
    }
  }
  int best = n - 2;
  for (int i = n - 3; i >= 0; i--) {
    auto consider = [&] (int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
      line A(xc, yc, xd, yd);
      if (A.f(xa, ya) >= 0 && A.f(xb, yb) >= 0) {
        return;
      }
      if (A.f(xb, yb) <= 0 && A.f(xa, ya) <= 0) {
        ans += dist(xa, ya, xb, yb);
        return;
      }
      line B(xa, ya, xb, yb);
      auto [xi, yi] = interserct(A, B);
      if (A.f(xa, ya) < 0) {
        ans += dist(xi, yi, ld(xa), ld(ya));
      } else if (A.f(xb, yb) < 0) {
        ans += dist(xi, yi, ld(xb), ld(yb));
      }
    };
    consider(x[i], y[i], x[i + 1], y[i + 1], x[best], y[best], x[n - 1], y[n - 1] + H);
    line A(x[best], y[best], x[n - 1], y[n - 1] + H);
    if ((-A.C - A.A * x[i]) / A.B < y[i]) {
      best = i;
    }
  }
  cout << fixed << setprecision(10) << tot_dist - ans << "\n";
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  solve();
  return 0;
}