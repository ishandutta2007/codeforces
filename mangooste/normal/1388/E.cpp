#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

struct point {
    int x, y;
    point() {}
    point(ll x, ll y) : x(x), y(y) {}

    ll operator % (point p) {
        return 1ll * x * p.y - 1ll * y * p.x;
    }

    point operator - (point p) {
        return point(x - p.x, y - p.y);
    }
};

struct event {
    point vec;
    int type, i, j;
    event(point vec, int type, int i = -1, int j = -1) : vec(vec), type(type), i(i), j(j) {}

    bool operator < (event e) {
        ll p = vec % e.vec;
        if (p != 0)
            return p > 0;
        return type > e.type;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vec<int> l(n), r(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> y[i];

    bool same = true;
    for (int i = 1; i < n; i++)
        same &= y[i] == y[i - 1];
    if (same) {
        cout << *max_element(all(r)) - *min_element(all(l)) << '\n';
        return 0;
    }

    vec<event> evs;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (y[i] > y[j]) {
                point v1(l[j] - r[i], y[j] - y[i]);
                point v2(r[j] - l[i], y[j] - y[i]);
                evs.push_back(event(v1, 0));
                evs.push_back(event(v2, 1));
            }
    sort(all(evs));

    int cnt = 0;
    vec<point> good;
    for (auto [vec, type, i, j] : evs) {
        if (type == 1)
            cnt--;
        if (!cnt)
            good.push_back(vec);
        if (type == 0)
            cnt++;
    }

    evs.clear();
    for (auto vec : good)
        evs.push_back(event(vec, 1));
    vec<point> points;
    for (int i = 0; i < n; i++) {
        points.push_back(point(l[i], y[i]));
        points.push_back(point(r[i], y[i]));
    }
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            if (points[i].y > points[j].y)
                evs.push_back(event(point(points[j].x - points[i].x, points[j].y - points[i].y), 0, i, j));
    sort(all(evs));

    vec<int> ord(2 * n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        if (points[i].y != points[j].y)
            return points[i].y < points[j].y;
        return points[i].x > points[j].x;
    });
    vec<int> where(2 * n);
    for (int i = 0; i < 2 * n; i++)
        where[ord[i]] = i;

    double ans = 1e20;
    auto get = [&](point p, point vec) {
        double k = double(-p.y) / vec.y;
        return p.x + vec.x * k;
    };
    for (int i = 0; i < len(evs); i++) {
        if (evs[i].type == 1)
            ans = min(ans, get(points[ord[0]], evs[i].vec) - get(points[ord.back()], evs[i].vec));
        else {
            int j = i;
            vec<int> cur;
            while (j < len(evs) && evs[j].type == 0 && evs[i].vec % evs[j].vec == 0) {
                auto [vec, _, i1, i2] = evs[j];
                cur.push_back(i1);
                cur.push_back(i2);
                j++;
            }
            sort(all(cur));
            cur.resize(unique(all(cur)) - cur.begin());
            sort(all(cur), [&](int a, int b) -> bool {
                if (evs[i].vec.x == 0) {
                    if (points[a].x != points[b].x)
                        return points[a].x > points[b].x;
                    return points[a].y > points[b].y;
                }
                ll p = (points[a] - points[b]) % evs[i].vec;
                if (!p) {
                    assert(points[a].y != points[b].y);
                    return points[a].y > points[b].y;
                }
                return (p > 0) ^ (evs[i].vec.x > 0);
            });
            for (int j = 0; j < len(cur);) {
                int k = j + 1;
                while (k < len(cur) && (points[cur[k]] - points[cur[j]]) % evs[i].vec == 0)
                    k++;
                int st = 2 * n;
                for (int z = j; z < k; z++)
                    st = min(st, where[cur[z]]);
                for (int z = j; z < k; z++) {
                    where[cur[z]] = st;
                    ord[st] = cur[z];
                    st++;
                }
                j = k;
            }
            i = j - 1;
        }
    }
    cout << ans << '\n';
}