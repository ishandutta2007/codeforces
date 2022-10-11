#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5, Q = 1E5 + 5, MX = 1E5 + 5, INF = 1E9 + 7;

int n, q, l, r, a[N], ans[Q], lst[MX];
int nxt[N], pt[N], dif[N], upd[N];
vector<pair<int, int>> que[N];

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int mi[4 * N], su[4 * N];

    void build(int l, int r, int i) {
        mi[i] = INF;
        if (l == r) {
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
    }

    void update(int l, int r, int i, int u, int v) {
        if (u == 0) {
            return;
        }
        if (l == r) {
            mi[i] = v;
            su[i] = (v == INF ? 0 : 1);
        } else {
            if (u <= m) {
                update(l, m, lc, u, v);
            } else {
                update(m + 1, r, rc, u, v);
            }
            mi[i] = min(mi[lc], mi[rc]);
            su[i] = su[lc] + su[rc];
        }
    }

    int query_min(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return INF;
        } else if (L <= l && r <= R) {
            return mi[i];
        } else {
            return min(query_min(l, m, lc, L, R), query_min(m + 1, r, rc, L, R));
        }
    }

    int query_sum(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return 0;
        } else if (L <= l && r <= R) {
            return su[i];
        } else {
            return query_sum(l, m, lc, L, R) + query_sum(m + 1, r, rc, L, R);
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
        nxt[i] = n + 1;
        nxt[lst[a[i]]] = i;
        upd[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        que[r].push_back({l, i});
    }
    seg.build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        if (dif[a[i]] != i - upd[i]) {
            pt[a[i]] = upd[upd[i]];
            dif[a[i]] = i - upd[i];
        }
        int val = pt[a[i]];
        seg.update(1, n, 1, i, val);
        seg.update(1, n, 1, upd[i], INF);
        for (pair<int, int> &v : que[i]) {
            int cur = seg.query_sum(1, n, 1, v.fi, i);
            if (seg.query_min(1, n, 1, v.fi, i) >= v.fi) {
                cur++;
            }
            ans[v.se] = cur;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}