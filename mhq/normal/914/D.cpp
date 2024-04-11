#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e5 + 10;
int a[maxN];
int t[4 * maxN];
int n, q;
int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        if (x < y) swap(x, y);
        x %= y;
    }
    return x + y;
}
void build(int tl, int tr, int v) {
    int mid = (tl + tr) / 2;
    if (tl == tr) {
        t[v] = a[tl];
        return ;
    }
    build(tl, mid, 2 * v);
    build(mid + 1, tr, 2 * v + 1);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
        return ;
    }
    int mid = (tl + tr) / 2;
    if (pos <= mid) {
        upd(v * 2, tl, mid, pos, val);
    }
    else upd(2 * v + 1, mid + 1, tr, pos, val);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}
bool getf(int v, int tl, int tr, int l, int r, int d) {
    if (l > r) return true;
    if (l == tl && r == tr) {
        return ((t[v] % d) == 0);
    }
    int mid = (tl + tr) / 2;
    bool ok1 = getf(2 * v, tl, mid, l, min(r, mid), d);
    bool ok2 = getf(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, d);
    return (ok1 && ok2);
}
bool gets(int v, int tl, int tr, int l, int r, int d) {
    int mid = (tl + tr) / 2;
    if (l >= r) return true;
    if (r <= mid) {
        return gets(2 * v, tl, mid, l, r, d);
    }
    if (l >= mid + 1) {
        return gets(2 * v + 1, mid + 1, tr, l, r, d);
    }
    bool ok1 = getf(2 * v, tl, mid, l, mid, d);
    bool ok2 = getf(2 * v + 1, mid + 1, tr, mid + 1, r, d);
    if (ok1) {
        return gets(2 * v + 1, mid + 1, tr, mid + 1, r, d);
    }
    if (ok2) {
        return gets(2 * v, tl, mid, l, mid, d);
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    build(1, n, 1);
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 2) {
            int pos, val;
            cin >> pos >> val;
            a[pos] = val;
            upd(1, 1, n, pos, val);
        }
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            if (gets(1, 1, n, l, r, x)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}