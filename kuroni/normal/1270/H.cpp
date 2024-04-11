#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 5E5 + 5, MX = 1E6 + 5, INF = 1E9 + 7;

int n, q, u, v, a[N];

struct node {
    pair<int, int> mi;
    bool on;

    node(pair<int, int> _mi = {0, 1}, bool _on = false) : mi(_mi), on(_on) {}

    node operator+(const node &oth) const {
        pair<int, int> ans = {INF, 0};
        if (on) {
            if (mi.fi < ans.fi) {
                ans = mi;
            } else if (mi.fi == ans.fi) {
                ans.se += mi.se;
            }
        }
        if (oth.on) {
            if (oth.mi.fi < ans.fi) {
                ans = oth.mi;
            } else if (oth.mi.fi == ans.fi) {
                ans.se += oth.mi.se;
            }
        }
        return node(ans, true);
    }
};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    node tr[4 * MX];
    int lz[4 * MX];

    void apply(int i, int v) {
        lz[i] += v;
        tr[i].mi.fi += v;
    }

    void down(int i) {
        apply(lc, lz[i]);
        apply(rc, lz[i]);
        lz[i] = 0;
    }

    void build(int l, int r, int i) {
        if (l == r) {
            tr[i] = node();
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        tr[i] = tr[lc] + tr[rc];
    }

    void update(int l, int r, int i, int L, int R, int v) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(i, v);
            return;
        } else {
            down(i);
            update(l, m, lc, L, R, v);
            update(m + 1, r, rc, L, R, v);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    void toggle(int l, int r, int i, int u) {
        if (l == r) {
            tr[i].on = !tr[i].on;
        } else {
            down(i);
            if (u <= m) {
                toggle(l, m, lc, u);
            } else {
                toggle(m + 1, r, rc, u);
            }
            tr[i] = tr[lc] + tr[rc];
        }
    }

#undef m
#undef lc
#undef rc
} seg;

void update(int l, int r, int v) {
    if (l >= r) {
        swap(l, r);
    }
    seg.update(1, MX - 1, 1, l + 1, r, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q; a[0] = MX - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        seg.toggle(1, MX - 1, 1, a[i]);
    }
    for (int i = 0; i <= n; i++) {
        update(a[i], a[i + 1], 1);
    }
    while (q--) {
        cin >> u >> v;
        update(a[u - 1], a[u], -1);
        update(a[u], a[u + 1], -1);
        seg.toggle(1, MX - 1, 1, a[u]);
        a[u] = v;
        update(a[u - 1], a[u], 1);
        update(a[u], a[u + 1], 1);
        seg.toggle(1, MX - 1, 1, a[u]);
        cout << seg.tr[1].mi.se << '\n';
    }
}