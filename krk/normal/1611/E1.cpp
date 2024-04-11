#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n, k;
int dist[Maxn];
vector <int> neigh[Maxn];
int L[Maxn];

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        L[u] = L[v] + 1;
        Traverse(u, v);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            dist[i] = Inf;
        }
        queue <int> Q;
        for (int i = 0; i < k; i++) {
            int x; scanf("%d", &x);
            dist[x] = 0;
            Q.push(x);
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Traverse(1, 0);
        bool win = false;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            if (v != 1 && neigh[v].size() == 1 && L[v] < dist[v]) win = true;
            for (int i = 0; i < neigh[v].size(); i++) {
                int u = neigh[v][i];
                if (dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
        printf("%s\n", win? "YES": "NO");
    }
    return 0;
}