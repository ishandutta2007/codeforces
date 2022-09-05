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

const int N = 1e5 + 5;

vector <int> adj[N], cyc[N];
int a[N], col[N], dfn[N], low[N], st[N], inst[N];
int n, m, h, top, dfnt, cnt, ans;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfnt; st[++top] = u; inst[u] = 1;
    for (auto v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++cnt;
        int tmp = 0;
        while (tmp != u) {
            tmp = st[top--];
            col[tmp] = cnt;
            inst[tmp] = 0;
            cyc[cnt].push_back(tmp);
        }
    }
}

int main() {
    read(n); read(m); read(h);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        if ((a[u] + 1) % h == a[v]) adj[u].push_back(v);
        if ((a[v] + 1) % h == a[u]) adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        int cando = 1;
        for (auto j : cyc[i]) {
            for (auto v : adj[j]) {
                if (col[j] != col[v]) {
                    cando = 0;
                }
            }
        }
        if (!cando) continue;
        if (!ans || cyc[i].size() < cyc[ans].size()) {
            ans = i;
        }
    }
    print((int)cyc[ans].size(), '\n');
    for (auto i : cyc[ans]) print(i, ' ');
    putchar('\n');
    return 0;
}