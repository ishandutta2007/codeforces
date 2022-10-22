#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {1, 0, -1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const string lets = "DLUR";

int n;
ii B[Maxn][Maxn];
char res[Maxn][Maxn];

void Fill(int r, int c, const ii &nd, char wr)
{
    if (B[r][c] != nd || res[r][c] != '?') return;
    res[r][c] = wr;
    for (int i = 0; i < Maxd; i++) {
        int nr = r + dy[i], nc = c + dx[i];
        Fill(nr, nc, nd, lets[(i + 2) % Maxd]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d %d", &B[i][j].first, &B[i][j].second);
            res[i][j] = '?';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (B[i][j].first == -1) {
                for (int d = 0; d < Maxd; d++) {
                    int ni = i + dy[d], nj = j + dx[d];
                    if (1 <= ni && ni <= n && 1 <= nj && nj <= n && B[ni][nj].first == -1) {
                        res[i][j] = lets[d];
                        break;
                    }
                }
            } else if (B[i][j] == ii(i, j))
                Fill(i, j, ii(i, j), 'X');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (res[i][j] == '?') {
                printf("INVALID\n");
                return 0;
            }
    printf("VALID\n");
    for (int i = 1; i <= n; i++) {
        res[i][n + 1] = '\0';
        printf("%s\n", res[i] + 1);
    }
    return 0;
}