#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 4;

int n, m;
char str[Maxn];
ll dp[Maxn][Maxm][Maxm];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    dp[0][1][Maxm - 1] = 1;
    for (int i = 0; i < n; i++)
        for (int a = 0; a < Maxm; a++)
            for (int b = 0; b < Maxm; b++) if (dp[i][a][b]) {
                for (int c = 0; c < m; c++) {
                    int cur1 = i + a - 1;
                    while (cur1 - i + 1 < Maxm - 1 && cur1 < n && str[cur1] != c + 'a')
                        cur1++;
                    cur1 = cur1 - i + 1;
                    int cur2 = i + b - 1;
                    while (cur2 - i + 1 < Maxm - 1 && cur2 < n && str[cur2] != c + 'a')
                        cur2++;
                    cur2 = cur2 - i + 1;
                    if (a != Maxm - 1)
                        cur2 = min(cur2, a - 1);
                    dp[i + 1][cur1][cur2] += dp[i][a][b];
                }
            }
    for (int a = 2; a < Maxm; a++)
        for (int b = 0; b < Maxm; b++)
            if (a == 2 || b < Maxm - 2)
                res += dp[n][a][b];
    cout << res << endl;
    return 0;
}