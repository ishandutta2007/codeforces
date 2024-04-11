#include <bits/stdc++.h>
using namespace std;

const int DX[4] = {0, 1, 0, -1}, DY[4] = {-1, 0, 1, 0};

int n, x, y;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
vector<point> ve;

long long area(point a, point b, point c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

long long dist(point a, point b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        for (int j = 0; j < 4; j++) {
            ve.push_back(point(x + DX[j], y + DY[j]));
        }
    }
    sort(ve.begin(), ve.end(), [](const point &u, const point &v) {
        return u.x < v.x || (u.x == v.x && u.y < v.y);
    });
    vector<point> hi, lo;
    for (point &v : ve) {
        while (hi.size() >= 2 && area(hi[hi.size() - 2], hi.back(), v) >= 0) {
            hi.pop_back();
        }
        hi.push_back(v);
        while (lo.size() >= 2 && area(lo[lo.size() - 2], lo.back(), v) <= 0) {
            lo.pop_back();
        }
        lo.push_back(v);
    }
    long long ans = 0;
    for (int i = 1; i < hi.size(); i++) {
        ans += dist(hi[i - 1], hi[i]);
    }
    for (int i = 1; i < lo.size(); i++) {
        ans += dist(lo[i - 1], lo[i]);
    }
    cout << ans;
}