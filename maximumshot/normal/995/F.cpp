#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

const int N = 3005;

int n, D;
int p[N];
vec< int > g[N];
int dp[N][N];
int coef[N];

void dfs(int v) {
    if(g[v].empty()) {
        for(int d = 1;d <= n + 1;d++) {
            dp[v][d] = d;
        }
        return;
    }
    for(int to : g[v]) dfs(to);
    for(int d = 1;d <= n + 1;d++) {
        if(d) dp[v][d] = dp[v][d - 1];
        int add = 1;
        for(int to : g[v]) {
            add = _mul(add, dp[to][d]);
        }
        dp[v][d] = _sum(dp[v][d], add);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &D);

    for(int v = 2;v <= n;v++) {
        scanf("%d", &p[v]);
        g[p[v]].push_back(v);
    }

    dfs(1);

    int res = 0;

    for(int i = 1;i <= n + 1;i++) {
        int add = dp[1][i], tmp = 1;
        for(int j = 1;j <= n + 1;j++) {
            if(i == j) continue;
            tmp = _mul(tmp, _sub(i, j));
        }
        add = _div(add, tmp);
        for(int j = 1;j <= n + 1;j++) {
            if(i == j) continue;
            add = _mul(add, _sub(D, j));
        }
        res = _sum(res, add);
    }

    printf("%d\n", res);

    return 0;
}