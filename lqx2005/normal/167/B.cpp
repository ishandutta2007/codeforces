#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int N = 200 + 10;
int n, l, k;
int a[N];
db dp[N][N][N * 2], p[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i++) cin >> p[i], p[i] /= 100;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0][n + min(k, n)] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = -i; k <= n; k++) {
                dp[i + 1][j][k + n] += dp[i][j][k + n] * (1 - p[i + 1]);
                dp[i + 1][j + 1][min(n, k + a[i + 1]) + n] += dp[i][j][k + n] * p[i + 1];
            }
        }
    }
    cout.precision(20), cout << fixed;
    db ans = 0;
    for(int i = l; i <= n; i++) for(int j = 0; j <= n; j++) ans += dp[n][i][j + n];
    cout << ans << endl;
    return 0;
}