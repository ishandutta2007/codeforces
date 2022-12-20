#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 1e5 + 10;
int n, m;
vi e[maxn];
vector <pii> ntr;

struct dsu {
    int fa[maxn];
    void init(int n) { iota(fa + 1, fa + n + 1, 1); }
    int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
    void merge(int x, int y) { fa[get(x)] = get(y); }
} d;

int dep[maxn], f[maxn][20];
void dfs1(int u, int pre) {
    f[u][0] = pre, dep[u] = dep[pre] + 1;
    for (int i = 1; i < 20; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v : e[u]) if (v != pre) dfs1(v, u);
}

int jump(int x, int y) {
    for (int i = 19; i >= 0; --i)
        if (dep[x] - dep[y] > (1 << i)) x = f[x][i];
    return x;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; --i)
        if (dep[x] - dep[y] >= (1 << i)) x = f[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int c[maxn];

void dfs2(int u, int pre) {
    c[u] += c[pre];
    for (int v : e[u]) if (v != pre) dfs2(v, u);
}

int main() {
    read(n, m);
    d.init(n);
    for (int i = 1; i <= m; ++i) {
        int x, y; read(x, y);
        if (d.get(x) == d.get(y)) ntr.push_back(make_pair(x, y));
        else e[x].push_back(y), e[y].push_back(x), d.merge(x, y);
    }
    dfs1(1, 0);
    for (pii p : ntr) {
        int x = p.fir, y = p.sec, z = lca(x, y);
        if (dep[x] < dep[y]) swap(x, y);
        if (z == y) c[jump(x, y)]++, c[x]--;
        else c[1]++, c[x]--, c[y]--;
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) write(c[i] == 0);
	return 0;
}