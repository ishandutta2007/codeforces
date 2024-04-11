#include <cstdio>
using namespace std;

const double eps = 1e-8;

int vp, vd, t, f;
double wh, c;
int res;

int main()
{
    scanf("%d %d %d %d %lf", &vp, &vd, &t, &f, &c);
    if (vp >= vd) { printf("0\n"); return 0; }
    wh = double(t) * double(vp);
    while (wh + eps < c) {
          double tim = wh / double(vd - vp);
          wh += tim * double(vp);
          if (wh + eps >= c) break;
          res++;
          wh += (tim + double(f)) * vp;
    }
    printf("%d\n", res);
    return 0;
}