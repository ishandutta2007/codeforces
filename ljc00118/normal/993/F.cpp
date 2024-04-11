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

const int N = 105;

struct node_t { int opt, x, y; } a[N], b[N];

char c[N];
int n, m, k, ans = -1;

int getop() {
    scanf("%s", c + 1);
    if (c[1] == 'a') return 0;
    if (c[1] == 'n' && c[2] == 'a') return 1;
    if (c[1] == 'o') return 2;
    return 3;
}

int getval(int x, int y, int op) {
    if (op == 0) return x & y;
    if (op == 1) return (x & y) ^ 1;
    if (op == 2) return x | y;
    return (x | y) ^ 1;
}

pii getxy() {
    scanf("%s", c + 1);
    int x = 0, y = 0, len = strlen(c + 1);
    for (int i = 1; i <= len; i++) {
        if (c[i] == 'x') {
            if (!x) x = i;
            else y = i;
        }
    }
    return make_pair(x, y);
}

node_t getNode() {
    node_t a;
    a.opt = getop();
    pii tmp = getxy();
    a.x = tmp.first; a.y = tmp.second;
    return a;
}

vector <int> adj[N];
int low[N], dfn[N], inst[N], st[N], col[N], top, cnt, ccnt;

void tarjan(int u) {
    low[u] = dfn[u] = ++cnt; inst[u] = 1; st[++top] = u;
    for (auto v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++ccnt;
        int tmp = 0;
        while (tmp != u) {
            tmp = st[top--];
            col[tmp] = ccnt;
            inst[tmp] = 0;
        }
    }
}

int t[N], used[N], val[N], seq[5], slen, ban;

void dfs1(int u, int i) {
    if (u == slen + 1) {
        ban |= getval(getval(val[a[b[i].x].x], val[a[b[i].x].y], a[b[i].x].opt), getval(val[a[b[i].y].x], val[a[b[i].y].y], a[b[i].y].opt), b[i].opt);
        return;
    }
    val[seq[u]] = 0; dfs1(u + 1, i);
    val[seq[u]] = 1; dfs1(u + 1, i);
}

void solve() {
    memset(t, 0, sizeof(t));
    memset(dfn, 0, sizeof(dfn));
    for (int i = 1; i <= n * 2; i++) adj[i].clear();
    cnt = ccnt = 0;
    int nowans = 0;
    for (int i = 1; i <= k; i++) {
        memset(used, 0, sizeof(used));
        slen = 0;
        auto ins = [&](int x) {
            if (!used[x]) {
                used[x] = 1;
                seq[++slen] = x;
            }
        };
        ins(a[b[i].x].x); ins(a[b[i].x].y);
        ins(a[b[i].y].x); ins(a[b[i].y].y);
        ban = 0; dfs1(1, i);
        if (!ban) {
            ++nowans;
            if (b[i].opt == 0) {
                t[b[i].x] |= 1; t[b[i].y] |= 1;
            }
            if (b[i].opt == 3) {
                t[b[i].x] |= 2; t[b[i].y] |= 2;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 3) {
            ans = max(ans, nowans);
            return;
        }
        if (t[i] == 1) {
            if (a[i].opt == 0) {
                adj[a[i].x].push_back(a[i].y + n);
                adj[a[i].y].push_back(a[i].x + n);
            }
            if (a[i].opt == 1) {
                adj[a[i].x + n].push_back(a[i].x);
                adj[a[i].y + n].push_back(a[i].y);
            }
            if (a[i].opt == 2) {
                adj[a[i].x].push_back(a[i].x + n);
                adj[a[i].y].push_back(a[i].y + n);
            }
            if (a[i].opt == 3) {
                adj[a[i].x + n].push_back(a[i].y);
                adj[a[i].y + n].push_back(a[i].x);
            }
        }
        if (t[i] == 2) {
            if (a[i].opt == 0) {
                adj[a[i].x + n].push_back(a[i].x);
                adj[a[i].y + n].push_back(a[i].y);
            }
            if (a[i].opt == 1) {
                adj[a[i].x].push_back(a[i].y + n);
                adj[a[i].y].push_back(a[i].x + n);
            }
            if (a[i].opt == 2) {
                adj[a[i].x + n].push_back(a[i].y);
                adj[a[i].y + n].push_back(a[i].x);
            }
            if (a[i].opt == 3) {
                adj[a[i].x].push_back(a[i].x + n);
                adj[a[i].y].push_back(a[i].y + n);
            }
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == col[i + n]) {
            ans = max(ans, nowans);
            return;
        }
    }
}

int main() {
    read(n); read(m); read(k);
    for (int i = 1; i <= m; i++) a[i] = getNode();
    for (int i = 1; i <= k; i++) b[i] = getNode();
    solve();
    for (int i = 1; i <= m; i++) a[i].opt ^= 1;
    for (int i = 1; i <= k; i++) b[i].opt ^= 1;
    solve();
    if (ans == -1) print(-1, '\n');
    else print(k - ans, '\n');
    return 0;
}