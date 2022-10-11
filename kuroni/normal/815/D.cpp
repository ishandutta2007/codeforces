#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 5E5 + 5;

int n, p, q, r, a, b, c, mx = 1;
long long ans = 0;
vector<pair<int, int>> eve[N];

struct STree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    int mi[4 * N], lz[4 * N];
    long long sum[4 * N];

    void apply(int l, int r, int i, int v) {
        lz[i] = mi[i] = v;
        sum[i] = 1LL * (r - l + 1) * v;
    }

    void down(int l, int r, int i) {
        if (lz[i] == -1) {
            return;
        }
        apply(l, m, lc, lz[i]);
        apply(m + 1, r, rc, lz[i]);
        lz[i] = -1;
    }

    int binary_search(int l, int r, int i, int v) {
        if (l == r) {
            return l + (mi[i] < v);
        } else {
            down(l, r, i);
            if (mi[rc] >= v) {
                return binary_search(l, m, lc, v);
            } else {
                return binary_search(m + 1, r, rc, v);
            }
        }
    }

    void update(int l, int r, int i, int L, int R, int v) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(l, r, i, v);
            return;
        } else {
            down(l, r, i);
            update(l, m, lc, L, R, v);
            update(m + 1, r, rc, L, R, v);
            mi[i] = mi[lc];
            sum[i] = sum[lc] + sum[rc];
        }
    }

    long long query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return 0;
        } else if (L <= l && r <= R) {
            return sum[i];
        } else {
            down(l, r, i);
            return query(l, m, lc, L, R) + query(m + 1, r, rc, L, R);
        }
    }

#undef m
#undef lc
#undef rc
} seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> q >> r;
    seg.update(1, q, 1, 1, q, r);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        int up = min(b + 1, seg.binary_search(1, q, 1, r - c));
        seg.update(1, q, 1, up, b, r - c);
        eve[a].push_back({b, c});
    }
    for (int i = p; i >= 1; i--) {
        for (pair<int, int> &v : eve[i]) {
            int up = seg.binary_search(1, q, 1, r - v.se);
            seg.update(1, q, 1, up, q, r - v.se);
            mx = max(mx, v.fi + 1);
        }
        ans += seg.query(1, q, 1, mx, q);
    }
    cout << ans;
}