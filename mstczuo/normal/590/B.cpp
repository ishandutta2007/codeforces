# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cmath>

using namespace std;
#define y1 ____y1____

double x1, y1, x2, y2;
double vx, vy, wx, wy;
double vmax, t;

double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double xr, yr;
bool check1(double time) {
    xr = x1 + vx * time, yr = y1 + vy * time;
    return (dist(xr, yr, x2, y2) <= vmax * time);
}

bool check2(double time) {
    xr = x1 + wx * (time - t), yr = y1 + wy * (time - t);
    return (dist(xr, yr, x2, y2) <= vmax * time);
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;

    if(check1(t)) {
        double L = 0, R = t, Mid;
        while(R - L > 1e-8) check1(Mid=(L+R)/2) ? R=Mid: L=Mid;
        printf("%.18f\n", L);
    } else {
        x1 = xr; y1 = yr;
        double L = 0, R = 1e9, Mid;
        while(R - L > 1e-8) check2(Mid=(L+R)/2) ? R=Mid: L=Mid;
        printf("%.18f\n", L);
    }
}