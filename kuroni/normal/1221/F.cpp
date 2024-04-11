#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 500005;
const long long INF = 1E18;

int n, x, y, c;
vector<array<int, 3>> que;
vector<int> pt;
tuple<long long, int, int> ans = {0, 2E9, 2E9};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    long long lz[4 * N];
    pair<long long, int> tr[4 * N];

    void apply(int i, long long u) {
        tr[i].fi += u;
        lz[i] += u;
    }

    void down(int i) {
        apply(lc, lz[i]);
        apply(rc, lz[i]);
        lz[i] = 0;
    }

    void build(int l, int r, int i) {
        if (l == r) {
            tr[i] = {0, l};
        } else {
            build(l, m, lc);
            build(m + 1, r, rc);
            tr[i] = max(tr[lc], tr[rc]);
        }
    }

    void update(int l, int r, int i, int L, int R, long long v) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(i, v);
        } else {
            down(i);
            update(l, m, lc, L, R, v);
            update(m + 1, r, rc, L, R, v);
            tr[i] = max(tr[lc], tr[rc]);
        }
    }

    pair<long long, int> query(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return {-INF, 0};
        } else if (L <= l && r <= R) {
            return tr[i];
        } else {
            down(i);
            return max(query(l, m, lc, L, R), query(m + 1, r, rc, L, R));
        }
    }

#undef m
#undef lc
#undef rc
} seg;

int pos(int u) {
    return upper_bound(pt.begin(), pt.end(), u) - pt.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> x >> y >> c;
        if (x > y) {
            swap(x, y);
        }
        que.push_back({y, x, c});
        pt.push_back(x);
    }
    sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    sort(que.begin(), que.end());
    n = pt.size(); seg.build(1, n, 1); int le = 0;
    for (int i = 0; i < n; i++) {
        seg.update(1, n, 1, i + 1, i + 1, pt[i]);
    }
    for (int i = 0; i < que.size(); i++) {
        auto [r, l, c] = que[i];
        seg.update(1, n, 1, 1, n, le - r); le = r;
        seg.update(1, n, 1, 1, pos(l), c);
        if (i + 1 == que.size() || r != get<0>(que[i + 1])) {
            pair<long long, int> mx = seg.query(1, n, 1, 1, pos(r));
            ans = max(ans, {mx.fi, pt[mx.se - 1], r});
        }
    }
    auto [val, l, r] = ans;
    cout << val << "\n" << l << " " << l << " " << r << " " << r << '\n';
}