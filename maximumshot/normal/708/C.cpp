#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n;
vec< vec< int > > g;

vec< int > cn, dp;

void dfs(int v, int par = -1) {
    cn[v] = 1;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        cn[v] += cn[to];
    }
    if(cn[v] == 1) dp[v] = 1;
    if(cn[v] <= n / 2) dp[v] = cn[v];
    for(int to : g[v]) {
        if(to == par) continue;
        dp[v] = max(dp[v], dp[to]);
        if(cn[to] <= n / 2) dp[v] = max(dp[v], cn[to]);
    }
}

vec< int > ans;

void go(int v, int dp_par = 0, int par = -1) {
    int mx = n - cn[v];
    for(int to : g[v]) {
        if(to == par) continue;
        mx = max(mx, cn[to]);
    }
    if(mx <= n / 2) {
        ans[v] = 1;
    }else {
        if(n - cn[v] > n / 2) {
            if(n - cn[v] - dp_par <= n / 2)
                ans[v] = 1;
        }
        for(int to : g[v]) {
            if(to == par) continue;
            if(cn[to] > n / 2) {
                if(cn[to] - dp[to] <= n / 2)
                    ans[v] = 1;
            }
        }
    }
    int sz = (int)g[v].size();

    vec< int > pr(sz), sf(sz);

    for(int i = 0;i < sz;i++) {
        int to = g[v][i];
        if(i > 0) pr[i] = pr[i - 1];
        if(g[v][i] == par) continue;
        pr[i] = max(pr[i], dp[to]);
        if(cn[to] <= n / 2) pr[i] = max(pr[i], cn[to]);
    }

    for(int i = sz - 1;i >= 0;i--) {
        int to = g[v][i];
        if(i + 1 < sz) sf[i] = sf[i + 1];
        if(to == par) continue;
        sf[i] = max(sf[i], dp[to]);
        if(cn[to] <= n / 2) sf[i] = max(sf[i], cn[to]);
    }

    for(int i = 0;i < sz;i++) {
        int to = g[v][i];
        if(to == par) continue;
        mx = 1;
        if(n - cn[to] <= n / 2) mx = max(mx, n - cn[to]);
        mx = max(mx, dp_par);
        if(n - cn[v] <= n / 2) mx = max(mx, n - cn[v]);
        if(i > 0) mx = max(mx, pr[i - 1]);
        if(i + 1 < sz) mx = max(mx, sf[i + 1]);
        go(to, mx, v);
    }
}

bool solve() {

    scanf("%d", &n);

    g.resize(n + 1);

    for(int u, v, i = 0;i < n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cn.resize(n + 1);
    dp.resize(n + 1);

    dfs(1);

    ans.resize(n + 1);

    go(1);

    for(int i = 1;i <= n;i++)
        printf("%d ", ans[i]);
    printf("\n");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}