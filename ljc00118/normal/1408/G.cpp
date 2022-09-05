#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 3005, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

struct ele {
    int u, v, w;
    ele (int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
    bool operator < (const ele A) const { return w < A.w; }
} e[N * N];

vector <int> adj[N];
int f[N], dp[N][N / 2], sz[N], cnt[N], siz[N], tmp[N];
int n, len, tot;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u) {
    dp[u][0] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v);
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j <= siz[u]; j++) {
            for (int k = 1; k <= siz[v]; k++) {
                addx(tmp[j + k], mul(dp[u][j], dp[v][k]));
            }
        }
        memcpy(dp[u], tmp, sizeof(dp[u])); siz[u] += siz[v];
    }
    if (cnt[u] == sz[u] * (sz[u] - 1) / 2) {
        siz[u] = max(siz[u], 1);
        dp[u][1] = add(dp[u][1], 1);
    }
}

int main() {
    read(n); tot = n;
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; read(w);
            if (i < j) e[++len] = ele(i, j, w);
        }
    }
    sort(e + 1, e + len + 1);
    for (int i = 1; i <= len; i++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) {
            ++cnt[x];
            continue;
        }
        ++tot; f[x] = f[y] = f[tot] = tot;
        adj[tot].push_back(x);
        adj[tot].push_back(y);
        sz[tot] = sz[x] + sz[y];
        cnt[tot] = cnt[x] + cnt[y] + 1;
    }
    dfs1(tot);
    for (int i = 1; i <= n; i++) print(dp[tot][i], i == n ? '\n' : ' ');
    return 0;
}