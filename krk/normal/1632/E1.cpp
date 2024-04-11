#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 3005;

int T;
int n;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn];
int cur1[Maxn], cur2[Maxn];
int res[Maxn];

void Traverse(int v, int p, int dist[], int cur)
{
    dist[v] = cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, dist, cur + 1);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
            Traverse(i, 0, dist[i], 0);
        fill(res, res + n + 1, Inf);
        for (int i = 1; i <= n; i++) {
            fill(cur1, cur1 + n + 1, -Inf);
            fill(cur2, cur2 + n + 1, -Inf);
            for (int v = 1; v <= n; v++) {
                int d = dist[1][v], add = dist[i][v];
                int x = max(0, d - add);
                cur1[x] = max(cur1[x], d);
                if (d - add >= 0)
                    cur2[x] = max(cur2[x], d - x);
            }
            for (int z = 1; z <= n; z++)
                cur1[z] = max(cur1[z], cur1[z - 1]);
            for (int z = n - 1; z >= 1; z--)
                cur2[z] = max(cur2[z], cur2[z + 1]);
            for (int z = 1; z <= n; z++)
                res[z] = min(res[z], max(cur1[z], cur2[z] + z));
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}