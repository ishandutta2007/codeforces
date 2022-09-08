#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 2e5 + 5, INF = 0x7fffffff;

struct edge_t {
    int u, v, next, val, id;
} G[N << 1];

struct ele {
    int u, v, val, id;
    ele (int a = 0, int b = 0, int c = 0, int d = 0) : u(a), v(b), val(c), id(d) {}
    bool operator < (const ele A) const { return val < A.val; }
} E[N];

int head[N], x[N], y[N], val[N], cost[N], fa[N], d[N], cnt[N], id[N];
int n, m, s, tot; ll sum, ans = 0x7fffffffffffffff;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

inline void addedge(int u, int v, int val, int id) {
    G[++tot] = (edge_t) {u, v, head[u], val, id}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val, id}, head[v] = tot;
}

int father[N][20], mx[N][20];
void dfs1(int u, int fa) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        id[v] = G[i].id; d[v] = d[u] + 1; father[v][0] = u; mx[v][0] = G[i].val;
        for(register int j = 1; j <= 18; j++) {
            father[v][j] = father[father[v][j - 1]][j - 1];
            mx[v][j] = max(mx[v][j - 1], mx[father[v][j - 1]][j - 1]);
        }
        dfs1(v, u);
    }
}

int query(int u, int v) {
    int ans = -INF;
    if(d[u] < d[v]) swap(u, v);
    for(register int i = 18; i >= 0; i--) {
        if(d[father[u][i]] >= d[v]) {
            ans = max(ans, mx[u][i]);
            u = father[u][i];
        }
    }
    if(u == v) return ans;
    for(register int i = 18; i >= 0; i--) {
        if(father[u][i] != father[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = father[u][i]; v = father[v][i];
        }
    }
    return max(ans, max(mx[u][0], mx[v][0]));
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) fa[i] = i;
    for(register int i = 1; i <= m; i++) read(val[i]);
    for(register int i = 1; i <= m; i++) read(cost[i]);
    for(register int i = 1; i <= m; i++) read(x[i]), read(y[i]), E[i] = ele(x[i], y[i], val[i], i);
    read(s);
    sort(E + 1, E + m + 1);
    for(register int i = 1; i <= m; i++) {
        int fx = find(E[i].u);
        int fy = find(E[i].v);
        if(fx != fy) {
            fa[fx] = fy;
            addedge(E[i].u, E[i].v, E[i].val, E[i].id);
            sum += E[i].val;
            ++cnt[E[i].id];
        }
    }
    d[1] = 1; dfs1(1, 0);
    for(register int i = 1; i <= m; i++) ans = min(ans, sum - query(x[i], y[i]) + val[i] - s / cost[i]);
    cout << ans << endl;
    for(register int i = 1; i <= m; i++) {
        if(sum - query(x[i], y[i]) + val[i] - s / cost[i] == ans) {
            ++cnt[i];
            int now = query(x[i], y[i]);
            while(x[i] != y[i]) {
                if(d[x[i]] < d[y[i]]) swap(x[i], y[i]);
                if(val[id[x[i]]] == now) {
                    --cnt[id[x[i]]];
                    break;
                }
                x[i] = father[x[i]][0];
            }
            val[i] -= s / cost[i];
            for(register int i = 1; i <= m; i++) {
                if(cnt[i]) {
                    print(i, ' ');
                    print(val[i], '\n');
                }
            }
            return 0;
        }
    }
    return 0;
}