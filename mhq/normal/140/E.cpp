#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 5005;
int mod;
int sum(int a, int b) {
    int s = (a + b) % mod;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = (a - b) % mod;
    if (s < 0) s += mod;
    return s;
}
int g[maxN][maxN];
int dp[maxN][maxN];
int cc[55][55];
int was[maxN], got[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m >> mod;
    cc[0][0] = 1;
    for (int i = 1; i <= 15; i++) {
        cc[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            cc[i][j] = sum(cc[i - 1][j - 1], cc[i - 1][j]);
        }
    }
    g[0][0] = 1;
    dp[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            g[i][j] = sum(g[i][j], sum(mult((j - 1), g[i - 1][j]), mult((m - j + 1), g[i - 1][j - 1])));
        }
    }
    for (int i = 1; i < maxN; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = sum(dp[i][j], sum(mult(j, dp[i - 1][j - 1]), mult(j - 1, dp[i - 1][j])));
        }
    }
    was[0] = 1;
    int prvl = 0;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j <= l; j++) got[j] = 0;
        int total_sum = 0;
        for (int v = 0; v <= prvl; v++) total_sum = sum(total_sum, was[v]);
        for (int k = 1; k <= l; k++) {
            got[k] = mult(total_sum, g[l][k]);
            if (k <= prvl) {
                got[k] = sub(got[k], mult(was[k], dp[l][k]));
            }
        }
        for (int j = 0; j <= prvl; j++) {
            was[j] = 0;
        }
        prvl = l;
        for (int j = 0; j <= prvl; j++) {
            was[j] = got[j];
        }
     //   cout << total[1][2] << " ?? " << endl;
    }
    int ans = 0;
    for (int v = 0; v <= prvl; v++) {
       // cout << v << " ???? " << endl;
        ans = sum(ans, was[v]);
    }
    cout << ans;
    return 0;
}