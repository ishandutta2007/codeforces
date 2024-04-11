# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

const int maxn = 200010;
vector<int> g[maxn], G[maxn];

int n;
int a[maxn], ans[maxn];
int tag[maxn];
long long dist[maxn];

void dfs(int u,int dep) {
    int sz = g[u].size();
    for(int i = 0; i < sz; ++i) {
        dist[dep+1] = dist[dep] + G[u][i];
        dfs(g[u][i], dep + 1);
    }
    ans[u] = tag[dep];
    int k = lower_bound(dist + 1, dist + dep + 1, dist[dep] - a[u]) - dist;
    --tag[k-1]; tag[dep]++;
    tag[dep-1] += tag[dep];
    tag[dep] = 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 2; i <= n; ++i) {
        int u, w;
        scanf("%d%d", &u, &w);
        g[u].push_back(i);
        G[u].push_back(w);
    }
    dist[0] = 0;
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}