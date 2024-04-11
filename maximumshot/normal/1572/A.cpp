#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1), gr(n + 1);
        for (int v = 1; v <= n; v++) {
            int k;
            cin >> k;
            for (int it = 0; it < k; it++) {
                int u;
                cin >> u;
                g[u].push_back(v);
                gr[v].push_back(u);
            }
        }
        vector<int> used(n + 1), tops;
        function<void(int)> dfs = [&](int v) {
            if (used[v])
                return;
            used[v] = 1;
            for (int to : g[v]) {
                dfs(to);
            }
            tops.push_back(v);
        };
        for (int v = 1; v <= n; v++)
            dfs(v);
        reverse(tops.begin(), tops.end());
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++)
            pos[tops[i]] = i;
        int ok = 1;
        for (int v = 1; v <= n; v++) {
            for (int to : g[v]) {
                if (pos[to] < pos[v])
                    ok = 0;
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        vector<int> dp(n + 1, 1);
        for (int v : tops) {
            for (int u : gr[v]) {
                int tmp = dp[u];
                if (u > v) tmp++;
                dp[v] = max(dp[v], tmp);
            }
        }
        cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}