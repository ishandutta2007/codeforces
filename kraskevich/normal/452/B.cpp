#include <bits/stdc++.h>

using namespace std;

int sqr(int a) {
  return a * a;
}

double dist(int x1, int y1, int x2, int y2, int x3, int y3) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2)) + sqrt(sqr(x2 - x3) + sqr(y2 - y3));
}

double d2(int x1, int y1, int x2, int y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

int main() {
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  bool rot = false;
  if (n > m) {
    swap(n, m);
    rot = true;
  }
  int x1, y1, x2, y2, x3, y3, x4, y4;
  if (n == 0) {
    x1 = x2 = x3 = x4 = 0;
    y1 = 1;
    y2 = m;
    y3 = 0;
    y4 = m - 1;
  } else {
    x1 = 0;
    y1 = 0;
    x2 = n;
    y2 = m;
    x3 = 0;
    y3 = m;
    x4 = n;
    y4 = 0;
    for (int xx = 0; xx <= n; xx++)
      for (int yy = 0; yy <= m; yy++) {
        if (xx != 0 && xx != n && yy != 0 && yy != m)
          continue;
        if (xx == x1 && yy == y1)
          continue;
        if (xx == x2 && yy == y2)
          continue;
        for (int xxx = 0; xxx <= n; xxx++) {
          if (xxx == 0 || xxx == n) {
            for (int yyy = 0; yyy <= m; yyy++) {
              if (xxx != 0 && xxx != n && yyy != 0 && yyy != m)
                continue;
              if (xxx == x1 && yyy == y1)
                continue;
              if (xxx == x2 && yyy == y2)
                continue;
              if (xx == xxx && yy == yyy)
                continue;
              if (dist(x2, y2, xx, yy, xxx, yyy) > dist(x2, y2, x3, y3, x4, y4)) {
                x3 = xx;
                y3 = yy;
                x4 = xxx;
                y4 = yyy;
              }
            }
          }
          else {
            for (int yyy = 0; yyy <= m; yyy += m) {
              if (xxx != 0 && xxx != n && yyy != 0 && yyy != m)
                continue;
              if (xxx == x1 && yyy == y1)
                continue;
              if (xxx == x2 && yyy == y2)
                continue;
              if (xx == xxx && yy == yyy)
                continue;
              if (dist(x2, y2, xx, yy, xxx, yyy) > dist(x2, y2, x3, y3, x4, y4)) {
                x3 = xx;
                y3 = yy;
                x4 = xxx;
                y4 = yyy;
              }
            }
          }
        }
      }
    double d = d2(x1, y1, x2, y2) + d2(x2, y2, x3, y3) + d2(x3, y3, x4, y4);
    int xx2 = 0;
    int yy2 = 0;
    int xx3 = n;
    int yy3 = m;
    int xx1 = 0;
    int yy1 = m;
    int xx4 = n;
    int yy4 = 0;
    for (int xx = 0; xx <= n; xx++)
      for (int yy = 0; yy <= m; yy++) {
        if (xx != 0 && xx != n && yy != 0 && yy != m)
          continue;
        if (xx == xx2 && yy == yy2)
          continue;
        if (xx == xx3 && yy == yy3)
          continue;
        for (int xxx = 0; xxx <= n; xxx++)
          for (int yyy = 0; yyy <= m; yyy += (xxx == 0 || xxx == n) ? 1 : m) {
            if (xxx != 0 && xxx != n && yyy != 0 && yyy != m)
              continue;
            if (xxx == xx2 && yyy == yy2)
              continue;
            if (xxx == xx3 && yyy == yy3)
              continue;
            if (xx == xxx && yy == yyy)
              continue;
            if (d2(xx, yy, xx2, yy2) + d2(xxx, yyy, xx3, yy3) > d2(xx1, yy1, xx2, yy2) + d2(xx4, yy4, xx3, yy3)) {
              xx1 = xx;
              yy1 = yy;
              xx4 = xxx;
              yy4 = yyy;
            }
          }
      }
    double dd = d2(xx1, yy1, xx2, yy2) + d2(xx2, yy2, xx3, yy3) + d2(xx3, yy3, xx4, yy4);
    if (dd > d) {
      x1 = xx1;
      y1 = yy1;
      x2 = xx2;
      y2 = yy2;
      x3 = xx3;
      y3 = yy3;
      x4 = xx4;
      y4 = yy4;
    }
  }
  if (rot) {
    swap(x1, y1);
    swap(x2, y2);
    swap(x3, y3);
    swap(x4, y4);
  }
  cout << x1 << " " << y1 << "\n";
  cout << x2 << " " << y2 << "\n";
  cout << x3 << " " << y3 << "\n";
  cout << x4 << " " << y4 << "\n";
  return 0;
}