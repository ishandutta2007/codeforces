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

int const N = 2e5 + 5;

vec< int > dv[N];

void prepare() {
    for(int i = 1;i < N;i++) {
        for(int j = i;j < N;j += i) {
            dv[j].push_back(i);
        }
    }
}

int cnt[N];

inline void chg(int x, int k) {
    for(int y : dv[x]) {
        cnt[y] += k;
    }
}

int n;
vec< int > g[N];
int res[N];
int a[N];

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

void dfs(int v, int dist = 0, int par = -1, int tot = 0) {
    res[v] = max(tot, gcd(tot, a[v]));
    chg(a[v], 1);
    for(int y : dv[a[v]]) {
        if(cnt[y] >= dist) {
            res[v] = max(res[v], y);
        }
    }
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, dist + 1, v, gcd(tot, a[v]));
    }
    chg(a[v], -1);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    prepare();

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i = 1;i <= n;i++) {
        printf("%d", res[i]);
        if(i < n) {
            printf(" ");
        }else {
            printf("\n");
        }
    }

    return 0;
}