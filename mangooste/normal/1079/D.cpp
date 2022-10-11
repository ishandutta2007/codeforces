#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

#define int ll

inline ld sqr(ld x) {
    return x * x;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int a, b, c;
    cin >> a >> b >> c;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (a == 0 || b == 0) {
        cout << abs(x2 - x1) + abs(y2 - y1) << '\n';
        return 0;
    }

    auto get_x = [&](int y) {
        return ld(-c - 1ll * b * y) / a;
    };
    auto get_y = [&](int x) {
        return ld(-c - 1ll * a * x) / b;
    };
    ld ans = abs(x2 - x1) + abs(y2 - y1);
    auto get_where = [&](int x, int y) {
        ar<ar<ld, 3>, 2> maybe;
        {
            ld yy = get_y(x);
            maybe[0][0] = x;
            maybe[0][1] = yy;
            maybe[0][2] = abs(yy - y);
        }
        {
            ld xx = get_x(y);
            maybe[1][0] = xx;
            maybe[1][1] = y;
            maybe[1][2] = abs(xx - x);
        }
        return maybe;
    };
    auto where11 = get_where(x1, y1);
    auto where22 = get_where(x2, y2);
    for (auto where1 : where11)
        for (auto where2 : where22)
                ans = min(ans, sqrt(sqr(where1[0] - where2[0]) + sqr(where1[1] - where2[1])) + where1[2] + where2[2]);
    cout << ans << '\n';
}