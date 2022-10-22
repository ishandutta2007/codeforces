#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, k;
vector <int> neigh[Maxn];
int dist[Maxn];
int root = -1;

bool Check(int v, int p, int need)
{
    int deg = int(neigh[v].size()) - (p != 0);
    if (deg == 0 || need == 0)  return deg == 0 && need == 0;
    if (deg < 3) return false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (!Check(u, v, need - 1)) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    fill(dist, dist + Maxn, k + 1);
    vector <int> Q;
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 1) {
            dist[i] = 0; Q.push_back(i);
        }
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        if (dist[v] == k) { root = v; break; }
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push_back(u);
            }
        }
    }
    if (root == -1) { printf("No\n"); return 0; }
    if (Check(root, 0, k)) printf("Yes\n");
    else printf("No\n");
    return 0;
}