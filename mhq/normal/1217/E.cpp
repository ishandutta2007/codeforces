#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int pw10[10];
const int INF = (int)1e9 + 100;
struct node{
    vector < pair < int, int > > all;
    node() {
        all.resize(9, make_pair(INF, INF));
    }
    node(int x) {
        all.resize(9, make_pair(INF, INF));
        for (int i = 0; i < 9; i++) {
            if ((x / pw10[i]) % 10 != 0) all[i].first = x;
        }
    }

};

node merge(node& a, node& b) {
    node c;
    for (int i = 0; i < 9; i++) {
        auto tA = a.all[i];
        auto tB = b.all[i];
        if (tB.first < tA.first) swap(tA, tB);
        if (tB.first < tA.second) tA.second = tB.first;
        c.all[i] = tA;
    }
    return c;
}

const int maxN = 2 * (int)1e5 + 100;

node t[4 * maxN];

int a[maxN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = node(a[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = node(a[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos);
    else upd(2 * v + 1, tm + 1, tr, pos);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else {
        node f1 = get(2 * v, tl, tm, l, tm);
        node f2 = get(2 * v + 1, tm + 1, tr, tm + 1, r);
        return merge(f1, f2);
    }
}

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    pw10[0] = 1;
    for (int i = 1; i < 9; i++) {
        pw10[i] = 10 * pw10[i - 1];
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, x;
            cin >> i >> x;
            a[i] = x;
            upd(1, 1, n, i);
        }
        else {
            int l, r;
            cin >> l >> r;
            node p = get(1, 1, n, l, r);
            int best = 2 * INF;
            for (int j = 0; j < 9; j++) {
                if (p.all[j].first == INF || p.all[j].second == INF) continue;
                best = min(best, p.all[j].first + p.all[j].second);
            }
            if (best == 2 * INF) cout << -1 << '\n';
            else cout << best << '\n';
        }
    }
    return 0;
}