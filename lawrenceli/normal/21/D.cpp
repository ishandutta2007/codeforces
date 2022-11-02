#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 16;

int n, m, dist[MAXN][MAXN], ans, deg[MAXN], memo[1<<MAXN];
bool vis[MAXN], in[1<<MAXN];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    for (int i=0; i<n; i++) {
        if (dist[cur][i] < 1e9) dfs(i);
    }
}

int calc(int cur) {
    if (memo[cur] >= 0) return memo[cur];
    if (in[cur]) return 1e9;
    in[cur] = 1;
    int ret = 1e9;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (dist[i][j] == 1e9) continue;
            int tmp = calc(cur ^ (1<<i) ^ (1<<j));
            if (tmp == 1e9) continue;
            ret = min(ret, tmp + dist[i][j]);
        }
    }
    in[cur] = 0;
    return memo[cur] = ret;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            dist[i][j] = 1e9;
    for (int i=0; i<m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        x--; y--;
        ans += w;
        dist[x][y] = min(dist[x][y], w);
        dist[y][x] = min(dist[y][x], w);
        deg[x]++; deg[y]++;
    }
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    dfs(0);
    for (int i=0; i<n; i++) {
        if (!vis[i] && deg[i] > 0) { //can't visit
            printf("-1\n");
            return 0;
        }
    }
    int cur = 0;
    for (int i=0; i<n; i++) cur += (1<<i) * (deg[i] & 1);
    for (int i=1; i<(1<<n); i++) memo[i] = -1;
    printf("%d\n", calc(cur) + ans);
}