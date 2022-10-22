#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int Maxn = 10000, Maxm = 100000;
const double g = 9.8, lim = 0.78539816;

double v, a[Maxn], d[Maxm], u[Maxm];
int n, m;
pair <double, double> c[Maxm];

void Find(double l, double r, int i, double &res)
{
     if (l + 0.00000001 > r) return;
     double mid = (l + r) / 2;
     double ans = (v*v*sin(2*mid)*c[i].first - g*c[i].first*c[i].first) / (2*v*v*cos(mid)*cos(mid));
     if (ans > c[i].second) Find(l, mid-0.00000001, i, res);
     else {
          res = mid;
          Find(mid+0.00000001, r, i, res);
     }
}

void Find2(int l, int r, int i, int &res)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     if (d[mid] <= a[i] && a[i] <= u[mid]) {
                res = mid;
                Find2(l, mid-1, i, res);
     } else Find2(mid+1, r, i, res);
}

int main()
{
    int i, tmp;
    cin >> n >> v;
    for (i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (i = 0; i < m; i++) cin >> c[i].first >> c[i].second;
    sort(c, c+m);
    for (i = 0; i < m; i++) {
        d[i] = asin(g*c[i].first/v/v) / 2;
        Find(0, lim, i, u[i]);
    }
    for (i = 1; i < m; i++) {
        u[i] = max(u[i-1], u[i]);
        d[i] = min(d[i-1], d[i]);
    }
    for (i = 0; i < n; i++) {
        tmp = -1;
        Find2(0, m-1, i, tmp);
        if (tmp == -1) cout << fixed << setprecision(9) << v*v*sin(2*a[i])/g << " " << 0.000000000 << endl;
        else cout << fixed << setprecision(9) << c[tmp].first << " " << fixed << setprecision(9)
                  << (v*v*sin(2*a[i])*c[tmp].first - g*c[tmp].first*c[tmp].first) / (2*v*v*cos(a[i])*cos(a[i])) << endl;
    }
    return 0;
}