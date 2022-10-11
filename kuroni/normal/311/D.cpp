#include <bits/stdc++.h>
using namespace std;

const int MX = 48, N = 100005, MOD = 95542721;

int n, q, t, l, r, a[N];

struct node {
    long long a[MX];
    
    node operator+(const node &oth) const {
        node ans;
        for (int i = 0; i < MX; i++) {
            ans.a[i] = (a[i] + oth.a[i]) % MOD;
        }
        return ans;
    }

    void rotate(int u) {
        u %= MX;
        node tmp;
        for (int i = 0; i < MX; i++) {
            tmp.a[i] = a[i];
        }
        for (int i = 0; i < MX; i++) {
            a[i] = tmp.a[(i + u) % MX];
        }
    }
};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    node tr[4 * N];
    int lz[4 * N];

    void apply(int i, int u) {
        tr[i].rotate(u);
        lz[i] += u;
    }

    void down(int i) {
        apply(lc, lz[i]);
        apply(rc, lz[i]);
        lz[i] = 0;
    }

    void build(int l, int r, int i) {
        if (l == r) {
            tr[i].a[0] = a[l] % MOD;
            for (int j = 1; j < MX; j++) {
                tr[i].a[j] = tr[i].a[j - 1] * tr[i].a[j - 1] % MOD * tr[i].a[j - 1] % MOD;
            }
        } else {
            build(l, m, lc);
            build(m + 1, r, rc);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    void update(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(i, 1);
            return;
        } else {
            down(i);
            update(l, m, lc, L, R);
            update(m + 1, r, rc, L, R);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    long long query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return 0;
        } else if (L <= l && r <= R) {
            return tr[i].a[0];
        } else {
            down(i);
            return (query(l, m, lc, L, R) + query(m + 1, r, rc, L, R)) % MOD;
        }
    }

#undef m
#undef lc
#undef rc
} seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    seg.build(1, n, 1);
    cin >> q;
    while (q--) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << seg.query(1, n, 1, l, r) << '\n';
        } else {
            seg.update(1, n, 1, l, r);
        }
    }
}