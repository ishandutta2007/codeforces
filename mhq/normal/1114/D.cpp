#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 5005;
int dp[maxN][maxN][2];
const int INF = (int)1e6;
int n;
int c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector < int > clr;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || (c[i] != c[i - 1])) clr.push_back(c[i]);
    }
    if (clr.size() == 1) {
        cout << 0;
        return 0;
    }
    n = clr.size();
    for (int i = 1; i <= n; i++) {
        c[i] = clr[i - 1];
    }
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            for (int flag = 0; flag < 2; flag++) {
                dp[l][r][flag] = INF;
            }
        }
    }
    for (int l = 1; l <= n; l++) {
        dp[1][l][0] = dp[1][l][1] = 0;
    }
    int ans = INF;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            for (int flag = 0; flag < 2; flag++) {
                int r = l + len - 1;
                int cur_color = c[l];
                if (flag) cur_color = c[r];
                if (l > 1) {
                    dp[len + 1][l - 1][0] = min(dp[len + 1][l - 1][0], dp[len][l][flag] + (cur_color != c[l - 1]));
                }
                if (r < n) {
                    dp[len + 1][l][1] = min(dp[len + 1][l][1], dp[len][l][flag] + (cur_color != c[r + 1]));
                }
                if (len == n) {
                    ans = min(ans, dp[len][l][flag]);
                    //cout << dp[len][l][flag] << endl;
                }
            }
        }
    }
    cout << ans;
}