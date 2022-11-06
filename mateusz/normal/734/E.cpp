#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a, b;
int color[N], dist[N];
bool vis[N];
vector<int> V[N];
queue<int> Q;

void BFS(int v) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 0;
        vis[i] = false;
    }
    vis[v] = true;
    Q.push(v);
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i];
            if (!vis[u]) {
                Q.push(u);
                vis[u] = true;
                dist[u] = dist[w] + (color[w] != color[u]);
            }
        }
    }
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    BFS(1);
    int furthest = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[furthest]) {
            furthest = i;
        }
    }

    BFS(furthest);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dist[i]);
    }

    printf("%d\n", (mx + 1) / 2);

    return 0;
}