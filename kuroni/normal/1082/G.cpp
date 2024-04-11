#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const long long INF = 1E18 + 7;

int n, m, s, t, u, v, w, ind = 0, it = 0, vis[N];
long long sum = 0, cap[N];
vector<pair<int, int>> adj[N];

bool DFS(int u, int low) {
    vis[u] = it;
    if (u == t) {
        return true;
    }
    for (auto [v, ind] : adj[u]) {
        if (vis[v] < it && cap[ind] >= low && DFS(v, low)) {
            cap[ind] -= low;
            cap[ind ^ 1] += low;
            return true;
        }
    }
    return false;
}

long long flow() {
    long long ans = 0;
    for (int i = 29; i >= 0; i--) {
        while (true) {
            it++;
            if (DFS(s, (1 << i))) {
                ans += (1 << i);
            } else {
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    s = 0; t = m + n + 1;
    auto add_edge = [](int u, int v, long long c) {
        adj[u].push_back({v, ind}); cap[ind++] = c;
        adj[v].push_back({u, ind}); cap[ind++] = 0;
    };
    for (int i = 1; i <= n; i++) {
        cin >> w;
        add_edge(i, t, w);
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        add_edge(s, i + n, w); sum += w;
        add_edge(i + n, u, INF);
        add_edge(i + n, v, INF);
    }
    cout << sum - flow();
}