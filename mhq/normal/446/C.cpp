#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 9;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int root_5 = 383008016;
const int inv2 = (mod + 1) / 2;
const int a1 = mult(inv2, sum(1, root_5));
const int a2 = mult(inv2, sub(1, root_5));
const int roots[2] = {a1, a2};
int coef[2];
const int maxN = 3e5 + 10;
int sz[4 * maxN];
int add[4 * maxN];
int coef_mult[2][4 * maxN];
int pw_root[2][maxN];
int pref_sum[2][maxN];
int n, m;
int a[maxN];
void merge(int v) {
    add[v] = sum(add[2 * v], add[2 * v + 1]);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        add[v] = a[tl];
        sz[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    sz[v] = sz[2 * v] + sz[2 * v + 1];
    merge(v);
}
void apply(int v, int z, int s) {
    //add += s, s * alpha, .. ,
    coef_mult[z][v] = sum(coef_mult[z][v], s);
    add[v] = sum(add[v], mult(s, pref_sum[z][sz[v] - 1]));
}
void push(int v, int tl, int tr) {
    if (tl != tr) {
        for (int z = 0; z < 2; z++) {
            apply(2 * v, z, coef_mult[z][v]);
            apply(2 * v + 1, z, mult(coef_mult[z][v], pw_root[z][sz[2 * v]]));
            coef_mult[z][v] = 0;
        }
    }
}
void add_fib(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        for (int z = 0; z < 2; z++) {
            apply(v, z, mult(coef[z], pw_root[z][tl - l]));
        }
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    add_fib(2 * v, tl, tm, l, r);
    add_fib(2 * v + 1, tm + 1, tr, l, r);
    merge(v);
}
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return 0;
    if (l <= tl && tr <= r) {
        return add[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return sum(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 //   freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int z = 0; z < 2; z++) {
        pw_root[z][0] = 1;
        pref_sum[z][0] = 1;
        for (int i = 1; i <= n; i++) {
            pw_root[z][i] = mult(pw_root[z][i - 1], roots[z]);
            pref_sum[z][i] = sum(pref_sum[z][i - 1], pw_root[z][i]);
        }
    }
    build(1, 0, n - 1);
    for (int z = 0; z < 2; z++) {
        coef[z] = mult(roots[z], pw(sub(mult(2, roots[z]), 1), mod - 2));
    }
    assert(sum(coef[0], coef[1]) == 1);
    assert(sum(mult(coef[0], roots[0]), mult(coef[1], roots[1])) == 1);
    assert(sum(mult(coef[0], mult(roots[0], roots[0])), mult(coef[1], mult(roots[1], roots[1])) == 2));
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            add_fib(1, 0, n - 1, l, r);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << get(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}