#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;
const int sInf = 1000000000;

int T;
int n, m, a, b, c;
vector <int> neigh[Maxn];
int distA[Maxn], distB[Maxn], distC[Maxn];
int P[Maxn];
ll sum[Maxn];

void getDist(int v, int dist[])
{
    fill(dist, dist + n + 1, sInf);
    dist[v] = 0;
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++)
            scanf("%d", &P[i]);
        sort(P, P + m);
        for (int i = 1; i <= m; i++)
            sum[i] = sum[i - 1] + P[i - 1];
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        getDist(a, distA);
        getDist(b, distB);
        getDist(c, distC);
        ll res = Inf;
        for (int D = 1; D <= n; D++) if (distA[D] + distB[D] + distC[D] <= m)
            res = min(res, sum[distB[D]] + sum[distA[D] + distB[D] + distC[D]]);
        printf("%I64d\n", res);
    }
    return 0;
}