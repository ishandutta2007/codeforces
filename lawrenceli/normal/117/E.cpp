#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAXN = 1<<17;
const int MAXLG = 17;

int n, m;
int sum;
vector<int> adj[MAXN];
bool vis[MAXN], good;
int tree[2*MAXN], lazy[2*MAXN];
vector<int> cyc;
stack<int> stk;
int pos[MAXN], flip[MAXN];
int jump[MAXN][MAXLG], par[MAXN], dep[MAXN], sub[MAXN], root[MAXN];
int head[MAXN], ind[MAXN], cmp[MAXN];
vector<vector<int> > chain, tree2, lazy2;

void dfs(int cur, int p=-1) {
    vis[cur] = 1;
    stk.push(cur);
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        if (vis[nxt]) {
            if (!good) {
                while (stk.top() != nxt) {
                    cyc.push_back(stk.top()), stk.pop();
                }
                cyc.push_back(stk.top()), stk.pop();
                good = 1;
            }
        } else dfs(nxt, cur);
    }
    if(!stk.empty()) stk.pop();
}

void dfs2(int cur, int p, int r) {
    par[cur] = p;
    jump[cur][0] = par[cur] != -1 ? par[cur] : cur;
    dep[cur] = dep[jump[cur][0]]+1;
    sub[cur] = 1;
    root[cur] = r;
    head[cur] = cur;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        sum++;
        dfs2(nxt, cur, r);
        sub[cur] += sub[nxt];
    }
}

void dfs3(int cur, int p) {
    if (head[cur] == cur) {
        ind[cur] = 0;
        cmp[cur] = chain.size();
        chain.push_back(vector<int>());
        chain.back().push_back(cur);
    }
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        if (sub[nxt] > sub[cur] / 2) {
            head[nxt] = head[cur];
            ind[nxt] = ind[cur]+1;
            cmp[nxt] = cmp[cur];
            chain[cmp[nxt]].push_back(nxt);
        }
        dfs3(nxt, cur);
    }
}

void initlca() {
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return par[a];
}

void init(int cur, int lt, int rt) {
    tree[cur] = rt-lt;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        tree[cur] = rt-lt-tree[cur];
        if (lt + 1 != rt) {
            lazy[2*cur] ^= 1;
            lazy[2*cur+1] ^= 1;
        }
        lazy[cur] = 0;
    }
}

int query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    down(cur, lt, rt);
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return query(2*cur, lt, mid, ql, qr) +
               query(2*cur+1, mid, rt, ql, qr);
    }
}

void update(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = 1;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr);
        update(2*cur+1, mid, rt, ql, qr);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
    }
}

void init(int c, int cur, int lt, int rt) {
    tree2[c][cur] = rt-lt;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(c, 2*cur, lt, mid);
        init(c, 2*cur+1, mid, rt);
    }
}

void down(int c, int cur, int lt, int rt) {
    if (lazy2[c][cur]) {
        tree2[c][cur] = rt-lt-tree2[c][cur];
        if (lt + 1 != rt) {
            lazy2[c][2*cur] ^= 1;
            lazy2[c][2*cur+1] ^= 1;
        }
        lazy2[c][cur] = 0;
    }
}

int query(int c, int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    down(c, cur, lt, rt);
    if (lt >= ql && rt <= qr) return tree2[c][cur];
    else {
        int mid = (lt + rt) / 2;
        return query(c, 2*cur, lt, mid, ql, qr) +
               query(c, 2*cur+1, mid, rt, ql, qr);
    }
}

void update(int c, int cur, int lt, int rt, int ql, int qr) {
    down(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy2[c][cur] = 1;
        down(c, cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(c, 2*cur, lt, mid, ql, qr);
        update(c, 2*cur+1, mid, rt, ql, qr);
        tree2[c][cur] = tree2[c][2*cur] + tree2[c][2*cur+1];
    }
}

void tupdate(int cur, int nd) {
    while (cur >= 0) {
        //cout << cur+1 << ' ' << nd+1 << endl;
        if (cmp[cur] != cmp[nd]) {
            int x = query(cmp[cur], 1, 0, chain[cmp[cur]].size(), 0, ind[cur]);
            //cout << cur+1 << ' ' << ind[cur] << ' ' << x << endl;
            sum += ind[cur]-2*x;
            update(cmp[cur], 1, 0, chain[cmp[cur]].size(), 0, ind[cur]);
            sum += 1-2*flip[head[cur]];
            flip[head[cur]] ^= 1;
            cur = par[head[cur]];
        } else {
            int x = query(cmp[cur], 1, 0, chain[cmp[cur]].size(), ind[nd], ind[cur]);
            sum += ind[cur]-ind[nd]-2*x;
            update(cmp[cur], 1, 0, chain[cmp[cur]].size(), ind[nd], ind[cur]);
            return;
        }
    }
}


int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    memset(pos, -1, sizeof(pos));
    for (int i=0; i<cyc.size(); i++) pos[cyc[i]] = i;
    for (int i=0; i<cyc.size(); i++) {
        int v = cyc[i];
        vector<int> chd;
        for (int j=0; j<adj[v].size(); j++) {
            int nxt = adj[v][j];
            if (pos[nxt] == -1) chd.push_back(nxt);
        }
        adj[v] = chd;
        dfs2(v, -1, v);
        dfs3(v, -1);
    }
    initlca();
    init(1, 0, cyc.size());
    tree2.resize(chain.size());
    lazy2.resize(chain.size());
    for (int i=0; i<chain.size(); i++) {
        tree2[i].resize(4*chain[i].size(), 0);
        lazy2[i].resize(4*chain[i].size(), 0);
        init(i, 1, 0, chain[i].size());
        flip[chain[i][0]] = 1;
    }

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        if (root[a] != root[b]) {
            //cout << root[a]+1 << ' ' << root[b]+1 << endl;
            tupdate(a, root[a]);
            tupdate(b, root[b]);
            a = pos[root[a]], b = pos[root[b]];
            bool flipped = 0;
            if (a > b) swap(a, b), flipped = 1;
            int d1 = b-a, d2 = cyc.size()-d1;
            if (d1 < d2 || d1 == d2 && (!flipped && cyc[(a+1)%cyc.size()] < cyc[(a-1+cyc.size())%cyc.size()] || flipped && cyc[(b-1+cyc.size())%cyc.size()] < cyc[(b+1)%cyc.size()])) {
                update(1, 0, cyc.size(), a, b);
            } else {
                update(1, 0, cyc.size(), 0, a);
                update(1, 0, cyc.size(), b, cyc.size());
            }
            int sum2 = query(1, 0, cyc.size(), 0, cyc.size());
            sum2 = max(0, sum2-1);
            //cout << sum << ' ' << sum2 << endl;
            printf("%d\n", sum+sum2+1);
        } else {
            int l = lca(a, b);
            //cout << a+1 << ' ' << b+1 << ' ' << l+1 << endl;
            tupdate(a, l);
            tupdate(b, l);
            int sum2 = query(1, 0, cyc.size(), 0, cyc.size());
            sum2 = max(0, sum2-1);
            //cout << sum << ' ' << sum2 << endl;
            printf("%d\n", sum+sum2+1);
        }
    }
    return 0;
}