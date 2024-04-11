#include <bits/stdc++.h>
using namespace std;

const int N = 100001, MOD = 1E9 + 7;

int n, u, v, sub[N], l[N], r[N], dst[N] = {-1};
bool chk[N];
long long tot = 1, ans = 0, inv[N];
vector<int> lcl, gbl, adj[N];

void add(long long &u, long long v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    } else if (u < MOD) {
        u += MOD;
    }
}

struct bit {
    long long bit[N];

    void update(int u, long long v) {
        for (; u < N; u += u & -u) {
            bit[u] += v;
        }
    }

    void update(int l, int r, long long v) {
        update(l, v);
        update(r + 1, -v);
    }

    long long query(int u) {
        long long ret = 0;
        for (; u > 0; u -= u & -u) {
            ret += bit[u];
        }
        return ret;
    }
};

struct slope_bit {
    bit sl, co;

    void update(int l, int r, long long v) {
        sl.update(l, r, v);
        co.update(l, -v * (l - 1) % MOD);
        co.update(r + 1, v * r % MOD);
    }

    long long query(int l, int r) {
        return (sl.query(r) % MOD * r + co.query(r) - sl.query(l - 1) % MOD * (l - 1) - co.query(l - 1)) % MOD;
    }
} coe, val;

void init() {
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
}

void add(int u, int s = 1) {
    coe.update(l[u], r[u], s * inv[r[u] - l[u] + 1]);
    val.update(l[u], r[u], s * dst[u] * inv[r[u] - l[u] + 1] % MOD);
}

int DFS(int u, int p = 0) {
    sub[u] = 1;
    dst[u] = dst[p] + 1;
    for (int &v : adj[u]) {
        if (v != p && !chk[v]) {
            sub[u] += DFS(v, u);
        }
    }
    return sub[u];
}

void find_ans(int u, int p) {
    add(ans, dst[u] * inv[r[u] - l[u] + 1] % MOD * coe.query(l[u], r[u]) % MOD);
    add(ans, inv[r[u] - l[u] + 1] * val.query(l[u], r[u]) % MOD);
    lcl.push_back(u);
    for (int &v : adj[u]) {
        if (v != p && !chk[v]) {
            find_ans(v, u);
        }
    }
}

void centroid(int u) {
    int sz = DFS(u);
    bool rt = false;
    while (!rt) {
        rt = true;
        for (int &v : adj[u]) {
            if (!chk[v] && sub[v] < sub[u] && sub[v] >= sz / 2) {
                u = v;
                rt = false;
                break;
            }
        }
    }
    DFS(u);
    add(u); gbl.push_back(u);
    for (int &v : adj[u]) {
        if (!chk[v]) {
            find_ans(v, u);
        }
        for (int &v : lcl) {
            add(v);
            gbl.push_back(v);
        }
        lcl.clear();
    }
    for (int &v : gbl) {
        add(v, -1);
    }
    gbl.clear();
    chk[u] = true;
    for (int &v : adj[u]) {
        if (!chk[v]) {
            centroid(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        (tot *= r[i] - l[i] + 1) %= MOD;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    centroid(1);
    cout << (ans * tot % MOD + MOD) % MOD;
}