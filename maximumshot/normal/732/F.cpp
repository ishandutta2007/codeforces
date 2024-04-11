#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long LL;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
LL const inf64 = 1ll * inf * inf;

int const MAXN = 400005;

int n, m;
pii edge[MAXN];
vec< pii > g[MAXN];
bool br[MAXN];

int timer = 0;
int tin[MAXN];
int fup[MAXN];
bool used[MAXN];

void dfs(int v, int par = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for(pii cur : g[v]) {
        int to, ed;
        tie(to, ed) = cur;
        if(to == par) continue;
        if(used[to]) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(tin[v] < fup[to]) {
                br[ed] = 1;
            }
        }
    }
}

int go(int v) {
    used[v] = 1;
    int res = 1;
    for(pii cur : g[v]) {
        int to, ed;
        tie(to, ed) = cur;
        if(br[ed]) continue;
        edge[ed] = {v, to};
        if(!used[to]) {
            res += go(to);
        }
    }
    return res;
}

void mark(int v) {
    used[v] = 1;
    for(pii cur : g[v]) {
        int to, ed;
        tie(to, ed) = cur;
        if(!used[to]) {
            if(br[ed]) edge[ed] = {to, v};
            mark(to);
        }
    }
}

bool solve() {

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        edge[i] = {u, v};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    dfs(1);

    for(int i = 1;i <= n;i++) {
        used[i] = 0;
    }

    int tot = 0;
    int best = -1;

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        int x = go(i);
        if(x > tot) {
            tot = x;
            best = i;
        }
    }

    for(int i = 1;i <= n;i++) {
        used[i] = 0;
    }

    mark(best);

    printf("%d\n", tot);

    for(int i = 0;i < m;i++) {
        printf("%d %d\n", edge[i].first, edge[i].second);
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}