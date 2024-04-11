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

const int mod = 998244353;
const int N = 8005;

int _mul() { return 1; }

template< typename ... Args >
int _mul(int x, Args ... rest) {
    return (1ll * x * _mul(rest...)) % mod;
}

int _sum() { return 1; }

template< typename ... Args >
int _sum(int x, Args ... rest) {
    int y = _sum(rest...);
    return x + y < mod ? x + y : x + y - mod;
}

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

inline int _sub(int x, int y) {
    return x >= y ? x - y : x - y + mod;
}

inline int _binpow(int x, int p) {
    int res = 1;
    int tmp = x;
    while(p > 0) {
        if(p & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        p >>= 1;
    }
    return res;
}

int fact[N];
int rfact[N];

inline int CNK(int n, int k) {
    if(n < k) return 0;
    return _mul(fact[n], rfact[k], rfact[n - k]);
}

void precalc() {
    fact[0] = rfact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = _mul(fact[i - 1], i);
    }
    {
        int hlp = _binpow(fact[N - 1], mod - 2);
        for(int i = N - 1;i >= 0;i--) {
            rfact[i] = hlp;
            hlp = _mul(hlp, i);
        }
    }
}

struct Tree {
    int n, k;
    vec< vec< int > > g;
    vec< int > used, sz;
    vec< int > tot;
    vec< vec< int > > w[2];

    void dfs(int v, int par = -1) {
        sz[v] = 1;
        for(int to : g[v]) {
            if(to == par || used[to]) continue;
            dfs(to, v);
            sz[v] += sz[to];
        }
    }

    void fnd(int v, int Size, int &centroid, int par = -1) {
        int mx = Size - sz[v];
        for(int to : g[v]) {
            if(to == par || used[to]) continue;
            fnd(to, Size, centroid, v);
            if(centroid != -1) return;
            if(mx < sz[to]) mx = sz[to];
        }
        if((mx << 1) <= Size) {
            centroid = v;
        }
    }

    void assign_list(int v, int par, vec< int > & l) {
        l.push_back(v);
        for(int to : g[v]) {
            if(to == par || used[to]) continue;
            assign_list(to, v, l);
        }
    }

    void solve(int v) {
        dfs(v);
        int centroid = -1;
        fnd(v, sz[v], centroid);
#ifdef debug
        assert(centroid != -1);
#endif
        vec< int > ar;
        assign_list(v, -1, ar);
        for(int u : ar) w[1][u][0] = u == centroid;
        for(int ln = 0;ln < k;ln++) {
            for(int u : ar) w[1][u][ln + 1] = 0;
            for(int u : ar) {
                for(int to : g[u]) {
                    if(used[to]) continue;
                    _add(w[1][to][ln + 1], w[1][u][ln]);
                }
            }
        }
        used[centroid] = 1;
        for(int V : g[centroid]) {
            if(used[V]) continue;
            ar.clear();
            assign_list(V, centroid, ar);
            for(int u : ar) w[0][u][1] = u == V;
            for(int ln = 1;ln < k;ln++) {
                for(int u : ar) w[0][u][ln + 1] = 0;
                for(int u : ar) {
                    for(int to : g[u]) {
                        if(used[to]) continue;
                        _add(w[0][to][ln + 1], w[0][u][ln]);
                    }
                }
            }
            for(int u : ar) {
                for(int i = 1;i <= k;i++) {
                    for(int j = 1;i + j <= k;j++) {
                        _add(tot[i + j], _mul(w[0][u][i], w[1][u][j]));
                    }
                }
            }
        }
        for(int i = 0;i <= k;i++) {
            _add(tot[i], w[1][centroid][i]);
        }
        for(int V : g[centroid]) {
            if(used[V]) continue;
            solve(V);
        }
    }

    Tree(int _n, int _k): n(_n), k(_k) {
        g.resize(n + 1);
        used.resize(n + 1);
        sz.resize(n + 1);
        tot.resize(k + 1);
        for(int i = 0;i < 2;i++) w[i].resize(n + 1, vec< int >(k + 1));
        for(int u, v, i = 1;i < n;i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve(1);
    }
};

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n1, n2, k;

    cin >> n1 >> n2 >> k;

    Tree t1(n1, k), t2(n2, k);

    vec< int > &tot1 = t1.tot;
    vec< int > &tot2 = t2.tot;

//    cout << "\n";
//    for(int x : tot1) cout << x << " ";
//    cout << "\n";
//    for(int x : tot2) cout << x << " ";
//    cout << "\n";

    int res = 0;

    for(int i = 0;i <= k;i++) {
        _add(res, _mul(CNK(k, i), tot1[i], tot2[k - i]));
    }

    cout << res << "\n";

    return 0;
}