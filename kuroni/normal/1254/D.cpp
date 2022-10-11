#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 150005, MOD = 998244353;

int n, q, u, v, t, cnt = 0, cur = 1, in[N], out[N], mc[N], sub[N], col[N], rt[N], par[N];
long long d, inv, f[N];
vector<int> adj[N];

struct bit {
    long long bit[N];

    void update(int u, long long v) {
        for (; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }

    long long query(int u) {
        long long ret = 0;
        for (; u > 0; u -= u & -u) {
            ret += bit[u];
        }
        return ret;
    }

    void update(int l, int r, long long v) {
        if (l == 0 || r == 0) {
            return;
        }
        update(l, v);
        update(r + 1, -v);
    }
} bit;

int DFS(int u, int p = 0) {
    in[u] = ++cnt;
    par[u] = p;
    for (int &v : adj[u]) {
        if (v != p) {
            sub[u] += DFS(v, u);
        }
    }
    out[u] = cnt;
    return ++sub[u];
}

void HLD(int u, int p = 0) {
    col[u] = cur;
    if (rt[cur] == 0) {
        rt[cur] = u;
    }
    for (int &v : adj[u]) {
        if (v != p && sub[v] > sub[mc[u]]) {
            mc[u] = v;
        }
    }
    if (mc[u] != 0) {
        HLD(mc[u], u);
    }
    for (int &v : adj[u]) {
        if (v != p && v != mc[u]) {
            ++cur;
            HLD(v, u);
        }
    }
}

long long pw(int u, int p) {
    long long ret = 1;
    for (int i = __lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    inv = pw(n, MOD - 2);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> u >> d;
            f[u] += d;
            bit.update(in[1], out[1], d * sub[u]);
            bit.update(in[u], out[u], -d * sub[u]);
            bit.update(in[mc[u]], out[mc[u]], d * (n - sub[mc[u]]));
        } else {
            cin >> u;
            long long ans = f[u] * n + bit.query(in[u]);
            while (u != 0) {
                u = rt[col[u]];
                if (par[u] != 0) {
                    ans += f[par[u]] * (n - sub[u]);
                }
                u = par[u];
            }
            cout << ans % MOD * inv % MOD << '\n';
        }
    }
}