
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

struct dsu {
    vi a;
    int n;
    vector<bool> b;
    vector<pii> ve;
    dsu() {}
    dsu(int n) : n(n) {
        a.assign(2 * n, -1);
        b.push_back(true);
    }
    int trace(int x) {
        return a[x] < 0 ? x : trace(a[x]);
    }
    void add(int x, int y) {
        x = trace(x), y = trace(y);
        ve.push_back({x, a[x]});
        ve.push_back({y, a[y]});
        if(x == y) return;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
    }
    void join(int x, int y) {
        add(x, y + n);
        add(x + n, y);
        b.push_back(b.back() && trace(x) != trace(x + n));
    }
    bool bip() const {
        return b.back();
    }
    void pop() {
        rep(j, 0, 4) {
            int i, v;
            tie(i, v) = ve.back(); ve.pop_back();
            a[i] = v;
        }
        b.pop_back();
    }
};

const int Q = 1e5 + 5;
vector<pii> tree[4 * Q];
dsu D;

void add(int i, int l, int r, int L, int R, const pii &pa) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        tree[i].push_back(pa);
        return;
    }
    int m = (l + r) / 2;
    add(2 * i + 1, l, m, L, R, pa);
    add(2 * i + 2, m + 1, r, L, R, pa);
}

void dfs(int i, int l, int r) {
    for(auto &pa : tree[i]) {
        D.join(pa.first, pa.second);
    }
    int m = (l + r) / 2;
    if(l < r) {
        dfs(2 * i + 1, l, m);
        dfs(2 * i + 2, m + 1, r);
    }else {
        cout << (D.bip() ? "YES\n" : "NO\n");
    }
    rep(j, 0, sz(tree[i])) {
        D.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<pii, int> ma;
    D = dsu(n + 1);
    rep(i, 1, q + 1) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        if(ma.count({u, v})) {
            add(0, 1, q, ma[{u, v}], i - 1, make_pair(u, v));
            ma.erase({u, v});
        }else {
            ma[{u, v}] = i;
        }
    }
    for(auto &pa : ma) {
        add(0, 1, q, pa.second, q, pa.first);
    }
    dfs(0, 1, q);
}