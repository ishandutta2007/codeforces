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

const int N = 2e5 + 5;

struct edge_t { int u, v, next, val; } G[N << 1];

int siz[N], maxn[N], head[N];
int T, n, allsize, root, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void getroot(int u, int fa) {
    siz[u] = 1; maxn[u] = 0;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        getroot(v, u); siz[u] += siz[v];
        maxn[u] = max(maxn[u], siz[v]);
    }
    maxn[u] = max(maxn[u], allsize - siz[u]);
    if (maxn[u] < maxn[root]) root = u;
}

ll ans1, ans2;
void dfs1(int u, int fa, int val) {
    siz[u] = 1;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs1(v, u, G[i].val);
        siz[u] += siz[v];
        ans2 += 1ll * siz[v] * G[i].val;
    }
    if (siz[u] & 1) ans1 += val;
}

int main() {
    read(T);
    while (T--) {
        read(n); n <<= 1;
        for (int i = 1; i <= n; i++) head[i] = 0;
        tot = 0;
        for (int i = 1; i < n; i++) {
            int u, v, val;
            read(u); read(v); read(val);
            addedge(u, v, val);
        }
        allsize = n; maxn[0] = n + 1; root = 0;
        ans1 = ans2 = 0;
        getroot(1, 0); dfs1(root, 0, 0);
        print(ans1, ' '); print(ans2, '\n');
    }
    return 0;
}