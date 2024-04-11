#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 12) + 5, Q = (1 << 16) + 5;

int n, q, l, r, cnt, a[N], ans[Q], inv[N];
long long rnd[N];
vector<pair<int, int>> ve;
mt19937_64 mt(133769420);

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    long long cur[4 * N];
    unordered_map<long long, int> ind[4 * N];

    void build(int l, int r, int i) {
        if (l == r) {
            ind[i][rnd[l]] = inv[l];
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
    }

    void update(int l, int r, int i, int u) {
        cur[i] ^= rnd[u];
        if (l == r) {
            return;
        }
        if (u <= m) {
            update(l, m, lc, u);
        } else {
            update(m + 1, r, rc, u);
        }
    }
    
    int get_set(int i) {
        if (cur[i] == 0) {
            return 0;
        }
        if (ind[i][cur[i]] == 0) {
            int le = get_set(lc), ri = get_set(rc);
            if (min(le, ri) == 0) {
                ind[i][cur[i]] = max(le, ri);
            } else {
                ve.push_back({le, ri});
                ind[i][cur[i]] = ++cnt;
            }
        }
        return ind[i][cur[i]];
    }

#undef m
#undef lc
#undef rc
} seg;

struct query {
    int l, r, ind;

    query(int _l, int _r, int _ind) : l(_l), r(_r), ind(_ind) {}
};
vector<query> que;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    cnt = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inv[a[i]] = i;
        rnd[i] = mt();
    }
    seg.build(1, n, 1);
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        que.push_back(query(l, r, i));
    }
    int d = max(1.0, n / sqrt(q));
    sort(que.begin(), que.end(), [&](const query& u, const query& v) {
        return u.l / d != v.l / d ? u.l < v.l : u.r < v.r;
    });
    int l = 1, r = 0;
    for (query& cur : que) {
        for (; l > cur.l; l--) {
            seg.update(1, n, 1, a[l - 1]);
        }
        for (; l < cur.l; l++) {
            seg.update(1, n, 1, a[l]);
        }
        for (; r > cur.r; r--) {
            seg.update(1, n, 1, a[r]);
        }
        for (; r < cur.r; r++) {
            seg.update(1, n, 1, a[r + 1]);
        }
        ans[cur.ind] = seg.get_set(1);
    }
    cout << cnt << '\n';
    for (auto& [l, r] : ve) {
        cout << l << " " << r << '\n';
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
}