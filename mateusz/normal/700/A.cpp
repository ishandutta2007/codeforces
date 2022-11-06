#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long double l, v1, v2;
int n, k;

int main() {

    cin >> n >> l >> v1 >> v2 >> k;

    long double low = l / v2;
    long double high = l / v1;
    long double ret = high;

    long double oldL = l;
    for (int zz = 1; zz <= 100; zz++) {
        long double mid = (low + high) / 2;
        l = oldL;
        long double t = mid;
        for (int i = 1; i <= (n + k - 1) / k; i++) {
            if (i == (n + k - 1) / k) {
                t -= l / v2;
                break;
            }
            long double t1 = (l - t * v1) / (v2 - v1);
            long double t2 = (t1 * v2 - t1 * v1) / (v1 + v2);
            t -= t1;
            if (i < (n + k - 1) / k) {
                t -= t2;
            }
            if (t < 0) break;
            l -= (t1 + t2) * v1;
            if (l <= 0) break;
        }
        if (t >= 0) {
            ret = mid;
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(10) << ret << endl;

    return 0;
}