#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

const ld eps = 1e-3;

int t;
int x[3][2], y[3][2];

ld Len(ld ax, ld ay)
{
     return sqrt(ax * ax + ay * ay);
}

bool First(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
     if (x2 != x3 || y2 != y3) return false;
     long long ax = x1 - x2, ay = y1 - y2, bx = x4 - x3, by = y4 - y3;
     long long prod = ax * bx + ay * by;
     if (prod < 0) return false;
     return prod < Len(ax, ay) * Len(bx, by);
}

bool Second(int x1, int y1, int x2, int y2, int x3, int y3)
{
     if (x3 < min(x1, x2) || x3 > max(x1, x2) ||
         y3 < min(y1, y2) || y3 > max(y1, y2)) return false;
     long long ax = x1 - x3, ay = y1 - y3, bx = x2 - x3, by = y2 - y3;
     ld l1 = Len(ax, ay), l2 = Len(bx, by);
     return max(l1, l2) / min(l1, l2) <= 4.0L && 
            fabs(-Len(ax, ay) * Len(bx, by) - ld(ax * bx + ay * by)) <= eps;
}

bool Check(int x1, int y1, int x2, int y2,
           int x3, int y3, int x4, int y4,
           int x5, int y5, int x6, int y6)
{
     return First(x1, y1, x2, y2, x3, y3, x4, y4) &&
            Second(x1, y1, x2, y2, x5, y5) &&
            Second(x3, y3, x4, y4, x6, y6);
}

bool Check(int i, int j, int k)
{
     for (int i2 = 0; i2 < 2; i2++)
         for (int j2 = 0; j2 < 2; j2++)
             for (int k2 = 0; k2 < 2; k2++)
                 if (Check(x[i][i2], y[i][i2], x[i][1 - i2], y[i][1 - i2],
                           x[j][j2], y[j][j2], x[j][1 - j2], y[j][1 - j2],
                           x[k][k2], y[k][k2], x[k][1 - k2], y[k][1 - k2]))
                           return true;
     return false;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
          for (int i = 0; i < 3; i++)
              for (int j = 0; j < 2; j++)
                  cin >> x[i][j] >> y[i][j];
          if (Check(0, 1, 2) || Check(0, 2, 1) || Check(1, 2, 0)) cout << "YES\n";
          else cout << "NO\n";
    }
    return 0;
}