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

const int N = 5e5 + 5;

vector <int> adj[N];
int fa[N][20];
int del[N], u[N], v[N], f[N], opt[N], x[N], val[N], tops[N], pre[N], siz[N], w[N];
int n, m, q, tot, dfn;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u) {
    tops[u] = ++dfn; siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v); siz[u] += siz[v];
    }
}

int mx[N << 2];

void update(int u) { mx[u] = max(mx[u << 1], mx[u << 1 | 1]); }

void change(int u, int l, int r, int x, int y) {
    if (l == r) {
        mx[u] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) change(u << 1, l, mid, x, y);
    else change(u << 1 | 1, mid + 1, r, x, y);
    update(u);
}

int query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return mx[u];
    int mid = (L + R) >> 1, ans = 0;
    if (mid >= l) ans = max(ans, query(u << 1, L, mid, l, r));
    if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, mid + 1, R, l, r));
    return ans;
}

int main() {
    read(n); read(m); read(q); tot = n;
    for (int i = 1; i <= n; i++) read(w[i]), pre[w[i]] = i, f[i] = i;
    for (int i = 1; i <= m; i++) read(u[i]), read(v[i]);
    for (int i = 1; i <= q; i++) {
        read(opt[i]); read(x[i]);
        if (opt[i] == 2) del[x[i]] = 1;
    }
    for (int i = 1; i <= m; i++) {
        if (!del[i]) {
            int _x = find(u[i]), _y = find(v[i]);
            if (_x == _y) continue;
            ++tot; val[tot] = q + 1;
            f[tot] = f[_x] = f[_y] = fa[_x][0] = fa[_y][0] = tot;
            adj[tot].push_back(_x); adj[tot].push_back(_y);
        }
    }
    for (int i = q; i >= 1; i--) {
        if (opt[i] == 2) {
            int _x = find(u[x[i]]), _y = find(v[x[i]]);
            if (_x == _y) continue;
            ++tot; val[tot] = i;
            f[tot] = f[_x] = f[_y] = fa[_x][0] = fa[_y][0] = tot;
            adj[tot].push_back(_x); adj[tot].push_back(_y);
        }
    }
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= tot; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    for (int i = 1; i <= tot; i++) if (find(i) == i) dfs1(i);
    for (int i = 1; i <= n; i++) change(1, 1, tot, tops[i], w[i]);
    for (int i = 1; i <= q; i++) {
        if (opt[i] == 1) {
            int u = x[i];
            for (int j = 19; j >= 0; j--) {
                if (fa[u][j] && val[fa[u][j]] >= i) {
                    u = fa[u][j];
                }
            }
            int pos = pre[query(1, 1, tot, tops[u], tops[u] + siz[u] - 1)];
            if (w[pos] == 0) print(0, '\n');
            else {
                print(w[pos], '\n');
                change(1, 1, tot, tops[pos], 0);
            }
        }
    }
    return 0;
}