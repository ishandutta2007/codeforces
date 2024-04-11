#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 3005;

int n;
vector<pii> adj[MAXN];
int ans, sum, mi;

void dfs(int cur, int par, int a, int b, int d) {
    d = min(d, a-b);
    mi = min(mi, b+d-a);
    for (int i=0; i<adj[cur].size(); i++) {
        pii p = adj[cur][i];
        if (p.fi == par) continue;
        sum += p.se;
        dfs(p.fi, cur, a+p.se, b+1-p.se, d);
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(pii(b, 0));
        adj[b].push_back(pii(a, 1));
    }

    ans = n-1;
    for (int i=0; i<n; i++) {
        sum = 0, mi = 100000;
        dfs(i, i, 0, 0, 0);
        ans = min(ans, sum+mi);
    }
    printf("%d\n", ans);
    return 0;
}