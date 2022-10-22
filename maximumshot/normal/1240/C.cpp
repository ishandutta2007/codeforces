#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5e5 + 5;

int n, k;
vector<pii> g[N];
ll dp[N][2];

void dfs(int v, int par = -1) {
    vector<pll> ar;
    dp[v][0] = dp[v][1] = 0;
    ll S0 = 0;
    for (pii ed : g[v]) {
        int to, we;
        tie(to, we) = ed;
        if (to == par) continue;
        dfs(to, v);
        ar.emplace_back(dp[to][0], dp[to][1] + we);
        S0 += dp[to][0];
    }
    sort(ar.begin(), ar.end(), [](const pll& p1, const pll& p2) {
        return p1.second - p1.first > p2.second - p2.first;
    });
    dp[v][0] = dp[v][1] = S0;
    for (int j = 1; j < k && j <= (int) ar.size(); j++) {
        if (ar[j - 1].second < ar[j - 1].first) break;
        dp[v][1] += ar[j - 1].second - ar[j - 1].first;
    }
    for (int j = 1; j <= k && j <= (int) ar.size(); j++) {
        if (ar[j - 1].second < ar[j - 1].first) break;
        dp[v][0] += ar[j - 1].second - ar[j - 1].first;
    }
}

void solve() {
    cin >> n >> k;
    for (int v = 1; v <= n; v++) {
        g[v].clear();
    }
    for (int u, v, w, i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}