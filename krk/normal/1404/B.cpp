#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, a, b, da, db;
vector <int> neigh[Maxn];
int dist[Maxn];
ii mx;

void Traverse(int v, int p, int d)
{
    dist[v] = d;
    mx = max(mx, ii(dist[v], v));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, d + 1);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v; scanf("%d %d", &u, &v);
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        mx = ii(-1, -1);
        Traverse(a, 0, 0);
        if (dist[b] <= da || 2 * da >= db) printf("Alice\n");
        else {
            int r = mx.second;
            mx = ii(-1, -1);
            Traverse(r, 0, 0);
            if (2 * da >= mx.first) printf("Alice\n");
            else printf("Bob\n");
        }
    }
    return 0;
}