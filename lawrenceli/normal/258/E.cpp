#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int MAXN = 1<<17;

int n, m;
vector<int> adj[MAXN], qadj[MAXN];
int ent[MAXN], exi[MAXN], cnt;
int ans[MAXN];

void dfs1(int cur, int p) {
    ent[cur] = cnt++;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs1(nxt, cur);
    }
    exi[cur] = cnt++;
}

struct data {
    int num, lo, cnt;
    data() {}
    data(int _num, int _lo, int _cnt) : num(_num), lo(_lo), cnt(_cnt) {}
};

data tree[4*MAXN];
int lazy[4*MAXN];

void init(int cur, int lt, int rt) {
    tree[cur] = data(0, 0, rt - lt);
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        tree[cur].lo += lazy[cur];
        if (tree[cur].lo) tree[cur].num = rt - lt;
        else tree[cur].num = rt - lt - tree[cur].cnt;
        if (lt + 1 != rt) {
            lazy[2*cur] += lazy[cur];
            lazy[2*cur+1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

data prop(data d1, data d2) {
    return data(d1.num + d2.num, min(d1.lo, d2.lo),
                d1.lo == d2.lo ? d1.cnt + d2.cnt :
                d1.lo < d2.lo ? d1.cnt : d2.cnt);
}

void update(int cur, int lt, int rt, int ql, int qr, int v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, v);
        update(2*cur+1, mid, rt, ql, qr, v);
        tree[cur] = prop(tree[2*cur], tree[2*cur+1]);
    }
}

void dfs2(int cur, int p) {
    for (int i=0; i<qadj[cur].size(); i++) {
        int nxt = qadj[cur][i];
        update(1, 0, 2*n, ent[nxt], exi[nxt]+1, 1);
    }

    ans[cur] = max(0, tree[1].num / 2 - 1);

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs2(nxt, cur);
    }

    for (int i=0; i<qadj[cur].size(); i++) {
        int nxt = qadj[cur][i];
        update(1, 0, 2*n, ent[nxt], exi[nxt]+1, -1);
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        qadj[a].push_back(b);
        qadj[b].push_back(a);
    }
    for (int i=0; i<n; i++)
        if (qadj[i].size())
            qadj[i].push_back(i);

    dfs1(0, 0);
    init(1, 0, 2*n);
    dfs2(0, 0);

    for (int i=0; i<n; i++)
        cout << ans[i] << ' ';

    return 0;
}