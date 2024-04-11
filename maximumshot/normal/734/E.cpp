#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct DSU {
    int n;
    vec< int > p, h;
    DSU() : n(0) { }
    DSU(int n) : n(n) {
        p.resize(n + 1);
        h.resize(n + 1);
        for(int i = 1;i <= n;i++) {
            p[i] = i;
            h[i] = 0;
        }
    }
    int find(int x) { return (p[x] == x ? x : p[x] = find(p[x])); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(h[x] == h[y]) {
            h[x]++;
            p[y] = x;
        }else {
            if(h[x] < h[y]) swap(x, y);
            p[y] = x;
        }
        return 1;
    }
};

int const N = 200005;

int n;
int color[N];
pii edge[N];
vec< int > g[N];
bool have[N];
int dist[N];
queue< int > q;

pair< int, int > get_dist(int start) {
    for(int i = 1;i <= n;i++) {
        if(have[i]) {
            dist[i] = inf;
        }
    }
    dist[start] = 0;
    q.push(start);
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
    pii result = {-1, -1};
    for(int i = 1;i <= n;i++) {
        if(have[i]) {
            result = max(result, {dist[i], i});
        }
    }
    return result;
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &color[i]);
    }

    DSU dsu(n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        edge[i] = {u, v};
        if(color[u] == color[v]) {
            dsu.merge(u, v);
        }
    }

    int root = dsu.find(1);

    for(int u, v, i = 1;i < n;i++) {
        tie(u, v) = edge[i];
        if(color[u] != color[v]) {
            u = dsu.find(u);
            v = dsu.find(v);
            have[u] = have[v] = 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    int D = get_dist(get_dist(root).second).first;
    D = (D + 1) / 2;

    printf("%d\n", D);

    return 0;
}