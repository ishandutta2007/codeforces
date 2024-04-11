#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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
 
const int N = 250005;

vector <int> adj[N];
int ch[N][2], fa[N], rev[N], st[N], f[N];
int n, top;

int find(int x) { return !f[x] ? x : f[x] = find(f[x]); }

bool isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }
bool get(int u) { return ch[fa[u]][1] == u; }

void rotate(int u) {
    int old = fa[u], oldd = fa[old], k = get(u);
    if (!isroot(old)) { ch[oldd][get(old)] = u; } fa[u] = oldd;
    ch[old][k] = ch[u][k ^ 1]; fa[ch[u][k ^ 1]] = old;
    ch[u][k ^ 1] = old; fa[old] = u;
}

void pushdown(int u) {
    if (rev[u]) {
        swap(ch[u][0], ch[u][1]);
        rev[ch[u][0]] ^= 1;
        rev[ch[u][1]] ^= 1;
        rev[u] = 0;
    }
}

void splay(int u) {
    st[top = 1] = u;
    for (int i = u; !isroot(i); i = fa[i]) st[++top] = fa[i];
    for (int i = top; i >= 1; i--) pushdown(st[i]);
    for (; !isroot(u); rotate(u)) if (!isroot(fa[u])) rotate(get(u) == get(fa[u]) ? fa[u] : u);
}

void access(int u) {
    for (int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        ch[u][1] = i;
    }
}

void makeroot(int u) {
    access(u); splay(u);
    rev[u] ^= 1;
}

void link(int u, int v) {
    makeroot(u);
    fa[u] = v;
}

void cut(int u, int v) {
    makeroot(u); access(v); splay(v);
    fa[u] = ch[v][0] = 0;
}

pair <int, int> query(int u, int v) {
    makeroot(u); access(v); splay(v);
    pair <int, int> ans;
    int las;
    while (v) {
        las = v;
        pushdown(v);
        if (find(v) != find(u)) {
            ans.first = v;
            v = ch[v][0];
        } else {
            ans.second = v;
            v = ch[v][1];
        }
    }
    splay(las);
    return ans;
}

void dfs1(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs1(v, u);
    }
    if (fa) {
        pair <int, int> ans = query(u, fa);
        print(u, ' '); print(fa, ' '); print(ans.first, ' '); print(ans.second, '\n');
        f[find(u)] = find(fa); cut(ans.first, ans.second); link(u, fa);
    }
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        link(u, v);
    }
    print(n - 1, '\n');
    dfs1(1, 0);
    return 0;
}