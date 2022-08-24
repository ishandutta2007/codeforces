#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4 * (int)1e5 + 100;
int a[maxN];
mt19937 rnd(228);
int t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
int find(int v, int tl, int tr, int l, int r, int val, bool left) {
    if (r < 1) return -1;
    if (l > r) return -1;
    if (t[v] > val) return -1;
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    if (left) {
        int p = find(2 * v, tl, tm, l, min(r, tm), val, left);
        if (p != -1) return p;
        return find(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val, left);
    }
    else {
        int p = find(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val, left);
        if (p != -1) return p;
        return find(2 * v, tl, tm, l, min(r, tm), val, left);
    }
}

pair < ll, int > tt[4 * maxN];
ll upd[4 * maxN];
void build2(int v, int tl, int tr) {
    tt[v] = make_pair(0, tl);
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build2(2 * v, tl, tm);
    build2(2 * v + 1, tm + 1, tr);
}
void push(int v, int tl, int tr) {
    if (upd[v] == 0) return;
    tt[v].first += upd[v];
    if (tl != tr) {
        upd[2 * v] += upd[v];
        upd[2 * v + 1] += upd[v];
    }
    upd[v] = 0;
}
void add(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l <= tl && tr <= r) {
        upd[v] += val;
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    if (r < tl || l > tr) return;
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, val);
    add(2 * v + 1, tm + 1, tr, l, r, val);
    tt[v] = max(tt[2 * v], tt[2 * v + 1]);
}
const ll INF = 2e9;
pair < int, int > get_mx(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l <= tl && tr <= r) return tt[v];
    if (l > r) return make_pair(-INF, -1);
    int tm = (tl + tr) / 2;
    return max(get_mx(2 * v, tl, tm, l, min(r, tm)), get_mx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
void add(int l, int r, int pos) {
    int where = find(1, 1, n, l, r, a[pos], false);
    if (where == -1) {
        add(1, 1, n, l, r, 1);
        add(1, 1, n, r + 1, r + 1, 1);
    }
    else {
        auto it = get_mx(1, 1, n, where, where);
        add(1, 1, n, where + 1, r, 1);
        add(1, 1, n, r + 1, r + 1, it.first + 1);
    }
}
void del(int l, int r, int pos) {
    int where = find(1, 1, n, l + 1, r, a[pos], true);
    if (where == -1) {
        add(1, 1, n, l + 1, r, -1);
    }
    else {
        add(1, 1, n, l + 1, where - 1, -1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    n *= 2;
    build(1, 1, n);
    build2(1, 1, n);
    for (int i = 1; i <= n / 2; i++) {
        add(1, i - 1, i);
    }
    pair < int, int > best = make_pair(get_mx(1, 1, n, 1, n / 2).first, 0);
    for (int i = n / 2 + 1; i < n; i++) {
        del(i - n / 2, i - 1, i - n / 2);
        add(i - n / 2 + 1, i - 1, i);
        best = min(best, make_pair(get_mx(1, 1, n, i - n / 2 + 1, i).first, i - n / 2));
    }
    cout << best.first << " " << best.second << '\n';
    return 0;
}