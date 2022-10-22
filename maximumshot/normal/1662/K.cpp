#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

const ld MX = 1e4;
const int N = 43;

struct point {
     ld x, y;

     ld dist(point o) {
        return sqrtl((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
     }
};

ld get(point a, point b, point c) {

    auto get3 = [&] (point d) {
        return d.dist(a) + d.dist(b) + d.dist(c);
    };

    auto get2 = [&](ld mx, ld my) {
        point d({mx, my});
        return get3(d);
    };

    auto get1 = [&](ld mx) {
            ld ly = -MX, ry = MX;
            for (int j = 0; j < N; j++) {
                ld m1y = (2 * ly + ry) / 3;
                ld m2y = (ly + 2 * ry) / 3;
                if (get2(mx, m1y) > get2(mx, m2y)) ly = m1y;
                else ry = m2y;
            }
        return get2(mx, (ly + ry) / 2);
    };

    ld lx = -MX, rx = MX;
    for (int i = 0; i < N; i++) {
        ld m1x = (2 * lx + rx) / 3;
        ld m2x = (lx + 2 * rx) / 3;
        if (get1(m1x) > get1(m2x)) lx = m1x;
        else rx = m2x;
    }
    return get1((lx + rx) / 2);
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;


    auto get2 = [&](ld mx, ld my) {
        point d({mx, my});
        return max(get(a, b, d), max(get(a, c, d), get(b, c, d)));
    };

    auto get1 = [&](ld mx) {
            ld ly = -MX, ry = MX;
            for (int j = 0; j < N; j++) {
                ld m1y = (2 * ly + ry) / 3;
                ld m2y = (ly + 2 * ry) / 3;
                if (get2(mx, m1y) > get2(mx, m2y)) ly = m1y;
                else ry = m2y;
            }
        return get2(mx, (ly + ry) / 2);
    };

    ld lx = -MX, rx = MX;
    for (int i = 0; i < N; i++) {
        ld m1x = (2 * lx + rx) / 3;
        ld m2x = (lx + 2 * rx) / 3;
        if (get1(m1x) > get1(m2x)) lx = m1x;
        else rx = m2x;
    }
    cout << fixed << setprecision(20) << get1((lx + rx) / 2) << '\n';


    return 0;
}