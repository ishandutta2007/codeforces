#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

int main()
{
#ifdef MANDELBROT
    freopen("input.txt", "r", stdin);
#endif
    double x1, y1, x2, y2;
    int n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    double d = y2 - y1, e = x1 - x2, f = x2 * y1 - x1 * y2;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;

        // line 1: ax + by = c

        // line 2: dx1 + ey1 + f = dx2 + ey2 + f
        // d(x1 - x2) = e(y2 - y1) = 0
        // d = (y2 - y1), e = (x1 - x2)
        // --------------------------------------------
        // (y2 - y1)x + (x1 - x2)y = 0

        double det = a * e - b * d;
        double detx = b * f - c * e;
        double dety = c * d - a * f;

//        cerr << det << ",\t" << detx << ",\t" << dety << endl;
//        cerr << min(det * x1, det * x2) << ",\t" << max(det * x1, det * x2) << endl;
//        cerr << min(det * y1, det * y2) << ",\t" << max(det * y1, det * y2) << endl;
//        cerr << endl;

        if (det != 0 &&
                min(det * x1, det * x2) <= detx && detx <= max(det * x1, det * x2) &&
                min(det * y1, det * y2) <= dety && dety <= max(det * y1, det * y2)) {
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}