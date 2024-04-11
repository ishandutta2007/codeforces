#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

vector< int > dv[N];
int prime[N];
int n;
int a[N];
vector< int > g[N];

void precalc() {
    fill(prime, prime + N, 1);
    prime[0] = prime[1] = 0;
    for(int p = 2;p * p < N;p++) {
        if(!prime[p]) continue;
        for(int x = p * p;x < N;x += p) {
            prime[x] = 0;
        }
    }
    for(int p = 2;p < N;p++) {
        if(!prime[p]) continue;
        for(int x = p;x < N;x += p) {
            dv[x].push_back(p);
        }
    }
}

int used[N];
int sz[N];

void go(int v, int par = -1) {
    sz[v] = 1;
    for(int to : g[v]) {
        if(to == par || used[to]) continue;
        go(to, v);
        sz[v] += sz[to];
    }
}

void fnd(int v, int &centroid, int Size, int par = -1) {
    int mx = Size - sz[v];
    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        fnd(to, centroid, Size, v);
        if(centroid != -1) return;
        if(mx < sz[to]) mx = sz[to];
    }
    if((mx << 1) <= Size) {
        centroid = v;
    }
}

int mem[N], res;
unordered_set< int > vals;

void update_mem(int dist, int GCD) {
    for(int p : dv[GCD]) {
        vals.insert(p);
        mem[p] = max(mem[p], dist);
    }
}

void upd(int v, int dist, int GCD, int par = -1) {
    for(int p : dv[GCD]) {
        res = max(res, dist + mem[p] - 1);
    }
    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        upd(to, dist + 1, __gcd(GCD, a[to]), v);
    }
}

void asgn(int v, int dist, int GCD, int par = -1) {
    update_mem(dist, GCD);
    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        asgn(to, dist + 1, __gcd(GCD, a[to]), v);
    }
}

void solve(int v) {
    go(v);
    int centroid = -1;
    int Size = sz[v];
    fnd(v, centroid, Size);

    used[centroid] = 1;
    update_mem(1, a[v]);

    for(int to : g[centroid]) {
        if(used[to]) continue;
        upd(to, 2, __gcd(a[centroid], a[to]), centroid);
        asgn(to, 2, __gcd(a[centroid], a[to]), centroid);
    }

    for(int p : vals) {
        mem[p] = 0;
    }

    vals.clear();

    for(int to : g[centroid]) {
        if(used[to]) continue;
        solve(to);
    }
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int v = 1;v <= n;v++) {
        cin >> a[v];
        if(a[v] > 1) {
            res = 1;
        }
    }

    for(int u, v, i = 1;i < n;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(1);

    printf("%d\n", res);

    return 0;
}