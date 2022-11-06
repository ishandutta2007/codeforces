#include <bits/stdc++.h>

using namespace std;

const int N = 500005, M = 1000000007;

int n, m, k;
int a, b;
long long key[N];
vector<int> V[N];
bool vis[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int power(int a, int k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 == 1 ? a : 1);
}

void DFS(int w) {
    vis[w] = true;
    for (int u : V[w]) {
        if (!vis[u]) {
            DFS(u);
        }
    }
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &key[i]);
    }
    
    vector<pair<long long, pair<int, int> > > edges;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        long long value = key[a] ^ key[b];
        edges.push_back({value, {a, b}});
    }
    
    int ans = 0;
    sort(edges.begin(), edges.end());
    int differentValues = 0;
    set<int> nodes;
    for (int i = 0; i < m; i++) {
        nodes.insert(edges[i].second.first);
        nodes.insert(edges[i].second.second);
        V[edges[i].second.first].push_back(edges[i].second.second);
        V[edges[i].second.second].push_back(edges[i].second.first);
        if (i == m - 1 || edges[i].first != edges[i + 1].first) {
            differentValues++;
            int components = 0;
            for (int u : nodes) {
                if (!vis[u]) {
                    DFS(u);
                    components++;
                }
            }
            
            add(ans, power(2, components + n - nodes.size()));
            
            for (int u : nodes) {
                vis[u] = false;
                V[u].clear();
            }
            nodes.clear();
        }
    }
    
    long long remainingValues = (power(2, k) - differentValues) % M;
    
    add(ans, mul(remainingValues, power(2, n)));
    
    printf("%d\n", ans);
    
    return 0;
}