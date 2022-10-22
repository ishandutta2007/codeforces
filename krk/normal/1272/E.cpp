#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int dist0[Maxn], dist1[Maxn];

void Solve(int par, int dist[])
{
    queue <int> Q;
    for (int i = 1; i <= n; i++)
        if (a[i] % 2 == par) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = Inf;
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i - a[i] >= 1) neigh[i - a[i]].push_back(i);
        if (i + a[i] <= n) neigh[i + a[i]].push_back(i);
    }
    Solve(0, dist0);
    Solve(1, dist1);
    for (int i = 1; i <= n; i++) {
        int res = a[i] % 2? dist0[i]: dist1[i];
        printf("%d%c", res >= Inf? -1: res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}