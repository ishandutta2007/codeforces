#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n, u, v;
bool vis[N];
vector<int> ans, adj[N];

bool find_swap(int u, int x, int to) {
    for (int i = to; i < 4; i++) {
        if (adj[u][i] == x) {
            swap(adj[u][i], adj[u][to]);
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() != 4) {
            return cout << -1, 0;
        }
    }
    sort(adj[1].begin(), adj[1].end());
    do {
        fill(vis + 1, vis + n + 1, false);
        int u = 1;
        bool chk = true;
        ans.clear();
        for (int i = 1; i <= n; i++) {
            ans.push_back(u);
            vis[u] = true;
            if (i == n) {
                break;
            }
            int nxt = adj[u][2];
            if (vis[nxt] || !find_swap(nxt, adj[u][1], 0) || !find_swap(nxt, u, 1) || !find_swap(nxt, adj[u][3], 2)) {
                chk = false;
                break;
            }
            u = nxt;
        }
        if (chk) {
            for (int &v : ans) {
                cout << v << " ";
            }
            return 0;
        }
    } while (next_permutation(adj[1].begin(), adj[1].end()));
    cout << -1;
}