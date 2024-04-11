#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;
const int Maxm = 512;

int n;
int a[Maxn];
int nxt[Maxn][Maxm];
int dp[Maxm][Maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < Maxm; i++)
        nxt[n][i] = n;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < Maxm; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][a[i]] = i;
    }
    fill((int*)dp, (int*)dp + Maxm * Maxm, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < Maxm; i++)
        for (int j = 0; j < Maxm; j++) if (dp[i][j] < Inf) {
            int ind = dp[i][j];
            for (int o = i + 1; o < Maxm; o++) if (nxt[ind][o] < n)
                dp[o][j ^ o] = min(dp[o][j ^ o], nxt[ind][o] + 1);
        }
    vector <int> res;
    for (int j = 0; j < Maxm; j++) {
        bool found = false;
        for (int i = 0; i < Maxm && !found; i++)
            found = dp[i][j] < Inf;
        if (found) res.push_back(j);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}