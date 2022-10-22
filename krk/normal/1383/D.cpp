#include <bits/stdc++.h>
using namespace std;

const int Maxn = 252;
const int Maxm = Maxn * Maxn;

int n, m;
int A[Maxn][Maxn];
int mxR[Maxn], mxC[Maxn];
bool row[Maxm], col[Maxm];
int tp[Maxn], bot[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
            mxR[i] = max(mxR[i], A[i][j]);
            mxC[j] = max(mxC[j], A[i][j]);
        }
    for (int i = 0; i < n; i++)
        row[mxR[i]] = true;
    for (int j = 0; j < m; j++)
        col[mxC[j]] = true;
    int r = n, c = m;
    for (int i = n * m; i > 0; i--)
        if (row[i] && col[i]) {
            r--; c--;
            tp[c] = bot[c] = r;
            A[r][c] = i;
        } else if (row[i]) {
            r--;
            A[r][c] = i;
            tp[c] = r;
        } else if (col[i]) {
            c--;
            A[r][c] = i;
            tp[c] = bot[c] = r;
        } else {
            bool done = false;
            for (int j = c; j < m && !done; j++)
                if (tp[j] > r) {
                    tp[j]--;
                    A[tp[j]][j] = i;
                    done = true;
                }
            for (int j = m - 1; j >= c && !done; j--)
                if (bot[j] + 1 < n) {
                    bot[j]++;
                    A[bot[j]][j] = i;
                    done = true;
                }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%c", A[i][j], j + 1 < m? ' ': '\n');
    return 0;
}