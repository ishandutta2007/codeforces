#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int T;
int n, m;
char B[Maxn][Maxn];

void Fill(int r, int c)
{
    if (r < 1 || r > n || c < 1 || c > m || B[r][c] == '#') return;
    B[r][c] = '#';
    for (int i = 0; i < Maxd; i++)
        Fill(r + dy[i], c + dx[i]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", B[i] + 1);
        bool fall = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) if (B[i][j] == 'B')
                for (int d = 0; d < Maxd; d++) {
                    int ni = i + dy[d], nj = j + dx[d];
                    if (1 <= ni && ni <= n && 1 <= nj && nj <= m)
                        if (B[ni][nj] == 'G') fall = true;
                        else if (B[ni][nj] == 'B') ;
                        else B[ni][nj] = '#';
                }
        if (fall) { printf("No\n"); continue; }
        Fill(n, m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (B[i][j] == 'G') fall = true;
        printf("%s\n", !fall? "Yes": "No");
    }
    return 0;
}