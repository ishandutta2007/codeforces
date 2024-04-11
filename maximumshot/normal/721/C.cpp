#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;
int const max_dist = inf + 1;

int n, m, T;
vec< pii > g[N];

int dist[N][N];
int par[N][N];
bool used[N];

void go(int v) {
    used[v] = 1;
    if(v == n - 1) {
        dist[v][1] = 0;
        return;
    }
    for(auto iter : g[v]) {
        int to, t;
        tie(to, t) = iter;
        if(!used[to]) go(to);
        for(int cnt = 1;cnt <= n;cnt++) {
            if(dist[v][cnt] > min(dist[to][cnt - 1] + t, max_dist)) {
                dist[v][cnt] = min(dist[to][cnt - 1] + t, max_dist);
                par[v][cnt] = to;
            }
        }
    }
}

int tops[N];
int cur = 0;

void dfs(int v) {
    used[v] = 1;
    for(auto iter : g[v]) {
        if(!used[iter.first])
            dfs(iter.first);
    }
    tops[cur++] = v;
}

#include <conio.h>

bool solve() {

    scanf("%d %d %d", &n, &m, &T);

    for(int u, v, t, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &t);
        u--, v--;
        g[u].push_back({v, t});
    }

    for(int i = 0;i < n;i++) {
        if(!used[i]) dfs(i);
    }

    reverse(tops, tops + n);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= n;j++) {
            dist[i][j] = max_dist;
            par[i][j] = -1;
        }
    }

    for(int i = 0;i < n;i++) used[i] = 0;

    for(int i = 0;i < n;i++) {
        if(!used[tops[i]]) go(tops[i]);
    }

    int res = -1;

    for(int cnt = 1;cnt <= n;cnt++) {
        if(res == -1 || dist[0][cnt] <= T)
            res = cnt;
    }

    printf("%d\n", res);
    
    for(int u = 0, cnt = res;u != -1;u = par[u][cnt--]) {
        printf("%d ", u + 1);
    }

    printf("\n");

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