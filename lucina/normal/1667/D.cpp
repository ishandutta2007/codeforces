#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
vector <int> g[nax];
char dp[nax];
vector <array <int, 2>> ans;
/// short code, remove comments
void dfs_dp(int node, int par) {
    dp[node] = 0;
    int c[4]{};
    for (int to : g[node]) {
        if (to == par) continue;
        dfs_dp(to, node);
        c[dp[to]] += 1;
    }
    if (c[0]) return;
    int sz = g[node].size();
    int even = (sz + 1) / 2;
    int odd = sz / 2;
    dp[node] = (odd >= c[2] && even > c[1]) + 2 * (odd > c[2] && even >= c[1]);
}

void restore(int v, int par, int state) {
    vector <int> lst[4];
    for (int to : g[v]) {
        if (to == par) continue;
        lst[dp[to]].push_back(to);
    }
    auto get_st = [&](int st) -> int {
        int nxt = -1;
        if (lst[1 << st].empty()) return nxt = lst[3].back(), lst[3].pop_back(), nxt;
        return nxt = lst[1 << st].back(), lst[1 << st].pop_back(), nxt;
    };
    auto run_state = [&]() {
        while (lst[1].size() || lst[2].size() || lst[3].size()) {
            int nxt = get_st(state);
            restore(nxt, v, state);
            state ^= 1;
        }
    };
    if (par == 0) return run_state();
    if (state == 0) {
        ans.push_back({v, par});
        state = 1;
        return run_state();
    }
    state = 0;
    int nxt = get_st(state);
    restore(nxt, v, state);
    ans.push_back({v, par});
    run_state();
}

void solve() {
    cin >> n;
    for (int i = 1, u, v ; i < n ; ++ i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_dp(1, 0);

    int c[4]{};
    for (int to : g[1]) {
        int msk = dp[to];
        c[msk] += 1;
    }
    int sz = g[1].size();
    if (c[0] || (sz + 1) / 2 < c[1] || sz / 2 < c[2]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ans.clear();
    restore(1, 0, 0);
    reverse(ans.begin(), ans.end());
    for (auto &[u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    ans.reserve(nax);

    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/**
    long time no div.1
*/