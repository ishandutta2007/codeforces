
#include <bits/stdc++.h>

#define ll long long
using namespace std;

double a, v, l, d, w;

double solve1(double d) {
    double t = (d - (v * v - w * w) / (2 * a)) / v + (v - w) / a;
    if(t - (v - w) / a >= 0) {
        return t;
    }
    return (-w + sqrt(w * w + 2 * d * a)) / a;
}

double solve2(double d) {
    double t0 = w / a;
    double d2 = d - a * t0 * t0 / 2;
    if(d2 <= 0) {
        t0 = sqrt(2 * d / a);
        w = a * t0;
        return t0;
    }
    t0 = v / a;
    d2 = d - a * t0 * t0 / 2;
    double t = (d2 - (v * v - w * w) / (2 * a)) / v + (v - w) / a;
    if(d2 >= 0 && t - (v - w) / a >= 0) {
        return t + t0;
    }
    double t1 = sqrt(d / a + w * w / (2 * a * a));
    t = 2 * t1 - w / a;
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> v >> l >> d >> w;
    w = min(w, v);
    cout << fixed << setprecision(8);
    double t1 = solve2(d);
    double t2 = solve1(l - d);
    cout << t1 + t2 << endl;
}