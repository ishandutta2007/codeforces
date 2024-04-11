#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxm = 4015;
const int Maxl = 26;
const int Inf = 1000000000;

int n, k;
char B[Maxn][Maxn];
int dp[Maxn][Maxn];
vector <ii> V[Maxm][Maxl];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    fill((int*)dp, (int*)dp + Maxn * Maxn, -Inf);
    dp[0][0] = k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (dp[i][j] >= 0) {
            int cost = B[i][j] != 'a';
            if (i + 1 < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - cost);
            if (j + 1 < n) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - cost);
        }
    if (dp[n - 1][n - 1] - (B[n - 1][n - 1] != 'a') >= 0) {
        printf("%s\n", string(n + n - 1, 'a').c_str());
        return 0;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (dp[i][j] >= 0) {
            mx = max(mx, i + j);
            V[i + j][B[i][j] - 'a'].push_back(ii(i, j));
        }
    if (mx > 0) printf("%s", string(mx, 'a').c_str());
    for (int d = mx; d <= 2 * (n - 1); d++) {
        int my = 0;
        while (V[d][my].empty()) my++;
        sort(V[d][my].begin(), V[d][my].end());
        V[d][my].erase(unique(V[d][my].begin(), V[d][my].end()), V[d][my].end());
        printf("%c", my + 'a');
        for (int i = 0; i < V[d][my].size(); i++) {
            ii p = V[d][my][i];
            if (p.first + 1 < n)
                V[d + 1][B[p.first + 1][p.second] - 'a'].push_back(ii(p.first + 1, p.second));
            if (p.second + 1 < n)
                V[d + 1][B[p.first][p.second + 1] - 'a'].push_back(ii(p.first, p.second + 1));
        }
    }
    printf("\n");
    return 0;
}