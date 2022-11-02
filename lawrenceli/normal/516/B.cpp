#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m, deg[MAXN][MAXN];
char mat[MAXN][MAXN];

int calc(int r, int c) {
    int ret = 0;
    for (int dr=-1; dr<=1; dr++)
        for (int dc=-1; dc<=1; dc++)
            if ((dr==0) != (dc==0))
                ret += mat[r+dr][c+dc] == '.';
    return ret;
}

char op(char c) {
    if (c == '<') return '>';
    if (c == '>') return '<';
    if (c == '^') return 'v';
    if (c == 'v') return '^';
    assert(0);
}

void dfs(int, int);

void upd(int r, int c) {
    for (int dr=-1; dr<=1; dr++)
        for (int dc=-1; dc<=1; dc++)
            if ((dr==0) != (dc==0)) {
                int nr = r+dr, nc = c+dc;
                if (mat[nr][nc] == '.') {
                    deg[nr][nc]--;
                    if (deg[nr][nc] == 1) dfs(nr, nc);
                }
            }
}

void dfs(int r, int c) {
    for (int dr=-1; dr<=1; dr++)
        for (int dc=-1; dc<=1; dc++)
            if ((dr==0) != (dc==0)) {
                int nr = r+dr, nc = c+dc;
                if (mat[nr][nc] == '.') {
                    if (dr == 0) {
                        if (dc == 1) mat[r][c] = '<';
                        else mat[r][c] = '>';
                    } else {
                        if (dr == 1) mat[r][c] = '^';
                        else mat[r][c] = 'v';
                    }
                    mat[nr][nc] = op(mat[r][c]);
                    upd(r, c);
                    upd(nr, nc);
                    return;
                }
            }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> (mat[i]+1);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (mat[i][j] == '.')
                deg[i][j] = calc(i, j);

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (deg[i][j] == 1)
                dfs(i, j);

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (mat[i][j] == '.') {
                cout << "Not unique";
                return 0;
            }
    for (int i=1; i<=n; i++) cout << (mat[i]+1) << '\n';
}