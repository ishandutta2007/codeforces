#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int a[N];
vector<int> V[N];
int dist[N];
bool vis[N];
queue<int> Q;
void BFS(int w) {
    vis[w] = true;
    Q.push(w);
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop();
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i];
            if (!vis[u]) {
                vis[u] = true;
                dist[u] = dist[w] + 1;
                Q.push(u);
            }
        }
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        V[i].push_back(a[i]);
        V[i].push_back(i + 1);
        V[i].push_back(i - 1);
    }

    BFS(1);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}