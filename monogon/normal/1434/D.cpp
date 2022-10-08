
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
int n;
vector<pii> adj[N];
int u[N], v[N], col[2][N], depth[2][N], tin[2][N], tout[2][N], tinv[2][N], ti = 0;
pii tree[2][4 * N];
bool lazy[2][4 * N];

void dfs(int x, int p) {
    for(auto &pa : adj[x]) {
        int y, t;
        tie(y, t) = pa;
        if(y != p) {
            depth[0][y] = depth[0][x] + 1;
            dfs(y, x);
        }
    }
}

void dfs2(int x, int p, bool b) {
    tin[b][x] = ti++;
    tinv[b][tin[b][x]] = x;
    for(auto &pa : adj[x]) {
        int y, t;
        tie(y, t) = pa;
        if(y != p) {
            depth[b][y] = depth[b][x] + 1;
            col[b][y] = col[b][x] ^ t;
            dfs2(y, x, b);
        }
    }
    tout[b][x] = ti;
}

pii add(pii a, pii b) {
    return {max(a.first, b.first), max(a.second, b.second)};
}

void build(bool b, int i, int l, int r) {
    if(l == r) {
        if(col[b][tinv[b][l]] == 0) tree[b][i] = {depth[b][tinv[b][l]], 0};
        else tree[b][i] = {0, depth[b][tinv[b][l]]};
        return;
    }
    int m = (l + r) / 2;
    build(b, 2 * i + 1, l, m);
    build(b, 2 * i + 2, m + 1, r);
    tree[b][i] = add(tree[b][2 * i + 1], tree[b][2 * i + 2]);
}
void prop(bool b, int i, int l, int r) {
    if(!lazy[b][i]) return;
    lazy[b][i] = false;
    tree[b][i] = {tree[b][i].second, tree[b][i].first};
    if(l < r) {
        lazy[b][2 * i + 1] ^= 1;
        lazy[b][2 * i + 2] ^= 1;
    }
}
void upd(bool b, int i, int l, int r, int L, int R) {
    prop(b, i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[b][i] ^= 1;
        prop(b, i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(b, 2 * i + 1, l, m, L, R);
    upd(b, 2 * i + 2, m + 1, r, L, R);
    tree[b][i] = add(tree[b][2 * i + 1], tree[b][2 * i + 2]);
}
pii query(bool b, int i, int l, int r, int L, int R) {
    if(r < L || R < l) return {0, 0};
    prop(b, i, l, r);
    if(L <= l && r <= R) return tree[b][i];
    int m = (l + r) / 2;
    return add(query(b, 2 * i + 1, l, m, L, R), query(b, 2 * i + 2, m + 1, r, L, R));
}

void printtree(bool b) {
    rep(i, 0, n) {
        pii pa = query(b, 0, 0, n - 1, i, i);
        cout << "(" << pa.first << ", " << pa.second << ") ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) {
        int t;
        cin >> u[i] >> v[i] >> t;
        adj[u[i]].emplace_back(v[i], t);
        adj[v[i]].emplace_back(u[i], t);
    }
    dfs(1, -1);
    int r1 = max_element(depth[0] + 1, depth[0] + n + 1) - depth[0];
    fill(depth[0], depth[0] + N, 0);
    dfs(r1, -1);
    int r2 = max_element(depth[0] + 1, depth[0] + n + 1) - depth[0];
    fill(depth[0], depth[0] + N, 0);

    dfs2(r1, -1, 0);
    ti = 0;
    dfs2(r2, -1, 1);
    build(0, 0, 0, n - 1);
    build(1, 0, 0, n - 1);

    // rep(i, 1, n + 1) {
    //     cout << i << ": " << depth[0][i] << endl;
    // }
    // printtree(1);

    int q;
    cin >> q;
    while(q--) {
        int e;
        cin >> e;
        int x = u[e];
        if(depth[0][u[e]] < depth[0][v[e]]) {
            x = v[e];
        }
        // update tree1
        upd(0, 0, 0, n - 1, tin[0][x], tout[0][x] - 1);
        int ans = query(0, 0, 0, n - 1, 0, n - 1).first;
        // printtree(0);
        x = u[e];
        if(depth[1][u[e]] < depth[1][v[e]]) {
            x = v[e];
        }
        // update tree2
        upd(1, 0, 0, n - 1, tin[1][x], tout[1][x] - 1);
        ans = max(ans, query(1, 0, 0, n - 1, 0, n - 1).first);
        // printtree(1);
        cout << ans << '\n';
    }
}