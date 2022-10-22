#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n, x;
vec< int > g[N];
int color[N];

vec< int > getWay() {
    vec< int > dist(n + 1, inf);
    vec< int > from(n + 1, -1);
    dist[1] = 0;
    queue< int > q;
    q.push(1);
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
    vec< int > res;
    for(int v = x;;v = from[v]) {
        res.push_back(v);
        if(v == 1) break;
    }
    reverse(ALL(res));
    return res;
}

int maxPath[N];

void dfs(int v, int par = -1) {
    for(int to : g[v]) {
        if(color[to] || to == par) continue;
        dfs(to, v);
        maxPath[v] = max(maxPath[v], maxPath[to] + 1);
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &x);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec< int > w = getWay();

    for(int x : w) color[x] = 1;

    for(int x : w) {
        dfs(x);
    }

    int res = 0;

    for(int l = 0, r = (int)w.size() - 1;l < r;l++, r--) {
        res = max(res, maxPath[w[r]] + r);
    }

    printf("%d\n", res + res);

    return 0;
}