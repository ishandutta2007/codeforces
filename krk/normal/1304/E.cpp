#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;
const int Inf = 1000000006;
const int Maxa = 4;
const int Maxb = 2;

int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int dist[Maxa][Maxb][Maxa][Maxb];

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        P[u][0] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
}

int getLCA(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int getDist(int a, int b) { return L[a] + L[b] - 2 * L[getLCA(a, b)]; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    int q; scanf("%d", &q);
    while (q--) {
        int v[Maxa];
        int k;
        for (int i = 0; i < Maxa; i++)
            scanf("%d", &v[i]);
        scanf("%d", &k);
        fill((int*)dist, (int*)dist + Maxa * Maxb * Maxa * Maxb, Inf);
        for (int i = 0; i < Maxa; i++)
            for (int i2 = 0; i2 < Maxb; i2++)
                dist[i][i2][i][i2] = 0;
        for (int i = 0; i < Maxa; i++)
            for (int j = i + 1; j < Maxa; j++) {
                int d = getDist(v[i], v[j]);
                for (int i2 = 0; i2 < Maxb; i2++) {
                    int j2 = (i2 ^ (d % 2));
                    dist[i][i2][j][j2] = min(dist[i][i2][j][j2], d);
                    dist[j][j2][i][i2] = dist[i][i2][j][j2];
                }
            }
        dist[0][0][1][1] = min(dist[0][0][1][1], 1);
        dist[1][1][0][0] = dist[0][0][1][1];
        dist[0][1][1][0] = min(dist[0][1][1][0], 1);
        dist[1][0][0][1] = dist[0][1][1][0];
        for (int z = 0; z < Maxa; z++)
            for (int z2 = 0; z2 < Maxb; z2++)
                for (int i = 0; i < Maxa; i++)
                    for (int i2 = 0; i2 < Maxb; i2++)
                        for (int j = 0; j < Maxa; j++)
                            for (int j2 = 0; j2 < Maxb; j2++)
                                dist[i][i2][j][j2] = min(dist[i][i2][j][j2], dist[i][i2][z][z2] + dist[z][z2][j][j2]);
        printf("%s\n", dist[2][0][3][k % 2] <= k? "YES": "NO");
    }
    return 0;
}