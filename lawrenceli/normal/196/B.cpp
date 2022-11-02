#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1505;

int n, m;
char mat[maxn][maxn];

bool vis[maxn][maxn];
int vx[maxn][maxn], vy[maxn][maxn];

void dfs(int r, int c, int a, int b) {
    if (vis[r][c]) {
        if (!(vx[r][c] == a && vy[r][c] == b)) {
            cout << "Yes\n";
            exit(0);
        }
        return;
    }

    vis[r][c] = 1;
    vx[r][c] = a, vy[r][c] = b;

    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if ((dr == 0) ^ (dc == 0)) {
                int nr = r + dr, nc = c + dc, na = a, nb = b;
                if (nr == -1) nr += n, na--;
                else if (nr == n) nr -= n, na++;

                if (nc == -1) nc += m, nb--;
                else if (nc == m) nc -= m, nb++;

                if (mat[nr][nc] != '#')
                    dfs(nr, nc, na, nb);
            }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'S') {
                dfs(i, j, 0, 0);
            }

    cout << "No\n";
}