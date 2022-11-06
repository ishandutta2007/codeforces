#include <iostream>

using namespace std;

const int N = 101;

int n, m;
int l[N][N], r[N][N], dp[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int L, R;
            cin >> L >> R;
            for (int x = L; x <= R; x++)
                l[i][x] = L, r[i][x] = R;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            if (l[i][j] == j && r[i][j] == j)
                dp[j][j]++;
        dp[j][j] *= dp[j][j];
    }
    for (int len = 2; len <= m; len++)
        for (int L = 1; L + len - 1 <= m; L++) {
            int R = L + len - 1;
            for (int k = L; k <= R; k++) {
                int x = 0;
                for (int i = 1; i <= n; i++)
                    if (l[i][k] >= L && r[i][k] <= R)
                        x++;
                dp[L][R] = max(dp[L][R], x * x + dp[L][k - 1] + dp[k + 1][R]);
            }
        }
    cout << dp[1][m];
    return 0;
}