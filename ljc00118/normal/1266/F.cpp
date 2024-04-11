#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 5e5 + 5;

struct edge_t { int u, v, next; } G[N << 1];

vector <int> d[N];
vector <pii> t[N];
int c[N];
int head[N], maxdep[N], maxn[N][2], tmp[N], fa[N], ans1[N], ans2[N];
int n, tot;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int fa) {
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        ::fa[v] = u; dfs1(v, u);
        maxdep[u] = max(maxdep[u], maxdep[v] + 1);
    }
}

void dfs2(int u, int fa, int mx) {
    maxn[u][0] = tmp[u] = mx;
    d[u].push_back(mx); ++c[mx];
    d[u].push_back(0); ++c[0];
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        d[u].push_back(maxdep[v] + 1); ++c[maxdep[v] + 1];
        if (maxdep[v] + 1 > maxn[u][0]) {
            maxn[u][1] = maxn[u][0];
            maxn[u][0] = maxdep[v] + 1;
        } else maxn[u][1] = max(maxn[u][1], maxdep[v] + 1);
    }
    sort(d[u].begin(), d[u].end());
    for (int i = 0; i < (int)d[u].size(); i++) {
        if (c[d[u][i]]) {
            t[u].push_back(make_pair(d[u][i], c[d[u][i]]));
            c[d[u][i]] = 0;
        }
    }
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        if (maxdep[v] + 1 == maxn[u][0]) dfs2(v, u, maxn[u][1] + 1);
        else dfs2(v, u, maxn[u][0] + 1);
    }
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0); dfs2(1, 0, 0);
    // cout << "ok" << endl;
    for (int u = 1; u <= n; u++) {
        int now = 0;
        for (int i = (int)t[u].size() - 1; i >= 0; i--) {
            if (now) ans1[t[u][i].first * 2 + 1] = max(ans1[t[u][i].first * 2 + 1], now + 1);
            now += t[u][i].second;
            if (now >= 2) ans1[t[u][i].first * 2] = max(ans1[t[u][i].first * 2], now);
        }
        if (fa[u]) {
            int i = (int)t[fa[u]].size() - 1, j = (int)t[u].size() - 1, I = maxdep[u] + 1, J = tmp[u], now = 0;
            while (i >= 0 || j >= 0) {
                int vali = (i >= 0 ? t[fa[u]][i].first : -1);
                int valj = (j >= 0 ? t[u][j].first : -1);
                if (vali > valj) {
                    int cnt = t[fa[u]][i].second;
                    if (t[fa[u]][i].first == I) --cnt;
                    if (!cnt) { --i; continue; }
                    now += cnt;
                    if (now >= 2) ans2[vali * 2] = max(ans2[vali * 2], now);
                    --i;
                }
                if (vali < valj) {
                    int cnt = t[u][j].second;
                    if (t[u][j].first == J) --cnt;
                    if (!cnt) { --j; continue; }
                    now += cnt;
                    if (now >= 2) ans2[valj * 2] = max(ans2[valj * 2], now);
                    --j;
                }
                if (vali == valj) {
                    int cnt = t[fa[u]][i].second + t[u][j].second;
                    if (t[fa[u]][i].first == I) --cnt;
                    if (t[u][j].first == J) --cnt;
                    if (!cnt) { --i; --j; continue; }
                    now += cnt;
                    if (now >= 2) ans2[vali * 2] = max(ans2[vali * 2], now);
                    --i; --j;
                }
            }
        }
    }
    ans1[n] = max(ans1[n], 1);
    for (int i = n - 1; i >= 1; i--) ans1[i] = max(ans1[i], ans1[i + 1]);
    for (int i = n - 2; i >= 2; i--) ans2[i] = max(ans2[i], ans2[i + 2]);
    for (int i = 1; i <= n; i++) print(max(ans1[i], ans2[i]), i == n ? '\n' : ' ');
    return 0;
}