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

const int maxn = 1e6 + 10;
int n, q, a[maxn], dep[maxn], deg[maxn], x, rt, ans;
vi e[maxn], val[maxn];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    val[u].resize(0);
    for (int v : e[u]) if (v != pre) {
        dfs(v, u);
        if (val[u].size() < val[v].size()) val[u].swap(val[v]);
        int lu = val[u].size(), lv = val[v].size();
        for (int i = 0; i < lv; ++i) {
            int j = max(0, ans - x - i);
            while (j < lu && val[u][j] + val[v][i] - 2 * dep[u] >= ans) ++ans, j = max(0, ans - x - i);
        }
        for (int i = 0; i < lv; ++i) val[u][i] = max(val[u][i], val[v][i]);
        val[v].resize(0);
    }
    int j = max(0, ans - x - a[u]), lu = val[u].size();
    while (j < lu && val[u][j] - dep[u] >= ans) ++ans, j = max(0, ans - x - a[u]);
    while (a[u] >= lu) val[u].push_back(0), ++lu;
    val[u][a[u]] = max(val[u][a[u]], dep[u]);
}

void init() {
    for (rt = 1; deg[rt] == 1; ++rt);
    queue <int> que;
    memset(a, -1, sizeof a);
    for (int i = 1; i <= n; ++i) if (deg[i] == 1) que.push(i), a[i] = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        for (int v : e[u]) if (a[v] == -1)
            a[v] = a[u] + 1, que.push(v);
    }
}

int query() {
    ans = 0;
    dfs(rt, 0);
    return ans - 1;
}

int main() {
    read(n);
    for (int i = 2; i <= n; ++i) {
        int p; read(p);
        e[i].push_back(p), e[p].push_back(i);
        deg[i]++, deg[p]++;
    }
    init(), read(q);
    while (q--) read(x), write(query(), ' ');
    write('\n');
	return 0;
}