#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = N * 20, K = 20;
int n, q, last, dep[N], rt, dfn[N], ld[N], rd[N], dfnid = 0, anc[K][N];
struct getsum {
    int s[M];
    void add(int x, int v) { 
        for(; x < M; x += x & (-x)) s[x] += v;
    }
    int qry(int x) {
        int sum = 0; 
        for(; x > 0; x -= x & (-x)) sum += s[x];
        return sum;
    }
}sum;
struct getmax {
    int f[N];
    void add(int x, int v) {
        for(; x <= n; x += x & (-x)) f[x] = max(f[x], v);
    }
    int qry(int x) {
        int res = 0;
        for(; x > 0; x -= x & (-x)) res = max(res, f[x]);
        return res;
    }
}pre, suf;
int ch[N][2], fa[N], tag[N];
vector<int> g[N];
void dfs(int u, int fa) {
    ::fa[u] = fa, ld[u] = dfn[u] = ++dfnid;
    dep[u] = dep[fa] + 1;
    for(auto v : g[u]) if(v != fa) dfs(v, u);
    rd[u] = dfnid;
    return;
}
int dir(int x, int y) {return ch[x][1] == y; }
int nroot(int x) {return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
void pushdown(int x) {
    int lc = ch[x][0], rc = ch[x][1];
    if(lc) tag[lc] = tag[x];
    if(rc) tag[rc] = tag[x];
    return;
}
void rotate(int x) {
    int y = fa[x], z = fa[y], k = dir(y, x), w = ch[x][k ^ 1];
    if(nroot(y)) ch[z][dir(z, y)] = x;
    ch[x][k ^ 1] = y, ch[y][k] = w, fa[x] = z, fa[y] = x;
    if(w) fa[w] = y;
    return;
}
int stk[N], top = 0;
void splay(int x) {
    top = 0;
    stk[++top] = x;
    for(int y = x; nroot(y); stk[++top] = y = fa[y]);
    for(; top; pushdown(stk[top--]));
    while(nroot(x)) {
        int y = fa[x], z = fa[y];
        if(nroot(y)) rotate(dir(y, x) != dir(z, y) ? y : x);
        rotate(x);
    }
    return;
}
int find(int x) {
    while(ch[x][0]) x = ch[x][0];
    splay(x);
    return dep[x];
}
void access(int x) {
    rt = x;
    last++;
    pre.add(dfn[x], last), suf.add(n + 1 - dfn[x], last);
    int len = dep[x], y;
    for(y = 0; x; x = fa[y = x]) {
        splay(x);
        int r = dep[x];
        int l = find(x);
        splay(x);
        sum.add(tag[x], - (r - l + 1));
        ch[x][1] = y;
    }
    tag[y] = last;
    sum.add(tag[y], len);
}
int jump(int x, int k) {
    for(int i = K - 1; i >= 0; i--) if(k >> i & 1) x = anc[i][x];
    return x;
}
int find(int x, int y) {
    for(int i = K - 1; i >= 0; i--) {
        if(anc[i][x] && max(pre.qry(ld[anc[i][x]] - 1), suf.qry(n + 1 - (rd[anc[i][x]] + 1))) > y) {
            x = anc[i][x];
        }
    }
    if(max(pre.qry(ld[x] - 1), suf.qry(n + 1 - (rd[x] + 1))) <= y) x = anc[0][x];
    else x = anc[1][x];
    return dep[x];
}
int when(int x) {
    if(x == rt) return n;
    int tim, delta;
    if(ld[x] <= dfn[rt] && dfn[rt] <= rd[x]) {
        int y = jump(rt, dep[rt] - dep[x] - 1);
        tim = max(pre.qry(ld[y] - 1), suf.qry(n + 1 - (rd[y] + 1)));
        // cout << tim << endl;
        int cnt = find(rt, tim);
        delta = -(cnt - dep[x]) + cnt;
    } else {
        splay(x);
        tim = tag[x];
        int l = find(x);
        delta = -(dep[x] - l) + find(rt, tim - 1);
    }
    return sum.qry(tim) + delta;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) anc[0][i] = fa[i];
    for(int i = 1; i < K; i++) for(int j = 1; j <= n; j++) anc[i][j] = anc[i - 1][anc[i - 1][j]];
    last = 1;
    for(int i = 1; i <= n; i++) tag[i] = 1;
    sum.add(1, n);
    for(int i = 1; i <= n; i++) access(i);
    for(int i = 1; i <= q; i++) {
        string opt;
        int u, v;
        cin >> opt;
        if(opt == "up") {
            cin >> v;
            access(v);
        } else if(opt == "when") {
            cin >> v;
            cout << when(v) << endl;
        } else {
            cin >> u >> v;
            cout << (when(u) < when(v) ? u : v) << endl;
        }
    }
    return 0;
}