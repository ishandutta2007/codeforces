
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// dp[i][j][k] = answer for number in news feed, number of pictures left, allowed remaining gap

const int N = 205;
const ll M = LLONG_MIN;
int n, k, x;
ll a[N], dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            for(int kk = 0; kk < k; kk++) {
                if(i == 0) {
                    if(j == 0) dp[i][j][kk] = 0;
                    else dp[i][j][kk] = M;
                }else if(j == 0) {
                    if(kk == 0) dp[i][j][kk] = M;
                    else dp[i][j][kk] = dp[i - 1][j][kk - 1];
                }else if(kk == 0) {
                    if(dp[i - 1][j - 1][k - 1] > M)
                        dp[i][j][kk] = a[i] + dp[i - 1][j - 1][k - 1];
                    else dp[i][j][kk] = M;
                }else {
                    dp[i][j][kk] = M;
                    if(dp[i - 1][j - 1][k - 1] > M) {
                        dp[i][j][kk] = a[i] + dp[i - 1][j - 1][k - 1];
                    }
                    if(dp[i - 1][j][kk - 1] > M) {
                        dp[i][j][kk] = max(dp[i][j][kk], dp[i - 1][j][kk - 1]);
                    }
                }
            }
        }
    }
    cout << max(dp[n][x][k - 1], -1LL) << endl;
}