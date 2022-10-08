
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

const int N = 2e5 + 5;
int n, q, tin[N], tout[N], depth[N], par[N][20], lazy[4 * N], ti = 1;
vi adj[N];

void dfs(int x, int p) {
    par[x][0] = p;
    tin[x] = ti++;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            dfs(y, x);
        }
    }
    tout[x] = ti;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

struct node {
    int val, cnt;
    node(int val = 0, int cnt = 0) : val(val), cnt(cnt) {}
    node operator+(const node &o) const {
        if(val == o.val) {
            return node(val, cnt + o.cnt);
        }
        return val > o.val ? *this : o;
    }
};

node tree[4 * N];

void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i].val += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = node(0, 1);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] +  tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int lift(int x, int amt) {
    rep(l, 0, 20) {
        if((amt >> l) & 1) {
            x = par[x][l];
        }
    }
    return x;
}

void solve(int x, int y, int ef) {
    if(anc(x, y)) {
        y = lift(y, depth[y] - depth[x] - 1);
        upd(0, 1, n, 1, n, ef);
        upd(0, 1, n, tin[y], tout[y] - 1, -ef);
    }else {
        upd(0, 1, n, tin[x], tout[x] - 1, ef);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    build(0, 1, n);
    set<pii> se;
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        int ef = 1;
        if(se.count({u, v})) {
            ef = -1;
            se.erase({u, v});
        }else {
            se.emplace(u, v);
        }
        solve(u, v, ef);
        solve(v, u, ef);
        node ans = query(0, 1, n, 1, n);
        if(ans.val == sz(se)) {
            cout << ans.cnt << '\n';
        }else {
            cout << 0 << '\n';
        }
    }
}