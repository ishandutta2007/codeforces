#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int father[300001], size[300001], use[300001];
int visit[300001], visit_n[300001];

int find(int u) {
    if (father[u] == u) {
        return u;
    } else {
        return father[u] = find(father[u]);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    vector<pair<int, pair<int, int> > > edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        father[i] = i; size[i] = 1; use[i] = 0;
    }
    int ans = 0;
    for (int i = edges.size() - 1; i >= 0; i--) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (find(u) != find(v) and (use[find(u)] != size[find(u)] or 
            use[find(v)] != size[find(v)])) {
            visit[i] = true;
            ans += w;
            size[father[v]] += size[father[u]];
            use[father[v]] += use[father[u]];
            use[father[v]]++;
            father[father[u]] = father[v];
        }
        else
            if (find(u) == find(v) && size[find(u)] > use[find(u)]) {
                ans += w;
                use[father[u]]++;
            }
    } 
    cout << ans << endl;
    return 0;
}