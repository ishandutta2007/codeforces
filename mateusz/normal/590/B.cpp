#include <bits/stdc++.h>

using namespace std;

long double dist(long double xA, long double yA, long double xB, long double yB) {
    return sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
}

int xA, yA, xB, yB, vMax, t, vx, vy, wx, wy;

int main() {

    ios_base::sync_with_stdio(0);

    cin >> xA >> yA >> xB >> yB;
    cin >> vMax >> t;
    cin >> vx >> vy >> wx >> wy;

    long double low = 0.0;
    long double high = 1e9;
    long double ans = high;

    for (int zz = 1; zz <= 10000; zz++) {
        long double mid = (low + high) / 2;
        long double endPositionX = xB - min((long double)t, mid) * vx - max(0.0L, mid - t) * wx;
        long double endPositionY = yB - min((long double)t, mid) * vy - max(0.0L, mid - t) * wy;
        long double d = dist(xA, yA, endPositionX, endPositionY);
        if (mid * vMax >= d) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}