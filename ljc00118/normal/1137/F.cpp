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

const int N = 2e5 + 5;

struct fenwick {
    int f[N << 1], n;

    inline int lowbit(int x) { return x & -x; }

    void add(int x, int y) {
        for(register int i = x; i <= n; i += lowbit(i))
            f[i] += y;
    }

    int query(int x) {
        int ans = 0;
        for(register int i = x; i; i -= lowbit(i))
            ans += f[i];
        return ans;
    }
} tr;

priority_queue <int, vector <int>, greater <int> > Q;
int ch[N][2], fa[N], rev[N], tag[N], val[N], siz[N], st[N], in[N];
int n, m, top, now;

int isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }
int get(int u) { return ch[fa[u]][1] == u; }
void update(int u) { siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }

void pushdown(int u) {
    if(rev[u]) {
        swap(ch[u][0], ch[u][1]);
        rev[ch[u][0]] ^= 1;
        rev[ch[u][1]] ^= 1;
        rev[u] = 0;
    }
    if(tag[u]) {
        val[ch[u][0]] = tag[ch[u][0]] = tag[u];
        val[ch[u][1]] = tag[ch[u][1]] = tag[u];
        tag[u] = 0;
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

void access(int u, int ti) {
    for(register int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        ch[u][1] = 0;
        update(u);
        tr.add(val[u], -siz[u]);
        val[u] = tag[u] = ti;
        tr.add(val[u], siz[u]);
        ch[u][1] = i;
        update(u);
    }
}

int query(int u) {
    splay(u); pushdown(u);
    return tr.query(val[u]) - siz[ch[u][0]];
}

vector <int> adj[N];
void dfs1(int u, int fa) {
    if(fa) ::fa[u] = fa;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        if(adj[u][i] != fa) {
            dfs1(adj[u][i], u);
        }
    }
}

int main() {
    read(n); read(m); tr.n = n + m; now = n;
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++in[v]; ++in[u];
    }
    dfs1(n, 0);
    for(register int i = 1; i <= n; i++) if(in[i] == 1) Q.push(i);
    for(register int i = 1; i <= n; i++) {
        int u = Q.top(); Q.pop();
        val[u] = i; tr.add(i, 1);
        for(register unsigned j = 0; j < adj[u].size(); j++) {
            if(!val[adj[u][j]]) {
                --in[adj[u][j]];
                if(in[adj[u][j]] == 1) Q.push(adj[u][j]);
            }
        }
    }
    while(m--) {
        static char c[10];
        scanf("%s", c + 1);
        if(c[1] == 'u') {
            int u; read(u);
            access(u, ++now);
            splay(u);
            rev[u] ^= 1;
        }
        if(c[1] == 'w') {
            int u; read(u);
            print(query(u), '\n');
        }
        if(c[1] == 'c') {
            int x, y;
            read(x); read(y);
            print(query(x) < query(y) ? x : y, '\n');
        }
    }
    return 0;
} //