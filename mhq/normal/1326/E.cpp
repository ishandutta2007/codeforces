#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 10;
int p[maxN], q[maxN];
/*int lazy[4 * maxN];
int t[4 * maxN];
void build() {
    for (int i = 0; i < 4 * maxN; i++) {
        t[i] = lazy[i] = 0;
    }
}

void upd(int v, int by) {
    lazy[v] += by;
    t[v] += by;
}

void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        upd(2 * v, lazy[v]);
        upd(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int by) {
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
        lazy[v] += by;
        t[v] += by;
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) /  2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}*/
int lo[maxN];
int hi[maxN];
int mid[maxN];
int pos[maxN];

int h = sizeof(int) * 8 - __builtin_clz(n);
int t[2 * maxN];
int d[2 * maxN];
void apply(int p, int value) {
    t[p] += value;
    if (p < n) d[p] += value;
}

void build(int p) {
    while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}

void inc(int l, int r, int value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    int res = -2e9;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    h = sizeof(int) * 8 - __builtin_clz(n);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        lo[i] = 1;
        hi[i] = n + 1;
    }
    for (int iter = 0; iter < 20; iter++) {
        int cur = n + 1;
        for (int i = 1; i < 2 * maxN; i++) {
            t[i] = d[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                inc(1, q[i - 1] + 1, -1);
            }
            if (lo[i] != hi[i]) {
                mid[i] = (lo[i] + hi[i]) / 2;
                while (cur > mid[i]) {
                    cur--;
                    inc(1, pos[cur] + 1, +1);
                }
                if (query(1, n + 1) > 0) {
                    lo[i] = mid[i];
                } else {
                    hi[i] = mid[i];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << lo[i] << " ";
    return 0;
}