#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int INF = 1e8;
int n;
int a[nax];
int dp[nax][2];

void upd_min(int &a, int b) {
    a = min(a, b);
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    for (int i = 0 ; i <= n + 2 ; ++ i) {
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = 0;
    a[n + 1] = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        upd_min(dp[i + 1][1], dp[i][0] + (a[i] == 1));
        upd_min(dp[i + 2][1], dp[i][0] + ((a[i] == 1) + (a[i + 1] == 1)));
        upd_min(dp[i + 1][0], dp[i][1]);
        upd_min(dp[i + 2][0], dp[i][1]);
    }
    cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
   // cout << "ANS\n";

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    ZZZZZZZ
*/