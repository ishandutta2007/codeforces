#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Maxd = 5;
const int Inf = 2000000000;

int n;
int c1, v, c2;
int dp[Maxn][1 << 4][Maxd][Maxd][Maxd][Maxd];
int res = -Inf;

int getPar(const vector <int> &par, int x)
{
    if (par[x - 1] == x) return x;
    return getPar(par, par[x - 1]);
}

vector <int> Update(const vector <int> &par, int a, int b)
{
    vector <int> res = par;
    if (res[a - 1] == 0) res[a - 1] = a;
    if (res[b - 1] == 0) res[b - 1] = b;
    a = getPar(res, a), b = getPar(res, b);
    if (a == b) return res;
    res[b - 1] = a;
    return res;
}

bool Verify(const vector <int> &par)
{
    set <int> S;
    for (int i = 1; i <= 4; i++)
        if (par[i - 1]) S.insert(getPar(par, i));
    return S.size() <= 1;
}

int main()
{
    fill((int*)dp, (int*)dp + Maxn * (1 << 4) * Maxd * Maxd * Maxd * Maxd, -Inf);
    scanf("%d", &n);
    dp[0][0][0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &c1, &v, &c2);
        vector <int> cur(4, 0);
        int mask = ((1 << c1 - 1) ^ (1 << c2 - 1));
        for (int j = 0; j < 1 << 4; j++)
            for (cur[0] = 0; cur[0] < Maxd; cur[0]++)
                for (cur[1] = 0; cur[1] < Maxd; cur[1]++)
                    for (cur[2] = 0; cur[2] < Maxd; cur[2]++)
                        for (cur[3] = 0; cur[3] < Maxd; cur[3]++) if (dp[i][j][cur[0]][cur[1]][cur[2]][cur[3]] >= 0) {
                            dp[i + 1][j][cur[0]][cur[1]][cur[2]][cur[3]] = max(dp[i + 1][j][cur[0]][cur[1]][cur[2]][cur[3]], dp[i][j][cur[0]][cur[1]][cur[2]][cur[3]]);
                            int nj = (j ^ mask);
                            auto nw = Update(cur, c1, c2);
                            dp[i + 1][nj][nw[0]][nw[1]][nw[2]][nw[3]] = max(dp[i + 1][nj][nw[0]][nw[1]][nw[2]][nw[3]], dp[i][j][cur[0]][cur[1]][cur[2]][cur[3]] + v);
                        } 
    }
    for (int j = 0; j < 1 << 4; j++) if (__builtin_popcount(j) == 0 || __builtin_popcount(j) == 2) {
        vector <int> cur(4, 0);
        for (cur[0] = 0; cur[0] < Maxd; cur[0]++)
            for (cur[1] = 0; cur[1] < Maxd; cur[1]++)
                for (cur[2] = 0; cur[2] < Maxd; cur[2]++)
                    for (cur[3] = 0; cur[3] < Maxd; cur[3]++) if (dp[n][j][cur[0]][cur[1]][cur[2]][cur[3]] >= 0)
                        if (Verify(cur)) res = max(res, dp[n][j][cur[0]][cur[1]][cur[2]][cur[3]]);
    }
    printf("%d\n", res);
    return 0;
}