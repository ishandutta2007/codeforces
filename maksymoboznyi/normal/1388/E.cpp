#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e3 + 5;

struct Seg {
    int x1, x2, y;
};

bool cmp(Seg a, Seg b) {
    return a.y < b.y;
}

int n;
Seg a[N];

double get(int x1, int y1, int x2, int y2) {
    return (y1 - y2) * 1.0 / (x1 - x2);
}

double go1(double b) {
    double mn = 1e18, mx = -1e18;
    for (int i = 1; i <= n; i++) {
        if (b == 0) {
            double v = a[i].x1;
            mn = min(mn, v);
            v = a[i].x2;
            mx = max(mx, v);
            continue;
        }
        double v = a[i].x1 + a[i].y * 1.0 / b;
        mn = min(mn, v);
        v = a[i].x2 + a[i].y * 1.0 / b;
        mx = max(mx, v);
    }
    return mx - mn;
}

double go2(double b) {
    double mn = 1e18, mx = -1e18;
    for (int i = 1; i <= n; i++) {
        if (b == 0) {
            double v = a[i].x1;
            mn = min(mn, v);
            v = a[i].x2;
            mx = max(mx, v);
            continue;
        }
        double v = a[i].x1 - a[i].y * 1.0 / b;
        mn = min(mn, v);
        v = a[i].x2 - a[i].y * 1.0 / b;
        mx = max(mx, v);
    }
    return mx - mn;
}

bool can_easy() {
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (max(a[j].x1, a[i].x1) < min(a[j].x2, a[i].x2)) {
                //cout << i << ' ' << j << endl;
                return 0;
            }
    return 1;
}

double f(double b) {
    if (b <= 1e-8)
        return go1(-b);
    return go2(b);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x1 >> a[i].x2 >> a[i].y;

    sort(a + 1, a + n + 1, cmp);
    int mx = 0;
    vector<pair<double, double> > q;
    vector<double> check;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (a[j].y < a[i].y) {
                if (a[j].x2 <= a[i].x1)
                    continue;
                if (a[j].x2 <= a[i].x2 && a[j].x1 <= a[i].x1) {
                    q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                    mx++;
                    continue;
                }
                if (a[j].x2 <= a[i].x2 && a[j].x1 >= a[i].x1) {
                    q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                    mx++;
                    continue;
                }
                if (a[j].x2 >= a[i].x2 && a[j].x1 <= a[i].x1) {
                    q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                    mx++;
                    continue;
                }
                if (a[j].x2 >= a[i].x2 && a[j].x1 <= a[i].x2) {
                    q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                    mx++;
                    continue;
                }
                q.pb({-1e9, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                mx++;
            }
    }
    if (can_easy()) {
        check.pb(0);
    }
    int cur = 0;
    vector<pair<double, double> > v;
    for (auto p: q)
        v.pb({p.first, 0}), v.pb({p.second, 1});//, cout << p.first << ' ' << p.second << endl;
    sort(all(v));
    double mn = 0, ans = 1e18;
    if (q.size() == 0)
        ans = min(ans, go1(0.0));
    for (auto p: v)
        if (p.second == 0) {
            cur++;
            if (cur == mx && p.first != -1e9) {
                check.pb(p.first);
            }
        } else {

            if (cur == mx && p.first != 1e9) {
                check.pb(p.first);

            }
            cur--;
        }

    mx = 0;
    q.clear();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (a[j].y < a[i].y) {
                if (a[j].x2 < a[i].x1) {
                    q.pb({get(a[i].x1, a[i].y, a[j].x2, a[j].y), 1e9});
                    q.pb({0, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                    mx++;
                    continue;
                }
                if (a[j].x2 <= a[i].x2 && a[j]. x1 <= a[i].x1) {
                    q.pb({0, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                    mx++;
                    continue;
                }
                if (a[j].x2 <= a[i].x2 && a[j].x1 >= a[i].x1) {
                    q.pb({0, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                    mx++;
                    continue;
                }
                if (a[j].x2 >= a[i].x2 && a[j].x1 <= a[i].x1) {
                    q.pb({0, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                    mx++;
                    continue;
                }
                if (a[j].x2 >= a[i].x2 && a[j].x1 <= a[i].x2) {
                    q.pb({0, get(a[i].x2, a[i].y, a[j].x1, a[j].y)});
                    mx++;
                    continue;
                }
            }
    }

    cur = 0;
    v.clear();
    for (auto p: q)
        v.pb({p.first, 0}), v.pb({p.second, 1});
    sort(all(v));
    mn = 0;
    for (auto p: v)
        if (p.second == 0) {
            cur++;
            if (cur == mx && p.first != 0 ) {
check.pb(p.first);
            }
        } else {
            if (cur == mx && p.first != 1e9 ) {
            check.pb(p.first);
            }
            cur--;

        }
    sort(all(check));
    int l = 0, r = check.size() - 1;
    while (r - l > 1000) {
        int y1 = (2 * l + r) / 3, y2 = (l + 2 * r) / 3;
        if (f(check[y1]) < f(check[y2]))
            r = y2;
        else
            l = y1;
    }
    for (int i = l; i <= r; i++)
        ans = min(ans, f(check[i]));
    cout << fixed << setprecision(9) << ans;
    return 0;
}