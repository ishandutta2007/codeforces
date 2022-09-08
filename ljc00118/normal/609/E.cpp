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

int fa[N], ch[N][2], rev[N], st[N], val[N], maxn[N];
int n, m, top;

int isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }
int get(int u) { return ch[fa[u]][1] == u; }
void update(int u) { maxn[u] = max(val[u], max(maxn[ch[u][0]], maxn[ch[u][1]])); }

void pushdown(int u) {
    if(rev[u]) {
        swap(ch[u][0], ch[u][1]);
        rev[ch[u][0]] ^= 1;
        rev[ch[u][1]] ^= 1;
        rev[u] = 0;
    }
}

void rotate(int u) {
    int old = fa[u], oldd = fa[old], k = get(u);
    if(!isroot(old)) { ch[oldd][get(old)] = u; } fa[u] = oldd;
    ch[old][k] = ch[u][k ^ 1]; fa[ch[u][k ^ 1]] = old;
    ch[u][k ^ 1] = old; fa[old] = u;
    update(old); update(u);
}

void splay(int u) {
    st[top = 1] = u;
    for(register int i = u; !isroot(i); i = fa[i]) st[++top] = fa[i];
    for(register int i = top; i >= 1; i--) pushdown(st[i]);
    for(; !isroot(u); rotate(u)) if(!isroot(fa[u])) rotate(get(u) == get(fa[u]) ? fa[u] : u);
}

void access(int u) {
    for(register int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        ch[u][1] = i;
        update(u);
    }
}

void makeroot(int u) {
    access(u);
    splay(u);
    rev[u] ^= 1;
}

struct ele {
    int l, r, val, id;
    bool operator < (const ele A) const { return val < A.val; }
} G[N];

ll ans;
int f[N], vis[N], cnt;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void link(int u, int v) {
    // fprintf(stderr, "u = %d, v = %d\n", u, v);
    makeroot(u);
    fa[u] = v;
}

int query(int u, int v) {
    makeroot(u);
    access(v);
    splay(v);
    return maxn[v];
}

bool cmp(ele A, ele B) { return A.id < B.id; }

int main() {
    read(n); read(m); cnt = n;
    for(register int i = 1; i <= n; i++) f[i] = i;
    for(register int i = 1; i <= m; i++) {
        read(G[i].l); read(G[i].r); read(G[i].val);
        G[i].id = i;
    }
    sort(G + 1, G + m + 1);
    for(register int i = 1; i <= m; i++) {
        int x = find(G[i].l), y = find(G[i].r);
        if(x != y) {
            f[x] = y;
            ans += G[i].val;
            vis[G[i].id] = 1;
            ++cnt; val[cnt] = maxn[cnt] = G[i].val;
            link(G[i].l, cnt); link(G[i].r, cnt);
        }
    }
    sort(G + 1, G + m + 1, cmp);
    for(register int i = 1; i <= m; i++) {
        if(vis[i]) print(ans, '\n');
        else print(ans - query(G[i].l, G[i].r) + G[i].val, '\n');
    }
    return 0;
}