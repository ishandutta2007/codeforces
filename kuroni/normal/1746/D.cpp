#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector adj(n, vector<int>());
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
            int p; cin >> p; p--;
            adj[p].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        function<pair<long long, long long>(int, int)> DFS = [&](int u, int k) {
            long long ans = 1LL * a[u] * k;
            if (adj[u].empty()) {
                return make_pair(ans, 1LL * a[u]);
            } else {
                int num = k / adj[u].size(), lft = k % adj[u].size();
                vector<long long> nxt;
                for (int v : adj[u]) {
                    auto [ac, nc] = DFS(v, num);
                    ans += ac;
                    nxt.push_back(nc);
                }
                sort(nxt.begin(), nxt.end(), greater<long long>());
                for (int i = 0; i < lft; i++) {
                    ans += nxt[i];
                }
                return make_pair(ans, nxt[lft] + a[u]);
            }
        };
        cout << DFS(0, k).first << '\n';
    }
}