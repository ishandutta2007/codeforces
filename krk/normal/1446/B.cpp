#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, m;
char A[Maxn], B[Maxn];
int dp[Maxn][Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", A);
    scanf("%s", B);
    for (int i = n; i >= 0; i--)
        for (int j = m; j >= 0; j--) {
            if (i < n) dp[i][j] = max(dp[i][j], dp[i + 1][j] - 1);
            if (j < m) dp[i][j] = max(dp[i][j], dp[i][j + 1] - 1);
            if (i < n && j < m && A[i] == B[j])
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 2);
            res = max(res, dp[i][j]);
        }
    cout << res << endl;
    return 0;
}