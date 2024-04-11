#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 4e5 + 5;

int n, q;
pair< pii, int > edge[N];
vec< pii > g[N];
ll S[N];
int tin[N];
int tout[N];
ll toRoot[N];
int euler[2 * N];

void dfs(int v, int par = -1) {
    static int timer = 0;
    euler[timer] = v;
    tin[v] = timer++;
    for(pii iter : g[v]) {
        int to, w;
        tie(to, w) = iter;
        if(to == par) continue;
        S[to] = S[v] + w;
        dfs(to, v);
    }
    euler[timer] = v;
    tout[v] = timer++;
}

ll tree[8 * N];
ll delt[8 * N];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = S[euler[tl]] + toRoot[euler[tl]];
    }else {
        int tm = (tl + tr) / 2;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

void push(int v) {
    if(delt[v]) {
        delt[v * 2 + 1] += delt[v];
        delt[v * 2 + 2] += delt[v];
        tree[v * 2 + 1] += delt[v];
        tree[v * 2 + 2] += delt[v];
        delt[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if(l <= tl && tr <= r) {
        delt[v] += x;
        tree[v] += x;
    }else {
        int tm = (tl + tr) / 2;
        push(v);
        if(l <= tm) update(v * 2 + 1, tl, tm, l, r, x);
        if(r > tm) update(v * 2 + 2, tm + 1, tr, l, r, x);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

ll get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return tree[v];
    }else {
        int tm = (tl + tr) / 2;
        ll res = inf64;
        push(v);
        if(l <= tm) res = min(res, get(v * 2 + 1, tl, tm, l, r));
        if(r > tm) res = min(res, get(v * 2 + 2, tm + 1, tr, l, r));
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
        return res;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int u, v, w, i = 1;i <= 2 * n - 2;i++) {
        scanf("%d %d %d", &u, &v, &w);
        edge[i] = make_pair(make_pair(u, v), w);
        if(i <= n - 1) {
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }else {
            toRoot[u] = w;
        }
    }

    dfs(1);

    build(0, 0, 2 * n - 1);

    ll res;

    for(int i, u, v, w, type, iter = 0;iter < q;iter++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d %d", &i, &w);
            if(i <= n - 1) {
                tie(u, v) = edge[i].first;
                update(0, 0, 2 * n - 1, tin[v], tout[v], w - edge[i].second);
            }else {
                u = edge[i].first.first;
                update(0, 0, 2 * n - 1, tin[u], tin[u], w - edge[i].second);
                update(0, 0, 2 * n - 1, tout[u], tout[u], w - edge[i].second);
                toRoot[u] = w;
            }
            edge[i].second = w;
        }else {
            scanf("%d %d", &u, &v);
            if(tin[u] <= tin[v] && tout[v] <= tout[u]) {
                res = get(0, 0, 2 * n - 1, tin[v], tin[v]) - get(0, 0, 2 * n - 1, tin[u], tin[u]) -
                        toRoot[v] + toRoot[u];
            }else {
                res = get(0, 0, 2 * n - 1, tin[u], tout[u]) - get(0, 0, 2 * n - 1, tin[u], tin[u]) + toRoot[u] +
                        get(0, 0, 2 * n - 1, tin[v], tin[v]) - toRoot[v];
            }
#ifdef debug
            printf("%lld\n", res);
#else
            printf("%I64d\n", res);
#endif
        }
    }

    return 0;
}