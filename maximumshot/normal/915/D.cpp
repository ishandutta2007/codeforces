#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 505;
const int M = 1e5 + 5;

int n, m;
vec< int > g[N];
pii edge[M];

inline int get_to(int id) {
    return edge[id].second;
}

inline int get_from(int id) {
    return edge[id].first;
}

int color[N];
int from[N];
int st, fn;
int connector;

int dfs(int v, int del = -1) {
    color[v] = 1;
    for(int id : g[v]) {
        if(id == del) continue;
        int to = get_to(id);
        if(color[to] == 1) {
            st = to;
            fn = v;
            connector = id;
            return 1;
        }else if(color[to] == 0) {
            from[to] = id;
            if(dfs(to, del)) {
                return 1;
            }
        }
    }
    color[v] = 2;
    return 0;
}

bool check(int del) {
    memset(color, 0, sizeof(int) * (n + 1));
    for(int v = 1;v <= n;v++) {
        if(color[v]) continue;
        if(dfs(v, del)) {
            return false;
        }
    }
    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(i);
        edge[i] = make_pair(u, v);
    }

    for(int v = 1;v <= n;v++) {
        if(color[v]) continue;
        if(!dfs(v)) continue;
        vec< int > mas;
        for(int v = fn;v != st;v = get_from(from[v])) {
            mas.push_back(from[v]);
        }
        mas.push_back(connector);
        for(int id : mas) {
            if(check(id)) {
                puts("YES");
                return 0;
            }
        }
        puts("NO");
        return 0;
    }

    puts("YES");

    return 0;
}