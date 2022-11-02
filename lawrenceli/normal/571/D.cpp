#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

const int maxn = 1<<20;

int n, m;
int qt[maxn], qa[maxn], qb[maxn];

vector<int> adj[maxn];
int nodecnt; //count of current node number

int par[maxn], sze[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }

int ent[maxn], exi[maxn], cnt;

void dfs(int cur) {
    ent[cur] = cnt++;
    for (int i : adj[cur]) dfs(i);
    exi[cur] = cnt++;
}

ll tree[4*maxn], lazy[4*maxn];

void down(int cur, int lt, int rt) {
    tree[cur] = max(tree[cur], lazy[cur]);
    if (lt + 1 != rt) {
        lazy[2*cur] = max(lazy[2*cur], lazy[cur]);
        lazy[2*cur+1] = max(lazy[2*cur+1], lazy[cur]);
    }
    lazy[cur] = 0;
}

void upd(int cur, int lt, int rt, int ql, int qr, int v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2*cur, lt, mid, ql, qr, v);
        upd(2*cur+1, mid, rt, ql, qr, v);
    }
}

int qry(int cur, int lt, int rt, int p) {
    down(cur, lt, rt);
    if (lt + 1 == rt) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return qry(2*cur, lt, mid, p);
        else return qry(2*cur+1, mid, rt, p);
    }
}

void down2(int cur, int lt, int rt) {
    tree[cur] += lazy[cur];
    if (lt + 1 != rt) {
        lazy[2*cur] += lazy[cur];
        lazy[2*cur+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

void upd2(int cur, int lt, int rt, int ql, int qr, int v) {
    down2(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down2(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd2(2*cur, lt, mid, ql, qr, v);
        upd2(2*cur+1, mid, rt, ql, qr, v);
    }
}

ll qry2(int cur, int lt, int rt, int p) {
    down2(cur, lt, rt);
    if (lt + 1 == rt) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return qry2(2*cur, lt, mid, p);
        else return qry2(2*cur+1, mid, rt, p);
    }
}

vector<int> qryt[maxn];

ll ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        char c; cin >> c;
        if (c == 'U') {
            qt[i] = 0;
            cin >> qa[i] >> qb[i];
        } else if (c == 'M') {
            qt[i] = 1;
            cin >> qa[i] >> qb[i];
        } else if (c == 'A') {
            qt[i] = 2;
            cin >> qa[i];
        } else if (c == 'Z') {
            qt[i] = 3;
            cin >> qa[i];
        } else {
            qt[i] = 4;
            cin >> qa[i];
        }
    }

    //first part
    nodecnt = n;
    for (int i=0; i<maxn; i++) par[i] = i;
    for (int i=0; i<m; i++)
        if (qt[i] == 1) {
            nodecnt++;
            adj[nodecnt].push_back(getpar(qa[i]));
            adj[nodecnt].push_back(getpar(qb[i]));
            par[getpar(qa[i])] = nodecnt;
            par[getpar(qb[i])] = nodecnt;
        }
    
    cnt = 0;
    for (int i=1; i<=nodecnt; i++)
        if (getpar(i) == i)
            dfs(i);

    nodecnt = n;
    for (int i=0; i<maxn; i++) par[i] = i;

    for (int i=0; i<m; i++) {
        if (qt[i] == 1) {
            nodecnt++;
            par[getpar(qa[i])] = nodecnt;
            par[getpar(qb[i])] = nodecnt;
        } else if (qt[i] == 3) {
            int x = getpar(qa[i]);
            upd(1, 0, cnt, ent[x], exi[x], i+1);
        } else if (qt[i] == 4) {
            int t = qry(1, 0, cnt, ent[qa[i]]);
            qryt[t].push_back(i);
        }
    }

    //second part
    for (int i=0; i<maxn; i++) adj[i].clear();
    for (int i=0; i<maxn; i++) par[i] = i;
    nodecnt = n;

    for (int i=0; i<m; i++)
        if (qt[i] == 0) {
            nodecnt++;
            adj[nodecnt].push_back(getpar(qa[i]));
            adj[nodecnt].push_back(getpar(qb[i]));
            par[getpar(qa[i])] = nodecnt;
            par[getpar(qb[i])] = nodecnt;
        }

    cnt = 0;
    for (int i=1; i<=nodecnt; i++)
        if (getpar(i) == i)
            dfs(i);
    
    nodecnt = n;
    for (int i=0; i<maxn; i++) par[i] = i;
    for (int i=1; i<=n; i++) sze[i] = 1;
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    for (int i=0; i<m; i++) {
        for (int j : qryt[i]) {
            ans[j] -= qry2(1, 0, cnt, ent[qa[j]]);
        }

        if (qt[i] == 0) {
            nodecnt++;
            sze[nodecnt] += sze[getpar(qa[i])];
            sze[nodecnt] += sze[getpar(qb[i])];
            par[getpar(qa[i])] = nodecnt;
            par[getpar(qb[i])] = nodecnt;
        } else if (qt[i] == 2) {
            int x = getpar(qa[i]);
            upd2(1, 0, cnt, ent[x], exi[x], sze[x]);
        } else if (qt[i] == 4) {
            ans[i] += qry2(1, 0, cnt, ent[qa[i]]);
        }
    }

    for (int i=0; i<m; i++)
        if (qt[i] == 4)
            cout << ans[i] << '\n';
}