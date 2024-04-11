#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n, m, k;
vec< int > g[N];
bool used[N];
int way[2 * N];
int sz = 0;

void dfs(int v) {
    used[v] = 1;
    way[sz++] = v;
    for(int to : g[v]) {
        if(used[to]) continue;
        dfs(to);
        way[sz++] = v;
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    sz = unique(way, way + sz) - way;

    int ln = (sz + k - 1) / k;

    for(int j = 0, i = 0;i < k;i++) {
        int c = min(ln, sz - j);
        if(c > 0) {
            printf("%d ", min(ln, sz - j));
            for(int it = 0;it < ln && j < sz;it++, j++) {
                printf("%d ", way[j]);
            }
            printf("\n");
        }else {
            printf("1 1\n");
        }
    }

    return 0;
}