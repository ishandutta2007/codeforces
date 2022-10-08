
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n;
ll h[MAX_N][2], dp[MAX_N][2];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i][0];
    }
    for(int i = 0; i < n; i++) {
        cin >> h[i][1];
    }
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], h[i - 1][0] + dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][1], h[i - 1][1] + dp[i - 1][0]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}