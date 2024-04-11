#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int K = 30, N = 500005, MOD = 998244353;

int n, k, m, l, r, x, sum[N], prv[N];
long long dp[N] = {1};
long long ans = 1;
vector<tuple<int, int, int>> ve;

long long solve(int bit) {
    fill(sum + 1, sum + n + 1, 0);
    fill(prv + 1, prv + n + 1, 0);
    fill(dp + 1, dp + n + 1, 0);
    for (auto [l, r, typ] : ve) {
        if ((typ >> bit & 1) == 0) {
            prv[r] = max(prv[r], l);
        } else {
            sum[l]++;
            sum[r + 1]--;
        }
    }
    long long aux = (sum[1] == 0);
    for (int i = 1, pt = 0; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (prv[i] == 0) {
            dp[i] = dp[i - 1];
            if (sum[i] == 0) {
                (dp[i] += dp[i - 1]) %= MOD;
            }
        } else {
            for (; pt < prv[i] - 1; pt++) {
                if (sum[pt + 1] == 0) {
                    (aux -= dp[pt]) %= MOD;
                }
            }
            dp[i] = aux;
        }
        if (sum[i] + sum[i + 1] == 0) {
            (aux += dp[i]) %= MOD;
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r >> x;
        ve.push_back({l, r, x});
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < k; i++) {
        (ans *= solve(i)) %= MOD;
    }
    cout << (ans + MOD) % MOD;
}