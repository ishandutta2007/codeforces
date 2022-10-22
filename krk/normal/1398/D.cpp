#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205;

int n, m, k;
vector <int> A, B, C;
ll dp[Maxn][Maxn][Maxn];

vector <int> Read(int n)
{
    vector <int> res;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        res.push_back(a);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    A = Read(n);
    B = Read(m);
    C = Read(k);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int l = 0; l <= k; l++) {
                if (i < n)
                    dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
                if (j < m)
                    dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l]);
                if (l < k)
                    dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
                if (i < n && j < m)
                    dp[i + 1][j + 1][l] = max(dp[i + 1][j + 1][l], dp[i][j][l] + A[i] * B[j]);
                if (i < n && l < k)
                    dp[i + 1][j][l + 1] = max(dp[i + 1][j][l + 1], dp[i][j][l] + A[i] * C[l]);
                if (j < m && l < k)
                    dp[i][j + 1][l + 1] = max(dp[i][j + 1][l + 1], dp[i][j][l] + B[j] * C[l]);
            }
    printf("%I64d\n", dp[n][m][k]);
    return 0;
}