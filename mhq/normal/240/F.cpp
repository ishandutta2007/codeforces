#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
const int A = 26;
int t[4 * maxN][A];
int lazy[4 * maxN][A];
int val[maxN];
int sz[4 * maxN];
void merge(int id, int v) {
    t[v][id] = t[2 * v][id] + t[2 * v + 1][id];
}
void apply(int id, int v, int clr) {
    lazy[v][id] = clr;
    if (clr == 1) t[v][id] = sz[v];
    else t[v][id] = 0;
}
void push(int id, int v, int tl, int tr) {
    if (lazy[v][id] != -1 && tl != tr) {
        apply(id, 2 * v, lazy[v][id]);
        apply(id, 2 * v + 1, lazy[v][id]);
    }
    lazy[v][id] = -1;
}
void build(int v, int tl, int tr) {
    sz[v] = tr - tl + 1;
    if (tl == tr) {
        t[v][val[tl]] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    for (int z = 0; z < A; z++) merge(z, v);
}
int res[A];
int get(int id, int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return t[v][id];
    }
    if (tr < l || tl > r) return 0;
    push(id, v, tl, tr);
    int tm = (tl + tr) / 2;
    return get(id, 2 * v, tl, tm, l, r) + get(id, 2 * v + 1, tm + 1, tr, l, r);
}
void upd(int id, int v, int tl, int tr, int l, int r, int clr) {
    if (l <= tl && tr <= r) {
        apply(id, v, clr);
        return;
    }
    if (tr < l || tl > r) return;
    int tm = (tl + tr) / 2;
    push(id, v, tl, tr);
    upd(id, 2 * v, tl, tm, l, r, clr);
    upd(id, 2 * v + 1, tm + 1, tr, l, r, clr);
    merge(id, v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        val[i] = c - 'a';
    }
    memset(lazy, -1, sizeof lazy);
    build(1, 1, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        int who_odd = -1;
        bool ok = true;
        for (int z = 0; z < A; z++) {
            res[z] = get(z, 1, 1, n, l, r);
            if (res[z] & 1) {
                if (who_odd != -1) ok = false;
                else who_odd = z;
            }
        }
        if (!ok) {
            continue;
        }
        if (who_odd != -1) res[who_odd] -= 1;
        int cur_l = l;
        int cur_r = r;
        for (int t = 0; t < A; t++) {
            upd(t, 1, 1, n, l, r, 0);
            if (res[t]) {
                upd(t, 1, 1, n, cur_l, cur_l + res[t] / 2 - 1, 1);
                upd(t, 1, 1, n, cur_r - res[t] / 2 + 1, cur_r, 1);
                cur_l += res[t] / 2;
                cur_r -= res[t] / 2;
            }
        }
        if (who_odd != -1) {
            assert(cur_l == cur_r && cur_l == (l + r) / 2);
            upd(who_odd, 1, 1, n, cur_l, cur_l, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int z = 0; z < A; z++) {
            if (get(z, 1, 1, n, i, i)) {
                cout << (char)(z + 'a');
                break;
            }
        }
    }
    return 0;
}