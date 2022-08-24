#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
ll a[maxN];
int lazy[4 * maxN];
ll sum[4 * maxN];
ll min_suf[4 * maxN];
ll max_suf[4 * maxN];
void merge(int v) {
    min_suf[v] = min(min_suf[2 * v + 1], min_suf[2 * v] + sum[2 * v + 1]);
    max_suf[v] = max(max_suf[2 * v + 1], max_suf[2 * v] + sum[2 * v + 1]);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
}
void mlt(int v, int by) {
    if (by == -1) {
        lazy[v] *= by;
        swap(max_suf[v], min_suf[v]);
        max_suf[v] *= -1;
        min_suf[v] *= 1;
        sum[v] *= -1;
    }
}
void push(int v, int tl, int tr) {
    if (lazy[v] != 1 && tl != tr) {
        mlt(2 * v, lazy[v]);
        mlt(2 * v + 1, lazy[v]);
    }
    lazy[v] = 1;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        min_suf[v] = min(0LL, a[tl]);
        max_suf[v] = max(0LL, a[tl]);
        sum[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    merge(v);
}
void upd(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        mlt(v, -1);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r);
    upd(2 * v + 1, tm + 1, tr, l, r);
    merge(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 4 * n; i++) {
        lazy[i] = 1;
    }
    build(1, 1, n);
    ll best = sum[1];
    for (int pref = 0; pref <= n; pref++) {
        if (pref != 0) {
            upd(1, 1, n, 1, pref);
        }
        push(1, 1, n);
        best = max(best, sum[1] - 2 * min_suf[1]);
        if (pref != 0) {
            upd(1, 1, n, 1, pref);
        }
    }
    cout << best;
    return 0;
}