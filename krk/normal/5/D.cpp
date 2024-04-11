#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-9;

double a, v, l, d, w;

double getEnd(double w)
{
    double t = (-w + sqrt(w * w + 2.0 * a * (l - d))) / a;
    if (w + a * t <= v + eps) return t;
    t = (v - w) / a;
    double s = l - d - (w * t + a * t * t / 2.0);
    return t + s / v;
}

int main()
{
    scanf("%lf %lf %lf %lf %lf", &a, &v, &l, &d, &w); w = min(w, v);
    double nw = sqrt(2.0 * a * d);
    if (nw <= w + eps) printf("%.12lf\n", nw / a + getEnd(nw));
    else {
         double l = w, r = v + eps;
         for (int i = 0; i < 44; i++) {
             double mid = (l + r) / 2.0;
             double t1 = mid / a, t2 = (mid - w) / a;
             if (a * t1 * t1 / 2.0 + mid * t2 - a * t2 * t2 / 2.0 <= d + eps) l = mid;
             else r = mid;
         }
         double t1 = l / a, t2 = (l - w) / a;
         double s = d - (a * t1 * t1 / 2.0 + l * t2 - a * t2 * t2 / 2.0);
         double t3 = s / l;
         printf("%.12lf\n", t1 + t2 + t3 + getEnd(w));
    }
    return 0;
}