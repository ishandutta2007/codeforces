#include <bits/stdc++.h>

using namespace std;

const int N = 300005, A = 26;

int n, m, a, b, c;
bool vis[N];
vector<pair<int, int> > V[N];
int ans[N];
int subtree[N];
int par[N];

int merge(vector<int> nodes) {
    int ret = 0;
    vector<int> neigh[A];
    for (int i = 0; i < nodes.size(); i++) {
        int w = nodes[i];
        for (int j = 0; j < V[w].size(); j++) {
            int u = V[w][j].first;
            int kr = V[w][j].second;
            if (par[w] != u) {
                neigh[kr - 97].push_back(u);
            }
        }
    }
    
    for (int i = 0; i < A; i++) {
        if (neigh[i].size() > 1) {
            ret += 1 + merge(neigh[i]);
        } else if (neigh[i].size() == 1) {
            ret += subtree[neigh[i][0]];
        }
    }
    
    return ret;
}

void DFS(int w, int depth) {
    subtree[w] = 1;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        if (par[w] != u) {
            par[u] = w;
            DFS(u, depth + 1);
            subtree[w] += subtree[u];
        }
    }
    vector<int> neigh;
    for (int i = 0; i < V[w].size(); i++) if (par[w] != V[w][i].first) neigh.push_back(V[w][i].first);
    ans[depth] += subtree[w] - 1 - merge(neigh);
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %c", &a, &b, &c);
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    
    DFS(1, 1);
    
    int best = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] > ans[best]) {
            best = i;
        }
    }
    
    printf("%d\n%d\n", n - ans[best], best);
    
    return 0;
}