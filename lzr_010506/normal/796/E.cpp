#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000;
const int MaxK = 50;

short int sum[3][1 + MaxN];
short int dp[2][1 + MaxK][1 + MaxN][1 + MaxN];

short int Sum(int a, int b, int c) {
    return sum[c][b] - sum[c][a - 1];
}

short int Max(short int a, short int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n, p, k;
    cin >> n >> p >> k;
    for (int i = 0; i < 2; i++) {
        int number;
        cin >> number;
        for (int j = 1; j <= number; j++) {
            int x;
            cin >> x;
            sum[i][x] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        sum[2][i] = sum[1][i] | sum[0][i];
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] += sum[i][j - 1];
    for (int i = 1; i <= n; i++)
        for (int l = 1; l < k && l <= i; l++)
            for (int q = 0; q < 2; q++)
                dp[q][l][i][0] = Sum(i - l + 1, i, q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
            for (int l = 0; l < k && l <= i; l++)
                for (int q = 0; q < 2; q++) {
                    if (l)
                        dp[q][l][i][j] = Max(dp[q][l - 1][i - 1][j] + Sum(i, i, q), dp[1 - q][min(i, k) - l][i - l][j - 1] + Sum(i - l + 1, i, 2));
                    else {
                        dp[q][l][i][j] = Max(dp[q][l][i - 1][j], dp[q][l][Max(i - k, 0)][j - 1] + Max(Sum(Max(i - k + 1, 1), i, 0), Sum(Max(i - k + 1, 1), i, 1)));
                        if (j > 1)
                            for (int m = Max(i - k + 1, 1); m < i; m++)
                                for (int t = 0; t < 2; t ++)
                                    dp[q][l][i][j] = Max(dp[q][l][i][j], dp[t][min(m, k) - (m - Max(i - k + 1, 1) + 1)][Max(i - k, 0)][j - 2] + Sum(m + 1, i, 1 - t) + Sum(Max(i - k + 1, 1), m, 2));
                    }
                    dp[q][l][i][j] = Max(dp[q][l][i][j], dp[q][l][i][j - 1]);
                }
    cout << dp[0][0][n][p] << "\n";
    return 0;
}