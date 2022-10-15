#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    using State = array<pair<ll, ll>, 3>;
    const ll INF = -1e10;
    const State INIT = State{pair<ll, ll>{INF, 0LL}, {INF, 0LL}, {INF, 0LL}};
    vector<State> dp(n, INIT);

    auto updateState = [&](pair<ll, ll>& lhs, const pair<ll, ll>& rhs, bool count = false) {
        if (rhs.first > lhs.first && !count) {
            lhs = {rhs.first, 0LL};
        }
        if (rhs.first == lhs.first) {
            lhs.second += rhs.second;
        }
    };

    auto dfs = [&](const auto& self, int v, int par) -> void {
        dp[v][1] = {a[v], 1};

        for (int u : g[v]) {
            if (u != par) {
                self(self, u, v);
                updateState(dp[v][0], max(dp[u][0], dp[u][1]));
                if (dp[u][1].first > 0) {
                    dp[v][1].first += dp[u][1].first;
                    updateState(dp[v][2], dp[u][2]);
                } else {
                    updateState(dp[v][2], dp[u][0]);
                }
            }
        }

        for (int u : g[v]) {
            if (u != par) {
                if (dp[u][1].first <= 0) {
                    updateState(dp[v][1], max(dp[u][0], dp[u][1]), true);
                } else {
                    updateState(dp[v][1], dp[u][2], true);
                }
            }
        }
    };

    dfs(dfs, 0, -1);
    auto best = max(dp[0][0], dp[0][1]);
    cout << best.first * best.second << ' ' << best.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}