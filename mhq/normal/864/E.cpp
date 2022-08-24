#include <bits/stdc++.h>
using namespace std;
int dp[105][2005];
int d[105];
int t[105];
int p[105];
int n;
int d1[105];
int t1[105];
int p1[105];
int u[105];
pair < int, int > q[105];
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for ( int i = 1; i <= n; i++) {
        cin >> t1[i] >> d1[i] >> p1[i];
        q[i].first = d1[i];
        q[i].second = i;
    }
    sort(q + 1, q + n + 1);
    for ( int i = 1; i <= n; i++) {
        d[i] = d1[q[i].second];
        t[i] = t1[q[i].second];
        p[i] = p1[q[i].second];
        u[i] = q[i].second;
    }
    for ( int i = 0; i <= 100; i++) {
        for ( int j = 0; j <= 2000; j++) {
            dp[i][j] = -100000;
        }
    }
    dp[0][0] = 0;
    for ( int i = 1; i <= n; i++) {
        if ( d[i] <= t[i]) {
            for ( int j = 0; j <= 2001; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        for ( int j = 0; j <= d[i] - t[i] - 1; j++) {
            dp[i][j + t[i]] = max(dp[i - 1][j] + p[i], dp[i - 1][j + t[i]]);
        }
        for ( int j = 0; j <= 2000; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
        }
    }
    int i = n;
    int ans = dp[n][0];
    int curj = 0;
    for ( int j = 0; j <= 2000; j++) {
        if (dp[i][j] > ans) {
            ans = dp[i][j];
            curj = j;
        }
    }
    vector < int > an;
    cout << dp[i][curj] << '\n';
    while ( i > 0) {
        if ( curj < t[i] || dp[i][curj] > dp[i - 1][curj - t[i]] + p[i]) {
            i--;
        }
        else {
            curj = curj - t[i];
            an.push_back(u[i]);
            i--;
        }
    }
    cout << an.size() << '\n';
    reverse(an.begin(), an.end());
    for ( int i = 0; i < an.size(); i++) {
        cout << an[i] << " ";
    }
    return 0;
}