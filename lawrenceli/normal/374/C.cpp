#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;

int n, m, ans;
char mat[MAXN][MAXN], name[5] = "DIMA";
int vis[MAXN][MAXN], dp[MAXN][MAXN];

void dfs(int r, int c, int cur) {
    if (vis[r][c] == 1) {
        printf("Poor Inna!\n");
        exit(0);
    } else if (vis[r][c] == 2) return;
    vis[r][c] = 1; dp[r][c] = 0;
    for (int dr=-1; dr<=1; dr++) {
        for (int dc=-1; dc<=1; dc++) {
            if (!(dr==0 ^ dc==0)) continue;
            int nr = r+dr, nc = c+dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (mat[nr][nc] != name[(cur+1)%4]) continue;
            dfs(nr, nc, (cur+1)%4);
            dp[r][c] = max(dp[r][c], dp[nr][nc]);
        }
    }
    if (mat[r][c] == name[3]) dp[r][c]++;
    vis[r][c] = 2;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    memset(dp, -1, sizeof(dp));
    scanf("%d %d\n", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("\n");
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == name[0] && !vis[i][j]) dfs(i, j, 0);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == name[0]) ans = max(ans, dp[i][j]);
        }
    }
    if (ans == 0) printf("Poor Dima!\n");
    else printf("%d\n", ans);
    return 0;
}