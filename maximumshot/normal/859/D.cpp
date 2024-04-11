#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100;

int n;
double p[N][N];
double dp[N][10];
vec< int > mas[10];

vec< int > build(int tl, int tr, int round) {
    if(tl == tr) {
        dp[tl][round] = 1.0;
        mas[round].push_back(tl);
        return vec< int >(1, tl);
    }
    int tm = (tl + tr) >> 1;
    vec< int > le = build(tl, tm, round - 1);
    vec< int > ri = build(tm + 1, tr, round - 1);
    vec< int > res = le;
    for(int x : ri) res.push_back(x);
    for(int x : le) {
        double sm = 0;
        for(int y : ri) {
            sm += dp[y][round - 1] * p[x][y];
        }
        dp[x][round] = sm * dp[x][round - 1];
    }
    for(int y : ri) {
        double sm = 0;
        for(int x : le) {
            sm += dp[x][round - 1] * p[y][x];
        }
        dp[y][round] = sm * dp[y][round - 1];
    }
    for(int x : res) mas[round].push_back(x);
    return res;
}

double f[4 * N][N];
double tmp[10][N];

void dfs(int v, int tl, int tr, int round) {
    if(tl + 1 == tr) {
        f[v][tl] = dp[tl][round];
        f[v][tr] = dp[tr][round];
        tmp[round][tl] = f[v][tl];
        tmp[round][tr] = f[v][tr];
        return;
    }
    int tm = (tl + tr) >> 1;
    dfs(v << 1, tl, tm, round - 1);
    dfs(v << 1 | 1, tm + 1, tr, round - 1);
    for(int x = tl;x <= tm;x++) {
        for(int y = tm + 1;y <= tr;y++) {
            f[v][x] = max(f[v][x], f[v << 1][x] + f[v << 1 | 1][y] + dp[x][round] * (1 << (round - 1)));
            f[v][y] = max(f[v][y], f[v << 1 | 1][y] + f[v << 1][x] + dp[y][round] * (1 << (round - 1)));
            tmp[round][x] = f[v][x];
            tmp[round][y] = f[v][y];
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= (1 << n);i++) {
        for(int x, j = 1;j <= (1 << n);j++) {
            scanf("%d", &x);
            p[i][j] = x / 100.0;
        }
    }

    vec< int > arr = build(1, 1 << n, n);

    dfs(1, 1, 1 << n, n);

    double res = 0;

    for(int x = 1;x <= (1 << n);x++) {
        res = max(res, f[1][x]);
    }

    printf("%.10lf\n", res);

    return 0;
}