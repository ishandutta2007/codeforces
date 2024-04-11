#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
ll s[maxN];
ll t[4 * maxN];
ll lazy[4 * maxN];

void add(int v, ll x) {
    t[v] += x;
    lazy[v] += x;
}

void push(int v, int tl, int tr) {
    if (tl != tr) {
        add(2 * v, lazy[v]);
        add(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}

void update(int v) {
    t[v] = min(t[v + v], t[v + v + 1]);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = s[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (l <= tl && tr <= r) {
        lazy[v] += val;
        t[v] += val;
        return;
    }
    if (l > tr || tl > r) {
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, r, val);
    upd(v + v + 1, tm + 1, tr, l, r, val);
    update(v);
}

int go(int v, int tl, int tr) {
    push(v, tl, tr);
    if (t[v] > 0) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int s = go(v + v + 1, tm + 1, tr);
    if (s != -1) return s;
    else return go(v + v, tl, tm);
}

int ans[maxN];
const ll INF = 1e15;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int where = go(1, 1, n);
        ans[where] = i;
        upd(1, 1, n, where, where, INF);
        if (where < n) upd(1, 1, n, where + 1, n, -i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}