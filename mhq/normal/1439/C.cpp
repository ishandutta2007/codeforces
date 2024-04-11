#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, q;
int a[maxN];
ll t[4 * maxN];
int mn[4 * maxN];
int cnt[4 * maxN];
int lazy[4 * maxN];
int mx[4 * maxN];
void merge(int v) {
    mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    t[v] = t[2 * v] + t[2 * v + 1];
}
void apply(int v, int x) {
    lazy[v] = x;
    mn[v] = x;
    mx[v] = x;
    t[v] = 1LL * cnt[v] * x;
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        mn[v] = a[tl];
        mx[v] = a[tl];
        t[v] = a[tl];
        cnt[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    cnt[v] = tr - tl + 1;
    merge(v);
}
void do_max(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (mn[v] >= x) return;
    if (l <= tl && tr <= r && mx[v] < x) {
        apply(v, x);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    do_max(2 * v, tl, tm, l, r, x);
    do_max(2 * v + 1, tm + 1, tr, l, r, x);
    merge(v);
}
int go(int v, int tl, int tr, int l, int r, int& y) {
    push(v, tl, tr);
    if (tl == l && tr == r) {
        if (y >= t[v]) {
            y -= t[v];
            return cnt[v];
        }
        if (mn[v] > y) {
            return 0;
        }
        int tm = (tl + tr) / 2;
        int d1 = go(2 * v, tl, tm, l, tm, y);
        int d2 = go(2 * v + 1, tm + 1, tr, tm + 1, r, y);
        return d1 + d2;
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) {
        return go(2 * v, tl, tm, l, r, y);
    }
    else if (l > tm) {
        return go(2 * v + 1, tm + 1, tr, l, r, y);
    }
    else {
        int d1 = go(2 * v, tl, tm, l, tm, y);
        int d2 = go(2 * v + 1, tm + 1, tr, tm + 1, r, y);
        return d1 + d2;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int tp, x, y;
        cin >> tp >> x >> y;
        if (tp == 1) {
            do_max(1, 1, n, 1, x, y);
        }
        else {
            cout << go(1, 1, n, x, n, y) << '\n';
        }
    }
    return 0;
}