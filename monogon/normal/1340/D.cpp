
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, u, v;
vector<int> adj[N];
bool vis[N];
vector<pair<int, int>> ve;

void dfs(int x, int t) {
    ve.emplace_back(x, t);
    vis[x] = true;
    int t0 = t;
    int remaining = (int) adj[x].size() - 1;
    if(t >= (int) adj[x].size()) {
        // reset to t0 - num_remaining - 1
        t = t0 - remaining - 1;
        ve.emplace_back(x, t);
    }
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y, t + 1);
            t++;
            remaining--;
            ve.emplace_back(x, t);
            if(t >= (int) adj[x].size() && t != t0 - remaining - 1) {
                // reset to t0 - num_remaining - 1
                t = t0 - remaining - 1;
                ve.emplace_back(x, t);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (int) ve.size() - 1 << '\n';
    for(int i = 0; i < (int) ve.size() - 1; i++) {
        auto [v, t] = ve[i];
        cout << v << " " << t << "\n";
    }
}