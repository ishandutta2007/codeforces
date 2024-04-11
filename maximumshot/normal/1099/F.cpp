#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const int X = 1e6;

struct Node {
    ll sum = 0, cnt = 0;
} rt[4 * (X + 5)];

Node merge(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.cnt = l.cnt + r.cnt;
    return res;
}

void update(int v, int tl, int tr, int pos, ll val) {
    if(tl == tr) {
        rt[v].cnt += val;
        rt[v].sum += pos * val;
    }else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v << 1, tl, tm, pos, val);
        else update(v << 1 | 1, tm + 1, tr, pos, val);
        rt[v] = merge(rt[v << 1], rt[v << 1 | 1]);
    }
}

ll query(int v, int tl, int tr, ll have) {
    if(have < 0) return 0;
    if(tl == tr) {
        return min(have / tl, rt[v].cnt);
    }else {
        ll res = 0;
        int tm = (tl + tr) >> 1;
        if(rt[v << 1].sum <= have) {
            return rt[v << 1].cnt +
                    query(v << 1 | 1, tm + 1, tr, have - rt[v << 1].sum);
        }else {
            return query(v << 1, tl, tm, have);
        }
    }
}

int n;
ll T;
int x[N];
int t[N];
vector< int > g[N];
int p[N];
int l[N];
ll f[N];

void dfs(int v, ll dist = 0) {
    dist += l[v];
    update(1, 1, X, t[v], +x[v]);
    f[v] = query(1, 1, X, T - 2 * dist);
    for(int to : g[v]) {
        dfs(to, dist);
    }
    update(1, 1, X, t[v], -x[v]);
}

ll dp[N];

void go(int v) {
    ll mx1 = 0, mx2 = 0;
    if(v == 1) mx1 = inf64;
    for(int to : g[v]) {
        go(to);
        if(dp[to] > mx1) {
            mx2 = mx1;
            mx1 = dp[to];
        }else if(dp[to] > mx2) {
            mx2 = dp[to];
        }
    }
    dp[v] = max(f[v], mx2);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %lld", &n, &T);

    for(int i = 1;i <= n;i++) scanf("%d", &x[i]);
    for(int i = 1;i <= n;i++) scanf("%d", &t[i]);
    for(int i = 2;i <= n;i++) {
        scanf("%d %d", &p[i], &l[i]);
        g[p[i]].push_back(i);
    }

    dfs(1);

//    for(int v = 1;v <= n;v++) {
//        cout << v << " : " << f[v] << "\n";
//    }

    go(1);

//    for(int v = 1;v <= n;v++) {
//        cout << v << " : " << dp[v] << "\n";
//    }

    printf("%lld\n", dp[1]);

    return 0;
}