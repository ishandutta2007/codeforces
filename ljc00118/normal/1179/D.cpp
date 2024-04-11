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

const int N = 5e5 + 5;
const double eps = 1e-8;

struct edge_t { int u, v, next; } G[N << 1];

struct ele {
    int siz;
    ll f, val;
    ele () {}
    ele (int a, ll b, ll c) : siz(a), f(b), val(c) {}
    bool operator < (const ele A) const { return siz < A.siz || (siz == A.siz && f < A.f); }
} a[N];

ll f[N], ans;
int head[N], siz[N], q[N];
int n, tot, hd, tl;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

inline ll calc(ll x) { return x * (x - 1) / 2; }

inline double calc(int x, int y) { return (double)(a[y].val - a[x].val) / (a[y].siz - a[x].siz); }

void dfs1(int u, int fa) {
    siz[u] = 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u); siz[u] += siz[v];
    }
    f[u] = calc(siz[u]);
    int len = 0;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        ans = min(ans, f[v] + calc(n - siz[v]));
        f[u] = min(f[u], f[v] + calc(siz[u] - siz[v]));
        a[++len] = ele(siz[v], f[v], f[v] * 2 + 1ll * siz[v] * siz[v]);
    }
    sort(a + 1, a + len + 1); hd = 1; tl = 0;
    for(register int i = 1; i <= len; i++) {
        while(hd < tl && calc(q[hd], q[hd + 1]) - eps <= 2 * n - 2 * a[i].siz - 1) ++hd;
        if(hd <= tl) ans = min(ans, a[q[hd]].f + a[i].f + calc(n - a[q[hd]].siz - a[i].siz));
        if(a[i].siz == a[i - 1].siz) continue;
        while(hd < tl && calc(q[tl - 1], q[tl]) >= calc(q[tl], i) - eps) --tl;
        q[++tl] = i;
    }
}

int main() {
    read(n); ans = 1ll * n * n;
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0);
    print(calc(n) * 2 - ans, '\n');
    return 0;
} //