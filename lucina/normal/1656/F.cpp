#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int64_t a[nax];
int n;

inline int64_t f(int64_t u, int64_t v, int64_t t) {
    return u * v + t * (u + v);
}


int64_t mst(int64_t t) {
    int cnt = 1;
    int64_t s = f(a[1], a[n], t);
    int fnt = 2, lst = n - 1;
    while (cnt != n - 1) {
        int64_t x = min(f(a[n], a[lst], t), f(a[1], a[lst], t));
        int64_t y = min(f(a[fnt], a[1], t), f(a[fnt], a[n], t));
        if (x < y) {
            s += x;
            lst -= 1;
        } else {
            s += y;
            fnt += 1;
        }
        cnt += 1;
    }
    return s;
}

/**
    sort things by slope
    -5 + c, -4, -3, -2, -1, ......,
    it's sorted this way
    the structure might change
    order set of lines
    convex hull like things
    query min(n - 1) lines at certain point?

    t -> -inf
*/

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int64_t mx = LLONG_MIN;

    int l = a[1], r = a[n];
    while (r - l > 3) {
        int m1 = l + (r - l + 1) / 3;
        int m2 = r - (r - l + 1) / 3;
        if (mst(m1) < mst(m2)) {
            l = m1 + 1;
        } else r = m2 - 1;
    }
    for (int j = l ; j <= r ; ++ j) {
        mx = max(mx, mst(j));
    }
    if (max(mst(a[1] - 1), mst(a[n] + 1)) > mx) {
        cout << "INF\n";
    } else {
        cout << mx << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}