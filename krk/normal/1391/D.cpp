#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 3;
const int Inf = 1000000000;

char tmp[Maxn];
int n, m;
vector <string> B;
bool good[1 << Maxm][1 << Maxm];
int dp[Maxn][1 << Maxm];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

vector <string> Change(const vector <string> &M)
{
    vector <string> nw(M[0].size());
    for (int i = 0; i < nw.size(); i++) {
        nw[i].resize(M.size());
        for (int j = 0; j < nw[i].size(); j++)
            nw[i][j] = M[j][i];
    }
    return nw;
}

int Cost(int row, int mask)
{
    int res = 0;
    for (int j = 0; j < m; j++)
        res += (B[row][j] == '1') != bool(mask & 1 << j);
    return res;
}

bool Good(int mask1, int mask2)
{
    for (int j = 0; j + 1 < m; j++) {
        int tot = int(bool(mask1 & 1 << j)) + int(bool(mask1 & 1 << j + 1)) + int(bool(mask2 & 1 << j)) + int(bool(mask2 & 1 << j + 1));
        if (tot % 2 == 0) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    if (n >= 4 && m >= 4) {
        printf("-1\n");
        return 0;
    }
    B.resize(n);
    for (int i = 0; i < n; i++)
        Read(B[i]);
    if (n < m) {
        B = Change(B);
        swap(n, m);
    }
    for (int i = 0; i < 1 << m; i++)
        for (int j = 0; j < 1 << m; j++)
            good[i][j] = Good(i, j);
    fill((int*)dp, (int*)dp + Maxn * (1 << Maxm), Inf);
    for (int j = 0; j < 1 << m; j++)
        dp[1][j] = Cost(0, j);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 1 << m; j++) if (dp[i][j] < Inf)
            for (int k = 0; k < 1 << m; k++) if (good[j][k])
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + Cost(i, k));
    int res = Inf;
    for (int j = 0; j < 1 << m; j++)
        res = min(res, dp[n][j]);
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}