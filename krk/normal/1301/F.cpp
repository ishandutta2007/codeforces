#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxk = 45;
const int MaxN = Maxn * Maxn + Maxk;
const int Inf = 1000000000;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int Maxq = 100005;
const int nil = MaxN + 5;

int n, m, k;
int mult;
int N;
int M[Maxn][Maxn], id[Maxn][Maxn];
vector <int> my[Maxk];
int st, en, Q[2 * MaxN + 15];
int dist[MaxN], rdist[MaxN];
bool tk[MaxN];
int q;
int r1[Maxq], c1[Maxq], r2[Maxq], c2[Maxq];
int res[Maxq];

void Solve(int v, int dist[], int A, int B)
{
    st = en = nil;
    fill(dist, dist + N, Inf);
    fill(tk, tk + N, false);
    dist[v] = 0;
    Q[en++] = v;
    while (st < en) {
        v = Q[st++];
        if (tk[v]) continue;
        tk[v] = true;
        if (v >= mult) {
            int c = v - mult;
            for (int i = 0; i < my[c].size(); i++) {
                int p = my[c][i];
                if (B == 0 && dist[v] < dist[p]) {
                    dist[p] = dist[v];
                    Q[--st] = p;
                } else if (B == 1 && dist[v] + 1 < dist[p]) {
                    dist[p] = dist[v] + 1;
                    Q[en++] = p;
                }
            }
        } else {
            int r = v / m, c = v % m;
            for (int d = 0; d < Maxd; d++) {
                int nr = r + dy[d], nc = c + dx[d];
                if (0 <= nr && nr < n && 0 <= nc && nc < m &&
                    dist[v] + 1 < dist[id[nr][nc]]) {
                    dist[id[nr][nc]] = dist[v] + 1;
                    Q[en++] = id[nr][nc];
                }
            }
            int u = mult + M[r][c];
            if (A == 0 && dist[v] < dist[u]) {
                dist[u] = dist[v];
                Q[--st] = u;
            } else if (A == 1 && dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q[en++] = u;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    mult = n * m;
    N = mult + k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &M[i][j]); M[i][j]--;
            id[i][j] = i * m + j;
            my[M[i][j]].push_back(id[i][j]);
        }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &r1[i], &c1[i], &r2[i], &c2[i]);
        r1[i]--; c1[i]--; r2[i]--; c2[i]--;
        res[i] = abs(r1[i] - r2[i]) + abs(c1[i] - c2[i]);
    }
    for (int c = 0; c < k; c++) {
        Solve(mult + c, dist, 0, 1);
        Solve(mult + c, rdist, 1, 0);
        for (int i = 0; i < q; i++)
            res[i] = min(res[i], rdist[id[r1[i]][c1[i]]] + dist[id[r2[i]][c2[i]]]);
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}