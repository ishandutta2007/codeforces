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

const int N = 5e5 + 5;

struct edge_t {
    int u, v, next;
} G[N << 1];

int head[N], w[N];
int n, tot;
ll ans;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

int fa[N][20], root = 1;
void dfs1(int u) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa[u][0]) continue;
        fa[v][0] = u;
        for(register int j = 1; j <= 19; j++) fa[v][j] = fa[fa[v][j - 1]][j - 1];
        ll minn = 1ll * w[v] + w[u];
        for(register int j = 1; j <= 19; j++) {
            int go = fa[v][j];
            if(!go) go = root;
            minn = min(minn, 1ll * j * w[go] + w[v] + w[go]);
            if(!fa[v][j]) break;
        }
        ans += minn;
        dfs1(v);
    }
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(w[i]);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    for(register int i = 2; i <= n; i++) if(w[i] < w[root]) root = i;
    dfs1(root);
    cout << ans << endl;
    return 0;
}