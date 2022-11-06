#include <bits/stdc++.h>

using namespace std;

const int N = 500005, LOG = 20;

int n, k;
int a, b;
vector<int> V[N];
vector<int> E[N];
bool vis[N];
int inTime[N], outTime[N], timer;
int par[N][LOG + 5];
int parent[N];
int parId[N];
int depth[N];

void DFS(int w) {
    inTime[w] = ++timer;
    vis[w] = true;
    par[w][0] = parent[w];
    for (int i = 1; i < LOG; i++) {
        par[w][i] = par[par[w][i - 1]][i - 1];
    }
    
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        int id = E[w][i];
        if (!vis[u]) {
            parent[u] = w;
            parId[u] = id;
            depth[u] = depth[w] + 1;
            DFS(u);
        }
    }
    outTime[w] = ++timer;
}

bool isAncestor(int anc, int w) {
    return inTime[anc] <= inTime[w] && outTime[anc] >= outTime[w];
}

int LCA(int a, int b) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = par[a][i];
        }
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[b] - (1 << i) >= depth[a]) {
            b = par[b][i];
        }
    }
    
    if (a == b) {
        return a;
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    
    return par[a][0];
}

int m;
multiset<int> limits[N];
int enemyA[N], enemyB[N], cost[N];
bool nope[N];
int rep[N];
int ans[N];
int c;

int find(int w) {
    return rep[w] = (rep[w] == w ? w : find(rep[w]));
}

void Union(int a, int b) {
    rep[find(a)] = find(b);
}

void makePath(int w, int anc, int cost) {
    while (true) {
        w = find(w);
        if (depth[w] <= depth[anc]) {
            break;
        }
        ans[parId[w]] = cost;
        Union(w, parent[w]);
        w = parent[w];
    }
}

const int INF = 2e9;

int main() {
    
    scanf("%d %d %d", &n, &k, &m);
    
    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }
    
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &a, &b);
        ans[i] = INF;
        V[a].push_back(b);
        V[b].push_back(a);
        E[a].push_back(i);
        E[b].push_back(i);
        Union(a, b);
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        enemyA[i] = a;
        enemyB[i] = b;
        cost[i] = c;
        if (find(a) != find(b)) {
            Union(a, b);
            V[a].push_back(b);
            V[b].push_back(a);
            E[a].push_back(-1);
            E[b].push_back(-1);
        } else {
            nope[i] = true;
        }
    }
    
    DFS(1);
    
    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (nope[i]) {
            int a = enemyA[i];
            int b = enemyB[i];
            int c = cost[i];
            int lca = LCA(a, b);
            
            makePath(a, lca, c);
            makePath(b, lca, c);
        }
    }

    long long res = 0;
    for (int i = 1; i <= k; i++) {
        if (ans[i] == INF) {
            printf("-1\n");
            return 0;
        }
        res += ans[i];
    }
    printf("%lld\n", res);
    return 0;
}