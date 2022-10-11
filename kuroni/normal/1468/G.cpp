#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, h;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    point(point a, point b) {
        x = a.x - b.x;
        y = a.y - b.y;
    }

    long double dist() {
        return hypot(x, y);
    }

    long long operator*(point oth) {
        return 1LL * x * oth.y - 1LL * y * oth.x;
    }
} pt[N];

long long cross(point a, point b, point c) {
    return point(a, b) * point(a, c);
}

pair<long double, long double> slope(point fi, point se) {
    long double a = (long double)1.0 * (se.y - fi.y) / (se.x - fi.x);
    long double b = se.y - a * se.x;
    return {a, b};
}

pair<long double, long double> inter(point a, point b, point c, point d) {
    auto [a1, b1] = slope(a, b);
    auto [a2, b2] = slope(c, d);
    long double x = (b2 - b1) / (a1 - a2);
    long double y = a1 * x + b1;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> pt[i].x >> pt[i].y;
    }
    point eye = point(pt[n].x, pt[n].y + h);
    int cur = n - 1;
    long double ans = point(pt[n], pt[n - 1]).dist();
    for (int i = n - 2; i >= 1; i--) {
        if (cross(eye, pt[cur], pt[i]) == 0) {
            if (i == cur - 1) {
                ans += point(pt[i + 1], pt[i]).dist();
            }
            cur = i;
        } else if (cross(eye, pt[cur], pt[i]) < 0) {
            pair<long double, long double> it = inter(eye, pt[cur], pt[i], pt[i + 1]);
            ans += hypot(it.first - pt[i].x, it.second - pt[i].y);
            cur = i;
        }
    }
    cout << fixed << setprecision(10) << ans;
}