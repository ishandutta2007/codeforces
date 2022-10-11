#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
vector<int> cur(1, 0), pre;

struct SSegmentTree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    vector<int> tr[4 * N];

    void update(int l, int r, int i, int L, int R, int v) {
        if (l > R || r < L || L > R) {
            return;
        }
        if (L <= l && r <= R) {
            tr[i].push_back(v);
            return;
        }
        update(l, m, lc, L, R, v);
        update(m + 1, r, rc, L, R, v);
    }

    void query(int l, int r, int i, int u) {
        for (int &v : tr[i]) {
            cur.push_back(v);
        }
        tr[i].clear();
        if (l == r) {
            return;
        }
        if (u <= m) {
            query(l, m, lc, u);
        } else {
            query(m + 1, r, rc, u);
        }
    }

#undef m
#undef lc
#undef rc
};

struct STreeGraph {

    int cnt = 0, cur = 1, h[N];
    int in[N], par[N], col[N], rt[N], sub[N];
    bool chk[N];
    vector<int> adj[N];
    SSegmentTree seg;

    int DFS(int u) {
        h[u] = h[par[u]] + 1;
        for (int &v : adj[u]) {
            sub[u] += DFS(v);
        }
        return ++sub[u];
    }

    void HLD(int u) {
        in[u] = ++cnt;
        col[u] = cur;
        if (rt[cur] == 0) {
            rt[cur] = u;
        }
        int mc = 0;
        for (int &v : adj[u]) {
            if (sub[v] > sub[mc]) {
                mc = v;
            }
        }
        if (mc != 0) {
            HLD(mc);
        }
        for (int &v : adj[u]) {
            if (v != mc) {
                ++cur;
                HLD(v);
            }
        }
    }

    void init() {
        h[0] = -1;
        for (int i = 2; i <= n; i++) {
            cin >> par[i];
            adj[par[i]].push_back(i);
        }
        DFS(1);
        HLD(1);
    }

    void add_element(int u, int v, int val) {
        while (col[u] != col[v]) {
            if (h[rt[col[u]]] < h[rt[col[v]]]) {
                swap(u, v);
            }
            seg.update(1, n, 1, in[rt[col[u]]], in[u], val);
            u = par[rt[col[u]]];
        }
        if (h[u] < h[v]) {
            swap(u, v);
        }
        seg.update(1, n, 1, in[v] + 1, in[u], val);
    }

} tr[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    tr[0].init();
    tr[1].init();
    for (int i = 0; i < 2; i++) {
        for (int v = 2; v <= n; v++) {
            tr[i ^ 1].add_element(tr[i].par[v], v, v);
        }
    }
    cin >> cur[0]; cur[0]++;
    for (int i = 0; !cur.empty(); i ^= 1)
    {
        for (int &v : cur) {
            if (!tr[i].chk[v]) {
                tr[i].chk[v] = true;
                pre.push_back(v);
            }
        }
        cur.clear();
        if (pre.empty()) {
            break;
        }
        cout << (i == 0 ? "Blue\n" : "Red\n");
        sort(pre.begin(), pre.end());
        for (int &v : pre) {
            cout << v - 1 << " ";
            tr[i].seg.query(1, n, 1, tr[i].in[v]);
        }
        cout << '\n';
        pre.clear();
    }
}