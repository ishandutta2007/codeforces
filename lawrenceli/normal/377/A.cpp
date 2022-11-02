#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 505;

int n, m, k;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (mat[r][c] != '.') return;
    if (vis[r][c]) return;
    vis[r][c] = 1;
    for (int dr=-1; dr<=1; dr++) {
        for (int dc=-1; dc<=1; dc++) {
            if (!(dr == 0 ^ dc == 0)) continue;
            dfs(r + dr, c + dc);
        }
    }

    if (k > 0) {
        mat[r][c] = 'X';
        k--;
    }
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> mat[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (mat[i][j] == '.') {
                dfs(i, j);
                i = n; break;
            }
        }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << mat[i][j];
        cout << endl;
    }

    return 0;
}