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

const int N = 5e5 + 5;

map <pii, int> mp;
vector <int> adj[N], e[N];
int low[N], dfn[N], st[N], u[N], v[N], ans[N], tag[N];
int n, m, dfnt, top;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfnt; st[++top] = u;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                vector <int> cyc;
                while (st[top + 1] != v) {
                    cyc.push_back(st[top]);
                    --top;
                }
                if (cyc.size() == 1) continue;
                cyc.push_back(u);
                vector <int> edg;
                for (int i = 0; i < (int)cyc.size(); i++) {
                    int go = (i + 1) % (int)cyc.size();
                    edg.push_back(mp[make_pair(min(cyc[i], cyc[go]), max(cyc[i], cyc[go]))]);
                }
                int mn = 0, mx = 0;
                for (int i = 1; i < (int)edg.size(); i++) {
                    if (edg[i] < edg[mn]) mn = i;
                    if (edg[i] > edg[mx]) mx = i;
                }
                int cando = 1;
                for (int i = mn, go; i != mx; i = go) {
                    go = (i + 1) % (int)edg.size();
                    if (edg[i] > edg[go]) cando = 0;
                }
                for (int i = mn, go; i != mx; i = go) {
                    go = (i + (int)edg.size() - 1) % (int)edg.size();
                    if (edg[i] > edg[go]) cando = 0;
                }
                if (cando) {
                    e[edg[mx]].push_back(edg[mn]);
                    // fprintf(stderr, "adde : %d %d\n", mx, mn);
                }
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        read(u[i]); read(v[i]);
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        mp[make_pair(min(u[i], v[i]), max(u[i], v[i]))] = i;
    }
    tarjan(1);
    for (int i = 1; i <= n; i++) ans[i] = 1;
    for (int i = m; i >= 1; i--) {
        ans[u[i]] = ans[v[i]] = ans[u[i]] + ans[v[i]] - tag[i];
        for (int j = 0; j < (int)e[i].size(); j++) {
            tag[e[i][j]] += ans[u[i]];
        }
    }
    for (int i = 1; i <= n; i++) print(ans[i] - 1, i == n ? '\n' : ' ');
    return 0;
}