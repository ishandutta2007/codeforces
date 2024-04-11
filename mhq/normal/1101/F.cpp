#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 405;
int dp[maxN][maxN][maxN];
int a[maxN];
int len[maxN];
int sum[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
         cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sum[i][j] = a[j] - a[i];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int k = 0; k <= n; k++) {
            int opt_l = i;
            for (int j = i; j <= n; j++) {
                if (k == 0) {
                    dp[i][j][k] = sum[i][j];
                    continue;
                }
                while (opt_l + 1 <= j && sum[i][opt_l + 1] <= dp[opt_l + 1][j][k - 1]) opt_l++;
                dp[i][j][k] = max(sum[i][opt_l], dp[opt_l][j][k - 1]);
                if (opt_l + 1 <= j) {
                    dp[i][j][k] = min(dp[i][j][k], max(sum[i][opt_l + 1], dp[opt_l + 1][j][k - 1]));
                }
            }
        }
    }
    ll mx = 0;
    for (int i = 1; i <= m; i++) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        mx = max(mx, 1LL * dp[s][f][r] * c);
    }
    cout << mx;
    return 0;
}