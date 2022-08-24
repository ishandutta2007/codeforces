#include <bits/stdc++.h>
using namespace std;
long long n;
int m;
long long dp[(1 << 18)][100];
int x[10];
int b[20];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin)  ;
    cin >> n >> m;
    long long q = n;
    int pt = 0;
    while (n > 0) {
        x[n % 10]++;
        b[pt] = n % 10;
        n /= 10;
        pt++;
    }
    //for (int i = 0; i < 10; i++) cout << x[i] << '\n';
    dp[0][0] = 1;
    for (int mask = 0; mask < (1 << pt); mask++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < pt; j++) {
                if ((mask & (1 << j)) == 0) {
                    if (mask != 0 || b[j] != 0) {
                        dp[mask | (1 << j)][(10 * i + b[j]) % m] += dp[mask][i];
                    }
                }
            }
        }
    }
    long long ans = dp[(1 << pt) - 1][0];
    //cout << ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= x[i]; j++) {
            ans = ans / (1LL * j);
        }
    }
    cout << ans;
    return 0;
}