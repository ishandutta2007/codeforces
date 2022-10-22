#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 53;
const int Maxm = 20005;

int n, m, k;
int B[Maxn][Maxm], S[Maxn][Maxm];
int dp[Maxn][Maxm];
int best, add;
int st, en;
ii Q[Maxm];
int mytop[Maxm];
int myB[Maxm], myS[Maxm];
int res1[Maxm], res2[Maxm];

void Solve(int res[])
{
    fill(res, res + m, 0);
    st = en = 0;
    best = add = 0;
    Q[en++] = ii(1, mytop[1]);
    res[1] = max(mytop[1], myS[1]);
    for (int i = 2; i + k <= m + 1; i++) {
        while (st < en && Q[st].first <= i - k) st++;
        if (i - k >= 1) best = max(best, mytop[i - k]);
        add += myB[i];
        int val = mytop[i] - add;
        while (st < en && Q[en - 1].second <= val) en--;
        Q[en++] = ii(i, val);
        res[i] = max(Q[st].second + add, best + myS[i]);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &B[i][j]);
            S[i][j] = S[i][j - 1] + B[i][j];
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + k <= m + 1; j++) {
            mytop[j] = dp[i][j];
            myB[j] = B[i][j + k - 1];
            myS[j] = S[i][j + k - 1] - S[i][j - 1];
        }
        Solve(res1);
        for (int j = 1; j + k <= m + 1; j++) {
            int ind = m + 1 - (j + k) + 1;
            mytop[ind] = dp[i][j];
            myB[ind] = B[i][j];
            myS[ind] = S[i][j + k - 1] - S[i][j - 1];
        }
        Solve(res2);
        for (int j = 1; j + k <= m + 1; j++) {
            int ind = m + 1 - (j + k) + 1;
            dp[i + 1][j] = max(res1[j], res2[ind]) + S[i + 1][j + k - 1] - S[i + 1][j - 1];
        }
    }
    int res = 0;
    for (int j = 1; j + k <= m + 1; j++)
        res = max(res, dp[n + 1][j]);
    printf("%d\n", res);
    return 0;
}