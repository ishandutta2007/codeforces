#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

const ll INF = (ll)1e18;

struct node{
    ll sum_pref;
    ll sum_suf;
    ll max_sum;
    ll total_sum;
    node() : sum_pref(-INF), sum_suf(-INF), max_sum(-INF), total_sum(-INF) {};
};

int n, m;
ll c;
const int maxN = 1.5 * (int)1e5 + 100;
ll x[maxN];
int prob[maxN];
ll d[maxN], f[maxN];
node t[4 * maxN];

node unite(node a, node b) {
    if (a.max_sum == -INF) return b;
    if (b.max_sum == -INF) return a;
    node c;
    c.total_sum = a.total_sum + b.total_sum;
    c.max_sum = max({a.max_sum, b.max_sum, a.sum_suf + b.sum_pref});
    c.sum_pref = max(a.sum_pref, a.total_sum + b.sum_pref);
    c.sum_suf = max(b.sum_suf, b.total_sum + a.sum_suf);
    return c;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].total_sum = d[tl];
        t[v].sum_pref = max(0LL, d[tl]);
        t[v].sum_suf = max(0LL, d[tl]);
        t[v].max_sum = max(0LL, d[tl]);
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = unite(t[v + v], t[v + v + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
    if (l > r) return node();
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return unite(get(v + v, tl, tm, l, min(tm, r)), get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] *= 100;
    }

    for (int i = 1; i < n; i++) {
        cin >> prob[i];
        d[i] = (x[i + 1] - x[i]) - prob[i] * c * 2;
    }
    n--;

    build(1, 1, n);
    ll total_profit = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        total_profit += get(1, 1, n, a, b).max_sum;
    }
    cout << fixed << setprecision(10) << (1.0 * total_profit / 200);
    return 0;
}