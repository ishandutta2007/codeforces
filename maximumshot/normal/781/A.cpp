#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n;
vec< int > g[N];
int color[N];
int res;

void dfs(int v, int par = -1) {
    int cur = 1;
    for(int to : g[v]) {
        if(to == par) continue;
        while(cur == color[v] || par != -1 && color[par] == cur) cur++;
        color[to] = cur++;
    }
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
}

int main() {

    scanf("%d", &n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        res = max(res, 1 + (int)g[i].size());
    }

    printf("%d\n", res);

    color[1] = 1;
    dfs(1);

    for(int i = 1;i <= n;i++) {
        printf("%d ", color[i]);
    }
    printf("\n");


    return 0;
}