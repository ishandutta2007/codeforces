#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, INF = 1E9 + 7;

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int tr[4 * N], lz[4 * N];

    void apply(int i, int v) {
        tr[i] += v; lz[i] += v;
    }

    void down(int i) {
        apply(lc, lz[i]); apply(rc, lz[i]);
        lz[i] = 0;
    }
    
    void build(int l, int r, int i, int n) {
        tr[i] = n - r; lz[i] = 0;
        if (l == r) {
            return;
        } else {
            build(l, m, lc, n);
            build(m + 1, r, rc, n);
        }
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
            tr[i] = min(tr[lc], tr[rc]);
        }
    }

    int query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return INF;
        } else if (L <= l && r <= R) {
            return tr[i];
        } else {
            down(i);
            return min(query(l, m, lc, L, R), query(m + 1, r, rc, L, R));
        }
    }

#undef m
#undef lc
#undef rc
} seg;

struct fenwick_tree {
    int bit[N];
    int n;

    void init(int _n) {
        n = _n;
        fill(bit + 1, bit + n + 1, 0);
    }

    int query(int u) {
        int ans = 0;
        for (; u <= n; u += u & -u) {
            ans += bit[u];
        }
        return ans;
    }

    void update(int u, int v) {
        for (; u > 0; u -= u & -u) {
            bit[u] += v;
        }
    }
} bit;

void solve() {
    int n, m; cin >> n >> m;
    int lst = INF;
    vector<int> ind;
    vector<pair<int, int>> typ;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        typ.push_back({u, i});
    }
    for (int i = 1; i <= m; i++) {
        int u; cin >> u;
        typ.push_back({u, 0});
    }
    seg.build(0, n, 1, n);
    bit.init(n);
    for (int i = 1; i <= n; i++) {
        bit.update(i, 1);
    }
    long long ans = 0;
    sort(typ.begin(), typ.end(), greater<pair<int, int>>());
    for (auto [u, v] : typ) {
        // flush positions
        if (u < lst) {
            lst = u;
            for (int v : ind) {
                seg.update(0, n, 1, v, n, 1);
            }
            ind.clear();
        }
        if (v > 0) {
            ind.push_back(v);
            seg.update(0, n, 1, 0, v - 1, -1);
            bit.update(v, -1);
            ans += bit.query(v);
        } else {
            ans += seg.query(0, n, 1, 0, n);
            // for (int i = 0; i <= n; i++) {
            //     cout << seg.query(0, n, 1, i, i) << " \n"[i == n];
            // }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}