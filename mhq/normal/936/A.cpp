#include <bits/stdc++.h>
using namespace std;
long long k, d, t;
long double eps = 1e-9;
long double get(long double x) {
    long long y = (k + d - 1) / d;
    y = y * d;
    long long cur = (long long)(x / y);
    long double ans = cur * ((1.0 * k / t) + ((1.0 * y - k) / (2 * t)));
    x = x - cur * y;
    if (x < k) ans += (x / t);
    else ans += (1.0 * k / t) + (x - k) / (2 * t);
    return ans;
}
int main() {
    srand(time(0));
    cin >> k >> d >> t;
    long double l = 0;
    long double r = 2.0 * t;
    for (int iter = 0; iter <= 5000; iter++) {
        long double mid = (l + r) / 2;
        if (get(mid) > 1) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(15) << (l + r) / 2;
    return 0;
}