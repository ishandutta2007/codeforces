#include <bits/stdc++.h>
using namespace std;

const int N = 3E5 + 5, MOD = 1E9 + 7;

int n, q, t, u, x, k, cnt = 0, h[N], in[N], out[N];
vector<int> adj[N];

void DFS(int u) {
    in[u] = ++cnt;
    for (int &v : adj[u]) {
        h[v] = h[u] + 1;
        DFS(v);
    }
    out[u] = cnt;
}

struct SNode {
    long long coe, con;

    SNode(long long _coe = 0, long long _con = 0) {
        coe = _coe; con = _con;
    }

    inline SNode operator+(const SNode &oth) const {
        return SNode((coe + oth.coe) % MOD, (con + oth.con) % MOD);
    }
};

struct STree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    SNode tr[4 * N];

    void update(int l, int r, int i, int L, int R, int k, int x, int h) {
        if (l > R || r < L || L > R) {
            return;
        } else if (L <= l && r <= R) {
            tr[i] = tr[i] + SNode(k, (x - 1LL * k * h) % MOD);
        } else {
            update(l, m, lc, L, R, k, x, h);
            update(m + 1, r, rc, L, R, k, x, h);
        }
    }

    SNode query(int l, int r, int i, int u) {
        if (l == r) {
            return tr[i];
        } else {
            return tr[i] + (u <= m ? query(l, m, lc, u) : query(m + 1, r, rc, u));
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
    for (int i = 2; i <= n; i++) {
        cin >> u;
        adj[u].push_back(i);
    }
    DFS(1);
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> u >> x >> k;
            seg.update(1, n, 1, in[u], out[u], -k, x, h[u]);
        } else {
            cin >> u;
            SNode ans = seg.query(1, n, 1, in[u]);
            long long ret = (ans.con + 1LL * h[u] * ans.coe) % MOD;
            (ret += MOD) %= MOD;
            cout << ret << '\n';
        }
    }
}