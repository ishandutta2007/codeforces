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

const int maxn = 2e5 + 10;
int n, m, fa[maxn], dep[maxn], ans[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
pii e[maxn];
vi g[maxn];

void dfs(int u, int pre) {
    fa[u] = pre, dep[u] = dep[pre] + 1;
    for (int i : g[u]) {
        int v = e[i].fir ^ e[i].sec ^ u;
        if (v == pre) continue;
        dfs(v, u);
    }
}

void work() {
    read(n, m);
    iota(fa + 1, fa + n + 1, 1);
    vi ext;
    for (int i = 1; i <= m; ++i) {
        int u, v; read(u, v);
        e[i] = make_pair(u, v);
        if (get(u) == get(v)) ext.push_back(i), ans[i] = 0;
        else g[u].push_back(i), g[v].push_back(i), fa[get(u)] = get(v), ans[i] = 1;
    }
    if (ext.size() == 3) {
        int i = ext[0], j = ext[1], k = ext[2];
        vi vec({e[i].fir, e[i].sec, e[j].fir, e[j].sec, e[k].fir, e[k].sec});
        sort(begin(vec), end(vec));
        if (vec[0] == vec[1] && vec[2] == vec[3] && vec[4] == vec[5]) {
            dfs(1, 0);
            ans[i] = 1;
            int x = e[i].fir, y = e[i].sec;
            if (dep[x] < dep[y]) swap(x, y);
            y = fa[x];
            for (int p : g[x])
                if ((e[p].fir ^ e[p].sec ^ x) == y) { ans[p] = 0; break; }
        }
    }
    for (int i = 1; i <= m; ++i) printf("%d", ans[i]);
    printf("\n");
    for (int i = 1; i <= n; ++i) g[i].resize(0);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}