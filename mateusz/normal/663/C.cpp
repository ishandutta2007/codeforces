#include <bits/stdc++.h>

using namespace std;

const int N = 200005, INF = 1e9;

int n, m;
int a[N], b[N];
vector<int> used, visited;
int col[N];
bool vis[N];
vector<int> V[N];

void DFS(int w) {
    visited.push_back(w);
    vis[w] = true;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u);
        }
    }
}

int calcCost(int color) {
    used.clear();
    for (int i = 0; i < 2 * n; i++) {
        vis[i] = false;
        V[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        if (col[i] == color) {
            V[2 * a[i]].push_back(2 * b[i]);
            V[2 * b[i]].push_back(2 * a[i]);

            V[2 * a[i] + 1].push_back(2 * b[i] + 1);
            V[2 * b[i] + 1].push_back(2 * a[i] + 1);
        } else {
            V[2 * a[i]].push_back(2 * b[i] + 1);
            V[2 * b[i] + 1].push_back(2 * a[i]);

            V[2 * a[i] + 1].push_back(2 * b[i]);
            V[2 * b[i]].push_back(2 * a[i] + 1);
        }
    }

    for (int i = 0; i < 2 * n; i += 2) {
        if (vis[i] == false && vis[i ^ 1] == false) {
            visited.clear();
            DFS(i);
            vector<int> u1, u2;
            for (int i = 0; i < visited.size(); i++) {
                if (vis[visited[i] ^ 1]) {
                    return INF;
                }
                if (visited[i] % 2 == 0) {
                    u1.push_back(visited[i] / 2);
                } else {
                    u2.push_back(visited[i] / 2);
                }
            }
            if (u1.size() < u2.size()) {
                for (int i = 0; i < u1.size(); i++) {
                    used.push_back(u1[i]);
                }
            } else {
                for (int i = 0; i < u2.size(); i++) {
                    used.push_back(u2[i]);
                }
            }
        }
    }
    return used.size();
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        char c;
        scanf("%d %d %c", &a[i], &b[i], &c);
        a[i]--, b[i]--;
        col[i] = (c == 'B' ? 0 : 1);
    }

    int ans = min(calcCost(0), calcCost(1));
    if (ans == INF) {
        printf("-1\n");
    } else {
        if (calcCost(0) == ans) {}
        else calcCost(1);

        printf("%d\n", used.size());
        for (int i = 0; i < used.size(); i++) {
            printf("%d ", used[i] + 1);
        }
    }

    return 0;
}