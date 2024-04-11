#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;
const int max_v = 1011;

int n, m, dist[max_n][max_n];
int c1, c2, k, h;
int v1[max_v], attack[max_v], fluel[max_v];
int v2[max_v], defend[max_v], p[max_v];
vector<int> g[max_v];
bool used[max_v], take[max_v];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (p[to] == -1 || dfs(p[to])) {
            p[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d%d%d%d", &c1, &c2, &k, &h);
    for (int i = 0; i < c1; ++i) {
        scanf("%d%d%d", &v1[i], &attack[i], &fluel[i]);
        --v1[i];
    }
    for (int i = 0; i < c2; ++i) {
        scanf("%d%d", &v2[i], &defend[i]);
        --v2[i];
    }
    for (int i = 0; i < c1; ++i) {
        for (int j = 0; j < c2; ++j) {
            if (dist[v1[i]][v2[j]] <= fluel[i] && defend[j] <= attack[i]) {
                g[i].push_back(j);
            }
        }
    }
    int mx = 0;
    memset(p, -1, sizeof(p));
    for (int run = 1; run; ) {
        run = 0;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < c1; ++i) {
            if (!take[i] && dfs(i)) {
                ++mx;
                take[i] = 1;
                run = 1;
            }
        }
    }
    long long ans = 1LL * mx * k;
    for (int i = 0; i < mx; ++i) {
        ans = min(ans, 1LL * i * k + 1LL * (c1 - i) * h);
    }
    printf("%I64d\n", ans);
    return 0;
}