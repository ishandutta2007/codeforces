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
 
const int N = 205, M = 6e5 + 5, INF = 0x7fffffff;
 
struct edge_t { int u, v, next, cap, flow; } G[M << 1];
 
int head[N], nowhead[N], d[N], x[N], y[N], _x[N], _y[N], a[N], b[N];
int n, m, s, t, tot = 1, al, bl;
 
inline void addedge(int u, int v, int cap) {
    G[++tot] = (edge_t) {u, v, head[u], cap, 0}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], 0, 0}, head[v] = tot;
}
 
queue <int> q;
int bfs() {
    memset(d, 0, sizeof(d));
    d[s] = 1; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(register int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(!d[v] && G[i].cap > G[i].flow) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t];
}
 
int dfs(int u, int Flow) {
    if(u == t || !Flow) return Flow;
    int flow = 0, f;
    for(register int &i = nowhead[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].cap - G[i].flow))) > 0) {
            G[i].flow += f; G[i ^ 1].flow -= f;
            Flow -= f; flow += f;
            if(!Flow) break;
        }
    }
    return flow;
}
 
int dinic() {
    int ans = 0;
    while(bfs()) {
        for(register int i = s; i <= t; i++) nowhead[i] = head[i];
        ans += dfs(s, INF);
    }
    return ans;
}
 
int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        read(x[i]); read(y[i]);
        read(_x[i]); read(_y[i]);
        a[++al] = x[i]; a[++al] = _x[i] + 1;
        b[++bl] = y[i]; b[++bl] = _y[i] + 1;
    }
    sort(a + 1, a + al + 1); al = unique(a + 1, a + al + 1) - a - 1;
    sort(b + 1, b + bl + 1); bl = unique(b + 1, b + bl + 1) - b - 1;
    s = 0; t = al + bl + 1;
    for(register int i = 1; i < al; i++) addedge(s, i, a[i + 1] - a[i]);
    for(register int i = 1; i < bl; i++) addedge(i + al, t, b[i + 1] - b[i]);
    for(register int i = 1; i <= m; i++) {
        int xl = lower_bound(a + 1, a + al + 1, x[i]) - a;
        int xr = lower_bound(a + 1, a + al + 1, _x[i] + 1) - a;
        int yl = lower_bound(b + 1, b + bl + 1, y[i]) - b;
        int yr = lower_bound(b + 1, b + bl + 1, _y[i] + 1) - b;
        for(register int j = xl; j < xr; j++) {
            for(register int k = yl; k < yr; k++) {
                addedge(j, k + al, INF);
            }
        }
    }
    print(dinic(), '\n');
    return 0;
}