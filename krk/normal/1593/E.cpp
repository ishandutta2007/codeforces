#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Inf = 1000000000;

int T;
int n, k;
set <int> neigh[Maxn];
int dist[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            dist[i] = Inf;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        queue <int> Q;
        for (int i = 1; i <= n; i++) if (neigh[i].size() <= 1) {
            dist[i] = 1;
            Q.push(i);
        }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            if (neigh[v].size() == 1) {
                int u = *neigh[v].begin();
                neigh[v].erase(u);
                neigh[u].erase(v);
                if (neigh[u].size() == 1) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
        int res = n;
        for (int i = 1; i <= n; i++)
            res -= dist[i] <= k;
        printf("%d\n", res);
    }
    return 0;
}