#include <bits/stdc++.h>
using namespace std;

const int N = 3005, Q = 5E5 + 5;

int n, m, q, u, v, k, ans[Q];
bool vis[N];
vector<int> ve, adj[N], rev[N], fun[N];

struct query {
    int u, v, k, ind;

    query(int _u = 0, int _v = 0, int _k = 0, int _ind = 0) : u(_u), v(_v), k(_k), ind(_ind) {}
};
vector<query> que[N], eve[N];

void DFS(int u) {
    vis[u] = true;
    for (int &v : rev[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void find_ans(int u) {
    ve.push_back(u);
    for (query &v : eve[u]) {
        if (v.k <= ve.size()) {
            ans[v.ind] = ve[ve.size() - v.k];
        }
    }
    for (int &v : fun[u]) {
        find_ans(v);
    }
    ve.pop_back();
}

void solve(int en) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        fun[i].clear();
        eve[i].clear();
    }
    DFS(en);
    for (query &v : que[en]) {
        eve[v.u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] && i != en) {
            int ret = N;
            for (int &v : adj[i]) {
                if (vis[v]) {
                    ret = min(ret, v);
                }
            }
            fun[ret].push_back(i);
        }
    }
    find_ans(en);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for (int i = 1; i <= q; i++) {
        ans[i] = -1;
        cin >> u >> v >> k;
        que[v].push_back(query(u, v, k, i));
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}