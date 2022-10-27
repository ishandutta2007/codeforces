#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int a[nax];
int n;
long long dp[nax][2];
long long const inf = 1e17;

void solve () {
    cin >> n;

    long long ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (i % 2) ans += a[i];
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (!(i % 2)) a[i] = -a[i];
        dp[i][0] = dp[i][1] = inf;
    }

    dp[0][0] = 0;
    dp[0][1] = inf;

    long long c = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        dp[i][0] = dp[i - 1][1] + a[i];
        dp[i][1] = dp[i - 1][0] + a[i];
        dp[i][1] = min(dp[i][1], (long long)a[i]);
        dp[i][0] = min(dp[i][0], 0LL);
        c = min(c, dp[i][0]);
    }

    cout << ans - c << '\n';

}

int main () {
    int T;

    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Sue is best girl in A19.
*/