#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const LOG = 21;

int n, q;
vec< int > g[N];
int parent[LOG][N];
int height[N];
int tin[N];
int tout[N];

void dfs(int v, int par = -1) {
    static int timer = 0;
    tin[v] = timer++;
    parent[0][v] = par;
    height[v] = par == -1 ? 0 : height[par] + 1;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

int getLca(int x, int y) {
    if(height[x] < height[y]) swap(x, y);
    for(int px, j = LOG - 1;j >= 0;j--) {
        px = parent[j][x];
        if(px == -1 || height[px] < height[y]) continue;
        x = px;
    }
    for(int px, py, j = LOG - 1;j >= 0;j--) {
        px = parent[j][x];
        py = parent[j][y];
        if(px == -1 || py == -1 || px == py) continue;
        x = px;
        y = py;
    }
    if(x != y) x = parent[0][x];
    return x;
}

void build() {
    for(int j = 0;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            parent[j][v] = -1;
        }
    }
    dfs(1);
    for(int j = 1;j < LOG;j++) {
        for(int pv, v = 1;v <= n;v++) {
            pv = parent[j - 1][v];
            if(pv == -1) {
                parent[j][v] = -1;
            }else {
                parent[j][v] = parent[j - 1][pv];
            }
        }
    }
}

inline bool inTree(int P, int S) {
    return tin[P] <= tin[S] && tout[S] <= tout[P];
}

int get(int s, int t, int f) {
    if(inTree(s, f)) {
        if(inTree(f, t)) {
            return 1;
        }else {
            if(!inTree(s, t)) {
                return height[f] - height[s] + 1;
            }else {
                return height[f] - height[getLca(f, t)] + 1;
            }
        }
    }else if(inTree(f, s)) {
        if(inTree(s, t)) {
            return height[s] - height[f] + 1;
        }else if(!inTree(f, t)) {
            return 1;
        }else {
            return height[getLca(s, t)] - height[f] + 1;
        }
    }else {
        int z = getLca(s, f);
        if(inTree(s, t)) {
            return height[s] + height[f] - 2 * height[z] + 1;
        }else if(inTree(f, t)) {
            return 1;
        }else if(!inTree(z, t)) {
            return height[f] - height[z] + 1;
        }else {
            int u = getLca(s, t);
            if(u == z) {
                u = getLca(f, t);
                return height[f] - height[u] + 1;
            }else {
                return height[u] + height[f] - 2 * height[z] + 1;
            }
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[x].push_back(i);
        g[i].push_back(x);
    }

    build();

    int arr[3];

    for(int res, iter = 0;iter < q;iter++) {
        for(int i = 0;i < 3;i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + 3);
        res = 0;
        for(int f = 0;f < 3;f++) {
            for(int t = 0;t < 3;t++) {
                if(f == t) continue;
                int s = 3 - f - t;
                res = max(res, get(arr[s], arr[t], arr[f]));
            }
        }
        printf("%d\n", res);
    }

    return 0;
}