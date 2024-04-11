#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n;
int w[N];
vector< pii > g[N];

int sz[N];
int used[N];
ll glob = 0;

void dfs(int v, int par = -1) {
    sz[v] = 1;
    for(pii ed : g[v]) {
        int to = ed.first;
        if(to == par || used[to]) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

void go(int v, int &centroid, int Size, int par = -1) {
    int mx = Size - sz[v];
    for(pii ed : g[v]) {
        int to = ed.first;
        if(to == par || used[to]) continue;
        go(to, centroid, Size, v);
        if(centroid != -1) return;
        mx = max(mx, sz[to]);
    }
    if(2 * mx <= Size) {
        centroid = v;
    }
}

ll get_max(int v, int par = -1) {
    ll mx = w[v];
    for(pii ed : g[v]) {
        int to = ed.first;
        if(to == par || used[to]) continue;
        ll tmp = get_max(to, v);
        mx = max(mx, tmp - ed.second + w[v]);
    }
    return mx;
}

void solve(int v) {
    dfs(v);
    int centroid = -1;
    int Size = sz[v];
    go(v, centroid, Size, -1);
    assert(centroid != -1);
    used[centroid] = 1;
    ll mx1 = 0;
    ll mx2 = 0;
    for(pii ed : g[centroid]) {
        int to = ed.first;
        if(used[to]) continue;
        ll tmp = get_max(to, centroid) - ed.second;
        if(tmp > mx1) {
            mx2 = mx1;
            mx1 = tmp;
        }else if(tmp > mx2) {
            mx2 = tmp;
        }
    }
    glob = max(glob, mx1 + mx2 + w[centroid]);
    for(pii ed : g[centroid]) {
        int to = ed.first;
        if(used[to]) continue;
        solve(to);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &w[i]);
        glob = max(glob, 1ll * w[i]);
    }

    for(int u, v, c, i = 1;i < n;i++) {
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    solve(1);

    printf("%lld\n", glob);

    return 0;
}