#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 55;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

char B[Maxn][Maxn];
char got[Maxm];
int cur, id[Maxn][Maxn];
int n, m;
set <int> neigh[Maxm];
int dist[Maxm];
int res = Inf;

void Fill(int r, int c, char col, int cur)
{
    if (r < 1 || c < 1 || r > n || c > m || B[r][c] != col) return;
    B[r][c] = '?'; id[r][c] = cur;
    for (int i = 0; i < Maxd; i++)
        Fill(r + dy[i], c + dx[i], col, cur);
}

int Get(int v)
{
    fill(dist, dist + Maxm, Inf); dist[v] = 0;
    int res = 0;
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        res = dist[v];
        for (auto u: neigh[v])
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
    }
    return res;
}

int main()
{
    fill((char*)B, (char*)B + Maxn * Maxn, 'W');
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf(" %c", &B[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (B[i][j] != '?') {
            cur++; got[cur] = B[i][j];
            Fill(i, j, B[i][j], cur);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i < n && id[i][j] != id[i + 1][j]) {
                neigh[id[i][j]].insert(id[i + 1][j]);
                neigh[id[i + 1][j]].insert(id[i][j]);
            }
            if (j < m && id[i][j] != id[i][j + 1]) {
                neigh[id[i][j]].insert(id[i][j + 1]);
                neigh[id[i][j + 1]].insert(id[i][j]);
            }
        }
    for (int i = 1; i <= cur; i++) {
        int ans = Get(i);
        if ((ans % 2) ^ (got[i] == 'B')) ans++;
        res = min(res, ans);
    }
    printf("%d\n", res);
    return 0;
}