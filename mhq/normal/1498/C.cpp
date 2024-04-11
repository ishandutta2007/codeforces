#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int) 1e9 + 7;

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

const int maxN = 1005;
int dp[maxN][maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = 0;
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int i = n; i >= 0; i--) {
                if (i == n) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = sum(dp[i + 1][j], dp[n - i][j - 1]);
                }
            }
        }
        cout << dp[0][k] << '\n';
    }
    return 0;
}