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

const int N = 105;

struct atom {
    ull a, b; int id;
    atom (ull x = 0, ull y = 0, int z = 0) : a(x), b(y), id(z) {}
};

void set0(atom &x, int y) {
    if (y <= 63) {
        if ((x.a >> y) & 1) x.a -= 1ull << y;
    } else {
        if ((x.b >> (y - 64)) & 1) x.b -= 1ull << (y - 64);
    }
}

void set1(atom &x, int y) {
    if (y <= 63) {
        if (!((x.a >> y) & 1)) x.a += 1ull << y;
    } else {
        if (!((x.b >> (y - 64)) & 1)) x.b += 1ull << (y - 64);
    }
}

int getbit(atom x, int y) {
    if (y <= 63) {
        return (x.a >> y) & 1;
    } else {
        return (x.b >> (y - 64)) & 1;
    }
}

vector <int> adj[N];
atom f[N];
int id[N], fa[N], vis[N];
int n;

bool operator < (const atom a, const atom b) {
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
}

bool check(atom now, vector <atom> son) {
    priority_queue <atom> Q;
    for (int i = 0; i < (int)son.size(); i++) Q.push(son[i]);
    for (int i = n; i >= 1 && !Q.empty(); i--) {
        if (getbit(now, i)) {
            atom x = Q.top(); Q.pop();
            if (!Q.empty() && getbit(Q.top(), i)) return 0;
            if (getbit(x, i)) set0(x, i), Q.push(x);
            else id[x.id] = i;
        } else if (getbit(Q.top(), i)) return 0;
    }
    return Q.empty();
}

void dfs1(int u, int fa) {
    vector <atom> son;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        ::fa[v] = u; dfs1(v, u);
        son.push_back(f[v]);
    }
    for (int i = 1; i <= n; i++) set1(f[u], i);
    for (int i = n; i >= 1; i--) {
        set0(f[u], i);
        if (!check(f[u], son)) set1(f[u], i);
    }
    // fprintf(stderr, "%d : ", u);
    // for (int i = 1; i <= n; i++) fprintf(stderr, "%d", getbit(f[u], i));
    // fprintf(stderr, "\n");
    check(f[u], son);
    f[u].id = u;
}

inline int getid(int u, int v) {
    if (fa[u] == v) return u;
    return v;
}

int mxid;
void dfs2(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[getid(u, v)] || v == fa) continue;
        if (!mxid || id[getid(u, v)] > id[mxid]) mxid = getid(u, v);
        dfs2(v, u);
    }
}

int lc[N], rc[N];
void build(int u) {
    vis[u] = 1;
    mxid = 0; dfs2(fa[u], 0); lc[u] = mxid;
    mxid = 0; dfs2(u, 0); rc[u] = mxid;
    if (lc[u]) build(lc[u]);
    if (rc[u]) build(rc[u]);
}

int query(int u, int v) {
    printf("? %d %d\n", u, v);
    fflush(stdout);
    int ans; read(ans); return ans;
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    int maxn = 2;
    for (int i = 3; i <= n; i++) {
        if (id[i] > id[maxn]) {
            maxn = i;
        }
    }
    // for (int i = 2; i <= n; i++) fprintf(stderr, "id[%d] = %d\n", i, id[i]);
    build(maxn);
    int now = maxn;
    while (now) {
        int ans = query(fa[now], now);
        if (ans == fa[now]) {
            if (!lc[now]) {
                now = fa[now];
                break;
            }
            now = lc[now];
        } else {
            if (!rc[now]) break;
            now = rc[now];
        }
    }
    printf("! %d\n", now);
    fflush(stdout);
    return 0;
}