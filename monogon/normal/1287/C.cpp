
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n, cnt[N][2], p[N], dp[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        cnt[i][0] = cnt[i - 1][0];
        cnt[i][1] = cnt[i - 1][1];
        if(p[i]) cnt[i][p[i] % 2]++;
    }
    int ecnt = (n / 2) - cnt[n][0], ocnt = ((n + 1) / 2) - cnt[n][1];
    for(int e = 1; e <= ecnt; e++) {
        dp[0][e][0] = dp[0][e][1] = 1e9 + 7;
    }
    for(int i = 1; i <= n; i++) {
        for(int e = 0; e <= ecnt; e++) {
            int o = (i - cnt[i][0] + cnt[i][1]) - e;
            if(o < 0 || o > ocnt) {
                dp[i][e][0] = dp[i][e][1] = 1e9 + 7;
            }
            for(int b : {0, 1}) {
                if(p[i])
                    dp[i][e][b] = (b + p[i]) % 2 + dp[i - 1][e][p[i] % 2];
                else {
                    int ae = b + dp[i - 1][e - 1][0];
                    int ao = !b + dp[i - 1][e][1];
                    if(o == 0) dp[i][e][b] = ae;
                    else if(e == 0) dp[i][e][b] = ao;
                    else dp[i][e][b] = min(ae, ao);
                }
            }
        }
    }
    cout << min(dp[n][ecnt][0], dp[n][ecnt][1]) << endl;
}