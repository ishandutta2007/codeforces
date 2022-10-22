#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n;
vec< int > g[N];
double res = 0.0;

void dfs(int v, int l, double M, int par = -1) {
    int d = (int)g[v].size() - (par != -1);
    if(!d) res += M;
    for(int to : g[v]) {
        if(to == par) continue;
        if(l > 0) {
            dfs(to, l + 1, M * (l + 1) / (l * d), v);
        }else {
            dfs(to, l + 1, 1.0 / d, v);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    printf("%.10lf\n", res);

    return 0;
}