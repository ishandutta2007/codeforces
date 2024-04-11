#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2005;
int dp[maxN][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    int n, m, k;
    cin >> n >> m >> k;
    dp[1][0] = m;
    for (int i = 1; i + 1 <= n; i++) {
        for (int cnt = 0; cnt <= k; cnt++) {
            dp[i + 1][cnt + 1] = sum(dp[i + 1][cnt + 1], mult(dp[i][cnt], m - 1));
            dp[i + 1][cnt] = sum(dp[i + 1][cnt], dp[i][cnt]);
        }
    }
    cout << dp[n][k];
    return 0;
}