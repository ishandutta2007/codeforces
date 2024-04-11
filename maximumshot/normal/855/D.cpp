#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int const N = 1e5 + 5;
int const LOG = 21;

int parent[LOG][N];
int Type[N];
int tin[N];
int tout[N];
vec< int > g[N];
int n;
int cnt[N][2];
int height[N];
vec< int > roots;
int comp[N];

void dfs(int v, int cl) {
    comp[v] = cl;
    if(parent[0][v] != -1) {
        cnt[v][0] = cnt[parent[0][v]][0];
        cnt[v][1] = cnt[parent[0][v]][1];
        cnt[v][Type[v]]++;
        height[v] = height[parent[0][v]] + 1;
    }
    static int timer = 0;
    tin[v] = timer++;
    for(int to : g[v]) {
        dfs(to, cl);
    }
    tout[v] = timer++;
}

int getLca(int x, int y) {
    if(height[x] < height[y]) {
        swap(x, y);
    }
    for(int j = LOG - 1;j >= 0;j--) {
        int px = parent[j][x];
        if(px == -1 || height[px] < height[y]) continue;
        x = px;
    }
    for(int j = LOG - 1;j >= 0;j--) {
        int px = parent[j][x];
        int py = parent[j][y];
        if(px == -1 || py == -1 || px == py) continue;
        x = px;
        y = py;
    }
    if(x != y) x = parent[0][x];
    return x;
}

int get(int P, int S) {
    for(int j = LOG - 1;j >= 0;j--) {
        int pS = parent[j][S];
        if(pS == -1 || height[pS] <= height[P]) continue;
        S = pS;
    }
    return S;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#else
#endif

    scanf("%d", &n);

    for(int j = 0;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            parent[j][v] = -1;
        }
    }

    for(int px, tx, i = 1;i <= n;i++) {
        scanf("%d %d", &px, &tx);
        if(px == -1) {
            roots.push_back(i);
        }else {
            parent[0][i] = px;
            Type[i] = tx;
            g[px].push_back(i);
        }
    }

    for(int j = 1;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            int pv = parent[j - 1][v];
            if(pv == -1) {
                parent[j][v] = pv;
            }else {
                parent[j][v] = parent[j - 1][pv];
            }
        }
    }

    for(int root : roots) {
        static int color = 1;
        dfs(root, color++);
    }

    int q;

    scanf("%d", &q);

    for(int type, u, v, iter = 0;iter < q;iter++) {
        scanf("%d %d %d", &type, &u, &v);
        type--;
        if(u == v || comp[u] != comp[v]) {
            puts("NO");
            continue;
        }
        if(type == 0) {
            if(tin[u] <= tin[v] && tout[v] <= tout[u]) {
                if(height[v] - height[u] == cnt[v][0] - cnt[u][0]) {
                    puts("YES");
                }else {
                    puts("NO");
                }
            }else {
                puts("NO");
            }
        }else {
            int z = getLca(u, v);
            if(z == v) {
                puts("NO");
                continue;
            }
            if(z == u) {
                if(height[v] - height[u] == cnt[v][1] - cnt[u][1]) {
                    puts("YES");
                }else {
                    puts("NO");
                }
                continue;
            }
            if(height[u] - height[z] == cnt[u][0] - cnt[z][0] &&
               height[v] - height[z] == cnt[v][1] - cnt[z][1]) {
                puts("YES");
            }else {
                puts("NO");
            }
        }
    }

    return 0;
}