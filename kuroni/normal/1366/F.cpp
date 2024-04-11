#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 2005, MOD = 1E9 + 7;

int u, v, w, m, n, q;
long long ans = 0, dp[M][N];
vector<pair<int, int>> adj[N];

struct line {
    int a;
    long long b;

    line(int _a, long long  _b) : a(_a), b(_b) {}

    long long intersect(const line &oth) const {
        return (b - oth.b) / (oth.a - a);
    }

    bool operator<(const line &oth) const {
        return a < oth.a || (a == oth.a && b < oth.b);
    }
};
vector<line> ve, cht;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    fill(dp[0] + 1, dp[0] + n + 1, INT_MIN);
    dp[0][1] = 0;
    for (int i = 1; i <= m; i++) {
        fill(dp[i] + 1, dp[i] + n + 1, INT_MIN);
        for (int j = 1; j <= n; j++) {
            for (auto [v, w] : adj[j]) {
                dp[i][v] = max(dp[i][v], dp[i - 1][j] + w);
            }
        }
        (ans += *max_element(dp[i] + 1, dp[i] + n + 1)) %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        if (dp[m][i] != INT_MIN) {
            int mx = 0;
            for (auto [_, w] : adj[i]) {
                mx = max(mx, w);
            }
            ve.push_back(line(mx, dp[m][i]));
        }
    }
    sort(ve.begin(), ve.end());
    for (line& nxt : ve) {
        if (!cht.empty() && cht.back().a == nxt.a) {
            cht.pop_back();
        }
        while (cht.size() >= 2) {
            line cur = cht[cht.size() - 1];
            line prv = cht[cht.size() - 2];
            if (prv.intersect(nxt) < prv.intersect(cur)) {
                cht.pop_back();
            } else {
                break;
            }
        }
        cht.push_back(nxt);
    }
    long long  lst = 1;
    for (int i = 0; i < cht.size(); i++) {
        long long  cur = min(0LL + q - m, i + 1 == cht.size() ? q - m : cht[i].intersect(cht[i + 1]));
        // lst -> cur uses cht[i]
        if (cur < lst) {
            continue;
        }
        long long  cnt = cur - lst + 1;
        (ans += 1LL * cht[i].b % MOD * cnt) %= MOD;
        (ans += 1LL * cnt * (cur + lst) / 2 % MOD * cht[i].a) %= MOD;
        lst = cur + 1;
    }
    cout << ans;
}