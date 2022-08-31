#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
// convex-hull from http://e-maxx.ru/algo/convex_hull_graham
struct pt {
    ll x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}
int n;
map < int, int > largest;
const ld eps = 1e-12;
signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (!largest.count(x)) largest[x] = y;
        else largest[x] = max(largest[x], y);
    }
    vector < pt > all;
    for (auto t : largest) {
        all.push_back({t.first, t.second - 1LL * t.first * t.first});
        //cout << all.back().x << " " << all.back().y << endl;
    }
    convex_hull(all);
    if (all.size() == 1) {
        cout << 0;
        return 0;
    }
    if (all.size() == 2) {
        cout << 1;
        return 0;
    }
    int ans = 0;
    for (int j = 0; j < all.size(); j++) {
        pt a = all[j];
        pt b = all[(j + 1) % all.size()];
        if (b.x < a.x) swap(b, a);
        bool ok = true;
        for (int t = j - 2; t <= j + 2; t++) {
            pt f = all[(t + 10 * all.size()) % all.size()];
            if ((b.y - a.y) * (f.x - a.x) < (b.x - a.x) * (f.y - a.y)) ok = false;
        }
        if (ok) {
            ans++;
           // cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
        }
    }
    cout << ans;
    return 0;
}