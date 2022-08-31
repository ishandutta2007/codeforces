#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2e5 + 10;
ld coef[3] = {1, 1, 1};

struct node {
    ld f[3][3];

    node(ld a) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    f[i][j] = -1e18;
                } else {
                    f[i][j] = a * coef[i];
                }
            }
        }
    }

    node() {
    }
};

node t[4 * maxN];

int X, Y, n;
const ld eps = 1e-12;
node merge(const node &a, const node &b) {
    node c;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            c.f[x][y] = -1e18;
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z  < 3; z++) {
                for (int t = 0; t < 3; t++) {
                    if (min(coef[y], coef[z]) * X + max(coef[y], coef[z]) * Y <= 1 + eps) {
                        c.f[x][t] = max(c.f[x][t], a.f[x][y] + b.f[z][t]);
                    }
                }
            }
        }
    }
    return c;
}


void merge(int v) {
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int tl, int tr, int pos, ld val) {
    if (tl == tr) {
        t[v] = node(val);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos, val);
    else upd(2 * v + 1, tm + 1, tr, pos, val);
    merge(v);
}

node get(int v, int tl, int tr, int l, int r) {
    if (l == tl && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
}

ld b[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int q;
    cin >> n >> q >> X >> Y;
    if (X > Y) swap(X, Y);
    coef[0] = 0;
    coef[1] = (ld) 1 / Y;
    coef[2] = (ld) 1 / (X + Y);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        upd(1, 1, n, i, b[i]);
    }

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int k;
            ld v;
            cin >> k >> v;
            upd(1, 1, n, k, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            node p = get(1, 1, n, l, r);
            ld best = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    best = max(best, p.f[x][y]);
                }
            }
            cout << fixed << setprecision(12) << best << '\n';
        }
    }
    return 0;
}