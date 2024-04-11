#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 60;

struct edge_t { int v, nxt, w; } G[N << 1];

queue <int> q;
int dp[N], x[N], y[N], vis[N], w[N], fac[100005];
int n, m, ans;

int par[N], tx[N], ty[N], tw[N], id[N], b[N], big, len;
int head[N], tot;

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

inline void addedge(int u, int v, int w) {
    G[++tot] = (edge_t) {v, head[u], w}, head[u] = tot;
    G[++tot] = (edge_t) {u, head[v], w}, head[v] = tot;
}

bool cmp(int i, int j) { return tx[i] < tx[j]; }

struct atom {
    int u, v, w;
    atom (int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
};

int used[N], g[N][2][N / 2], tem[2][N / 2], siz[N];
void dfs1(int u, int fa) {
    siz[u] = 1; g[u][used[u]][0] = 1;
    for (int i = head[u]; i; i = G[i].nxt) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs1(v, u);
        memset(tem, 0, sizeof(tem));
        for (int j = 0; j <= siz[u] / 2; j++) {
            for (int x = 0; x <= 1; x++) {
                if (!g[u][x][j]) continue;
                for (int k = 0; k <= siz[v] / 2; k++) {
                    for (int y = 0; y <= 1; y++) {
                        tem[x][j + k] = add(tem[x][j + k], mul(g[u][x][j], g[v][y][k]));
                        if (!x && !y) tem[1][j + k + 1] = add(tem[1][j + k + 1], mul(mul(g[u][x][j], g[v][y][k]), G[i].w));
                    }
                }
            }
        }
        memcpy(g[u], tem, sizeof(g[u])); siz[u] += siz[v];
    }
}

int f[1 << 18][19];
void solve(int *x, int *y, int *w, int n) {
    set <int> sx, sy;
    for (int i = 1; i <= n; i++) {
        sx.insert(x[i]);
        sy.insert(y[i]);
    }
    if ((int)min(sx.size(), sy.size()) <= n / 3) {
        if (sx.size() < sy.size()) {
            swap(sx, sy);
            for (int i = 1; i <= n; i++) swap(x[i], y[i]);
        }
        for (int i = 1; i <= n; i++) b[i] = y[i], id[i] = i;
        sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; i++) y[i] = lower_bound(b + 1, b + big + 1, y[i]) - b - 1;
        sort(id + 1, id + n + 1, cmp);
        for (int i = 0; i < (1 << big); i++) memset(f[i], 0, sizeof(f[i]));
        f[0][0] = 1;
        int sum = 0, S = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = l;
            while (r + 1 <= n && x[id[l]] == x[id[r + 1]]) ++r;
            for (int i = S; ; i = (i - 1) & S) {
                for (int j = sum; j >= 0; j--) {
                    if (f[i][j]) {
                        for (int k = l; k <= r; k++) {
                            if ((i >> y[id[k]]) & 1) continue;
                            f[i | (1 << y[id[k]])][j + 1] = add(f[i | (1 << y[id[k]])][j + 1], mul(f[i][j], w[id[k]]));
                        }
                    }
                }
                if (!i) break;
            }
            for (int i = l; i <= r; i++) S |= (1 << y[id[i]]);
            sum = min(sum + 1, big);
        }
        int tt[19]; memset(tt, 0, sizeof(tt));
        for (int i = S; ; i = (i - 1) & S) {
            for (int j = 0; j <= sum; j++) tt[j] = add(tt[j], f[i][j]);
            if (!i) break;
        }
        for (int i = 55; i >= 0; i--) {
            for (int j = 1; j <= min(i, sum); j++) dp[i] = add(dp[i], mul(dp[i - j], tt[j]));
        }
    } else {
        for (int i = 1; i <= n; i++) b[i] = x[i];
        sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; i++) x[i] = lower_bound(b + 1, b + big + 1, x[i]) - b;
        for (int i = 1; i <= n; i++) b[i] = y[i];
        sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; i++) y[i] = lower_bound(b + 1, b + big + 1, y[i]) - b;
        int m = (int)sx.size() + (int)sy.size();
        for (int i = 1; i <= m; i++) par[i] = i;
        memset(head, 0, sizeof(head)); tot = 0;
        vector <atom> seq;
        for (int i = 1; i <= n; i++) {
            int _x = find(x[i]), _y = find(y[i] + (int)sx.size());
            if (_x != _y) {
                par[_x] = _y;
                addedge(x[i], y[i] + (int)sx.size(), w[i]);
            } else {
                seq.push_back(atom(x[i], y[i] + (int)sx.size(), w[i]));
            }
        }
        int tt[30]; memset(tt, 0, sizeof(tt));
        for (int i = 0; i < (1 << (int)seq.size()); i++) {
            memset(used, 0, sizeof(used));
            int cando = 1, ss = 1;
            for (int j = 0; j < (int)seq.size(); j++) {
                if ((i >> j) & 1) {
                    if (used[seq[j].u]) {
                        cando = 0;
                        break;
                    }
                    if (used[seq[j].v]) {
                        cando = 0;
                        break;
                    }
                    used[seq[j].u] = used[seq[j].v] = 1;
                    ss = mul(ss, seq[j].w);
                }
            }
            if (cando) {
                memset(g, 0, sizeof(g));
                dfs1(1, 0);
                int popc = __builtin_popcount(i);
                for (int i = 0; i <= 29 - popc; i++) tt[i + popc] = add(tt[i + popc], mul(ss, add(g[1][0][i], g[1][1][i])));
            }
        }
        for (int i = 55; i >= 0; i--) {
            for (int j = 1; j <= min(i, 29); j++) dp[i] = add(dp[i], mul(dp[i - j], tt[j]));
        }
    }
}

int main() {
    // freopen("matrix.in", "r", stdin);
    // freopen("matrix.out", "w", stdout);
    read(n); read(m);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    for (int i = 1; i <= m; i++) read(x[i]), read(y[i]), read(w[i]), --w[i];
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        if (!vis[i]) {
            len = 0;
            q.push(i); vis[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                ++len; tx[len] = x[u]; ty[len] = y[u]; tw[len] = w[u];
                for (int v = 1; v <= m; v++) {
                    if (!vis[v] && (x[u] == x[v] || y[u] == y[v])) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            solve(tx, ty, tw, len);
        }
    }
    for (int i = 0; i <= min(n, m); i++) ans = add(ans, mul(dp[i], fac[n - i]));
    print(ans, '\n');
    return 0;
}