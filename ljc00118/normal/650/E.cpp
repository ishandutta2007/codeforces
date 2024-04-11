#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
#define mp make_pair
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

const int N = 5e5 + 5;

pair <pii, pii> ans[N];
vector <int> adj[2][N];
int fa[2][N], f[N];
int n, len;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int id, int u) {
    for(register unsigned i = 0; i < adj[id][u].size(); i++) {
        int v = adj[id][u][i];
        if(v == fa[id][u]) continue;
        fa[id][v] = u;
        dfs1(id, v);
    }
}

void dfs2(int u) {
    for(register unsigned i = 0; i < adj[0][u].size(); i++) {
        int v = adj[0][u][i];
        if(v == fa[0][u]) continue;
        dfs2(v);
        // fprintf(stderr, "u = %d, v = %d\n", u, v);
        // fprintf(stderr, "fa[1][u] = %d, fa[1][v] = %d\n", fa[1][u], fa[1][v]);
        if(fa[1][u] != v && fa[1][v] != u) ans[++len] = mp(mp(v, u), mp(find(v), fa[1][find(v)]));
    }
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[0][u].push_back(v);
        adj[0][v].push_back(u);
    }
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[1][u].push_back(v);
        adj[1][v].push_back(u);
    }
    dfs1(0, 1); dfs1(1, 1); f[1] = 1;
    for(register int i = 2; i <= n; i++) {
        if(fa[0][i] == fa[1][i] || fa[0][fa[1][i]] == i) f[i] = fa[1][i];
        else f[i] = i;
    }
    dfs2(1);
    print(len, '\n');
    for(register int i = 1; i <= len; i++) {
        print(ans[i].first.first, ' ');
        print(ans[i].first.second, ' ');
        print(ans[i].second.first, ' ');
        print(ans[i].second.second, '\n');
    }
    return 0;
}