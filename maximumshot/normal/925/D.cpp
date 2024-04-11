#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 3e5 + 5;

int n, m;
vec< int > g[N];

bool solve_simple() {
    vec< int > dist(n + 1, inf);
    vec< int > from(n + 1, -1);
    queue< int > q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int to : g[v]) {
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }
    if(dist[n] > 3) return false;
    printf("%d\n", dist[n]);
    vec< int > way;
    {
        int v = n;
        while(v != -1) {
            way.push_back(v);
            v = from[v];
        }
        reverse(ALL(way));
        for(int u : way) {
            printf("%d ", u);
        }
        printf("\n");
    }
    return true;
}

bool try_4() {
    vec< int > neigh(n + 1);
    neigh[1] = 1;
    for(int v : g[1]) {
        neigh[v] = 1;
    }
    for(int v : g[1]) {
        for(int u : g[v]) {
            if(!neigh[u]) {
                puts("4");
                printf("1 %d %d 1 %d\n", v, u, n);
                return true;
            }
        }
    }
    return false;
}

bool try_5() {
    vec< int > neigh(n + 1);
    for(int v1 : g[1]) {
        for(int u : g[v1]) {
            neigh[u] = 1;
        }
        neigh[v1] = 1;
        for(int v2 : g[v1]) {
            if(v2 == 1) continue;
            for(int v3 : g[v2]) {
                if(neigh[v3]) continue;
                puts("5");
                printf("1 %d %d %d %d %d\n", v1, v2, v3, v1, n);
                return true;
            }
        }
        for(int u : g[v1]) {
            neigh[u] = 0;
        }
        neigh[v1] = 0;
    }
    return false;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(solve_simple()) {
        return 0;
    }

    if(try_4()) {
        return 0;
    }

    if(try_5()) {
        return 0;
    }

    puts("-1");

    return 0;
}