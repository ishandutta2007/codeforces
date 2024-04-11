#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, bool> pib;

const int MAXN = 200010;

int n, sub[MAXN], dp[MAXN], ans[MAXN], best = 1e9;
bool vis[MAXN];
vector<pib> adj[MAXN];

void dfs1(int cur) {
    vis[cur] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i].first]) continue;
        dfs1(adj[cur][i].first);
        sub[cur] += sub[adj[cur][i].first] + adj[cur][i].second;
    }
}

void dfs2(int cur, int val) {
    vis[cur] = 1;
    ans[cur] = val + sub[cur];
    for (int i=0; i<adj[cur].size(); i++) {
        if (vis[adj[cur][i].first]) continue;
        if (!adj[cur][i].second) dfs2(adj[cur][i].first, ans[cur] - sub[adj[cur][i].first] + 1);
        else dfs2(adj[cur][i].first, ans[cur] - sub[adj[cur][i].first] - 1);
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        s--; e--;
        adj[s].push_back(pib(e, 0));
        adj[e].push_back(pib(s, 1));
    }
    dfs1(0);
    for (int i=0; i<n; i++) vis[i] = 0;
    dfs2(0, 0);
    for (int i=0; i<n; i++) best = min(best, ans[i]);
    printf("%d\n", best);
    for (int i=0; i<n; i++) {
        if (ans[i] == best) {
            printf("%d ", i + 1);
        }
    }
}