#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int cost[maxN];
int p[maxN];
ll val[maxN];
ll t[4 * maxN];
ll lazy[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = val[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
ll get() {
    return t[1];
}
void upd(int v, ll by) {
    t[v] += by;
    lazy[v] += by;
}
void push(int v, int tl, int tr) {
    if (tl != tr) {
        if (lazy[v]) {
            upd(2 * v, lazy[v]);
            upd(2 * v + 1, lazy[v]);
            lazy[v] = 0;
        }
    }
}
void upd(int v, int tl, int tr, int l, int r, ll by) {
    if (l <= tl && tr <= r) {
        upd(v, by);
        return;
    }
    if (l > tr || r < tl) return;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[p[i]];
    }
    val[0] = 0;
    for (int i = 1; i <= n; i++) val[i] = val[i - 1] + cost[i];
    build(1, 0, n);
    ll pref = 0;
    ll ans = 9e18;
    for (int i = 1; i < n; i++) {
        pref += cost[p[i]];
        upd(1, 0, n, 0, p[i] - 1, 2 * cost[p[i]]);
        ans = min(ans, get() - pref);
    }
    cout << ans;
    return 0;
}