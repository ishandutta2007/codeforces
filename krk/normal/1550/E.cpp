#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxk = 17;

int n, k;
char str[Maxn];
int mx[Maxn][Maxk];
int nxt[Maxn][Maxk];
int dp[1 << Maxk];

bool Possible(int x)
{
    for (int j = 0; j < k; j++)
        nxt[n][j] = n;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < k; j++)
            nxt[i][j] = mx[i][j] >= x? i: nxt[i + 1][j];
    fill(dp, dp + (1 << k), Maxn);
    dp[0] = 0;
    for (int i = 0; i < 1 << k; i++) if (dp[i] < Maxn)
        for (int j = 0; j < k; j++) if (!(i & 1 << j)) {
            int oth = nxt[dp[i]][j];
            if (oth <= n - x) {
                int ni = oth + x;
                dp[i | 1 << j] = min(dp[i | 1 << j], ni);
            }
        }
    return dp[(1 << k) - 1] <= n;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < k; j++)
            mx[i][j] = (str[i] == '?' || str[i] == 'a' + j)? 1 + mx[i + 1][j]: 0;
    int lef = 0, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Possible(mid)) lef = mid + 1;
        else rig = mid - 1;
    }
    printf("%d\n", rig);
    return 0;
}