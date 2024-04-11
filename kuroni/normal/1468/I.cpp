#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, dx1, dy1, dx2, dy2;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    point(point a, point b) {
        x = a.x - b.x;
        y = a.y - b.y;
    }

    long long operator*(point oth) {
        return 1LL * x * oth.y - 1LL * y * oth.x;
    }
} ori, fi, se, en;

long long cross(point a, point b, point c) {
    return point(a, b) * point(a, c);
}

bool within(point a, point b, point c, bool rev = false) {
    if (a.x == b.x) {
        return min(a.y, b.y) <= c.y && max(a.y, b.y) >= c.y;
    } else {
        if (rev) {
            return cross(a, b, c) <= 0;
        } else {
            return cross(a, b, c) >= 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
    if (dx1 < 0 || (dx1 == 0 && dy1 < 0)) {
        dx1 = -dx1; dy1 = -dy1;
    }
    if (dx2 < 0 || (dx2 == 0 && dy2 < 0)) {
        dx2 = -dx2; dy2 = -dy2;
    }

    fi = point(dx1, dy1); se = point(dx2, dy2); en = point(dx1 + dx2, dy1 + dy2);
    if (cross(ori, fi, se) == 0) {
        return cout << "NO", 0;
    } else if (cross(ori, fi, se) < 0) {
        swap(fi, se);
    }
    vector<point> tmp;
    int lo = 0, hi = 0;
    point ll = ori, lr = ori, hl = fi, hr = se;
    for (int i = 0; i <= dx1 + dx2; i++) {
        while (!within(ll, hl, point(i, lo))) {
            lo++;
        }
        while (within(ll, hl, point(i, lo - 1))) {
            lo--;
        }
        while (!within(lr, hr, point(i, hi), true)) {
            hi--;
        }
        while (within(lr, hr, point(i, hi + 1), true)) {
            hi++;
        }
        for (int j = lo; j <= hi; j++) {
            point cur = point(i, j);
            if (cross(cur, fi, en) != 0 && cross(cur, se, en) != 0) {
                tmp.push_back(cur);
                if (tmp.size() > n) {
                    return cout << "NO", 0;
                }
            }
        }
        if (i == fi.x) {
            ll = fi; hl = en;
        }
        if (i == se.x) {
            lr = se; hr = en;
        }
    }
    if (tmp.size() < n) {
        return cout << "NO", 0;
    }
    cout << "YES\n";
    for (point u : tmp) {
        cout << u.x << " " << u.y << '\n';
    }
}