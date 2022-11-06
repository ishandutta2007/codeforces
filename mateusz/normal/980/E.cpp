#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, LOG = 21;

int n, k;
int a, b;
vector<int> V[N];
bool vis[N];
int inTime[N], outTime[N], timer;
int par[N][LOG + 5];
int parent[N];
int depth[N];
bool taken[N];

void DFS(int w) {
    inTime[w] = ++timer;
    vis[w] = true;
    par[w][0] = parent[w];
    for (int i = 1; i < LOG; i++) {
        par[w][i] = par[par[w][i - 1]][i - 1];
    }
    
    for (int u : V[w]) {
        if (!vis[u]) {
            parent[u] = w;
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
    
    assert(a != b);
    assert(par[a][0] == par[b][0]);
    return par[a][0];
}

int findClosest(int w, int highest) {
    for (int i = LOG - 1; i >= 0; i--) {
//         cerr << "SKOK " << w << " " << i << " " << endl;
        if (depth[w] - (1 << i) >= depth[highest] && !taken[par[w][i]]) {
            w = par[w][i];
        }
    }
    assert(!taken[w]);
    assert(taken[par[w][0]]);
    return par[w][0];
}

void merge(int w, int u, bool topar=false) {
    assert(isAncestor(u, w));
    while (w != u) {
        if (topar) {
//             assert(!taken[u]);
            taken[par[w][0]] = true;
        } else {
//             assert(!taken[w]);
            taken[w] = true;
        }
        k--;
        w = par[w][0];
    }
}


int main() {
    depth[0] = -1;
    scanf("%d %d", &n, &k);
    int oldK = k;
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
    k = n - k - 1;
    int highest = n;
    taken[n] = true;
    
    for (int i = n - 1; i >= 1; i--) {
        int w = i;
        if (taken[i]) continue;
        if (isAncestor(highest, w)) {
            int u = findClosest(w, highest);
//             cerr << i << " " << u << " " << highest << endl;
            if (depth[w] - depth[u] <= k) {
//                 cerr << i << " " << "GOOOOD\n";
                merge(w, u);
                assert(k >= 0);
            }
        } else {
            int lca = LCA(w, highest);
            assert(isAncestor(lca, w) && isAncestor(lca, highest));
            if (depth[highest] + depth[w] - 2 * depth[lca] <= k) {
//                 cerr << i << " " << "GOOD\n";
                merge(highest, lca, true);
                merge(w, lca);
                highest = lca;
                assert(k >= 0);
            }
        }
        
//         cerr << k << endl;
        
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            ans.push_back(i);
//             printf("%d ", i);
        }
    }
    
//     assert(ans.size() <= oldK);
//     for (int i = 1; i <= n; i++) {
//         if (taken[i] && ans.size() < oldK) {
//             ans.push_back(i);
//         }
//     }
    
    sort(ans.begin(), ans.end());
    
//     assert(ans.size() == oldK);
    for (int x : ans) {
        printf("%d ", x);
    }
    
    return 0;
}