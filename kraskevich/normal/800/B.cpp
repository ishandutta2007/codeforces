#include <bits/stdc++.h>

using namespace std;

using ld = long double;

const int N = 1111;

struct Point {
    ld x, y;

    Point(ld xx = 0, ld yy = 0): x(xx), y(yy) {}

    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    ld operator*(const Point& p) const {
        return x * p.y - y * p.x;
    }

    ld operator%(const Point& p) const {
        return x * p.x + y * p.y;
    }

    ld sqr_len() const {
        return *this % *this;
    }

    ld len() const {
        return sqrtl(sqr_len());
    }

    void read() {
        cin >> x >> y;
    }
};

ld dist(Point a, Point b, Point c) {
    return fabsl((c - a) * (b - a) / (c - a).len());
}

const ld INF = 1e18;

ld res = INF;
Point p[N];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        p[i].read();
    for (int i = 0; i < n; i++)
        res = min(res, dist(p[i], p[(i + 1) % n], p[(i + 2) % n]) / 2);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res << endl;
}