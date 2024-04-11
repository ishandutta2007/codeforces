#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

int n;
vec< int > g[N];
int c[N];
bool good[N];
int global_c[N];

int dfs(int v, int par = -1) {
    int res = c[v];
    good[v] = 1;
    for(int to : g[v]) {
        if(to == par) continue;
        int to_res = dfs(to, v);
        if(to_res == -1) good[v] = 0, res = -1;
        else if(to_res != res) res = -1;
    }
    return global_c[v] = res;
}

void go(int v, int par = -1, int par_res = -1) {
    if(good[v] && (par == -1 || par_res != -1) ) {
        printf("YES\n%d\n", v);
        exit(0);
    }
    if(par != -1) {
        if(par_res != c[v]) {
            return;
        }
    }else {
        par_res = c[v];
    }
    int tot = 0;
    int child = 0;
    for(int to : g[v]) {
        if(to == par) continue;
        child++;
        if(global_c[to] == par_res) tot++;
    }
    for(int to : g[v]) {
        if(to == par) continue;
        if(global_c[to] == par_res) tot--;
        if(tot == child - 1) go(to, v, par_res);
        if(global_c[to] == par_res) tot++;
    }
}

int main() {

    scanf("%d", &n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &c[i]);
    }

    dfs(1);
    go(1);

    printf("NO\n");

    return 0;
}