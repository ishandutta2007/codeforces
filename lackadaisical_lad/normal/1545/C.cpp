#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n * 2, vector<int>(n));
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<vector<vector<int>>> kek(n, vector<vector<int>>(n));
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++) {
            kek[j][a[i][j]].push_back(i);
        }
    }

    ll ans_count = 1;
    set<int> ans;

    vector<vector<int>> used(n, vector<int>(n));
    vector<int> bad(n * 2);
    for (int it = 0; it < 2; it++)
    for (int i = 0; i < n; i++) {
        vector<int> cnt(n);
        int good = 0;
        for (int j = 0; j < n * 2; j++) {
            if (bad[j]) continue;
            ++cnt[a[j][i]];
        }
        for (int j = 0; j < n * 2; j++) {
            if (cnt[a[j][i]] == 1 && !bad[j]) {
                ans.insert(j);
                bad[j] = 1;
                for (int k = 0; k < n; k++) {
                    if (!used[k][a[j][k]]) {
                        used[k][a[j][k]] = 1;
                        for (int row : kek[k][a[j][k]]) {
                            bad[row] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            kek[i][j].clear();
        }
    }
    for (int i = 0; i < n * 2; i++) {
        if (bad[i]) continue;
        for (int j = 0; j < n; j++) {
            kek[j][a[i][j]].push_back(i);
        }
    }

    vector<vector<int>> g(n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (kek[i][j].empty()) continue;
            assert(kek[i][j].size() == 2);
            int v = kek[i][j][0];
            int u = kek[i][j][1];
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }

    vector<int> vis(n * 2);
    for (int i = 0; i < n * 2; i++) {
        if (vis[i] || g[i].empty()) {
            continue;
        }
        ans_count = ans_count * 2 % MOD;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (vis[v] == 1) {
                ans.insert(v);
            }
            for (int u : g[v]) {
                if (!vis[u]) {
                    vis[u] = 3 - vis[v];
                    q.push(u);
                }
                assert(vis[v] != vis[u]);
            }
        }
    }
    
    cout << ans_count << endl;
    for (int i : ans) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}