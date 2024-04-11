#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

istream& operator >> (istream &in, __int128 &x) {
    ll value;
    in >> value;
    x = value;
    return in;
}

#define Vec Point
struct Point {
    __int128 x, y;

    Point() : x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}
    Vec(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}

    ll sqrLength() {
        return x * x + y * y;
    }

    bool operator < (Point point) const {
        return x < point.x || (x == point.x && y > point.y);
    }

    ll operator % (Point point) const {
        return x * point.y - y * point.x;
    }

    friend istream& operator >> (istream &in, Point &point) {
        return in >> point.x >> point.y;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto &point : points) cin >> point;
    for (auto &point : points) point.y -= point.x * point.x;

    sort(all(points));
//    sort(points.begin() + 1, points.end(), [&](Point a, Point b) {
//        ll product = Vec(points[0], a) % Vec(points[0], b);
//        if (product != 0) return product > 0;
//        return Vec(points[0], a).sqrLength() < Vec(points[0], b).sqrLength();
//    });

    vector<Point> hull;
    hull.reserve(n);
    hull.emplace_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (sz(hull) > 1 && Vec(hull.end()[-2], hull.end()[-1]) % Vec(hull.end()[-2], points[i]) >= 0)
            hull.pop_back();
        if (hull.back().x != points[i].x)
            hull.emplace_back(points[i]);
    }
    cout << sz(hull) - 1 << '\n';

//    int ans = 0;
//    bool needToAdd = false;
//    hull.emplace_back(hull[0]);
//    for (int i = 0; i < sz(hull) - 1; i++) {
//        ans += needToAdd && hull[i].x != hull[i + 1].x;
//        if (hull[i].x == hull[i + 1].x) needToAdd ^= 1;
//        if (i == sz(hull) - 2) continue;
//        ll p1 = Vec(hull[i], hull[i + 1]) % Vec(0, 1);
//        ll p2 = Vec(0, 1) % Vec(hull[i + 1], hull[i + 2]);
//        if (p1 * p2 > 0) needToAdd ^= 1;
//    }
//    cout << ans << '\n';
}