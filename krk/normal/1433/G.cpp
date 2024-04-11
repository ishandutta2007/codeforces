#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 1005;

int n, m, k;
int A[Maxn], B[Maxn], C[Maxn];
vector <ii> neigh[Maxn];
int dist[Maxn][Maxn];
int qa[Maxn], qb[Maxn];
int res = Inf;

void Dijkstra(int v, int dist[])
{
    fill(dist, dist + n + 1, Inf); dist[v] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[v], v));
    while (!Q.empty()) {
        int d = -Q.top().first;
        int v = Q.top().second; Q.pop();
        if (dist[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            ii u = neigh[v][i];
            if (d + u.second < dist[u.first]) {
                dist[u.first] = d + u.second;
                Q.push(ii(-dist[u.first], u.first));
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        neigh[A[i]].push_back(ii(B[i], C[i]));
        neigh[B[i]].push_back(ii(A[i], C[i]));
    }
    for (int i = 1; i <= n; i++)
        Dijkstra(i, dist[i]);
    for (int i = 0; i < k; i++)
        scanf("%d %d", &qa[i], &qb[i]);
    for (int i = 0; i < m; i++) {
        int cand = 0;
        for (int j = 0; j < k; j++) {
            int my = min(dist[qa[j]][qb[j]], min(dist[qa[j]][A[i]] + dist[B[i]][qb[j]],
                                                 dist[qa[j]][B[i]] + dist[A[i]][qb[j]]));
            cand += my;
        }
        res = min(res, cand);
    }
    printf("%d\n", res);
    return 0;
}