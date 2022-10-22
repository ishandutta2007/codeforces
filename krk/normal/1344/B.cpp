#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int rows, cols;
int res;

void Visit(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] != '#') return;
    B[r][c] = '.';
    for (int i = 0; i < Maxd; i++)
        Visit(r + dy[i], c + dx[i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", B[i]);
        int fir = -1, lst = -1;
        int black = 0;
        for (int j = 0; j < m; j++)
            if (B[i][j] == '#') {
                if (fir == -1) fir = j;
                lst = j;
                black++;
            }
        if (!black) rows++;
        else if (lst - fir + 1 != black) { printf("-1\n"); return 0; }
    }
    for (int j = 0; j < m; j++) {
        int fir = -1, lst = -1;
        int black = 0;
        for (int i = 0; i < n; i++)
            if (B[i][j] == '#') {
                if (fir == -1) fir = i;
                lst = i;
                black++;
            }
        if (!black) cols++;
        else if (lst - fir + 1 != black) { printf("-1\n"); return 0; }
    }
    if (rows == n && cols == m) { printf("0\n"); return 0; }
    if (rows == 0 && cols > 0 || cols == 0 && rows > 0) { printf("-1\n"); return 0; }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (B[i][j] == '#') {
            res++;
            Visit(i, j);
        }
    printf("%d\n", res);
    return 0;
}