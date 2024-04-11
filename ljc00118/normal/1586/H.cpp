#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

struct edge_t { int u, v, nxt, val; } G[N << 1];

int fa[N][20], mx[N][20];
int a[N], head[N], u[N], v[N], c[N], t[N], id[N], dep[N], vv[N], x[N], f[N], idq[N], ans1[N], ans2[N];
int n, q, tot;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool cmpc(int i, int j) { return c[i] > c[j]; }
bool cmpq(int i, int j) { return vv[i] > vv[j]; }

inline void addedge(int u, int v, int t) {
    G[++tot] = (edge_t) {u, v, head[u], t}, head[u] = tot;
}

void dfs1(int u) {
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
    }
    for (int i = head[u]; i; i = G[i].nxt) {
        int v = G[i].v;
        if (v == fa[u][0]) continue;
        fa[v][0] = u; mx[v][0] = G[i].val;
        dep[v] = dep[u] + 1; dfs1(v);
    }
}

int getmx(int u, int v) {
    int ans = 0;
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            ans = max(ans, mx[u][i]);
            u = fa[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = fa[u][i]; v = fa[v][i];
        }
    }
    return max(ans, max(mx[u][0], mx[v][0]));
}

struct atom { int p, maxn; } tt[N];

atom merge(atom A, atom B) {
    atom ans;
    if (a[A.p] > a[B.p]) return A;
    if (a[A.p] < a[B.p]) return B;
    ans.p = A.p;
    ans.maxn = max(max(A.maxn, B.maxn), getmx(A.p, B.p));
    return ans;
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) {
        read(u[i]); read(v[i]); read(c[i]); read(t[i]);
        id[i] = i;
        addedge(u[i], v[i], t[i]);
        addedge(v[i], u[i], t[i]);
    }
    for (int i = 1; i <= q; i++) read(vv[i]), read(x[i]), idq[i] = i;
    dep[1] = 1; dfs1(1);
    sort(id + 1, id + n, cmpc); sort(idq + 1, idq + q + 1, cmpq);
    for (int i = 1; i <= n; i++) tt[i].p = i, tt[i].maxn = 0, f[i] = i;
    for (int i = 1, j = 1; i <= q; i++) {
        while (j < n && c[id[j]] >= vv[idq[i]]) {
            int x = find(u[id[j]]), y = find(v[id[j]]);
            f[x] = y; tt[y] = merge(tt[x], tt[y]);
            ++j;
        }
        int b = find(x[idq[i]]);
        ans1[idq[i]] = a[tt[b].p];
        ans2[idq[i]] = max(tt[b].maxn, getmx(tt[b].p, x[idq[i]]));
    }
    for (int i = 1; i <= q; i++) print(ans1[i], ' '), print(ans2[i], '\n');
    return 0;
}