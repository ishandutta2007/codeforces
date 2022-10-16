#include <iostream>

using namespace std;

constexpr int64_t mx = int64_t(1e8) * int64_t(1e8) * 4;

int64_t dif(int64_t x1, int64_t x2) {
  if (x1 < mx && x2 < mx) {
    return x1 < x2? x2 - x1: x1 - x2;
  }
  return mx;
}

int64_t dst(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
  auto res = dif(x1, x2) + dif(y1, y2);
  return min(res, mx);
}

int64_t fmul(int64_t x, int64_t a, int64_t b) {
  if (x <= mx) {
    x = x * a + b;
  }
  return min(x, mx);
}

int64_t x[64], y[64];
int64_t x0, y0, ax, ay, bx, by, xs, ys, t;
int imax = 0;

int case0(int i0) {
  int am = 0;
  int64_t cd = dst(x[i0], y[i0], xs, ys);
  for (int i = i0; cd <= t; ++i) {
    ++am;
    if (i != imax - 1) {
      cd += dst(x[i + 1], y[i + 1], x[i], y[i]);
    } else {
      break;
    }
  }
  return am;
}

int case1(int i0) {
  int am = 0;
  int64_t cd = dst(x[i0], y[i0], xs, ys);
  for (int i = i0; cd <= t; --i) {
    ++am;
    if (i > 0) {
      cd += dst(x[i - 1], y[i - 1], x[i], y[i]);
    } else {
      break;
    }
  }
  return am;
}

int main() {
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  while (x0 < mx && y0 < mx) {
    x[imax] = x0;
    y[imax] = y0;
    x0 = fmul(x0, ax, bx);
    y0 = fmul(y0, ay, by);
    imax++;
  }
  int am = 0;
  for (int i = 0; i < imax; ++i) {
    am = max(am, case0(i));
    am = max(am, case1(i));
  }
  cout << am << '\n';
}