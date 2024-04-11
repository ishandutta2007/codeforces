#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXM = 15;
const int BLOCK = 500;

int n, m, q;
char mat[MAXN][MAXM];
pii nxt[MAXN][MAXM], jump[MAXN][MAXM];

bool in(pii p) {
    if (p.fi <= 0) return 0;
    if (p.se <= 0 || p.se > m) return 0;
    return 1;
}

pii calc(int r, int c) {
    if (!in(pii(r, c))) return pii(r, c);
    if (nxt[r][c].fi != -2) return nxt[r][c];
    if (mat[r][c] == '<') {
        if (mat[r][c-1] == '>') return nxt[r][c] = pii(-1, -1);
        else return nxt[r][c] = calc(r, c-1);
    } else if (mat[r][c] == '>') {
        if (mat[r][c+1] == '<') return nxt[r][c] = pii(-1, -1);
        else return nxt[r][c] = calc(r, c+1);
    } else return nxt[r][c] = pii(r-1, c);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d %d\n", &n, &m, &q);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            scanf("%c", &mat[i][j]);
        scanf("\n");
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) nxt[i][j] = pii(-2, -2);
        for (int j=1; j<=m; j++) calc(i, j);
    }

    for (int i=1; i<=n; i++)
        if (i%BLOCK == 1) {
            for (int j=1; j<=m; j++)
                jump[i][j] = nxt[i][j];
        } else {
            for (int j=1; j<=m; j++) {
                if (!in(nxt[i][j])) jump[i][j] = nxt[i][j];
                else jump[i][j] = jump[nxt[i][j].fi][nxt[i][j].se];
            }
        }

    for (int ii=0; ii<q; ii++) {
        char type; scanf("%c ", &type);
        if (type == 'C') {
            int x, y; char c;
            scanf("%d %d %c\n", &x, &y, &c);
            mat[x][y] = c;
            for (int j=1; j<=m; j++) nxt[x][j] = pii(-2, -2);
            for (int j=1; j<=m; j++) calc(x, j);

            if (x%BLOCK == 1) {
                for (int j=1; j<=m; j++)
                    jump[x][j] = nxt[x][j];
            } else {
                for (int j=1; j<=m; j++) {
                    if (!in(nxt[x][j])) jump[x][j] = nxt[x][j];
                    else jump[x][j] = jump[nxt[x][j].fi][nxt[x][j].se];
                }
            }

            for (int i=x+1; i<=n && i%BLOCK != 1; i++)
                for (int j=1; j<=m; j++) {
                    if (!in(nxt[i][j])) jump[i][j] = nxt[i][j];
                    else jump[i][j] = jump[nxt[i][j].fi][nxt[i][j].se];
                }
        } else {
            int x, y;
            scanf("%d %d\n", &x, &y);
            pii p = pii(x, y);
            while (in(p)) p = jump[p.fi][p.se];
            printf("%d %d\n", p.fi, p.se);
        }
    }
    return 0;
}