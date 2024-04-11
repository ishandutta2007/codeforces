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

const int N = 1e5 + 5, K = 205, md = 1e9 + 7;

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline void add(int &x, int y) {
    x += y;
    if(x >= md) x -= md;
}

inline void sub(int &x, int y) {
    x -= y;
    if(x < 0) x += md;
}

struct edge_t {
    int u, v, next;
} G[N << 1];

int f[N][K], s2[K][K], siz[N], head[N], fac[N], res[N];
int n, k, tot, ans;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

int tmp[K];
void dfs1(int u, int fa) {
    siz[u] = 1; f[u][0] = 2;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        for(register int j = 0; j <= k; j++) sub(res[j], f[v][j]);
        memset(tmp, 0, sizeof(tmp));
        // for(register int j = 0; j <= k; j++) fprintf(stderr, "f[%d][%d] = %d\n", u, j, f[u][j]);
        // for(register int j = 0; j <= k; j++) fprintf(stderr, "f[%d][%d] = %d\n", v, j, f[v][j]);
        for(register int j = 0; j <= min(::k, siz[u]); j++)
            for(register int k = 0; k <= min(::k - j, siz[v]); k++)
                add(tmp[j + k], mul(f[u][j], f[v][k]));
        memcpy(f[u], tmp, sizeof(f[u]));
        siz[u] += siz[v];
    }
    for(register int i = 0; i <= k; i++) add(res[i], f[u][i]);
    for(register int i = k; i >= 1; i--) add(f[u][i], f[u][i - 1]);
    sub(f[u][1], 1);
}

int main() {
    read(n); read(k);
    for(register int i = 1; i < n; i++) {
        int u, v; read(u); read(v);
        addedge(u, v);
    }
    s2[0][0] = fac[0] = 1;
    for(register int i = 1; i <= k; i++) fac[i] = mul(fac[i - 1], i);
    for(register int i = 1; i <= k; i++)
        for(register int j = 1; j <= i; j++)
            s2[i][j] = (s2[i - 1][j - 1] + 1ll * s2[i - 1][j] * j) % md;
    dfs1(1, 0);
    // for(register int i = 0; i <= k; i++) fprintf(stderr, "res[%d] = %d\n", i, res[i]);
    for(register int i = 0; i <= k; i++) add(ans, mul(fac[i], mul(s2[k][i], res[i])));
    cout << ans << endl;
    return 0;
}