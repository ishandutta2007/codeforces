#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1e5 + 5, M = 2e5 + 5;

struct edge_t { int u, v, next; } G[M];

int x[M], y[M], cnt;
int deg[N], in[N], f[N], head[N], tag[N], q[N], top;
int n, m, tot, las;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u, int fa) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u); ++in[u];
    }
}

void dfs2(int u, int fa) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs2(v, u);
        tag[u] ^= tag[v];
        if(tag[v]) print(v, ' '), print(u, '\n');
        else print(u, ' '), print(v, '\n');
    }
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) f[i] = i;
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v); ++deg[u]; ++deg[v];
        if(find(u) != find(v)) {
            addedge(u, v);
            f[find(u)] = find(v);
        } else x[++cnt] = u, y[cnt] = v, ++in[u];
    }
    for(register int i = 1; i <= n; i++) {
        if(deg[i] & 1) {
            if(las) x[++cnt] = las, y[cnt] = i, ++in[las], las = 0;
            else las = i;
        }
    }
    dfs1(1, 0);
    for(register int i = 1; i <= n; i++) if(in[i] & 1) q[++top] = i;
    if(top & 1) x[++cnt] = q[top], y[cnt] = q[top], --top;
    for(register int i = 1; i <= top; i++) tag[q[i]] ^= 1;
    print(cnt + n - 1, '\n');
    for(register int i = 1; i <= cnt; i++) print(x[i], ' '), print(y[i], '\n');
    dfs2(1, 0);
    return 0;
}