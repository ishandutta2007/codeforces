#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 105, M = 2005;

vector <int> adj[M];
int pre[M], x[M], a[M], F[M], used[M];
int f[N][N];
int n, m, s, b, k, h;

int dfs1(int u) {
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!used[v]) {
            used[v] = 1;
            if(!pre[v] || dfs1(pre[v])) {
                pre[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    memset(f, 0x3f, sizeof(f));
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        int u, v; read(u); read(v);
        f[u][v] = f[v][u] = 1;
    }
    for(register int i = 1; i <= n; i++) f[i][i] = 0;
    for(register int k = 1; k <= n; k++) {
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    read(s); read(b); read(k); read(h);
    for(register int i = 1; i <= s; i++) {
        read(x[i]); read(a[i]); read(F[i]);
    }
    for(register int i = 1; i <= b; i++) {
        int x, d;
        read(x); read(d);
        for(register int j = 1; j <= s; j++) {
            if(f[::x[j]][x] <= F[j] && a[j] >= d) {
                adj[j].push_back(i + s);
                adj[i + s].push_back(j);
            }
        }
    }
    int ans = 0;
    for(register int i = 1; i <= s; i++) {
        memset(used, 0, sizeof(used));
        ans += dfs1(i);
    }
    if(1ll * ans * k <= 1ll * s * h) cout << 1ll * ans * k << endl;
    else cout << 1ll * s * h << endl;
    return 0;
}