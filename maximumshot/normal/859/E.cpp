#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n;
vec< int > g[N];
vec< int > f[N];
int color[N];
int used[N];

int go(int v, int x) {
    used[v] = x;
    int res = 1;
    for(int to : f[v]) {
        if(!used[to]) {
            res += go(to, x);
        }
    }
    return res;
}

bool dfs(int v) {
    color[v] = 1;
    for(int to : g[v]) {
        if(!color[to]) {
            if(dfs(to)) {
                return true;
            }
        }else if(color[to] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool loop[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int u, v, i = 1;i <= n;i++) {
        scanf("%d %d", &u, &v);
        if(u != v) {
            g[u].push_back(v);
            f[u].push_back(v);
            f[v].push_back(u);
        }else {
            loop[u] = 1;
        }
    }

    int res = 1;

    for(int i = 1;i <= n+n;i++) {
        if(loop[i]) {
            go(i, 1);
        }
    }

    for(int i = 1;i <= n+n;i++) {
        if(used[i]) continue;
        if(dfs(i)) {
            go(i, 1);
            res = (1ll * res * 2) % (inf + 7);
        }else {
            res = (1ll * res * go(i, 1)) % (inf + 7);
        }
    }

    printf("%d\n", res);

    return 0;
}