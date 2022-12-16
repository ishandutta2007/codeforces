#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

const int N = 1234567;

int x[N], y[N];
int n;
double areas[N];

void line(int i, int j, double &a, double &b, double &c) {
  i %= n;
  j %= n;
  a = y[j] - y[i];
  b = x[i] - x[j];
  c = -a * x[i] - b * y[i];
}

void intersect(double a, double b, double c, double aa, double bb, double cc, double &dx, double &dy) {
  double d = a * bb - b * aa;
  dx = (b * cc - c * bb) / d;
  dy = (c * aa - a * cc) / d;
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  reverse(x, x + n);
  reverse(y, y + n);
  areas[0] = 0;
  for (int i = 0; i < 4 * n; i++) {
    areas[i + 1] = areas[i] + (x[i % n] - x[(i + 1) % n]) * 1.0 * (y[i % n] + y[(i + 1) % n]);
  }
  double total_area = 0.0;
  for (int i = 0; i < n; i++) {
    total_area += (x[i] - x[(i + 1) % n]) * 1.0 * (y[i] + y[(i + 1) % n]);
  }
  for (int i = 0; i < q; i++) {
    int qx, qy;
    scanf("%d %d", &qx, &qy);
    double low = 0, high = pi;
    double zero = -1.0;
    for (int it = 0; it < 60; it++) {
      double mid = 0.5 * (low + high);
      if (mid == low || mid == high) {
        break;
      }
      if (it == 0) {
        mid = low;
      }
      double dx = cos(mid);
      double dy = sin(mid);
      double a = dy;
      double b = -dx;
      double c = -a * qx - b * qy;
      double u0 = a * x[0] + b * y[0] + c;
      double u1 = a * x[1] + b * y[1] + c;
      bool flag = false;
      if (u0 > u1) {
        flag = true;
        u0 = -u0;
        u1 = -u1;
        a = -a;
        b = -b;
        c = -c;
      }
      int ll = 0, rr = n - 1;
      while (ll < rr) {
        int i = (ll + rr + 1) >> 1;
        int j = (i + 1) % n;
        double ui = a * x[i] + b * y[i] + c;
        double uj = a * x[j] + b * y[j] + c;
        if (ui <= uj && ui >= 0.5 * (u0 + u1)) {
          ll = i;
        } else {
          rr = i - 1;
        }
      }
      int id_max = (ll + 1) % n;
      ll = id_max + 1, rr = id_max + n - 1;
      while (ll < rr) {
        int i = (ll + rr) >> 1;
        int j = i + 1;
        double ui = a * x[i % n] + b * y[i % n] + c;
        double uj = a * x[j % n] + b * y[j % n] + c;
        if (ui > uj) {
          ll = i + 1;
        } else {
          rr = i;
        }
      }
      int id_min = ll;
      int last, first;
      {
        ll = id_max, rr = id_min;
        while (ll < rr) {
          int i = (ll + rr + 1) >> 1;
          double ui = a * x[i % n] + b * y[i % n] + c;
          if (ui > 0) {
            ll = i;
          } else {
            rr = i - 1;
          }
        }
        last = ll + n;
      }
      {
        ll = id_min, rr = id_max + n;
        while (ll < rr) {
          int i = (ll + rr) >> 1;
          double ui = a * x[i % n] + b * y[i % n] + c;
          if (ui < 0) {
            ll = i + 1;
          } else {
            rr = i;
          }
        }
        first = ll;
      }
      double xf, yf, xl, yl;
      double aa, bb, cc;
      line(first - 1, first, aa, bb, cc);
      intersect(a, b, c, aa, bb, cc, xf, yf);
      line(last, last + 1, aa, bb, cc);
      intersect(a, b, c, aa, bb, cc, xl, yl);
      double res = 0.0;
      res += (xf - x[first % n]) * (yf + y[first % n]);
      res += areas[last] - areas[first];
      res += (x[last % n] - xl) * (y[last % n] + yl);
      res += (xl - xf) * (yl + yf);
      if (flag) {
        res = total_area - res;
      }
      if (it == 0) {
        zero = res;
        continue;
      }
      if ((res > 0.5 * total_area) == (zero > 0.5 * total_area)) {
        low = mid;
      } else {
        high = mid;
      }
    }
    printf("%.17f\n", 0.5 * (low + high));
  }
  return 0;
}