#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int B[2][Maxn];
ll dp[Maxn][2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + ll(B[0][i]));
        dp[i + 1][1] = max(dp[i][1], dp[i][0] + ll(B[1][i]));
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}