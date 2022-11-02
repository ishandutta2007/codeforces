#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

int N, K, c[maxn];
int dp[maxn][maxn];

int ans[maxn], cnt;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> c[i];

    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
        for (int j = K; j >= 0; j--)
            for (int k = K; k >= 0; k--)
                if (dp[j][k]) {
                    if (j + c[i] <= K) dp[j + c[i]][k] = 1;
                    if (k + c[i] <= K) dp[j][k + c[i]] = 1;
                }
    
    for (int i = 0; i <= K; i++)
        if (dp[i][K - i])
            ans[cnt++] = i;

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) cout << ans[i] << ' ';
    cout << '\n';
}