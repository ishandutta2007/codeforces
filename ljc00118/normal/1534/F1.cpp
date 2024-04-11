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

const int N = 8e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector <int> adj[N], edg[N];
char c[N];
int low[N], dfn[N], st[N], inst[N], col[N], hav[N], f[N];
int n, m, tot, cnt, ans, top;

inline int s(int x, int y) { return (x - 1) * m + y; }

void tarjan(int u) {
    low[u] = dfn[u] = ++tot; st[++top] = u; inst[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++cnt;
        while (st[top + 1] != u) {
            int tmp = st[top--];
            col[tmp] = cnt;
            inst[tmp] = 0;
            if (tmp <= n * m && c[tmp] == '#') hav[cnt] = 1;
        }
    }
}

void dfs1(int u) {
    if (f[u] != -1) return;
    f[u] = hav[u];
    int tem = 0;
    for (int i = 0; i < (int)edg[u].size(); i++) {
        int v = edg[u][i];
        dfs1(v); tem |= f[v];
        // fprintf(stderr, "u = %d, v = %d, hav[u] = %d, f[v] = %d\n", u, v, hav[u], f[v]);
    }
    // fprintf(stderr, "u = %d, hav[u] = %d\n", u, hav[u]);
    if (!tem && hav[u]) ++ans;
    f[u] |= tem;
}

int main() {
    memset(f, -1, sizeof(f));
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t = getchar();
            while (t != '.' && t != '#') t = getchar();
            c[s(i, j)] = t;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int now = s(i, j) + n * m;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x <= 0 || x > n || y <= 0 || y > m) continue;
                if (c[s(x, y)] == '#') adj[now].push_back(s(x, y));
            }
            if (i != n) adj[now].push_back(s(i + 1, j) + n * m);
            adj[now].push_back(s(i, j));
            if (c[s(i, j)] == '#') adj[s(i, j)].push_back(now);
        }
    }
    // for (int i = 0; i < (int)adj[13].size(); i++) cout << adj[13][i] << " ";
    // cout << endl;
    for (int i = 1; i <= n * m * 2; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    // for (int i = 1; i <= n * m * 2; i++) fprintf(stderr, "col[%d] = %d\n", i, col[i]);
    for (int i = 1; i <= n * m * 2; i++) {
        for (int j = 0; j < (int)adj[i].size(); j++) {
            int v = adj[i][j];
            if (col[i] != col[v]) edg[col[v]].push_back(col[i]);
        }
    }
    for (int i = 1; i <= cnt; i++) dfs1(i);
    print(ans, '\n');
    return 0;
}