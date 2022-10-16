/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200000;

int n, v;
int t[N_MAX + 2];
int a[N_MAX + 2];

struct Point {
    ll x, y;
};
Point p[N_MAX + 2];

void compress () {
    vector <ll> xs, ys;
    for (int i = 0; i <= n; i++) {
        xs.push_back(p[i].x);
        ys.push_back(p[i].y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    map <ll, int> xmp, ymp;
    for (int i = 0; i < (int) xs.size(); i++) {
        xmp[xs[i]] = i + 1;
    }
    for (int i = 0; i < (int) ys.size(); i++) {
        ymp[ys[i]] = i + 1;
    }
    for (int i = 0; i <= n; i++) {
        p[i] = Point{xmp[p[i].x], ymp[p[i].y]};
    }
}

int Fen[N_MAX + 2];
void update (int pos, int val) {
    for (int i = pos; i >= 1; i -= i & -i) {
        Fen[i] = max(Fen[i], val);
    }
}
int query (int pos) {
    int val = INT_MIN / 2;
    for (int i = pos; i <= n + 1; i += i & -i) {
        val = max(val, Fen[i]);
    }
    return val;
}

int solve () {
    compress();
    sort(p + 1, p + n + 1, [&] (const Point &p1, const Point &p2) {
        return make_pair(p1.x, -p1.y) < make_pair(p2.x, -p2.y);
    });
    fill(Fen + 1, Fen + (n + 1) + 1, INT_MIN / 2);
    update(p[0].y, 0);
    for (int i = 1; i <= n; i++) {
        if (p[i].x >= p[0].x) {
            update(p[i].y, query(p[i].y) + 1);
        }
    }
    return query(1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        p[i] = Point{a[i] + (ll) t[i] * v, a[i] - (ll) t[i] * v};
    }

    cout << solve() << "\n";

    return 0;
}