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

const int N = 5e5 + 5;
const ll mod = inf + 7;

ll binpow(ll x, ll p) {
    ll res = 1;
    ll tmp = x;
    while(p > 0) {
        if(p & 1ll) {
            res = (res * tmp) % mod;
        }
        p >>= 1;
        tmp = (tmp * tmp) % mod;
    }
    return res;
}

int n, m, k;
ll c[N];
int par[N];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%lld", &c[i]);
    }

    vec< pair< ll, pii > > edge;

    for(int u, v, i = 1;i <= m;i++) {
        scanf("%d %d", &u, &v);
        edge.push_back({c[u] ^ c[v], {u, v}});
    }

    sort(ALL(edge));

    ll res = 0;
    ll diff = 0;

    for(int I = 0;I < m;I++) {
        int J = I;
        set< int > vs;
        while(J < m && edge[I].first == edge[J].first) {
            vs.insert(edge[J].second.first);
            vs.insert(edge[J].second.second);
            J++;
        }
        J--;
        ll add = binpow(2, n - (int)vs.size());
        for(int v : vs) par[v] = v;
        for(int iter = I;iter <= J;iter++) {
            int u, v;
            tie(u, v) = edge[iter].second;
            int pu = find(u);
            int pv = find(v);
            if(pu != pv) {
                par[pu] = pv;
            }
        }
        for(int v : vs) {
            if(par[v] == v) {
                add += add;
                if(add >= mod) add -= mod;
            }
        }
        I = J;
        res += add;
        if(res >= mod) res -= mod;
        diff++;
    }

    res += binpow(2, n) * (((1ll << k) - diff) % mod) % mod;
    if(res >= mod) res -= mod;

    printf("%d\n", int(res));

    return 0;
}