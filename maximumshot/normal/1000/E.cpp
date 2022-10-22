#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
vec< int > g[N];
int tin[N];
int fup[N];
int used[N];
int timer;
unordered_set< int > bridge[N];

void dfs(int v, int par = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for(int to : g[v]) {
        if(to == par) continue;
        if(!used[to]) {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(tin[v] < fup[to]) {
                bridge[min(v, to)].insert(max(v, to));
            }
        }else {
            fup[v] = min(fup[v], tin[to]);
        }
    }
}

int color[N];

void paint(int v, int cl) {
    color[v] = cl;
    for(int to : g[v]) {
        if(bridge[min(v, to)].count(max(v, to))) continue;
        if(!color[to]) {
            paint(to, cl);
        }
    }
}

vec< int > G[N];

pii bfs(int s) {
    vec< int > dist(n + 1, inf);
    queue< int > q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int to : g[v]) {
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    int t = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    return make_pair(t, dist[t]);
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

    for(int v = 1;v <= n;v++) {
        if(used[v]) continue;
        dfs(v);
    }

    int cl = 0;
    for(int i = 1;i <= n;i++) {
        if(!color[i]) {
            cl++;
            paint(i, cl);
        }
    }

    for(int v = 1;v <= n;v++) {
        for(int to : g[v]) {
            G[color[v]].push_back(color[to]);
        }
    }

    for(int v = 1;v <= cl;v++) {
        sort(ALL(G[v]));
        G[v].resize(unique(ALL(G[v])) - G[v].begin());
    }

    n = cl;
    for(int v = 1;v <= n;v++) {
        g[v] = G[v];
    }

    printf("%d\n", bfs(bfs(1).first).second);

    return 0;
}