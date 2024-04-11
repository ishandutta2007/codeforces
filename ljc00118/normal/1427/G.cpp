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

const int N = 205;

struct edge_t { int u, v, next, cap, flow; } G[N * N * 8];

vector <pii> v;
int a[N][N], head[N * N], ist[N * N], isw[N * N], vis[N * N];
int n, m, s, t, tot = 1, nowflow; ll ans;

inline void addedge(int u, int v, int cap) {
    G[++tot] = (edge_t) {u, v, head[u], cap, 0}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], cap, 0}, head[v] = tot;
}

inline int calc(int x, int y) { return (x - 1) * n + y; }

int push(int u, int add) {
    if (add == 1 && ist[u]) return 1;
    if (add == -1 && !ist[u] && isw[u]) return 1;
    vis[u] = 1;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (add == 1 && G[i].flow == 1) continue;
        if (add == -1 && G[i].flow != -1) continue;
        if (vis[v]) continue;
        if (push(v, add)) {
            ++G[i].flow;
            --G[i ^ 1].flow;
            return 1;
        }
    }
    return 0;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            read(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + 1 <= n && a[i][j] >= 0 && a[i + 1][j] >= 0) addedge(calc(i, j), calc(i + 1, j), 1);
            if (j + 1 <= n && a[i][j] >= 0 && a[i][j + 1] >= 0) addedge(calc(i, j), calc(i, j + 1), 1);
            if (a[i][j] > 0) v.push_back(make_pair(a[i][j], calc(i, j))), ist[calc(i, j)] = isw[calc(i, j)] = 1;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size() - 1; i++) {
        memset(vis, 0, sizeof(vis));
        while (push(v[i].second, -1)) {
            --nowflow;
            memset(vis, 0, sizeof(vis));
        }
        ist[v[i].second] = 0;
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j <= i; j++) {
            int u = v[j].second;
            if (!ist[u] && !vis[u]) {
                while (push(u, 1)) {
                    ++nowflow;
                    memset(vis, 0, sizeof(vis));
                }
            }
        }
        // fprintf(stderr, "nowflow = %d\n", nowflow);
        ans += 1ll * (v[i + 1].first - v[i].first) * nowflow;
    }
    print(ans, '\n');
    return 0;
}