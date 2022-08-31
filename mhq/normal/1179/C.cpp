#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e6 + 100;
int t[4 * maxN];
int lazy[4 * maxN];

void add(int v, int x) {
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
    t[v] = max(t[v + v], t[v + v + 1]);
}

void upd(int v, int tl, int tr, int l, int r, int val) {
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
    if (t[v] <= 0) return -1;
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int s = go(v + v + 1, tm + 1, tr);
    if (s != -1) return s;
    else return go(v + v, tl, tm);
}

int a[maxN], b[maxN];

const int INF = (int)1e6 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(1, 1, INF, 1, a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        upd(1, 1, INF, 1, b[i], -1);
    }
    int q;
    cin >> q;
    while (q--) {
        int tp, i, x;
        cin >> tp >> i >> x;
        if (tp == 1) {
            upd(1, 1, INF, 1, a[i], -1);
            a[i] = x;
            upd(1, 1, INF, 1, a[i], 1);
        }
        else {
            upd(1, 1, INF, 1, b[i], 1);
            b[i] = x;
            upd(1, 1, INF, 1, b[i], -1);
        }
        cout << go(1, 1, INF) << '\n';
    }
    return 0;
}