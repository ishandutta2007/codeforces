#include <cstdio>
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 0, 1};
const int dx[Maxd] = {0, -1, 1, 0};

int n, m;
char B[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n + 1; i++) B[i][0] = B[i][m + 1] = '#';
    for (int j = 0; j <= m + 1; j++) B[0][j] = B[n + 1][j] = '#';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf(" %c", &B[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j + 1 <= m; j++)
            if (B[i][j] == '.' && B[i][j + 1] == '.') {
                        char col;
                        if ((i + j) % 2) col = i % 3 * 3 + j % 3 + '0';
                        else col = i % 3 * 3 + (j + 1) % 3 + '0';
                        B[i][j] = B[i][j + 1] = col;
            }
    for (int j = 1; j <= m; j++)
        for (int i = 1; i + 1 <= n; i++)
            if (B[i][j] == '.' && B[i + 1][j] == '.') {
                        char col;
                        if ((i + j) % 2) col = i % 3 * 3 + j % 3 + '0';
                        else col = (i + 1) % 3 * 3 + j % 3 + '0';
                        B[i][j] = B[i + 1][j] = col;
            }
    bool isres = true;
    for (int i = 1; i <= n && isres; i++)
        for (int j = 1; j <= m && isres; j++)
            if (B[i][j] == '.') {
               int l;
               for (l = 0; l < Maxd; l++)
                   if (B[i + dy[l]][j + dx[l]] != '#') { B[i][j] = B[i + dy[l]][j + dx[l]]; break; }
               isres = l < Maxd;
            }
    if (isres)
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) printf("%c", B[i][j]);
           printf("\n");
       }
    else printf("-1\n");
    return 0;
}