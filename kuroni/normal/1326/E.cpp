#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005;

int n, u, ans, p[N];

struct segment_tree {
#define lc i * 2
#define rc i * 2 + 1
#define m (l + r) / 2

    int sum[4 * N], pre[4 * N];

    void update(int l, int r, int i, int u, int v) {
        if (l == r) {
            sum[i] += v;
            pre[i] = min(sum[i], 0);
        } else {
            if (u <= m) {
                update(l, m, lc, u, v);
            } else {
                update(m + 1, r, rc, u, v);
            }
            sum[i] = sum[lc] + sum[rc];
            pre[i] = min(pre[lc], sum[lc] + pre[rc]);
        }
    }

    pair<int, int> query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return {0, 0};
        } else if (L <= l && r <= R) {
            return {pre[i], sum[i]};
        } else {
            pair<int, int> le = query(l, m, lc, L, R);
            pair<int, int> ri = query(m + 1, r, rc, L, R);
            return {min(le.fi, le.se + ri.fi), le.se + ri.se};
        }
    }

#undef lc
#undef rc
#undef m
} seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; ans = n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        p[u] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans << ' ';
        cin >> u;
        seg.update(1, n, 1, u, -1);
        while (ans > 0 && seg.query(1, n, 1, 1, p[ans] - 1).se - seg.query(1, n, 1, 1, p[ans] - 1).fi + seg.query(1, n, 1, p[ans], n).fi < 0) {
            seg.update(1, n, 1, p[ans--], 1);
        }
    }
}