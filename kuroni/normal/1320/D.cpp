#include <bits/stdc++.h>
using namespace std;

const int N = 200009, Q = 2E5 + 5, MOD = 998244353;

int n, q, l, r, len;
char s[N];
long long pw[N];
pair<long long, int> ans[Q][2];
vector<pair<int, int>> que[N];

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    long long add[4 * N];
    int mul[4 * N], tot[4 * N];

    void apply(int i, int mu, long long ad, int to) {
        mul[i] += mu;
        ((add[i] *= pw[mu] %= MOD) += ad) %= MOD;
        tot[i] ^= to;
    }

    void down(int i) {
        apply(lc, mul[i], add[i], tot[i]);
        apply(rc, mul[i], add[i], tot[i]);
        mul[i] = add[i] = tot[i] = 0;
    }

    void update(int l, int r, int i, int L, int R, int mu, int ad, int to) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            apply(i, mu, ad, to);
            return;
        } else {
            down(i);
            update(l, m, lc, L, R, mu, ad, to);
            update(m + 1, r, rc, L, R, mu, ad, to);
        }
    }

    pair<long long, int> query(int l, int r, int i, int u) {
        if (l == r) {
            return {add[i], tot[i]};
        } else {
            down(i);
            return u <= m ? query(l, m, lc, u) : query(m + 1, r, rc, u);
        }
    }

#undef m
#undef lc
#undef rc
} seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> (s + 1) >> q;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * N % MOD;
    }
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> len;
        que[l + len - 1].push_back({l, -i});
        que[r + len - 1].push_back({r, i});
    }
    for (int i = 1, lst = 1; i <= n; i++) {
        if (s[i] == '0') {
            seg.update(1, n, 1, 1, i, (i - lst) & 1, 1, 0);
            lst = i + 1;
        } else {
            seg.update(1, n, 1, lst, i, 0, 0, 1);
        }
        for (auto [u, val] : que[i]) {
            int ind = abs(val), coe = val / ind;
            int it = (coe + 1) / 2;
            ans[ind][it] = seg.query(1, n, 1, u);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << (ans[i][0] == ans[i][1] ? "Yes\n" : "No\n");
    }
}