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

const int N = 1600005;

vector <int> adj[N];
int low[N], dfn[N], col[N], st[N], inst[N];
int n, p, M, m, D, cnt, top, ans;

void tarjan(int u) {
    low[u] = dfn[u] = ++D; st[++top] = u; inst[u] = 1;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++cnt;
        while(st[top + 1] != u) {
            int tmp = st[top--];
            col[tmp] = cnt;
            inst[tmp] = 0;
        }
    }
}

int main() {
    read(n); read(p); read(M); read(m);
    for(register int i = 1; i <= n; i++) {
        int x, y;
        read(x); read(y);
        adj[x + p].push_back(y);
        adj[y + p].push_back(x);
    }
    for(register int i = 2; i <= M; i++) {
        adj[i - 1 + p * 2].push_back(i + p * 2);
        adj[i + p * 2 + M].push_back(i - 1 + p * 2 + M);
    }
    for(register int i = 1; i <= p; i++) {
        int l, r; read(l); read(r);
        if(l != 1) adj[i].push_back(l - 1 + p * 2 + M);
        adj[i].push_back(r + p * 2);
        if(l != 1) adj[l - 1 + p * 2].push_back(i + p);
        adj[r + p * 2 + M].push_back(i + p);
    }
    for(register int i = 1; i <= m; i++) {
        int x, y;
        read(x); read(y);
        adj[x].push_back(y + p);
        adj[y].push_back(x + p);
    }
    for(register int i = 1; i <= (p + M) * 2; i++) if(!dfn[i]) tarjan(i);
    // for(register int i = 1; i <= (p + M) * 2; i++) fprintf(stderr, "%d : %d\n", i, col[i]);
    for(register int i = 1; i <= p; i++) if(col[i] == col[i + p]) { print(-1, '\n'); return 0; }
    for(register int i = 1; i <= M; i++) if(col[i + p * 2] == col[i + p * 2 + M]) { print(-1, '\n'); return 0; }
    for(register int i = 1; i <= p; i++) if(col[i] < col[i + p]) ++ans;
    print(ans, ' ');
    for(register int i = 1; i <= M; i++) if(col[i + p * 2] < col[i + p * 2 + M]) { print(i, '\n'); break; }
    for(register int i = 1; i <= p; i++) if(col[i] < col[i + p]) print(i, ' ');
    putchar('\n');
    return 0;
}