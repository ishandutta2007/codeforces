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

const int N = 3e5 + 5;

struct fenwick {
    ll f[N]; int n;

    void clear() { memset(f, 0, sizeof(f)); }

    inline int lowbit(int x) { return x & -x; }

    inline void add(int x, int y) {
        for(register int i = x; i <= n; i += lowbit(i))
            f[i] += y;
    }

    inline ll query(int x) {
        ll ans = 0;
        for(register int i = x; i; i -= lowbit(i))
            ans += f[i];
        return ans;
    }
} tr[2];

struct edge_t {
    int u, v, next;
} G[N << 1];

vector <int> id[N];
ll ans[N];
int head[N], low[N], dfn[N], st[N], l[N], r[N], R[N];
int n, m, q, tot, cnt, top;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++cnt; st[++top] = u;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                int minn = u, maxn = u, cnt = 0;
                while(st[top + 1] != v) {
                    int tmp = st[top--];
                    minn = min(minn, tmp);
                    maxn = max(maxn, tmp);
                    ++cnt;
                }
                if(cnt > 1) R[minn] = min(R[minn], maxn);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    read(n); read(m); tr[0].n = tr[1].n = n;
    for(register int i = 1; i <= n; i++) R[i] = n + 1;
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    read(q);
    for(register int i = 1; i <= q; i++) read(l[i]), read(r[i]), id[l[i]].push_back(i);
    for(register int i = 1; i <= n; i++) if(!dfn[i]) top = 0, tarjan(i);
    for(register int i = n - 1; i >= 1; i--) R[i] = min(R[i], R[i + 1]);
    // for(register int i = 1; i <= n; i++) fprintf(stderr, "R[%d] = %d\n", i, R[i]);
    for(register int i = n; i >= 1; i--) {
        int j = R[i];
        tr[0].add(i, -(i - 1));
        tr[0].add(j, j - 1);
        tr[1].add(i, 1);
        tr[1].add(j, -1);
        for(register unsigned j = 0; j < id[i].size(); j++) {
            int u = id[i][j];
            ans[u] += tr[0].query(r[u]) + r[u] * tr[1].query(r[u]);
        }
    }
    for(register int i = 1; i <= q; i++) print(ans[i], '\n');
    return 0;
}