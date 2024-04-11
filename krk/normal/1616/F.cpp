#include <bits/stdc++.h>
using namespace std;

const int Maxn = 260;
const int Maxm = 17000;

int T;
int n, m;
int has[Maxn][Maxn];
int C[Maxm];
int B[Maxm][Maxn];
int blen;
int myrow[Maxn];
int res[Maxn];

void Add(int ind)
{
    if (C[ind] == -1) B[blen][ind] = 1;
    else B[blen][m + 1] = (B[blen][m + 1] - (C[ind] - 1) + 3) % 3;
}

void Swap(int r1, int r2, int c)
{
    for (int j = c; j <= m + 1; j++)
        swap(B[r1][j], B[r2][j]);
}

void Sub(int r1, int r2, int c)
{
    int mult = B[r1][c] == B[r2][c]? 1: 2;
    for (int j = c; j <= m + 1; j++)
        B[r2][j] = (B[r2][j] - mult * B[r1][j] % 3 + 3) % 3;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill((int*)has, (int*)has + Maxn * Maxn, 0);
        for (int i = 1; i <= m; i++) {
            int a, b; scanf("%d %d %d", &a, &b, &C[i]);
            has[a][b] = has[b][a] = i;
        }
        blen = 0;
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= n; b++) if (has[a][b])
                for (int c = 1; c <= n; c++) if (has[a][b] < has[b][c] && has[b][c] < has[c][a]) {
                    fill(B[blen], B[blen] + m + 2, 0);
                    Add(has[a][b]);
                    Add(has[b][c]);
                    Add(has[c][a]);
                    blen++;
                }
        int r = 0, c = 0;
        while (r < blen && c <= m) {
            int i = r;
            while (i < blen && B[i][c] == 0) i++;
            if (i >= blen) { myrow[c] = -1; c++; continue; }
            if (i != r) Swap(r, i, c);
            for (i++; i < blen; i++)
                if (B[i][c] != 0) Sub(r, i, c);
            myrow[c] = r;
            r++; c++;
        }
        while (c <= m) myrow[c++] = -1;
        bool fall = false;
        for (int i = r; i < blen && !fall; i++)
            fall = B[i][m + 1] != 0;
        if (fall) { printf("-1\n"); continue; }
        for (int i = m; i >= 1; i--)
            if (myrow[i] == -1) res[i] = C[i] == -1? 0: C[i] - 1;
            else {
                int ind = myrow[i];
                res[i] = B[ind][m + 1];
                for (int j = i + 1; j <= m; j++)
                    res[i] = (res[i] - B[ind][j] * res[j] % 3 + 3) % 3;
                res[i] = res[i] * B[ind][i] % 3;
            }
        for (int i = 1; i <= m; i++)
            printf("%d%c", res[i] + 1, i + 1 <= m? ' ': '\n');
    }
    return 0;
}