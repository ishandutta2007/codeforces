#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

const int LOG = 21;

int n, m;
vec< vec< int > > g;
// {edge_id}

vec< pair< int, int > > edge; // 
vec< ll > value; //  

void read() {
    scanf("%d %d", &n, &m);

    g.resize(n + 1);
    edge.resize(n);
    value.resize(n);

    for(int i = 1;i <= n - 1;i++) {
        int u, v;
        ll x;
        scanf("%d %d %I64d", &u, &v, &x);

        g[u].push_back(i);
        g[v].push_back(i);
        edge[i] = mp(u, v);
        value[i] = x;
    }
}

vec< int > h; //  
vec< int > par[LOG];
vec< int > up;
vec< ll > p_edge;

void dfs(int v, int p = -1, int H = 0) {
    up[v] = v;
    h[v] = H;
    par[0][v] = p;

    for(int i = 0;i < (int)g[v].size();i++) {
        int edge_id = g[v][i];
        int to = (edge[edge_id].first == v?edge[edge_id].second : edge[edge_id].first);
        ll w = value[edge_id];
        if(to == p) continue;
        dfs(to, v, H + 1);
        p_edge[to] = w;
    }
}

int lca(int x, int y) {
    if(h[x] > h[y]) swap(x, y);
    for(int k = LOG - 1;k >= 0;k--) {
        int py = par[k][y];
        if(py == -1 || h[py] < h[x]) continue;
        y = py;
    }
    for(int k = LOG - 1;k >= 0;k--) {
        int px = par[k][x];
        int py = par[k][y];
        if(px == -1 || py == -1 || px == py) continue;
        x = px;
        y = py;
    }
    if(x != y) x = par[0][x];
    return x;
}

void precalc() {

    p_edge.resize(n + 1, 1ll);
    up.resize(n + 1);
    h.resize(n + 1);
    for(int i = 0;i < LOG;i++) {
        par[i].resize(n + 1, -1);
    }

    dfs(1);

    for(int k = 1;k < LOG;k++) {
        for(int i = 1;i <= n;i++) {
            int x = par[k - 1][i];
            if(x != -1) par[k][i] = par[k - 1][x];
        }
    }
}

int go_to(int v) {
    if(up[v] != v) up[v] = go_to(up[v]);
    else if(p_edge[v] == 1 && v != 1) up[v] = go_to(par[0][v]);
    return up[v];
}

bool solve() {

    read();
    precalc();

    int ty, a, b, cnt, z, v, edge_id;
    ll y, new_cost;

    vec< ll > mas1, mas2;

    for(;m;m--) {
        scanf("%d", &ty);
        
        if(ty == 1) {
            scanf("%d %d %I64d", &a, &b, &y);
            z = lca(a, b);
    
            // a -> z -> b

            v = a;

            while((int)mas1.size() < 70) {
                v = go_to(v);
                if(h[v] <= h[z]) break;
                if(p_edge[v] > 1) mas1.push_back(p_edge[v]);
                v = par[0][v];
            }

            v = b;

            while((int)mas2.size() < 70) {
                v = go_to(v);
                if(h[v] <= h[z]) break;
                if(p_edge[v] > 1) mas2.push_back(p_edge[v]);
                v = par[0][v];
            }

            for(int i = 0;i < (int)mas1.size();i++) y /= mas1[i];
            for(int i = (int)mas2.size() - 1;i >= 0;i--) y /= mas2[i];

            printf("%I64d\n", y);

            mas1.clear();
            mas2.clear();
        }else {
            scanf("%d %I64d", &edge_id, &new_cost);
            int v1, v2;
            tie(v1, v2) = edge[edge_id];
            // v1 -> v2
            if(h[v1] < h[v2]) swap(v1, v2);
            p_edge[v1] = new_cost;
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}