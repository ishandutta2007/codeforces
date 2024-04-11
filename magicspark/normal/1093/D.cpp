 #include <bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 3e5 + 40, MOD = 998244353;
int a[max_n * 2], ans[max_n], mark[max_n];
vector<int> adj[max_n];
int n, m, ch, cnt;
void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int dfs(int v, int s) {
    cnt++;
    mark[v] = s;
    int tmp = s - 1;
    for (auto i : adj[v]) {
        if (!mark[i])
            tmp += dfs(i, 3 - s);
        if (mark[i] == s) {
            ch = 1;
            return 0;
        }
    }
    return tmp;
}
void clr() {
    for (int i = 0; i < n; i++)
        adj[i].clear(), mark[i] = 0;
    ch = 0;
}
int32_t main() {
    int t;
    cin >> t;
    a[0] = 1;
    for (int i = 1; i < 2 * max_n; i++)
        a[i] = (a[i - 1] * 2) % MOD;
    for (int k = 0; k < t; k++) {
        inp();
        int ans = 1;
        for (int i = 0; i < n; i++)
            if (!mark[i]) {
                int tmp = dfs(i, 1);
                ans *= (a[tmp] + a[cnt - tmp]) % MOD;
                ans %= MOD;
                cnt = 0;
            }
        if (ch)
            cout << 0 << endl;
        else
            cout << (ans) % MOD << endl;
        clr();
    }
    return 0;
}