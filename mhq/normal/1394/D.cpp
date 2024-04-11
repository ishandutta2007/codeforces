#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int t[maxN];
int h[maxN];
vector < int > g[maxN];
bool used[maxN];
int bal[maxN];
vector < ll > dp[maxN];
int SHIFT[maxN];
void dfs(int v, int p) {
    used[v] = true;
    for (int to : g[v]) {
        if (to == p) continue;
        assert(h[to] == h[v]);
        SHIFT[v]++;
        dfs(to, v);
    }
    dp[v].resize(SHIFT[v] + 1);
    vector < ll > diff;
    ll inival = 0;
//    cout << " HI " << SHIFT[v] << " " << v << endl;
    for (int to : g[v]) {
        if (to == p) continue;
        ll valpos = 1e18;
        ll valneg = 1e18;
        for (int c = 0; c < dp[to].size(); c++) {
            int real_bal = bal[to] + 2 * c - SHIFT[to];
            valneg = min(valneg, 1LL * abs(real_bal + 1) * t[to] + dp[to][c]);
            valpos = min(valpos, 1LL * abs(real_bal - 1) * t[to] + dp[to][c]);
        }
        inival += valneg;
        diff.emplace_back(valpos - valneg);
    }
    sort(diff.begin(), diff.end());
    dp[v][0] = inival;
    assert(diff.size() + 1 == dp[v].size());
    for (int i = 1; i < dp[v].size(); i++) {
        dp[v][i] = dp[v][i - 1] + diff[i - 1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ans += (t[u] + t[v]);
        if (h[u] < h[v]) {
            bal[u]++;
            bal[v]--;
        }
        else if (h[u] > h[v]) {
            bal[u]--;
            bal[v]++;
        }
        else {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, -1);
            ll mn = 1e18;
            for (int c = 0; c < dp[i].size(); c++) {
                mn = min(mn, 1LL * abs(bal[i] + 2 * c - SHIFT[i]) * t[i] + dp[i][c]);
            }
            ans += mn;
        }
    }
    assert(ans % 2 == 0);
    cout << ans / 2;
    return 0;
}