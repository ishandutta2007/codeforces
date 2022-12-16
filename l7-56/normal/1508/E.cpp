#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
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
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 3e5 + 10;
int n, a[maxn], pos[maxn], fa[maxn], dfn[maxn], idx, dep[maxn];
vi e[maxn];
void dfs(int u) {
    dep[u] = dep[fa[u]] + 1;
    dfn[u] = ++idx;
    for (auto it = begin(e[u]); it != end(e[u]); ++it)
        if ((*it) == fa[u]) { e[u].erase(it); break; }
    sort(begin(e[u]), end(e[u]), [&] (int x, int y) { return a[x] < a[y]; });
    for (int v : e[u]) fa[v] = u, dfs(v);
}

int ext[maxn];
void dfs2(int u) {
    for (int v : e[u]) dfs2(v);
    ext[u] = ++idx;
}

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]), pos[a[i]] = i;
    for (int i = 1; i < n; ++i) {
        int u, v; read(u, v);
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(1);
    if (a[1] == 1) {
        for (int i = 1; i <= n; ++i)
            if (a[i] != dfn[i]) return write("NO\n"), 0;
        write("YES\n0\n");
        for (int i = 1; i <= n; ++i) write(a[i], " \n"[i == n]);
        return 0;
    }
    int p = a[1] - 1;
    idx = 0, dfs2(1);
    for (int i = 1; i < p; ++i)
        if (ext[pos[i]] != i) return write("NO\n"), 0;
    for (int i = p + 1; i < n; ++i)
        if (dfn[pos[i]] > dfn[pos[i + 1]]) return write("NO\n"), 0;
    int u = pos[p];
    for (int flg = 1; flg; ) {
        flg = 0;
        for (int v : e[u])
            if (p < a[v]) { flg = v; break; }
        if (flg) u = flg;
    }
    if (ext[u] != p) return write("NO\n"), 0;
    ll ans = 0;
    for (int i = 1; i <= p; ++i) ans += dep[pos[i]] - 1;
    write("YES\n");
    write(ans, '\n');
    for (int i = 1; i <= n; ++i) write(dfn[i], " \n"[i == n]);
	return 0;
}