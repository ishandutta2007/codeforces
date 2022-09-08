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
 
const int N = 4e5 + 5;
 
vector <int> a[N], b[N];
int low[N], dfn[N], st[N], siz[N], fa[N];
int T, n, m, s, t, oldn, cnt, top;
 
void tarjan(int u) {
    low[u] = dfn[u] = ++cnt; st[++top] = u;
    for (int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                int tmp = 0; ++n;
                while (tmp != v) {
                    tmp = st[top--];
                    b[n].push_back(tmp);
                    b[tmp].push_back(n);
                }
                b[n].push_back(u);
                b[u].push_back(n);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}
 
void dfs1(int u) {
    siz[u] = (u <= oldn);
    for (int i = 0; i < (int)b[u].size(); i++) {
        int v = b[u][i];
        if (v == fa[u]) continue;
        fa[v] = u; dfs1(v);
        siz[u] += siz[v];
    }
}
 
int main() {
    read(T);
    while(T--) {
        read(n); read(m); read(s); read(t); oldn = n;
        cnt = top = 0;
        for (int i = 1; i <= n * 2; i++) {
            low[i] = dfn[i] = 0;
            a[i].clear(); b[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
        fa[s] = 0; dfs1(s);
        if (s == t) {
            ll ans = 0, sum = 0;
            for (int i = 0; i < (int)b[s].size(); i++) {
                int v = b[s][i];
                ans += sum * siz[v];
                sum += siz[v];
            }
            print(ans, '\n');
            continue;
        }
        int tmp = t;
        while (fa[tmp] != s) tmp = fa[tmp];
        print(1ll * (siz[t] - 1) * (oldn - siz[tmp] - 1), '\n');
    }
    return 0;
}