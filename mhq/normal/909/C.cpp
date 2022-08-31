#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
char x;
int n;
const int mod = (int)1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i + 1 < n; i++) {
        cin >> x;
        //cout << x << endl;
        if (x == 'f') {
            //cout << i << "HERE";
            for (int j = 0; j <= 5003; j++) {
                //if (i == 0 && j == 0) cout << "TUT";
                dp[i + 1][j + 1] = dp[i][j];
            }
        }
        else {
            int cursum = 0;
            for (int j = 5003; j >= 0; j--) {
                cursum = (cursum + dp[i][j]) % mod;
                dp[i + 1][j] = cursum;
            }
        }
    }
    //cout << dp[3][2];
    int ans = 0;
    for (int i = 0; i <= 5003; i++) {
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout << ans;
}