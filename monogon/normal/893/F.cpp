
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// for each node store the answer for its k-blocked tree
// sum of all nodes in subtree with depth <= val
// go by increasing val, update segment tree
// answer to query is subtree min
// but we must answer online, so use persistent segment tree
// point updates, range queries
// minimum value queries

struct node {
    int val, le, ri;
    node(): val(1e9 + 5), le(0), ri(0) {}
    // node(int val): val(val), le(0), ri(0) {}
};

const int N = 1e5 + 5;
int n, r, m, p, q, u, v, a[N], depth[N], root[N], tin[N], tout[N], ti = 1;
vi adj[N];
bool vis[N];
vector<node> tree;

void dfs(int x) {
    vis[x] = true;
    tin[x] = ti++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = 1 + depth[x];
            dfs(y);
        }
    }
    tout[x] = ti;
}

int build(int l, int r) {
    int k = sz(tree);
    tree.emplace_back();
    if(l < r) {
        int m = (l + r) / 2;
        tree[k].le = build(l, m);
        tree[k].ri = build(m + 1, r);
        tree[k].val = min(tree[tree[k].le].val, tree[tree[k].ri].val);
    }
    return k;
}
int upd(int i, int l, int r, int idx, int x) {
    int k = sz(tree);
    tree.emplace_back();
    if(l < r) {
        int m = (l + r) / 2;
        if(idx <= m) {
            tree[k].le = upd(tree[i].le, l, m, idx, x);
            tree[k].ri = tree[i].ri;
        }else {
            tree[k].le = tree[i].le;
            tree[k].ri = upd(tree[i].ri, m + 1, r, idx, x);
        }
        tree[k].val = min(tree[tree[k].le].val, tree[tree[k].ri].val);
    }else {
        tree[k].val = x;
    }
    return k;
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 1e9 + 5;
    if(L <= l && r <= R) return tree[i].val;
    int m = (l + r) / 2;
    return min(query(tree[i].le, l, m, L, R), query(tree[i].ri, m + 1, r, L, R));
}

// void printtree(int root) {
//     rep(i, 1, n + 1) {
//         cout << query(root, 1, n, i, i) << ' ';
//     }
//     cout << endl;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);
    vector<pii> ve;
    rep(i, 1, n + 1) {
        ve.emplace_back(depth[i], i);
    }
    sort(all(ve));
    root[0] = build(1, n);
    int prevdepth = 0;
    for(auto &p : ve) {
        int u = p.second;
        root[depth[u]] = upd(root[prevdepth], 1, n, tin[u], a[u]);
        prevdepth = depth[u];
    }
    cin >> m;
    int last = 0;
    while(m--) {
        cin >> p >> q;
        int x = 1 + ((p + last) % n);
        int k = (q + last) % n;
        last = query(root[min(prevdepth, depth[x] + k)], 1, n, tin[x], tout[x] - 1);
        cout << last << '\n';
    }
}