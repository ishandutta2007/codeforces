#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 1005;

int n, m;
int place[N];
double dp[N][N * M], pref[N][N * M];

int main() {

    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    if (m == 1) {
        cout << "1.0\n";
        return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> place[i];
    }

    for (int i = 0; i <= n * m; i++) {
        dp[0][i] = 1;
        pref[0][i] = dp[0][i] + pref[0][i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n * m; j++) {
            dp[i][j] = (pref[i - 1][j - 1] - (j - m - 1 >= 0 ? pref[i - 1][j - m - 1] : 0) - (j - place[i] >= 0 ? dp[i - 1][j - place[i]] : 0)) / (m - 1);
            pref[i][j] = pref[i][j - 1] + dp[i][j];
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += place[i];
    }

    cout << fixed << setprecision(10) << dp[n][sum - 1] * (m - 1) + 1 << endl;
    return 0;
}