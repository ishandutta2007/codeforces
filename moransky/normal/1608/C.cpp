// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, d[N];
int c[N], s[N], low[N], dfn[N], dfncnt, top, cnt;
bool ins[N];

PII a[N], b[N];

vector<int> g[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++dfncnt;
    s[++top] = u, ins[u] = true;
    for (int v: g[u]) {
        if (!dfn[v]) {
            tarjan(v), low[u] = min(low[u], low[v]);
        } else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v; ++cnt;
        do {
            v = s[top--], ins[v] = false, c[v] = cnt;
        } while (v != u);
    }
}
 
void inline clr() {
    cnt = top = dfncnt = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = low[i] = s[i] = c[i] = d[i] = 0;
        g[i].clear();
    }
}

void inline add(int u, int v) {
    g[u].pb(v);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i].fi), a[i].se = i;
        for (int i = 1; i <= n; i++) read(b[i].fi), b[i].se = i;
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = 2; i <= n; i++)
            add(a[i].se, a[i - 1].se), add(b[i].se, b[i - 1].se);
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) tarjan(i);
        for (int u = 1; u <= n; u++) {
            for (int v: g[u])
                if (c[u] != c[v]) d[c[v]]++;
        }  
        int num = 0, p = -1;
        for (int i = 1; i <= cnt; i++) {
            if (!d[i]) p = i, num++;
        }
        for (int i = 1; i <= n; i++) {
            if (num > 1) {
                putchar('0');
            } else {
                putchar(c[i] == p ? '1' : '0');
            }
        }
        puts("");
        clr();
    }
    return 0;
}