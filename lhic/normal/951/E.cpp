#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

struct point {
    ll x, y;
    point() {
        x = y = 0;
    }
    point(ll x, ll y): x(x), y(y) {}
    point operator+(point a) {
        return point(x + a.x, y + a.y);
    }
    point operator-(point a) {
        return point(x - a.x, y - a.y);
    }
    ll operator*(point a) {
        return x * a.y - y * a.x;
    }
    ll operator^(point a) {
        return x * a.x + y * a.y;
    }
};

int n;

point ptmp[2100];
point p[6100];
int lst[6100];
int cc[6100];

bool cmp(point a, point b) {
    if (a.y >= 0 && b.y < 0)
        return 1;
    if (a.y < 0 && b.y >= 0)
        return 0;
    return a * b > 0;
}


ull get(ull x) {
    if (x <= 1)
        return 0;
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ptmp[i].x >> ptmp[i].y;
    ull ans = 0;
    for (int it = 0; it < n; ++it) {
        int now = 0;
        for (int j = 0; j < n; ++j) {
            if (it != j)
                p[now++] = ptmp[j] - ptmp[it];
        }
        int m = now;
        sort(p, p + m, cmp);
        for (int i = 0; i < m; ++i)
            p[i + m] = p[i];
        now = 0;
        for (int i = 0; i < 2 * m; ++i) {
            while (i - now >= m || p[i] * p[now] > 0)
                ++now;
            lst[i] = now;
            cc[i] = i - now;
        }
        for (int i = 0; i < m; ++i)
            cc[i] = cc[i + m];
        now = 0;
        ull cur = 0;
        ull cursum = 0;
        for (int i = 0; i < 2 * m; ++i) {
            cursum += cur;
            while (i - now >= m || p[i] * p[now] > 0) {
                cursum -= ull(i - now - 1) * get(cc[now]);
                cur -= get(cc[now]);
                ++now;
            }
            if (i >= m) {
                ans += cursum;
            }
            cur += get(cc[i]);
            cursum -= get(cc[i]);
        }
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << "\n";
    return 0;
}