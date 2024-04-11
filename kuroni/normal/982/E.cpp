#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int m, n, x, y, vx, vy;

pair<long long, long long> solve(int ret, int a, int b) {
    if (b == 0) {
        if (ret % a != 0) {
            cout << -1;
            exit(0);
        } else {
            return {ret / a, 0};
        }
    }
    pair<long long, long long> cur = solve(ret, b, a % b);
    long long x = cur.se, y = cur.fi - a / b * cur.se;
    long long red = y / a;
    x += red * b; y -= red * a;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> x >> y >> vx >> vy;
    if (vx == 0) {
        if (x % m != 0) {
            cout << -1;
        } else {
            cout << x << " " << (vy == -1 ? 0 : n);
        }
    } else if (vy == 0) {
        if (y % n != 0) {
            cout << -1;
        } else {
            cout << (vx == -1 ? 0 : m) << " " << y;
        }
    } else {
        pair<long long, long long> ans = solve(x - vx * vy * y, m, -vx * vy * n);
        long long t = (m * ans.fi - x) * vx, div = 1LL * m * n / __gcd(m, n);
        t = (t % div + div) % div;
        int ax = ((x + vx * t) % (2 * m) != 0) * m, ay = ((y + vy * t) % (2 * n) != 0) * n;
        cout << ax << " " << ay;
    }
}