#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 5005;

int n, sub[MAXN];
vector<int> adj[MAXN];
bool good[MAXN], dp[MAXN];

void dfs(int cur, int p) {
    sub[cur] = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        memset(sub, 0, sizeof(sub));
        memset(dp, 0, sizeof(dp));
        dfs(i, i);
        dp[0] = 1;
        for (int j=0; j<adj[i].size(); j++) {
            int k = adj[i][j];
            for (int l=n; l>=0; l--)
                if (l+sub[k] <= n)
                    dp[l+sub[k]] |= dp[l];
        }
        for (int j=0; j<=n; j++)
            good[j] |= dp[j];
    }

    vector<int> ans;
    for (int i=1; i<n-1; i++)
        if (good[i])
            ans.push_back(i);

    printf("%d\n", ans.size());
    for (int i=0; i<ans.size(); i++)
        printf("%d %d\n", ans[i], n-1-ans[i]);
    return 0;
}