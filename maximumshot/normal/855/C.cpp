#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int const N = 1e5 + 5;

int n, m;
vec< int > g[N];
int k, x;
int dp[N][3][11];

void dfs(int v, int par = -1) {
    dp[v][0][0] = k - 1;
    dp[v][1][1] = 1;
    dp[v][2][0] = m - k;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        int nxt[3][11];
        for(int i = 0;i < 3;i++) {
            memset(nxt[i], 0, sizeof(int) * (x + 1));
        }
        for(int j = 0;j <= x;j++) {
            for(int tmp, j2 = 0;j + j2 <= x;j2++) {
                tmp = Sum( Sum(dp[to][0][j2], dp[to][1][j2]), dp[to][2][j2] );
                nxt[0][j + j2] = Sum(nxt[0][j + j2], Mul(tmp, dp[v][0][j]));
                tmp = dp[to][0][j2];
                nxt[1][j + j2] = Sum(nxt[1][j + j2], Mul(tmp, dp[v][1][j]));
                tmp = Sum(dp[to][0][j2], dp[to][2][j2]);
                nxt[2][j + j2] = Sum(nxt[2][j + j2], Mul(tmp, dp[v][2][j]));
            }
        }
        for(int i = 0;i < 3;i++) {
            memcpy(dp[v][i], nxt[i], sizeof(int) * (x + 1));
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#else
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    scanf("%d %d", &k, &x);

    dfs(1);

//    for(int v = 1;v <= n;v++) {
//        cout << v << " !\n";
//        for(int i = 0;i < 3;i++) {
//            for(int j = 0;j <= x;j++) {
//                cout << dp[v][i][j] << " ";
//            }
//            cout << "\n";
//        }
//    }

    int res = 0;

    for(int j = 0;j <= x;j++) {
        res = Sum(res, dp[1][0][j]);
        res = Sum(res, dp[1][1][j]);
        res = Sum(res, dp[1][2][j]);
    }

    printf("%d\n", res);

    return 0;
}