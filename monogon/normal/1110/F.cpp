
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 5e5 + 5;
ll tree[4 * N], z[4 * N];

void build(int i, int l, int r, const vector<ll> &w) {
    if(l == r) {
        tree[i] = w[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, w);
    build(2 * i + 2, m + 1, r, w);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

ll get(int i) {
    return tree[i] == LLONG_MAX ? tree[i] : tree[i] + z[i];
}
void prop(int i, int l, int r) {
    if(z[i] == 0) return;
    if(tree[i] != LLONG_MAX) {
        tree[i] += z[i];
    }
    if(l < r) {
        z[2 * i + 1] += z[i];
        z[2 * i + 2] += z[i];
    }
    z[i] = 0;
}

ll getmin(int i, int l, int r, int L, int R) {
    if(r < L || R < l || L > R) return LLONG_MAX;
    if(L <= l && r <= R) return get(i);
    prop(i, l, r);
    int m = (l + r) / 2;
    return min(getmin(2 * i + 1, l, m, L, R), getmin(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int L, int R, ll x) {
    if(r < L || R < l || L > R) return;
    if(L <= l && r <= R) {
        z[i] += x;
        return;
    }
    prop(i, l, r);
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = min(get(2 * i + 1), get(2 * i + 2));
}
void print(int n) {
    rep(i, 1, n + 1) {
        cout << getmin(0, 1, n, i, i) << ' ';
    }
    cout << '\n';
}

struct query {
    int l, r, i;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> w(n + 1);
    vi p(n + 1);
    p[1] = 1;
    vector<vi> g(n + 1);
    rep(i, 2, n + 1) {
        cin >> p[i] >> w[i];
        g[p[i]].push_back(i);
    }
    vi tin(n + 1), tout(n + 1);
    int ti = 1;
    auto dfs = [&](auto dfs, int x) -> void {
        tin[x] = ti++;
        for(int y : g[x]) {
            w[y] += w[x];
            dfs(dfs, y);
        }
        tout[x] = ti;
    };
    dfs(dfs, 1);
    vector<ll> w2(n + 1);
    rep(i, 1, n + 1) {
        if(!g[i].empty()) w2[tin[i]] = LLONG_MAX;
        else w2[tin[i]] = w[i];
    }
    build(0, 1, n, w2);
    vector<ll> ans(q);
    vector<vector<query>> qu(n + 1);
    rep(i, 0, q) {
        int v, l, r;
        cin >> v >> l >> r;
        qu[v].push_back({l, r, i});
    }
    auto dfs2 = [&](auto dfs2, int x) -> void {
        int l = tin[x], r = tout[x] - 1;
        upd(0, 1, n, l, r, -2 * (w[x] - w[p[x]]));
        for(auto &Q : qu[x]) {
            ans[Q.i] = w[x] + getmin(0, 1, n, Q.l, Q.r);
        }
        for(int y : g[x]) {
            dfs2(dfs2, y);
        }
        upd(0, 1, n, l, r, 2 * (w[x] - w[p[x]]));
    };
    dfs2(dfs2, 1);
    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
}