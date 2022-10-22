#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3e5 + 5;

int n, m;
vec< int > a[N];
vec< int > g[N];
int res[N];
int mx = 0;

void dfs(int v, int par = -1) {
    set< int > used;
    for(int color : a[v]) {
        if(res[color] > 0) {
            used.insert(res[color]);
        }
    }
    int cur = 1;
    for(int color : a[v]) {
        if(res[color]) continue;
        while(used.count(cur)) {
            cur++;
            if(cur > mx) {
                cur = 1;
            }
        }
        res[color] = cur++;
    }
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int sz, i = 1;i <= n;i++) {
        scanf("%d", &sz);
        a[i].resize(sz);
        for(int j = 0;j < sz;j++) {
            scanf("%d", &a[i][j]);
        }
        mx = max(mx, sz);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    printf("%d\n", max(1, mx));

    for(int i = 1;i <= m;i++) {
        printf("%d ", max(1, res[i]));
    }
    printf("\n");

    return 0;
}