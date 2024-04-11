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

const int N = 4e5 + 5;

struct edge_t {
    int u, v, next;
} G[N << 1];

int maxn[N << 2], head[N], siz[N], ans[N], tops[N];
int n, tot, dfn;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void update(int u) { maxn[u] = max(maxn[u << 1], maxn[u << 1 | 1]); }

void change(int u, int l, int r, int x, int y) {
    if(l == r) {
        maxn[u] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) change(u << 1, l, mid, x, y);
    else change(u << 1 | 1, mid + 1, r, x, y);
    update(u);
}

int query(int u, int l, int r, int L, int R) {
    if(l > r) return 0;
    if(l <= L && R <= r) return maxn[u];
    int mid = (L + R) >> 1, ans = 0;
    if(mid >= l) ans = max(ans, query(u << 1, l, r, L, mid));
    if(mid + 1 <= r) ans = max(ans, query(u << 1 | 1, l, r, mid + 1, R));
    return ans;
}

void dfs1(int u, int fa) {
    tops[u] = ++dfn; siz[u] = 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
    if(siz[u] <= (n >> 1)) change(1, 1, n, tops[u], siz[u]);
}

void dfs2(int u, int fa, int mx) {
    bool qaq = 1;
    // fprintf(stderr, "%d : %d %d %d\n", u, query(1, 1, tops[u] - 1, 1, n), query(1, tops[u] + siz[u], n, 1, n), mx);
    if(n - siz[u] > (n >> 1) && max(max(query(1, 1, tops[u] - 1, 1, n), query(1, tops[u] + siz[u], n, 1, n)), mx) >= n - siz[u] - (n >> 1)) ans[u] = 1;
    // fprintf(stderr, "ans[%d] = %d\n", u, ans[u]);
    if(n - siz[u] <= (n >> 1)) mx = max(mx, n - siz[u]); else qaq = 0;
    if(siz[u] <= (n >> 1)) change(1, 1, n, tops[u], 0);
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs2(v, u, mx);
        if(siz[v] > (n >> 1)) {
            qaq = 0;
            if(query(1, tops[u], tops[u] + siz[u] - 1, 1, n) >= siz[v] - (n >> 1)) ans[u] = 1;
        }
    }
    // fprintf(stderr, "u = %d, siz[u] = %d, qaq = %d, ans[u] = %d\n", u, siz[u], qaq, ans[u]);
    if(qaq) ans[u] = 1;
    if(siz[u] <= (n >> 1)) change(1, 1, n, tops[u], siz[u]);
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0); dfs2(1, 0, 0);
    for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}