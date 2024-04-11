#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
const int64_t INF = 1e15;
int n, l, k;
int d[nax];
int a[nax];
int64_t dp[nax][nax];
void upd_min(int64_t &a, int64_t b) {
    a = min(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> l >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> d[i];
    }
    d[n + 1] = l;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 0 ; i <= n + 1 ; ++ i)
    for (int j = 0 ; j <= k ; ++ j)
        dp[i][j] = INF;

    dp[1][0] = 0;
    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 0 ; j <= k ; ++ j) {
        if (dp[i][j] == INF) continue;
        upd_min(dp[i + 1][j], dp[i][j] + a[i] * (d[i + 1] - d[i]));
        for (int nxt = i + 2; j + (nxt - i - 1) <= k && nxt <= n + 1 ; ++ nxt) {
            int nj = j + nxt - i - 1;
            int dist = a[i] * (d[nxt] - d[i]);
            upd_min(dp[nxt][nj], dp[i][j] + dist);
        }
    }
    int64_t ans = INF;
    for (int i = 0 ; i <= k ; ++ i)
        upd_min(ans, dp[n + 1][i]);
    cout << ans << '\n';
}