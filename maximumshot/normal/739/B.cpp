#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n;
int a[N];
vec< pii > g[N];

// sum[u] - sum[v] <= a[u]
// sum[u] - a[u] <= sum[v]

int euler[2 * N];
int tin[N];
int tout[N];
int timer = 0;
ll sum[N];

void dfs(int v, int pw = 0, int par = -1) {
    if(par == -1) {
        sum[v] = 0;
    }else {
        sum[v] = sum[par] + pw;
    }
    tin[v] = timer;
    euler[timer++] = v;
    for(auto iter : g[v]) {
        if(iter.first == par) continue;
        dfs(iter.first, iter.second, v);
    }
    tout[v] = timer;
    euler[timer++] = v;
}

vec< ll > tree[8 * N];

void merge(int v) {
    int ls = (int)tree[v * 2 + 1].size();
    int rs = (int)tree[v * 2 + 2].size();
    int i = 0, j = 0;
    while(i < ls && j < rs) {
        if(tree[v * 2 + 1][i] < tree[v * 2 + 2][j]) {
            tree[v].push_back(tree[v * 2 + 1][i++]);
        }else {
            tree[v].push_back(tree[v * 2 + 2][j++]);
        }
    }
    while(i < ls) tree[v].push_back(tree[v * 2 + 1][i++]);
    while(j < rs) tree[v].push_back(tree[v * 2 + 2][j++]);
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].push_back(sum[euler[tl]] - a[euler[tl]]);
    }else {
        int tm = (tl + tr) >> 1;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        merge(v);
    }
}

int get(int v, int tl, int tr, int l, int r, ll value) {
    if(l <= tl && tr <= r) {
        return upper_bound(ALL(tree[v]), value) - tree[v].begin();
    }else {
        int tm = (tl + tr) >> 1, res = 0;
        if(l <= tm) res += get(v * 2 + 1, tl, tm, l, r, value);
        if(r > tm) res += get(v * 2 + 2, tm + 1, tr, l, r, value);
        return res;
    }
}

int get(int l, int r, ll value) {
    if(l > r) return 0;
    return get(0, 0, 2 * n - 1, l, r, value);
}

int result[N];

void go(int v, int par = -1) {
    result[v] = get(tin[v] + 1, tout[v] - 1, sum[v]);
    for(auto iter : g[v]) {
        if(iter.first != par) {
            go(iter.first, v);
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    for(int par, we, i = 2;i <= n;i++) {
        scanf("%d %d", &par, &we);
        g[i].push_back({par, we});
        g[par].push_back({i, we});
    }

    dfs(1);

    build(0, 0, 2 * n - 1);

    go(1);

    for(int i = 1;i <= n;i++) {
        printf("%d ", result[i] / 2);
    }

    printf("\n");

    return 0;
}