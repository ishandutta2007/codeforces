#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

constexpr ld EPS = 1e-9;
constexpr ld PI = acos(-1);

struct point {
    ll x, y;

    ll length2() const {
        return x * x + y * y;
    }

    point operator-(const point &p) const {
        return {x - p.x, y - p.y};
    }

    ll operator%(const point &p) const {
        return x * p.y - y * p.x;
    }

    ll operator*(const point &p) const {
        return x * p.x + y * p.y;
    }

    int half() const {
        return pair{y, x} < pair{0ll, 0ll};
    }

    ld angle() const {
        if (half() == 0)
            return atan2(point{1, 0} % *this, point{1, 0} * *this);

        return PI + atan2(point{-1, 0} % *this, point{-1, 0} * *this);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    vector<point> a(n);
    for (auto &[x, y] : a)
        cin >> x >> y;

    vector good(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        ld from1 = 0, to1 = 4 * PI;
        ld from2 = 0, to2 = 6 * PI;

        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            auto cur = a[j] - a[i];
            if (cur.length2() <= 1ll * r * r)
                continue;

            ld base_angle = cur.angle(), angle = asin(ld(r) / sqrtl(cur.length2()));
            ld cur_from = base_angle - angle, cur_to = base_angle + angle;

            if (cur_from < 0) {
                cur_from += 2 * PI;
                cur_to += 2 * PI;
            }

            if (cur_to < 2 * PI) {
                from1 = max(from1, cur_from);
                to1 = min(to1, cur_to);
            } else {
                from2 = max(from2, cur_from);
                to2 = min(to2, cur_to);
            }
        }

        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            ld angle = (a[j] - a[i]).angle();
            good[i][j] = from1 - EPS < angle && angle < to1 + EPS
                && (from2 - EPS < angle && angle < to2 + EPS
                || from2 - EPS < angle + 2 * PI && angle + 2 * PI < to2 + EPS);
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            answer += good[i][j] && good[j][i];

    cout << answer << '\n';
}