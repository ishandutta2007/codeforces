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

const int N = 20005;

unordered_map <int, int> e[N];
vector <int> adj[N], vec[N];
int f[N], low[N], dfn[N], st[N], choose[N], vis[N], cyc[N];
int n, m, top, tot, cnt, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void tarjan(int u) {
    low[u] = dfn[u] = ++tot; st[++top] = u;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                vector <int> col;
                int las = u, tmp = 0;
                while (tmp != v) {
                    tmp = st[top--];
                    col.push_back(e[las][tmp]);
                    las = tmp;
                }
                col.push_back(e[u][las]);
                sort(col.begin(), col.end());
                int cando = 0;
                for (int i = 1; i < (int)col.size(); i++) {
                    if (col[i - 1] == col[i]) {
                        cando = 1;
                        break;
                    }
                }
                if (!cando) ++cnt;
                for (int i = 0; i < (int)col.size(); i++) {
                    if (cando) choose[col[i]] = 1;
                    else vec[col[i]].push_back(cnt);
                }
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}

void merge(int u, int v) {
    int x = find(u), y = find(v);
    if (x == y) {
        if (!cyc[x]) ++ans, cyc[x] = 1;
    } else {
        if (!cyc[x] || !cyc[y]) ++ans;
        f[x] = y; cyc[y] |= cyc[x];
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        read(u); read(v); read(c);
        adj[u].push_back(v);
        adj[v].push_back(u);
        e[u][v] = e[v][u] = c;
        vis[c] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (vis[i]) ++ans;
    }
    ans -= cnt;
    for (int i = 1; i <= cnt; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        if (choose[i]) {
            for (int j = 0; j < (int)vec[i].size(); j++) {
                int x = find(vec[i][j]);
                if (!cyc[x]) {
                    cyc[x] = 1;
                    ++ans;
                }
            }
            continue;
        }
        for (int j = 1; j < (int)vec[i].size(); j++) merge(vec[i][0], vec[i][j]);
    }
    print(ans, '\n');
    return 0;
}