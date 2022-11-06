#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b;
vector<int> V[N];
bool vis[N];
int color[N];

bool DFS(int w) {
    vis[w] = true;

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            color[u] = 1 - color[w];
            if (DFS(u)) {
                return true;
            }
        } else {
            if (color[w] == color[u]) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false && DFS(i) == true) {
            printf("-1\n");
            return 0;
        }
    }

    int blackCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            blackCnt++;
        }
    }

    printf("%d\n", blackCnt);

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            printf("%d ", i);
        }
    }


    printf("\n%d\n", n - blackCnt);

    for (int i = 1; i <= n; i++) {
        if (color[i] != 0) {
            printf("%d ", i);
        }
    }

    return 0;
}