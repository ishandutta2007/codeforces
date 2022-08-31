#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct Fenwick {
    vector<ll> f;
    int n;

    Fenwick() = default;

    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1);
    }

    void upd(int pos, int v) {
        while (pos <= n) {
            f[pos] += v;
            pos = (pos | (pos - 1)) + 1;
        }
    }

    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

struct addPathTree{
    const int LG = 20;
    //0-
    int n;
    vector < vector < int > > g;
    int ti = 0;
    vector < int > fi, lst;
    vector < int > lg;
    vector < int > h;
    vector < vector < pair < int, int > > > up;
    vector < ll > vals;
    Fenwick adder;
    vector < int > pos;
    addPathTree(const vector < vector < int > >& eds, int root) {
        g = eds;
        n = g.size();
        lg.resize(2 * n + 1);
        fi.resize(n);
        lst.resize(n);
        h.resize(n);
        vals.resize(n);
        pos.resize(n);
        lg[1] = 0;
        for (int i = 2; i <= 2 * n; i++) {
            lg[i] = lg[i - 1];
            if (!(i & (i - 1))) lg[i]++;
        }
        up.resize(LG);
        ti = 0;
        dfs(root, -1);
        adder = Fenwick(2 * n);
        for (int i = 1; i < LG; i++) {
            up[i].resize(up[0].size());
        }
        for (int i = 0; i + 1 < LG; i++) {
            for (int j = 0; j + (1 << (i + 1)) - 1 < up[0].size(); j++) {
                up[i + 1][j] = min(up[i][j], up[i][j + (1 << i)]);
            }
        }
    }

    void dfs(int v, int p) {
        fi[v] = ti++;
        pos[v] = up[0].size();
        up[0].emplace_back(h[v], v);
        for (int to : g[v]) {
            if (to == p) continue;
            up[0].emplace_back(h[v], v);
            h[to] = h[v] + 1;
            dfs(to, v);
        }
        lst[v] = ti++;
    }

    int getLca(int u, int v) {
        if (u == v) return u;
        int l = pos[u]; int r = pos[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        auto t = min(up[k][l], up[k][r - (1 << k) + 1]);
        return t.second;
    }

    void addVert(int v, int val) {
        vals[v] += val;
        assert(0 <= fi[v] && lst[v] < 2 * n);
        adder.upd(fi[v] + 1, val);
        adder.upd(lst[v] + 1, -val);
    }

    ll getToRoot(int v) {
        return adder.get(fi[v] + 1);
    }

    ll findSum(int u, int v) {
        if (h[u] > h[v]) swap(u, v);
        int w = getLca(u, v);
        if (w == u) {
            return getToRoot(v) - getToRoot(u) + vals[u];
        }
        else {
            return getToRoot(u) + getToRoot(v) - 2 * getToRoot(w) + vals[w];
        }
    }
};
const int maxN = 3e5 + 10;
int p[maxN];
int nxt[maxN];
bool ok[maxN];
int prv[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if (p[i] == -1) {
            root = i;
        }
        else {
            g[p[i]].emplace_back(i);
            g[i].emplace_back(p[i]);
        }
    }
    memset(nxt, -1, sizeof nxt);
    memset(prv, -1, sizeof prv);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        nxt[x] = y;
        prv[y] = x;
    }
    addPathTree F(g, root);
    vector<int> need(n, 1e9);
    for (int i = 0; i < n; i++) {
        if (prv[i] == -1) {
            int c = i;
            while (c != -1) {
                F.addVert(c, +1);
                need[c] = F.getToRoot(c);
                c = nxt[c];
            }
            c = i;
            while (c != -1) {
                F.addVert(c, -1);
                c = nxt[c];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        F.addVert(i, +1);
    }
    queue<int> q;
    vector<int> ans;
    auto can = [&](int x) {
        if (prv[x] != -1 && !ok[prv[x]]) return false;
        if (F.getToRoot(x) == need[x]) {
            return true;
        }
        else {
            return false;
        }
    };
    vector<int> chain;
    if (can(root)) {
        q.push(root);
        ok[root] = true;
        while (!q.empty()) {
            int v = q.front();
            if (nxt[v] == -1) {
                int pt = v;
                while (prv[pt] != -1) pt = prv[pt];
                chain.emplace_back(pt);
                int c = pt;
                while (c != -1) {
                    F.addVert(c, -1);
                    c = nxt[c];
                }
                c = pt;
                while (c != -1) {
                    for (int p : g[c]) {
                        if (!ok[p] && can(p)) {
                            q.push(p);
                            ok[p] = true;
                        }
                    }
                    c = nxt[c];
                }
            }
            q.pop();
            if (nxt[v] != -1 && !ok[nxt[v]] && can(nxt[v])) {
                ok[nxt[v]] = true;
                q.push(nxt[v]);
            }
        }
    }
    int sz_chain = 0;
    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1) sz_chain++;
    }
    if (chain.size() != sz_chain) {
        cout << 0;
        return 0;
    }
    else {
        for (int x : chain) {
            int y = x;
            while (y != -1) {
                ans.emplace_back(y);
                y = nxt[y];
            }
        }
        for (int v : ans) cout << v + 1 << " ";
    }
    return 0;
}