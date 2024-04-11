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
const int LOG = 30;
const int N = 1e5 + 5;
const int X = 1e7 + 5;

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = (1ll * res * tmp) % mod;
        }
        pw >>= 1;
        tmp = (1ll * tmp * tmp) % mod;
    }
    return res;
}

vec< pii > fct[X];
int prime[X];
int last[X];

void assgn(int value) {
    int x = value;
    while(x > 1) {
        int y = last[x];
        int cnt = 0;
        while(x % y == 0) {
            x /= y;
            cnt++;
        }
        fct[value].push_back({y, cnt});
    }
}

const vec< pii > & get_fct(int value) {
    if(fct[value].empty()) assgn(value);
    return fct[value];
}

void precalc() {
    fill(prime, prime + X, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i * i < X;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < X;j += i) prime[j] = 0;
    }
    for(int p = 2;p < X;p++) {
        if(!prime[p]) continue;
        for(int x = p;x < X;x += p) {
            last[x] = p;
        }
    }
}

int n, q;
vec< int > g[N];
int a[N];
int res[N];

vec< pii > query[LOG][N];
int from[N];
int used[N];
int sz[N];
int depth[N];
int DEL[N];

void calc(int v, int par = -1) {
    sz[v] = 1;
    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        calc(to, v);
        sz[v] += sz[to];
    }
}

void find_centroid(int v, int par, int &centroid, int Size) {
    int mx = Size - sz[v];
    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        find_centroid(to, v, centroid, Size);
        if(centroid) return;
        if(mx < sz[to]) mx = sz[to];
    }
    if((mx << 1) <= Size) {
        centroid = v;
    }
}

void build(int v, int _from, int lvl) {
    calc(v);
    int centroid = 0;
    find_centroid(v, -1, centroid, sz[v]);
    from[centroid] = _from;
    depth[centroid] = lvl;
    used[centroid] = 1;
    for(int to : g[centroid]) {
        if(used[to]) continue;
        build(to, centroid, lvl + 1);
    }
}

int find_lca(int x, int y) {
    while(x != y) {
        if(depth[x] > depth[y]) {
            x = from[x];
        }else {
            y = from[y];
        }
    }
    return x;
}

unordered_map< int, int > CNT[LOG];

void add(int value, int type) {
    const vec< pii > &ar = get_fct(value);
//    cout << value << " : ";
    for(const pii &pr : ar) {
//        cout << "(" << pr.first << ", " << pr.second << ") ";
        CNT[pr.second][pr.first] += type;
    }
//    cout << "\n";
}

void go(int v, int par, int lvl) {
    add(a[v], +1);

    for(pii qq : query[lvl][v]) {
        int x, id;
        tie(x, id) = qq;

        const vec< pii > &ar = get_fct(x);

//        cout << v << ", " << lvl << ", x = " << x << ", id = " << id << "\n";

        for(const pii &pr : ar) {
            int P, C;
            tie(P, C) = pr;
            int pw = 0;
            for(int j = 0;j <= C;j++) {
                pw += CNT[j][P] * j;
            }
            for(int j = C + 1;j < LOG;j++) {
                pw += CNT[j][P] * C;
            }
//            cout << "------ " << C << " -- " << P << " ** " << pw << "\n";
            res[id] = (1ll * res[id] * _binpow(P, pw)) % mod;
        }

    }

    for(int to : g[v]) {
        if(used[to] || to == par) continue;
        go(to, v, lvl);
    }

    add(a[v], -1);
}

void solve(int v, int _from, int lvl) {
    calc(v);
    int centroid = 0;
    find_centroid(v, -1, centroid, sz[v]);
    used[centroid] = 1;
    go(centroid, -1, lvl);
    for(int to : g[centroid]) {
        if(used[to]) continue;
        solve(to, centroid, lvl + 1);
    }
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    build(1, 0, 0);

//    for(int v = 1;v <= n;v++) {
//        cout << v << " : " << depth[v] << " " << from[v] << "\n";
//    }

    scanf("%d", &q);


    for(int u, v, x, iter = 0;iter < q;iter++) {
        res[iter] = 1;
        scanf("%d %d %d", &u, &v, &x);
        int w = find_lca(u, v);
//        cout << u << " " << v << " " << w << " !\n";
        query[ depth[w] ][u].push_back({x, iter});
        query[ depth[w] ][v].push_back({x, iter});
        DEL[iter] = __gcd(a[w], x);
    }

    fill(used + 1, used + n + 1, 0);
    solve(1, 0, 0);

    for(int iter = 0;iter < q;iter++) {
        printf("%d\n", (1ll * res[iter] * _binpow(DEL[iter], mod - 2)) % mod);
    }

    return 0;
}