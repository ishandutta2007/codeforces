#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int dp[Maxn][Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            dp[i][j] = 1;
            if (i + 2 < n && j - 1 >= 0 && j + 1 < m && B[i][j] == B[i + 1][j - 1] && B[i][j] == B[i + 1][j] && B[i][j] == B[i + 1][j + 1] && B[i][j] == B[i + 2][j])
                dp[i][j] = min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1], dp[i + 2][j]}) + 1;
            res += dp[i][j];
        }
    cout << res << endl;
    return 0;
}