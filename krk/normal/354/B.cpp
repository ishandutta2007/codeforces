#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 20;
const int MaxN = 1 << Maxn;
const int Maxl = 26;

int n;
char B[Maxn][Maxn];
int dp[2 * Maxn][MaxN];

int getRes(int r, int c, int len, int mask, char nd, char nnd)
{
    if (dp[r + c][mask] == Inf)
        if (r == n - 1 && c == n - 1)
            dp[r + c][mask] = 0;
        else {
            int M[Maxl] = {};
            int sub = 0;
            if (r || c == n - 1) sub = 1;
            for (int i = 0; i < len; i++) 
                if (mask & 1 << i) {
                    int nr = r + i, nc = c - i;
                    if (nr + 1 < n) M[B[nr + 1][nc] - 'a'] |= 1 << i + 1 - sub;
                    if (nc + 1 < n) M[B[nr][nc + 1] - 'a'] |= 1 << i - sub;
                }
            int mx = -Inf;
            if (sub) {
                for (int i = 0; i < Maxl; i++)
                    if (M[i]) mx = max(mx, (i + 'a' == nd) - (i + 'a' == nnd) - getRes(r + 1, c, len - 1, M[i], nnd, nd));
            } else for (int i = 0; i < Maxl; i++)
                        if (M[i]) mx = max(mx, (i + 'a' == nd) - (i + 'a' == nnd) - getRes(r, c + 1, len + 1, M[i], nnd, nd));
            dp[r + c][mask] = mx;
        }
    return dp[r + c][mask];
}

int main()
{
    fill((int*)dp, (int*)dp + (2 * Maxn) * MaxN, Inf);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &B[i][j]);
    int res = (B[0][0] == 'a') - (B[0][0] == 'b') - getRes(0, 0, 1, 1, 'b', 'a');
    if (res > 0) printf("FIRST\n");
    else if (res == 0) printf("DRAW\n");
    else printf("SECOND\n");
    return 0;
}