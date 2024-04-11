#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 1E5 + 5, MX = 2E6 + 5;

int n, x[N], v[N], pos[N];
long long ans = 0, inv[MX], p[N][2], ip[N][2];

struct fraction {
    long long x, y;

    fraction(long long _x = 0, long long _y = 1) : x(_x), y(_y) {}

    bool operator<(const fraction &oth) const {
        return 1LL * x * oth.y < 1LL * y * oth.x;
    }
};
vector<tuple<fraction, int, int>> ve;

struct node {
    long long val[4];
    int l, r;

    node(int _l = 0, int _r = 0) : l(_l), r(_r) {
        fill(val, val + 4, 0);
    }

    node operator+(const node &oth) const {
        node ans(l, oth.r);
        for (int msk = 0; msk < 4; msk++) {
            for (int i = 0; i < 2; i++) {
                (ans.val[(msk & 2) | i] += val[msk] * oth.val[((msk & 1) << 1) | i] % MOD * ip[oth.l][msk & 1]) %= MOD;
            }
        }
        return ans;
    }
};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    node tr[4 * N];

    void build(int l, int r, int i) {
        if (l == r) {
            tr[i] = node(l, l);
            pos[l] = i;
            for (int msk = 0; msk < 4; msk++) {
                tr[i].val[msk] = p[l][msk >> 1] * p[l + 1][msk & 1] % MOD;
            }
        } else {
            build(l, m, lc);
            build(m + 1, r, rc);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    void update(int l, int r, int i, int u, node val) {
        if (l == r) {
            tr[i] = val;
        } else {
            if (u <= m) {
                update(l, m, lc, u, val);
            } else {
                update(m + 1, r, rc, u, val);
            }
            tr[i] = tr[lc] + tr[rc];
        }
    }

#undef m
#undef lc
#undef rc
} seg;

void init() {
    inv[1] = 1;
    for (int i = 2; i < MX; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    if (n == 1) {
        return cout << 0, 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> v[i] >> p[i][1];
        p[i][0] = 100 - p[i][1];
        for (int j = 0; j < 2; j++) {
            ip[i][j] = 100 * inv[p[i][j]] % MOD;
            (p[i][j] *= inv[100]) %= MOD;
        }
    }
    for (int i = 1; i < n; i++) {
        ve.push_back({fraction(x[i + 1] - x[i], v[i] + v[i + 1]), i, 2});
        if (v[i] > v[i + 1]) {
            ve.push_back({fraction(x[i + 1] - x[i], v[i] - v[i + 1]), i, 3});
        } else if (v[i] < v[i + 1]) {
            ve.push_back({fraction(x[i + 1] - x[i], v[i + 1] - v[i]), i, 0});
        }
    }
    sort(ve.begin(), ve.end());
    seg.build(1, n - 1, 1);
    for (auto [fr, in, v] : ve) {
        node cur = seg.tr[pos[in]];
        node tmp = cur;
        for (int i = 0; i < 4; i++) {
            if (i != v) {
                tmp.val[i] = 0;
            }
        }
        seg.update(1, n - 1, 1, in, tmp);
        node &rt = seg.tr[1];
        long long sum = (rt.val[0] + rt.val[1] + rt.val[2] + rt.val[3]) % MOD;
        (ans += sum * fr.x % MOD * inv[fr.y]) %= MOD;
        cur.val[v] = 0;
        seg.update(1, n - 1, 1, in, cur);
    }
    cout << ans;
}