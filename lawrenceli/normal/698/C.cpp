#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int N, K;
ld p[20], dp[1<<20], sum[1<<20];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> p[i];

    dp[0] = 1;
    for (int i = 1; i < 1<<N; i++)
        for (int j = 0; j < N; j++)
            if (i & 1<<j) {
                int k = i ^ 1<<j;
                sum[i] = sum[k] + p[j];
                if (p[j]) dp[i] += dp[k] * p[j] / (1 - sum[k]);
            }

    //for (int i = 0; i < 1<<N; i++) cout << dp[i] << endl;

    for (int i = 0; i < N; i++) {
        ld ans = 0;
        for (int j = 0; j < 1<<N; j++)
            if (!(j & 1<<i) && __builtin_popcount(j) < K)
                if (p[i]) ans += dp[j] * p[i] / (1 - sum[j]);
        cout << fixed << setprecision(15) << ans << ' ';
    }
    cout << '\n';
}