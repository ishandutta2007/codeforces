#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5, Q = 3E5 + 5, INF = 1E9 + 7;

int n, q, l, r, a[N], ans[Q];
vector<int> ve;
vector<pair<int, int>> que[N];

struct STree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int tr[4 * N];

    void build(int l, int r, int i) {
        tr[i] = INF;
        if (l == r) {
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
    }

    void update(int l, int r, int i, int u, int val) {
        if (l == r) {
            tr[i] = min(tr[i], val);
            return;
        }
        if (u <= m) {
            update(l, m, lc, u, val);
        } else {
            update(m + 1, r, rc, u, val);
        }
        tr[i] = min(tr[lc], tr[rc]);
    }

    int query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return INF;
        } else if (L <= l && r <= R) {
            return tr[i];
        } else {
            return min(query(l, m, lc, L, R), query(m + 1, r, rc, L, R));
        }
    }

#undef m
#undef lc
#undef rc
} seg, pos;

int get(int u) {
    return distance(ve.begin(), lower_bound(ve.begin(), ve.end(), u)) + 1;
}

void solve() {
    ve.clear();
    seg.build(1, n, 1);
    pos.build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        ve.push_back(a[i]);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (int i = 1; i <= n; i++) {
        int val = 0, cur = get(a[i]);
        while (true) {
            int u = INF - pos.query(1, n, 1, get(val), cur);
            if (u == 0) {
                break;
            }
            seg.update(1, n, 1, u, a[i] - a[u]);
            if (a[i] == a[u]) {
                break;
            } else {
                val = (a[i] + a[u] + 1) / 2;
            }
        }
        pos.update(1, n, 1, get(a[i]), INF - i);
        for (pair<int, int> &v : que[i]) {
            ans[v.se] = min(ans[v.se], seg.query(1, n, 1, v.fi, n));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        que[r].push_back({l, i});
        ans[i] = INF;
    }
    solve();
    for (int i = 1; i <= n; i++) {
        a[i] = INF - a[i];
    }
    cout << '\n';
    solve();
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}