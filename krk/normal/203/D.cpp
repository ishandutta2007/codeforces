#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double Inf = 1e10;
const double eps = 1e-9;

double a, b, m;
int vx, vy, vz;
double x, y, z;

int main()
{
    scanf("%lf %lf %lf", &a, &b, &m);
    scanf("%d %d %d", &vx, &vy, &vz);
    x = a / 2.0, y = m, z = 0.0;
    while (true) {
        double t1 = vx? -x / double(vx): Inf; if (t1 <= eps) t1 = Inf;
        double t2 = vx? (a - x) / double(vx): Inf; if (t2 <= eps) t2 = Inf;
        double t3 = vy? -y / double(vy): Inf; if (t3 <= eps) t3 = Inf;
        double t4 = vz? -z / double(vz): Inf; if (t4 <= eps) t4 = Inf;
        double t5 = vz? (b - z) / double(vz): Inf; if (t5 <= eps) t5 = Inf;
        double mn = min(min(t1, t2), min(min(t3, t4), t5));
        x += mn * double(vx), y += mn * double(vy), z += mn * double(vz);
        if (fabs(t3 - mn) < eps) break;
        if (fabs(t1 - mn) < eps || fabs(t2 - mn) < eps) vx = -vx;
        if (fabs(t4 - mn) < eps || fabs(t5 - mn) < eps) vz = -vz;
    }
    printf("%.10lf %.10lf\n", x, z);
    return 0;
}