#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 200005;

int n, m;
int in[Maxn];
int dist[Maxn];
vector <int> neigh[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[b].push_back(a);
        in[a]++;
    }
    fill(dist, dist + n + 1, Inf); dist[n] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[n], n));
    while (!Q.empty()) {
        int v = Q.top().second;
        int d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            in[u]--;
            if (d + 1 + in[u] < dist[u]) {
                dist[u] = d + 1 + in[u];
                Q.push(ii(-dist[u], u));
            }
        }
    }
    printf("%d\n", dist[1]);
    return 0;
}