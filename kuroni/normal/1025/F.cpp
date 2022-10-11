#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2005;

int n, x[N], y[N], pos[2];
long long ans = 0;

struct point {
    int x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    bool upper() const {
        return y == 0 ? x > 0 : y > 0;
    }

    inline bool operator<(const point &oth) const {
        if (upper() != oth.upper()) {
            return upper();
        } else {
            return 1LL * y * oth.x - 1LL * x * oth.y < 0;
        }
    }
};
vector<pair<point, bool>> ve;

void solve(int cen) {
    ve.clear();
    pos[0] = pos[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i != cen) {
            int cx = x[i] - x[cen], cy = y[i] - y[cen];
            ve.push_back({point(cx, cy), true});
            ve.push_back({point(-cx, -cy), false});
            pos[!point(cx, cy).upper()]++;
        }
    }
    sort(ve.begin(), ve.end());
    for (pair<point, bool> &v : ve) {
        if (v.se) {
            pos[0]--;
            ans += 1LL * pos[0] * (pos[0] - 1) / 2 * pos[1] * (pos[1] - 1) / 2;
            pos[1]++;
        } else {
            point tmp = point(-v.fi.x, -v.fi.y);
            pos[1]--;
            pos[0]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    cout << ans / 2;
}