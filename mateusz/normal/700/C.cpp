#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, INF = 2e9 + 5;

int n, m, q;
int from[N], to[N], intimer[N], outtimer[N], low[N];
bool vis[N];
bool treeEdge[N], treeEdge2[N];
vector<pair<int, int> > V[N];
int timer, s, t;
int cost[N];
int par[N];

void DFS2(int w) {
    vis[w] = true;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        if (!vis[u]) {
            treeEdge[V[w][i].second] = true;
            DFS2(u);
        }
    }
}

void DFS(int w) {
    intimer[w] = ++timer;
    vis[w] = true;
    low[w] = intimer[w];
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        if (!vis[u]) {
            treeEdge2[V[w][i].second] = true;
            par[u] = V[w][i].second;
            DFS(u);
            low[w] = min(low[w], low[u]);
        } else if (par[w] != V[w][i].second){

            low[w] = min(low[w], intimer[u]);
        }
    }
    outtimer[w] = ++timer;
}

int main() {

    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &from[i], &to[i], &cost[i]);
        V[from[i]].push_back({to[i], i});
        V[to[i]].push_back({from[i], i});
    }

    DFS2(s);

    if (vis[t] == false) {
        printf("0\n0\n");
        return 0;
    }

    int ans = INF;
    int v1 = -1;
    int v2 = -1;
    for (int i = 1; i <= m; i++) {
        if (treeEdge[i]) {
            timer = 0;
            int c = cost[i];

            for (int j = 1; j <= n; j++) {
                V[j].clear();
                vis[j] = false;
                intimer[j] = outtimer[j] = 0;
                low[j] = 0;
            }
            for (int j = 1; j <= m; j++) {

                treeEdge2[j] = false;
                if (i == j) {
                    continue;
                } else {
                    V[from[j]].push_back({to[j], j});
                    V[to[j]].push_back({from[j], j});
                }
            }
            DFS(s);
            if (vis[t] == false) {
                ans = min(ans, c);
                if (ans == c) {
                    v1 = i;
                    v2 = -1;
                    continue;
                }
            }
            for (int j = 1; j <= m; j++) {

                if (intimer[from[j]] > intimer[to[j]]) {
                    swap(from[j], to[j]);
                }
                if (treeEdge2[j] == true && intimer[to[j]] <= intimer[t] && outtimer[to[j]] >= outtimer[t] && low[to[j]] >= intimer[to[j]]) {
                    ans = min(ans, c + cost[j]);
                    if (ans == c + cost[j]) {
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }
    }

    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
        if (v2 == -1) {
            printf("1\n");
            printf("%d\n", v1);
        } else {
            printf("2\n%d %d\n", v1, v2);
        }
    }

    return 0;
}