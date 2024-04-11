#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, m;
vector <ii> bycol[Maxn];
int dp[Maxn][Maxn];

int Get(int col, int lef, int rig)
{
    int res = 0;
    for (int i = 0; i < bycol[col].size(); i++) {
        auto p = bycol[col][i];
        if (lef <= p.first && p.second <= rig) res++;
    }
    return res * res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k; scanf("%d", &k);
        while (k--) {
            int l, r; scanf("%d %d", &l, &r);
            l--; r--;
            for (int j = l; j <= r; j++)
                bycol[j].push_back(ii(l, r));
        }
    }
    for (int i = 0; i < m; i++)
        dp[i][i] = Get(i, i, i);
    for (int l = 1; l <= m; l++)
        for (int i = 0, j = l; j < m; i++, j++)
            for (int z = i; z <= j; z++) {
                int cand = Get(z, i, j);
                if (z > i) cand += dp[i][z - 1];
                if (z < j) cand += dp[z + 1][j];
                dp[i][j] = max(dp[i][j], cand);
            }
    printf("%d\n", dp[0][m - 1]);
    return 0;
}