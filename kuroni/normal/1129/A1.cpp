#include <bits/stdc++.h>
using namespace std;

const int N = 105, INF = 1E9 + 7;

int n, m, u, v;
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return (u - i + n) % n < (v - i + n) % n;
        });
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (!adj[j].empty()) {
                int dst = (j - i + n) % n;
                dst += n * (adj[j].size() - 1);
                dst += (adj[j].front() - j + n) % n;
                ans = max(ans, dst);
            }
        }
        cout << ans << " ";
    }
}