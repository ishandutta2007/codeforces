#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1<<20;

int n, c;
char s[10];
vector<int> adj[MAXN][2];

pii tree[2*MAXN]; //min, pos
int lazy[2*MAXN];

void down(int cur, int lt, int rt) {
    tree[cur].fi += lazy[cur];
    if (lt + 1 != rt) {
        lazy[2*cur] += lazy[cur];
        lazy[2*cur+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

pii merge(pii p1, pii p2) {
    if (p1.fi <= p2.fi) return p1;
    else return p2;
}

void init(int cur, int lt, int rt) {
    tree[cur] = pii(0, lt);
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
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
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
    }
}

pii qry(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return pii(1e9, -1);
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return merge(qry(2*cur, lt, mid, ql, qr), qry(2*cur+1, mid, rt, ql, qr));
    }
}

int chd[MAXN][2];

void abort() {
    printf("IMPOSSIBLE\n");
    exit(0);
}

void dfs(int lt, int rt) {
    for (int i=0; i<2; i++)
        for (int j : adj[lt][i])
            upd(1, 1, n+2, lt+1, j+1, -1);

    int l = lt+1, r = rt+1;
    if (!adj[lt][0].empty()) l = adj[lt][0].back()+1;
    if (!adj[lt][1].empty()) r = adj[lt][1].front()+1;

    if (l>=r) abort();
    pii p = qry(1, 1, n+2, l, r);
    if (p.fi != 0) abort();
    int k = p.se;

    if (k > lt+1) {
        chd[lt][0] = lt+1;
        dfs(lt+1, k);
    }
    if (k < rt) {
        chd[lt][1] = k;
        dfs(k, rt);
    }
}

void dfs2(int cur) {
    if (!cur) return;
    dfs2(chd[cur][0]);
    printf("%d ", cur);
    dfs2(chd[cur][1]);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d\n", &n, &c);
    init(1, 1, n+2);
    for (int i=0; i<c; i++) {
        int a, b;
        scanf("%d %d %s\n", &a, &b, s);
        if (a>=b) abort();
        if (s[0] == 'L') adj[a][0].push_back(b);
        else adj[a][1].push_back(b);
        upd(1, 1, n+2, a+1, b+1, 1);
    }

    for (int i=1; i<=n; i++)
        for (int j=0; j<2; j++)
            sort(adj[i][j].begin(), adj[i][j].end());

    dfs(1, n+1);
    dfs2(1);
}