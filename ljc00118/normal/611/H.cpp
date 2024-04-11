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

const int N = 2e5 + 5, INF = 0x7fffffff;

struct edge_t { int u, v, next, cap, flow; } G[2000];

vector <pii> ans;
char c[10];
int head[30], nowhead[30], d[30], a[10][10], cnt[10], fir[10], now[10];
int n, s, t, tot, maxn;

inline void addedge(int u, int v, int cap) {
    G[++tot] = (edge_t) {u, v, head[u], cap, 0}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], 0, 0}, head[v] = tot;
}

int bfs() {
    memset(d, 0, sizeof(d)); d[s] = 1;
    queue <int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if (!d[v] && G[i].cap > G[i].flow) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t];
}

int dfs(int u, int Flow) {
    if (u == t || !Flow) return Flow;
    int flow = 0, f;
    for (int &i = nowhead[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].cap - G[i].flow))) > 0) {
            G[i].flow += f; G[i ^ 1].flow -= f;
            flow += f; Flow -= f;
            if (!Flow) break;
        }
    }
    return flow;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        memcpy(nowhead, head, sizeof(nowhead));
        ans += dfs(s, INF);
    }
    return ans;
}

int fa[N], f[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u) {
    if (u > maxn) {
        bool cando = 1;
        for (int i = 1; i <= maxn; i++) f[i] = i;
        for (int i = 2; i <= maxn; i++) {
            int x = find(fa[i]), y = find(i);
            if (x == y) {
                cando = 0;
                break;
            }
            f[x] = y;
        }
        for (int i = 2; i <= maxn; i++) {
            int x = fa[i], y = i;
            if (x > y) swap(x, y);
            if (!a[x][y]) cando = 0;
        }
        if (!cando) return;
        tot = 1;
        memset(head, 0, sizeof(head));
        for (int i = 2; i <= maxn; i++) {
            int x = fa[i], y = i;
            if (x > y) swap(x, y);
            --a[x][y];
        }
        int tnode = maxn + 1, added = 0;
        s = 0; t = maxn + 1;
        for (int i = 1; i <= maxn; i++) addedge(i, t, cnt[i] - 1 - a[i][i]), added += a[i][i];
        for (int i = 1; i <= maxn; i++) {
            for (int j = i + 1; j <= maxn; j++) {
                ++tnode;
                addedge(s, tnode, a[i][j]);
                addedge(tnode, i, a[i][j]);
                addedge(tnode, j, a[i][j]);
            }
        }
        if (dinic() == n - 1 - added - (maxn - 1)) {
            for (int i = 2; i <= maxn; i++) ans.emplace_back(fir[fa[i]], fir[i]);
            tnode = maxn + 1;
            for (int i = 1; i <= maxn; i++) {
                for (int j = i + 1; j <= maxn; j++) {
                    int u = ++tnode;
                    for (int k = head[u]; k; k = G[k].next) {
                        int v = G[k].v;
                        if (v >= 1 && v <= maxn) {
                            int x = v, y = i ^ j ^ v;
                            for (int t = 1; t <= G[k].flow; t++) {
                                ++now[x];
                                ans.emplace_back(fir[y], now[x]);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n - 1; i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
            exit(0);
        }
        for (int i = 2; i <= maxn; i++) {
            int x = fa[i], y = i;
            if (x > y) swap(x, y);
            ++a[x][y];
        }
        return;
    }
    for (int i = 1; i <= maxn; i++) {
        if (i == u) continue;
        fa[u] = i;
        dfs1(u + 1);
    }
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        scanf("%s", c + 1);
        int la = strlen(c + 1);
        scanf("%s", c + 1);
        int lb = strlen(c + 1);
        if (la > lb) swap(la, lb);
        ++a[la][lb];
    }
    for (int i = 1; i <= n; i++) {
        int len = 0, tmp = i;
        while (tmp) {
            ++len;
            tmp /= 10;
        }
        ++cnt[len];
        if (!fir[len]) fir[len] = now[len] = i;
        maxn = len;
    }
    for (int i = 1; i <= maxn; i++) {
        if (a[i][i] > cnt[i] - 1) {
            puts("-1");
            return 0;
        }
        for (int j = 1; j <= a[i][i]; j++) {
            ++now[i];
            ans.emplace_back(fir[i], now[i]);
        }
    }
    dfs1(2);
    puts("-1");
    return 0;
}