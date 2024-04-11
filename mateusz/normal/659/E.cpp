#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b, edges, nodes;
vector<int> V[N];
bool vis[N];

void DFS(int w) {
    nodes++;
    edges += V[w].size();
    vis[w] = true;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            edges = nodes = 0;
            DFS(i);
            edges /= 2;
            if (edges == nodes - 1) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}