#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 3E5 + 5, M = 3E5 + 5;

int n, m, dis[N], tr[N], u[M], v[M];
bool vis[N], chk[N];
vector<int> com, pat, cur, adj[N];
vector<pair<int, int>> ve;

int connected(int u, int v) {
    return u == v || binary_search(ve.begin(), ve.end(), make_pair(u, v));
}

void BFS() {
    queue<int> q;
    tr[1] = -1;
    for (q.push(1); !q.empty(); q.pop()) {
        int u = q.front();
        for (int &v : adj[u]) {
            if (tr[v] == 0) {
                tr[v] = u;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void DFS(int u) {
    vis[u] = true;
    com.push_back(u);
    for (int &v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

bool find_path(int u, int des) {
    chk[u] = true;
    cur.push_back(u);
    if (u == des) {
        return true;
    }
    for (int &v : adj[u]) {
        if (v != 1 && !chk[v] && find_path(v, des)) {
            return true;
        }
    }
    cur.pop_back();
    return false;
}

void solve() {
    if (!pat.empty() && pat.size() <= 5) {
        return;
    }
    for (int &u : com) {
        for (int &v : com) {
            if (!connected(u, v)) {
                cur.clear();
                find_path(u, v);
                for (int i = cur.size() - 2; i >= 0; i--) {
                    if (connected(u, cur[i])) {
                        pat = {1, u, cur[i], cur[i + 1], u, n};
                        break;
                    }
                }
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        ve.push_back({u[i], v[i]});
        ve.push_back({v[i], u[i]});
    }
    sort(ve.begin(), ve.end());
    BFS();
    if (tr[n] != 0) {
        for (int u = n; u != -1; u = tr[u]) {
            pat.push_back(u);
        }
        reverse(pat.begin(), pat.end());
    }
    for (int i = 1; i <= m; i++) {
        if (connected(1, u[i]) && !connected(1, v[i]) && (pat.empty() || pat.size() > 5)) {
            pat = {1, u[i], v[i], 1, n};
        }
        if (connected(1, v[i]) && !connected(1, u[i]) && (pat.empty() || pat.size() > 5)) {
            pat = {1, v[i], u[i], 1, n};
        }
    }
    vis[1] = true;
    for (int &v : adj[1]) {
        if (!vis[v]) {
            com.clear();
            DFS(v);
            solve();
        }
    }
    cout << (int)pat.size() - 1 << '\n';
    for (int &v : pat) {
        cout << v << " ";
    }
}