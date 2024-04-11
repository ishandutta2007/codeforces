#include <bits/stdc++.h>

using namespace std;

int n;
int d[200005], ans[200005], ok[200005];
vector<int> adj[200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            adj[i].clear();
        for (int i = 1; i <= n; ++i) {
            int sz, x;
            cin >> sz;
            d[i] = sz;
            while (sz--) {
                cin >> x;
                adj[x].push_back(i);
            }
            ans[i] = ok[i] = 0;
            if (!d[i]) ans[i] = 1, ok[i] = 1, q.push(i);
        }
        int res = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            //cout << u << '\n';
            for (auto v: adj[u]) {
                ans[v] = max(ans[v], ans[u] + (v < u));
                --d[v];
                if (!d[v]) {
                    q.push(v);
                    res = max(res, ans[v]);
                    ok[v] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) if (!ok[i]) res = -1;
        cout << res << '\n';
    }
    return 0;
}