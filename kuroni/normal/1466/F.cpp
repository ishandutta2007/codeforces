#include <bits/stdc++.h>
using namespace std;

const int N = 500005, MOD = 1E9 + 7;

int m, n, k, u, v, it = 0;
int chk[N], vis[N], tak[N];
long long t, pw[N];
vector<pair<int, int>> adj[N];
vector<int> ans;

struct dsu {
    int dsu[N];
    
    void init() {
        fill(dsu, dsu + n + 1, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
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
} dsu;

void init() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
}

void DFS(int u) {
    vis[u] = it;
    for (auto [v, ind] : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> m >> n;
    dsu.init();
    for (int i = 1; i <= m; i++) {
        cin >> k;
        if (k == 1) {
            cin >> u;
            if (dsu.connect(0, u)) {
                ans.push_back(i);
            }
        } else {
            cin >> u >> v;
            if (dsu.connect(u, v)) {
                ans.push_back(i);
            }
        }
    }
    t = ans.size();
    cout << pw[t] << " " << t << '\n';
    for (int v : ans) {
        cout << v << " ";
    }
}