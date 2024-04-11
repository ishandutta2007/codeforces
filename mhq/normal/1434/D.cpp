#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 5e5 + 10;
int u[maxN], v[maxN], t[maxN];
struct treeDiameter{
    //0-indexation
    int n;
    vector<vector<pair<int,int>>> g;
    vector<ll> h;
    vector<int> p;
    treeDiameter(int _n, vector<pair<pair<int,int>,int>>& ed) {
        n = _n;
        g.resize(n);
        for (auto& it : ed) {
            g[it.first.first].emplace_back(it.first.second, it.second);
            g[it.first.second].emplace_back(it.first.first, it.second);
        }
        h.resize(n);
        p.resize(n, -1);
    }
    void dfs(int v, int prv) {
        for (auto& to : g[v]) {
            if (to.first == prv) continue;
            p[to.first] = v;
            h[to.first] = h[v] + to.second;
            dfs(to.first, v);
        }
    }
    pair<ll, vector<int>> findPath() {
        dfs(0, -1);
        int from = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > h[from]) from = i;
        }
        h[from] = 0;
        p[from] = -1;
        dfs(from, -1);
        int to = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > h[to]) to = i;
        }
        ll diam = h[to];
        vector<int> his_path;
        while (to != -1) {
            his_path.emplace_back(to);
            to = p[to];
        }
        return make_pair(diam, his_path);
    }
};

const int INF = 1e8;
struct SG{
    vector<vector<int>> t;
    vector<bool> flip;
    SG() {}
    SG(int n, vector<int>& vals, vector<int>& f) {
        t.resize(4 * n + 5, vector<int>(2, 0));
        flip.resize(4 * n + 5);
        build(1, 0, n - 1, vals, f);
    }
    void merge(int v) {
        for (int c = 0; c < 2; c++) {
            t[v][c] = max(t[2 * v][c], t[2 * v + 1][c]);
        }
    }
    void do_flip(int v) {
        flip[v] = !flip[v];
        swap(t[v][0], t[v][1]);
    }
    void push(int v, int tl, int tr) {
        if (tl != tr && flip[v]) {
            do_flip(2 * v);
            do_flip(2 * v + 1);
        }
        flip[v] = false;
    }
    void build(int v, int tl, int tr, vector<int>& all, vector<int>& f) {
        if (tl == tr) {
            t[v][0] = t[v][1] = -INF;
            t[v][f[tl]] = all[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, all, f);
        build(2 * v + 1, tm + 1, tr, all, f);
        merge(v);
    }
    void upd(int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r) {
            do_flip(v);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r);
        upd(2 * v + 1, tm + 1, tr, l, r);
        merge(v);
    }
    int getMax(int clr) {
        return t[1][clr];
    }
};
struct tree{
    int n;
    vector<vector<pair<int,int>>> g;
    vector<int> tin;
    vector<int> tout;
    vector<int> h;
    vector<int> clr;
    int timer = 0;
    SG st;
    int root;
    void dfs(int v, int p) {
        tin[v] = timer++;
        for (auto to : g[v]) {
            if (to.first != p) {
                h[to.first] = h[v] + 1;
                clr[to.first] = clr[v] ^ to.second;
                dfs(to.first, v);
            }
        }
        tout[v] = timer;
    }
    tree(int rroot, vector<vector<pair<int,int>>>& ed) {
        root = rroot;
        n = ed.size() - 1;
        g = ed;
        tin.resize(n + 1);
        clr.resize(n + 1);
        tout.resize(n + 1);
        h.resize(n + 1);
        dfs(root, -1);
        vector<int> vals(n);
        vector<int> his(n);
        for (int i = 1; i <= n; i++) {
            vals[tin[i]] = h[i];
            his[tin[i]] = clr[i];
        }
        st = SG(n, vals, his);
    }
    void flip(int u, int v) {
        if (tin[u] > tin[v]) swap(u, v);
        st.upd(1, 0, n - 1, tin[v], tout[v] - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<pair<pair<int,int>,int>> ed;
    vector<vector<pair<int,int>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i] >> t[i];
        ed.emplace_back(make_pair(u[i] - 1, v[i] - 1), 1);
        g[u[i]].emplace_back(v[i], t[i]);
        g[v[i]].emplace_back(u[i], t[i]);
    }

    treeDiameter p(n, ed);
    auto td = p.findPath();
    int x = td.second[0] + 1;
    int y = td.second.back() + 1;
    tree p1(x, g);
    tree p2(y, g);
    int m;
    cin >> m;
    while (m--) {
        int id;
        cin >> id;
        p1.flip(u[id], v[id]);
        p2.flip(u[id], v[id]);
        int best = max(p1.st.getMax(0), p2.st.getMax(0));
        cout << best << '\n';
    }
    return 0;
}