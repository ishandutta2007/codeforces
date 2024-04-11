#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, q;
int a[nax];
int64_t dp[nax][2];
const int64_t INF = 1e15;
int64_t ans;
void upd_max(int64_t &a, int64_t b) {
    a = max(a, b);
    ans = max(ans, a);
}

void solve() {
    cin >> n >> q;

    for (int i = 0 ; i <= n ; ++ i) {
        dp[i][0] = dp[i][1] = -INF;
    }
    dp[0][0] = 0;
    ans = 0;

    for (int i = 0 ; i < n ; ++ i) {
        int x;
        cin >> x;
        upd_max(dp[i + 1][0], dp[i][0]);
        upd_max(dp[i + 1][1], dp[i][1]);
        upd_max(dp[i + 1][1], dp[i][0] + x);
        upd_max(dp[i + 1][0], dp[i][1] - x);
    }
    cout << ans << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}