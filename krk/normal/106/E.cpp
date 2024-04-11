#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 5e-7;
const double Inf = 1e9;
const int Maxn = 105;
const int Maxl = 3;
const double lim = 10000;

int n;
int x[Maxn], y[Maxn], z[Maxn];
double c[Maxl];

double ternarySearch(int lvl, double l, double r)
{
    if (lvl == Maxl) {
            double X = c[0], Y = c[1], Z = c[2];
            double mx = 0.0;
            for (int i = 0; i < n; i++)
                mx = max(mx, (c[0] - x[i]) * (c[0] - x[i]) + (c[1] - y[i]) * (c[1] - y[i]) + 
                             (c[2] - z[i]) * (c[2] - z[i]));
            return mx;
    } else {
           if (l + eps > r) return Inf;
           double p1 = (2.0 * l + r) / 3.0, p2 = (l + 2.0 * r) / 3.0;
           c[lvl] = p1; double val1 = ternarySearch(lvl + 1, -lim, lim);
           c[lvl] = p2; double val2 = ternarySearch(lvl + 1, -lim, lim);
           if (val1 < val2) { c[lvl] = p1; return min(val1, ternarySearch(lvl, l, p2 - eps)); }
           return min(val2, ternarySearch(lvl, p1 + eps, r));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    ternarySearch(0, -lim, lim);
    cout << fixed << setprecision(8);
    cout << c[0] << " " << c[1] << " " << c[2] << endl;
    return 0;
}