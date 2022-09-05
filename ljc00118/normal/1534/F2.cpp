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

const int N = 8e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector <int> adj[N], edg[N];
char c[N];
int low[N], dfn[N], st[N], inst[N], col[N], hav[N], l[N], r[N], up[N], fir[N], a[N], need[N], mx[N];
int n, m, tot, cnt, ans, top;

inline int s(int x, int y) { return (x - 1) * m + y; }

void tarjan(int u) {
    low[u] = dfn[u] = ++tot; st[++top] = u; inst[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++cnt;
        while (st[top + 1] != u) {
            int tmp = st[top--];
            col[tmp] = cnt;
            inst[tmp] = 0;
            if (tmp <= n * m && c[tmp] == '#') hav[cnt] = 1;
        }
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t = getchar();
            while (t != '.' && t != '#') t = getchar();
            c[s(i, j)] = t;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int now = s(i, j) + n * m;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x <= 0 || x > n || y <= 0 || y > m) continue;
                if (c[s(x, y)] == '#') adj[now].push_back(s(x, y));
            }
            if (i != n) adj[now].push_back(s(i + 1, j) + n * m);
            adj[now].push_back(s(i, j));
            if (c[s(i, j)] == '#') adj[s(i, j)].push_back(now);
        }
    }
    for (int i = 1; i <= n * m * 2; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n * m * 2; i++) {
        for (int j = 0; j < (int)adj[i].size(); j++) {
            int v = adj[i][j];
            if (col[i] != col[v]) edg[col[v]].push_back(col[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        read(a[i]);
        int now = 0;
        if (a[i] == 0) {
            need[i] = n + 1;
            continue;
        }
        for (int j = n; j >= 1; j--) {
            now += (c[s(j, i)] == '#');
            if (now == a[i]) {
                need[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int las = 0;
        for (int j = 1; j <= n; j++) {
            if (c[s(j, i)] == '#') {
                up[s(j, i)] = s(j, i);
                if (las && col[s(j, i)] == col[las]) up[s(j, i)] = up[las];
                las = s(j, i);
                // fprintf(stderr, "up[%d] = %d\n", s(j, i), up[s(j, i)]);
            }
        }
        for (int j = n; j >= 1; j--) {
            if (c[s(j, i)] == '#') fir[s(j, i)] = s(j, i);
            else if (j != n) fir[s(j, i)] = fir[s(j + 1, i)];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            if (c[s(j, i)] == '.' || j > need[i]) continue;
            l[s(j, i)] = i;
            if (i != 1 && fir[s(j, i - 1)]) {
                int u = up[fir[s(j, i - 1)]];
                if (l[u]) l[s(j, i)] = l[u];
            }
        }
    }
    for (int i = m; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (c[s(j, i)] == '.' || j > need[i]) continue;
            r[s(j, i)] = i;
            if (i != m && fir[s(j, i + 1)]) {
                int u = up[fir[s(j, i + 1)]];
                if (r[u]) r[s(j, i)] = r[u];
            }
        }
    }
    for (int i = 1; i <= n * m; i++) {
        if (l[i]) {
            mx[l[i]] = max(mx[l[i]], r[i]);
            // fprintf(stderr, "i = %d, l = %d, r = %d\n", i, l[i], r[i]);
        }
    }
    int maxn = 0, now = 0;
    while (now < m) {
        while (now < m && a[now + 1] == 0) {
            ++now;
            maxn = max(maxn, mx[now]);
        }
        if (now == m) break;
        maxn = max(maxn, mx[now + 1]);
        ++ans;
        int tem = maxn;
        while (now < tem) {
            ++now;
            maxn = max(maxn, mx[now]);
        }
    }
    print(ans, '\n');
    return 0;
}