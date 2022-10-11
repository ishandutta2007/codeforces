#include <bits/stdc++.h>
using namespace std;

const int N = 500005, MOD = 1E9 + 7;

int n, u, v, h[N], p[N], coe[N], ord[N], dsu[3 * N];
long long ans = 1, fct[N];
vector<int> adj[N];

void DFS(int u) {
    h[u] = h[p[u]] + 1;
    coe[u] = adj[u].size();
    for (int &v : adj[u]) {
        if (v != p[u]) {
            p[v] = u;
            DFS(v);
        }
    }
}

int trace(int u) {
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void rage_quit() {
    cout << 0;
    exit(0);
}

bool connect(int u, int v) {
    if ((u = trace(u)) == (v = trace(v))) {
        return false;
    }
    if (dsu[u] > dsu[v]) {
        swap(u, v);
    }
    dsu[u] += dsu[v];
    dsu[v] = u;
    return true;
}

void reduce(int &u, int &pu, int msk) {
    if ((ord[u] & msk) || !connect(p[u], pu)) {
        rage_quit();
    }
    ord[u] |= msk; coe[u]--; pu = u; u = p[u];
}

void solve(int s, int t) {
    int ps = s + n, pt = t + 2 * n;
    while (h[s] > h[t]) {
        reduce(s, ps, 1);
    }
    while (h[t] > h[s]) {
        reduce(t, pt, 2);
    }
    while (s != t) {
        reduce(s, ps, 1); reduce(t, pt, 2);
    }
    coe[s]--;
    if (!connect(ps, pt)) {
        rage_quit();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fct[0] = 1;
    for (int i = 1; i <= n; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        dsu[i] = dsu[i + n] = dsu[i + 2 * n] = -1;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (u != 0) {
            solve(u, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (trace(i + n) == trace(i + 2 * n) && coe[i] >= 0) {
            rage_quit();
        } else {
            (ans *= fct[max(0, coe[i])]) %= MOD;
        }
    }
    cout << ans;
}