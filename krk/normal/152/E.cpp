#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxk = 7;
const int Maxv = 205;
const int Inf = 1000000000;

int n, m, k;
int cost[Maxn][Maxn];
int dist[Maxv][Maxv], p[Maxv][Maxv];
int best[1 << Maxk][Maxv], pa[1 << Maxk][Maxv], pb[1 << Maxk][Maxv];
bool g[Maxn][Maxn];

bool Adj(int a, int b)
{
    return abs(a / m - b / m) + abs(a % m - b % m) == 1;
}

void printPath(int i, int j)
{
    g[i / m][i % m] = g[j / m][j % m] = true;
    if (p[i][j] == -1) return;
    printPath(i, p[i][j]); printPath(p[i][j], j);
}

void Print(int i, int j)
{
    g[j / m][j % m] = true;
    if (pa[i][j] == -1) return;
    if (pa[i][j] != i) { Print(pa[i][j], j); Print(i ^ pa[i][j], j); }
    else { printPath(j, pb[i][j]); Print(i, pb[i][j]); }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &cost[i][j]);
    fill((int*)best, (int*)best + (1 << Maxk) * Maxv, Inf);
    for (int i = 0; i < k; i++) {
        int x, y; scanf("%d %d", &x, &y);
        best[1 << i][m * (x - 1) + y - 1] = cost[x - 1][y - 1];
        pa[1 << i][m * (x - 1) + y - 1] = -1;
    }
    for (int i = 0; i < n * m; i++)
        for (int j = 0; j < n * m; j++)
            if (i == j) { dist[i][j] = cost[i / m][i % m]; p[i][j] = -1; }
            else if (Adj(i, j)) { dist[i][j] = cost[i / m][i % m] + cost[j / m][j % m]; p[i][j] = -1; }
            else dist[i][j] = Inf;
    for (int k = 0; k < n * m; k++)
        for (int i = 0; i < n * m; i++)
            for (int j = 0; j < n * m; j++) {
                int cand = dist[i][k] + dist[k][j] - cost[k / m][k % m];
                if (cand < dist[i][j]) {
                    dist[i][j] = cand; p[i][j] = k;
                }
            }
    for (int i = 1; i < 1 << k; i++) {
        for (int j = 0; j < n * m; j++)
            for (int l = 1; l < i; l++) if ((i | l) == i) {
                int cand = best[l][j] + best[i ^ l][j] - cost[j / m][j % m];
                if (cand < best[i][j]) {
                    best[i][j] = cand; pa[i][j] = l;
                }
            }
        for (int j = 0; j < n * m; j++)
            for (int l = 0; l < n * m; l++) {
                int cand = best[i][l] + dist[l][j] - cost[l / m][l % m];
                if (cand < best[i][j]) {
                    best[i][j] = cand; pa[i][j] = i; pb[i][j] = l;
                }
            }
    }
    int i = (1 << k) - 1, j = 0;
    for (int l = 0; l < n * m; l++) if (best[i][l] < best[i][j]) { j = l; }
    printf("%d\n", best[i][j]);
    Print(i, j);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", g[i][j]? 'X': '.');
        printf("\n");
    }
    return 0;
}