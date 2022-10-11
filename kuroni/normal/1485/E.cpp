#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const long long INF = 1E18 + 7;

int n, t, p[N], a[N];
vector<int> adj[N];
long long dp[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cur, nxt = {1};
    while (!nxt.empty()) {
        long long ml = -INF, mr = -INF;
        long long al = -INF, ar = -INF;
        for (int u : nxt) {
            for (int v : adj[u]) {
                cur.push_back(v);
                al = max(al, -1LL * a[v]);
                ar = max(ar, 1LL * a[v]);
                ml = max(ml, dp[u] - a[v]);
                mr = max(mr, dp[u] + a[v]);
            }
        }
        for (int u : cur) {
            dp[u] = max({dp[p[u]] + a[u] + al, dp[p[u]] - a[u] + ar, ml + a[u], mr - a[u]});
        }
        swap(cur, nxt);
        cur.clear();
    }
    cout << *max_element(dp + 1, dp + n + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}