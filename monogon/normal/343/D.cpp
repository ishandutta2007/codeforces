
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

// 1. most recent time emptied?
// 2. most recent time filled?

// 1 -> on empty operation, point set to time, range max query
// 2 -> on fill operation, range update, point query

const int N = 5e5 + 5;

int tree[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    lazy[i] = -1;
    if(l == r) {
        tree[i] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
int query2(int i, int l, int r, int k) {
    if(l == r) return lazy[i];
    int m = (l + r) / 2;
    if(k <= m) return max(lazy[i], query2(2 * i + 1, l, m, k));
    else return max(lazy[i], query2(2 * i + 2, m + 1, r, k));
}
void updempty(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = x;
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) updempty(2 * i + 1, l, m, k, x);
    else updempty(2 * i + 2, m + 1, r, k, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}
void updfill(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = x;
        return;
    }
    int m = (l + r) / 2;
    updfill(2 * i + 1, l, m, L, R, x);
    updfill(2 * i + 2, m + 1, r, L, R, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi tin(n + 1), tout(n + 1);
    int ti = 0;
    auto dfs = [&](auto dfs, int x, int p) -> void {
        tin[x] = ti++;
        for(int y : g[x]) {
            if(y != p) {
                dfs(dfs, y, x);
            }
        }
        tout[x] = ti;
    };
    dfs(dfs, 1, 1);
    // build
    build(0, 0, n - 1);
    int q;
    cin >> q;
    rep(i, 1, q + 1) {
        int ty, v;
        cin >> ty >> v;
        if(ty == 1) {
            // fill v
            updfill(0, 0, n - 1, tin[v], tout[v] - 1, i);
        }else if(ty == 2) {
            // empty v
            updempty(0, 0, n - 1, tin[v], i);
        }else {
            // query v
            int tempty = query(0, 0, n - 1, tin[v], tout[v] - 1);
            int tfill = query2(0, 0, n - 1, tin[v]);
            if(tempty > tfill) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}