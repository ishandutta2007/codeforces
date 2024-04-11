#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;
const ll Inf = 4000000000000000000ll;

int n, m;
char str[Maxn];
int tims[Maxm][Maxm];
ll cost[1 << Maxm];
ll dp[1 << Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    for (int i = 0; i + 1 < n; i++) if (str[i] != str[i + 1]) {
        tims[str[i] - 'a'][str[i + 1] - 'a']++;
        tims[str[i + 1] - 'a'][str[i] - 'a']++;
    }
    for (int i = 1; i < 1 << m; i++) {
        int b = __builtin_popcount((i & -i) - 1);
        cost[i] = cost[i ^ 1 << b];
        for (int j = 0; j < m; j++)
            if (i & 1 << j) cost[i] -= tims[j][b];
            else cost[i] += tims[j][b];
    }
    fill(dp, dp + (1 << m), Inf);
    dp[0] = 0;
    for (int i = 0; i + 1 < 1 << m; i++) if (dp[i] < Inf)
        for (int j = 0; j < m; j++) if (!(i & 1 << j))
            dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + cost[i | 1 << j]);
    cout << dp[(1 << m) - 1] << endl;
    return 0;
}