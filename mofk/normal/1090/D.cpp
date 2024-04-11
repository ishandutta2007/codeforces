#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (adj[i].size() < n - 1) {
        adj[i].push_back(0);
        adj[i].push_back(i);
        sort(adj[i].begin(), adj[i].end());
        int mex = 0;
        while (mex < adj[i].size() && adj[i][mex] == mex) ++mex;
        vector<int> v(n + 1, 0);
        v[i] = 1;
        v[mex] = 2;
        int z = 2;
        for (int i = 1; i <= n; ++i) if (!v[i]) v[i] = ++z;
        cout << "YES" << endl;
        for (int j = 1; j <= n; ++j) cout << v[j] << ' '; cout << endl;
        for (int j = 1; j <= n; ++j) cout << (j == mex ? v[i] : v[j]) << ' '; cout << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}