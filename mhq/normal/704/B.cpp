#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;
const int maxN = 5005;
int n, s, e;
ll x[maxN], c[maxN], d[maxN], a[maxN], b[maxN];
ll dp[2][maxN][2][2];
void upd(ll& x, ll y) {
    x = min(x, y);
}
void mem(int v) {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[v][i][j][k] = INF;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] -= x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] -= x[i];
    }
    int cur = 0;
    mem(cur);
    if (s == 1) {
        dp[cur][0][1][0] = d[1];
    }
    else if (e == 1) {
        dp[cur][0][0][1] = b[1];
    }
    else {
        dp[cur][1][0][0] = d[1] + b[1];
    }
    // nelza s i e
    ll ans = INF;
    for (int i = 2; i <= n; i++) {
        mem(cur ^ 1);
        for (int comp = 0; comp <= i; comp++) {
            for (int comp_s = 0; comp_s < 2; comp_s++) {
                for (int comp_e = 0; comp_e < 2; comp_e++) {
                    if (dp[cur][comp][comp_s][comp_e] == INF) continue;
                    if (i != s && i != e) {
                        if (i == n && comp_s == 1 && comp_e == 1 && comp == 0) upd(ans, dp[cur][comp][comp_s][comp_e] + a[i] + c[i]);
                        upd(dp[cur ^ 1][comp + 1][comp_s][comp_e], dp[cur][comp][comp_s][comp_e] + d[i] + b[i]);
                        if (comp || comp_s) upd(dp[cur ^ 1][comp][comp_s][comp_e], dp[cur][comp][comp_s][comp_e] + a[i] + d[i]);
                        if (comp + max(comp_s, comp_e) >= 2) upd(dp[cur ^ 1][comp - 1][comp_s][comp_e], dp[cur][comp][comp_s][comp_e] + a[i] + c[i]);
                        if (comp || comp_e) upd(dp[cur ^ 1][comp][comp_s][comp_e], dp[cur][comp][comp_s][comp_e] + c[i] + b[i]);
                    }
                    else if (i == s) {
                        assert(comp_s == 0);
                        if (i == n && comp_s == 0 && comp_e == 1 && comp == 0) upd(ans, dp[cur][comp][comp_s][comp_e] + c[i]);
                       upd(dp[cur ^ 1][comp][1][comp_e], dp[cur][comp][comp_s][comp_e] + d[i]);
                       if (comp >= 1) upd(dp[cur ^ 1][comp - 1][1][comp_e], dp[cur][comp][comp_s][comp_e] + c[i]);
                    }
                    else {
                        assert(comp_e == 0);
                        if (i == n && comp_s == 1 && comp_e == 0 && comp == 0) upd(ans, dp[cur][comp][comp_s][comp_e] + a[i]);
                        upd(dp[cur ^ 1][comp][comp_s][1], dp[cur][comp][comp_s][comp_e] + b[i]);
                        if (comp >= 1) upd(dp[cur ^ 1][comp - 1][comp_s][1], dp[cur][comp][comp_s][comp_e] + a[i]);
                    }
                }
            }
        }
        cur ^= 1;
    }
    cout << ans;
    return 0;
}