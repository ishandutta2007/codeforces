#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 1005;
int dp[maxN][2 * maxN][6];
int n, k;
int add[4][4];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int mask = 0; mask < 4; mask++) {
        if (mask == 0 || mask == 3) {
           // cout << mask << endl;
            dp[1][1][mask] = 1;
        }
        else dp[1][2][mask] = 1;
    }
    add[0][0] = 0;
    add[0][1] = 1;
    add[0][2] = 1;
    add[0][3] = 1;
    add[1][0] = 0;
    add[1][1] = 0;
    add[1][2] = 2;
    add[1][3] = 0;
    add[2][0] = 0;
    add[2][1] = 2;
    add[2][2] = 0;
    add[2][3] = 0;
    add[3][0] = 1;
    add[3][1] = 1;
    add[3][2] = 1;
    add[3][3] = 0;
    for (int i = 1; i + 1 <= n; i++) {
        for (int comp = 0; comp <= k; comp++) {
            for (int mask = 0; mask < 4; mask++) {
                if (dp[i][comp][mask] == 0) continue;
                for (int new_mask = 0; new_mask < 4; new_mask++) {
                    dp[i + 1][add[mask][new_mask] + comp][new_mask] = sum(dp[i][comp][mask], dp[i + 1][add[mask][new_mask] + comp][new_mask]);
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < 4; mask++) ans = sum(ans, dp[n][k][mask]);
    cout << ans;
    return 0;
}