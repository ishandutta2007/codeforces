#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1<<17;
const int maxlg = 17;
const int inf = 1e9;

int n, m, q;
vector<int> adj[maxn];
vector<int> ids[maxn];

int dep[maxn], jump[maxn][maxlg], ent[maxn], exi[maxn], cnt;

int qv[maxn];

void dfs(int cur, int p=-1) {
    ent[cur] = cnt++;
    dep[cur] = p == -1 ? 0 : dep[p] + 1;
    jump[cur][0] = p == -1 ? cur : p;
    for (int i : adj[cur]) {
        if (i == p) continue;
        dfs(i, cur);
    }
    exi[cur] = cnt++;
}

void initlca() {
    for (int k = 0; k < maxlg-1; k++)
        for (int i = 1; i <= n; i++)
            jump[i][k+1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = maxlg-1; k >= 0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];

    if (a == b) return a;

    for (int k = maxlg-1; k >= 0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int anc(int a, int d) {
    for (int k = maxlg-1; k >= 0; k--)
        if (d & 1<<k)
            a = jump[a][k];
    return a;
}

struct data {
    int a[10];
    data() {
        for (int i = 0; i < 10; i++) a[i] = inf;
    }
};

data merge(data d1, data d2) {
    int a[25];
    merge(d1.a, d1.a + 10, d2.a, d2.a + 10, a);
    data d = data();
    for (int i = 0; i < 10; i++) d.a[i] = a[i];
    return d;
}

typedef pair<int, int> pii;

int qa[maxn];
vector<pii> qadj[maxn];
data qans[maxn];

data tree[4*maxn], lazy[4*maxn];

void push(int cur, int lt, int rt) {
    if (lazy[cur].a[0] != inf) {
        tree[cur] = merge(tree[cur], lazy[cur]);
        if (lt + 1 != rt) {
            lazy[2*cur] = merge(lazy[2*cur], lazy[cur]);
            lazy[2*cur+1] = merge(lazy[2*cur+1], lazy[cur]);
        }
        lazy[cur] = data();
    }
}

void upd(int cur, int lt, int rt, int ql, int qr, data d) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = d;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2*cur, lt, mid, ql, qr, d);
        upd(2*cur+1, mid, rt, ql, qr, d);
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
    }
}

data qry(int cur, int lt, int rt, int p) {
    push(cur, lt, rt);
    if (lt + 1 == rt) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return qry(2*cur, lt, mid, p);
        else return qry(2*cur+1, mid, rt, p);
    }
}

void dfs2(int cur, int p=-1) {
    for (int i : adj[cur]) {
        if (i == p) continue;
        dfs2(i, cur);
    }

    data d = data();
    sort(ids[cur].begin(), ids[cur].end());
    for (int i = 0; i < ids[cur].size() && i < 10; i++)
        d.a[i] = ids[cur][i];

    upd(1, 0, 2*n, ent[cur], exi[cur], d);
    for (pii p : qadj[cur]) {
        data res = qry(1, 0, 2*n, ent[p.first]);
        qans[p.second] = merge(qans[p.second], res);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        ids[x].push_back(i);
    }

    dfs(1);
    initlca();

    for (int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u >> qa[i];
        int l = lca(v, u);
        qadj[l].push_back(pii(v, i));
        if (u != l) {
            qadj[anc(u, dep[u] - dep[l] - 1)].push_back(pii(u, i));
        }
    }

    dfs2(1);

    for (int i = 0; i < q; i++) {
        int sze = 0;
        for (; sze < qa[i] && qans[i].a[sze] != inf; sze++);
        cout << sze << ' ';
        for (int j = 0; j < sze; j++) cout << qans[i].a[j] << ' ';
        cout << '\n';
    }
}