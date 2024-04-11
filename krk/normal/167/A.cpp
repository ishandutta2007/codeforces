#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int n, a, d;
double mx;

int main()
{
    scanf("%d %d %d", &n, &a, &d);
    while (n--) {
        int t, v; scanf("%d %d", &t, &v);
        double nt = (double)v / a;
        if (a * nt * nt / 2.0 + eps >= d) nt = sqrt(2.0 * d / a);
        else nt += (d - a * nt * nt / 2.0) / v;
        mx = max(mx, t + nt);
        printf("%.10lf\n", mx);
    }
    return 0;
}