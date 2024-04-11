#include <cstdio>
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {1, 0, -1, 0};
const int dx[Maxd] = {0, 1, 0, -1};

int n, m;
char B[Maxn][Maxn];
bool fail;
int id[Maxn][Maxn];
bool need[Maxn][Maxn];
int cnt, tmp;
int res;

void Go(int r, int c, int col)
{
    fail = fail || r == 0 || r == n - 1 || c == 0 || c == m - 1;
    B[r][c] = '2';
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++) if (dr || dc) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (B[nr][nc] == '0') Go(nr, nc, col);
            else if (B[nr][nc] == '1' && id[nr][nc] != col) {
                id[nr][nc] = col; need[nr][nc] = true; cnt++;
            }
        }
}

void Check(int r, int c)
{
    need[r][c] = false; tmp++;
    int cnt = 0;
    for (int i = 0; i < Maxd; i++) {
        int nr = r + dy[i], nc = c + dx[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (id[nr][nc] == id[r][c]) {
            cnt++;
            if (need[nr][nc]) Check(nr, nc);
        }
    }
    fail = fail || cnt != 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf(" %c", &B[i][j]);
    for (int i = 0; i + 2 <= n && !res; i++)
        for (int j = 0; j + 2 <= m && !res; j++)
            if (B[i][j] == '1' && B[i][j + 1] == '1' && B[i + 1][j] == '1' && B[i + 1][j + 1] == '1') res = 4;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (B[i][j] == '0') {
            fail = false; cnt = 0;
            Go(i, j, i * m + j);
            if (fail || cnt < res) continue;
            fail = false; tmp = 0;
            Check(i - 1, j - 1);
            if (!fail && tmp == cnt) res = cnt;
        }
    printf("%d\n", res);
    return 0;
}