#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 205;
const int maxd = maxn * 18;
const int inf = 1e9;

int N, K;
int a[maxn], b[maxn];
int dp[2][maxn][maxd];

void setmax(int& x, int y) { if (x < y) x = y; }

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        ll y = x;
        while (x % 2 == 0) a[i]++, x /= 2;
        while (y % 5 == 0) b[i]++, y /= 5;
    }

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxd; j++)
            dp[0][i][j] = dp[1][i][j] = -inf;

    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++)
            for (int k = 0; k < maxd; k++)
                if (dp[0][j][k] >= 0) {
                    setmax(dp[1][j][k], dp[0][j][k]);
                    setmax(dp[1][j + 1][min(maxd - 1, k + a[i])], dp[0][j][k] + b[i]);
                }
        
        for (int j = 0; j <= K; j++)
            for (int k = 0; k < maxd; k++)
                dp[0][j][k] = dp[1][j][k], dp[1][j][k] = -inf;
    }

    int ans = 0;
    for (int i = 0; i < maxd; i++)
        ans = max(ans, min(i, dp[0][K][i]));

    cout << ans << '\n';
}