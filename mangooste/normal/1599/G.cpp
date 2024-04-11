#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

struct point {
    int x, y, id;

    point operator-(const point &pt) const {
        return {x - pt.x, y - pt.y, -1};
    }

    ll length2() const {
        return 1ll * x * x + 1ll * y * y;
    }

    bool operator<(const point &pt) const {
        return pair{x, y} < pair{pt.x, pt.y};
    }

    friend istream& operator>>(istream &in, point &pt) {
        return in >> pt.x >> pt.y;
    }
};

struct line {
    ll a, b, c;

    line(const point &pa, const point &pb) : a(pb.y - pa.y), b(pa.x - pb.x), c(-pa.x * a - pa.y * b) {}

    ll value(const point &pt) const {
        return a * pt.x + b * pt.y + c;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k, k--;

    vector<point> a(n);
    for (auto &pt : a) cin >> pt;
    for (int i = 0; i < n; i++) a[i].id = i;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<point> on_line;
    point special;

    while (true) {
        int i = rng() % n, j;
        do j = rng() % n; while (i == j);

        line ln(a[i], a[j]);
        for (int i = 0; i < n; i++) {
            if (ln.value(a[i]) == 0) {
                on_line.push_back(a[i]);
            } else {
                special = a[i];
            }
        }
        if (len(on_line) < n - 1) {
            on_line.clear();
            continue;
        }
        if (len(on_line) == n) {
            special = on_line.back();
            on_line.pop_back();
        }
        break;
    }

    sort(all(on_line));
    vector<ld> dist(n - 1);
    for (int i = 0; i < n - 1; i++) {
        dist[i] = sqrtl((on_line[i] - on_line[0]).length2());
    }

    ld ans = 1e18;
    if (special.id == k) {
        for (int i = 0; i < n - 1; i++) {
            ld left = dist[i];
            ld right = dist.back() - dist[i];
            ans = min(ans, sqrtl((special - on_line[i]).length2()) + left + right + min(left, right));
        }
    } else {
        int pos = 0;
        while (on_line[pos].id != k) pos++;

        for (int rot = 0; rot < 2; rot++, reverse(all(on_line)), pos = n - 2 - pos) {
            for (int i = 0; i < n - 1; i++) {
                dist[i] = sqrtl((on_line[i] - on_line[0]).length2());
            }

            ld mn = 1e18;
            for (int i = 0; i < n - 1; i++) {
                mn = min(mn, dist[i] + (i == n - 2 ? 0 : dist.back() - dist[i + 1])
                    + sqrtl((on_line[i] - special).length2()) + (i == n - 2 ? 0 : sqrtl((on_line[i + 1] - special).length2())));
            }
            ans = min(ans, dist[pos] + mn);
            ans = min(ans, dist[pos] + sqrtl((on_line[0] - special).length2())
                + (pos == n - 2 ? 0 : sqrtl((on_line[pos + 1] - special).length2()) + dist.back() - dist[pos + 1]));
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
}