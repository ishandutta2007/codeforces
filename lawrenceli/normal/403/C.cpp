#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int n, mat[MAXN][MAXN], st;
bool vis[MAXN];

void dfs(int cur) {
    vis[cur] = 1;
    for (int i=0; i<n; i++)
        if (mat[cur][i] && !vis[i])
            dfs(i);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
            if (i == j && mat[i][j]) st = i;
        }

    dfs(st);
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            printf("NO\n");
            return 0;
        }
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            swap(mat[i][j], mat[j][i]);

    memset(vis, 0, sizeof(vis));
    dfs(st);
    for (int i=0; i<n; i++)
        if (!vis[i]) {
            printf("NO\n");
            return 0;
        }

    printf("YES\n");
    return 0;
}