#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e6 + 5;

int n, q;
vec< int > g[N];
int mn[N];

void dfs(int v, int par = -1) {
    if(par == -1) {
        mn[v] = v;
    }else {
        mn[v] = min(mn[par], v);
    }
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int last = 0;
    int tot = inf;

    for(int type, z, x, iter = 0;iter < q;iter++) {
        scanf("%d %d", &type, &z);
        x = (last + z) % n + 1;
        if(type == 1) {
            if(iter == 0) dfs(x);
            tot = min(tot, mn[x]);
        }else {
            last = min(mn[x], tot);
            printf("%d\n", last);
        }
    }

    return 0;
}