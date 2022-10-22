#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n, m;
vector <int> neigh[Maxn];
int dist[Maxn], acc[2];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            dist[i] = n + 1;
        }
        acc[0] = acc[1] = 0;
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        queue <int> Q;
        dist[1] = 0; Q.push(1);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            acc[dist[v] % 2]++;
            for (int i = 0; i < neigh[v].size(); i++) {
                int u = neigh[v][i];
                if (dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
        int f = acc[0] < acc[1]? 0: 1;
        vector <int> res;
        for (int i = 1; i <= n; i++) if (dist[i] % 2 == f)
            res.push_back(i);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}