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

const int N = 8005;

struct edge_t { int v, nxt, flow, cost; } G[233333];

int head[N * 2], a[N], b[N];
int n, s, t, tot = 1;

inline void addedge(int u, int v, int flow, int cost) {
    G[++tot] = (edge_t) {v, head[u], flow, cost}, head[u] = tot;
    G[++tot] = (edge_t) {u, head[v], 0, -cost}, head[v] = tot;
    // fprintf(stderr, "u = %d, v = %d, flow = %d, cost = %d\n", u, v, flow, cost);
}

ll tt[N];
int id[N], id1[N], id2[N], e1[N], e2[N], vis[N];

bool cmp1(int i, int j) { return tt[i] < tt[j]; }
bool cmp2(int i, int j) { return b[i] < b[j]; }

bool check(int mid) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n * 2; i++) tt[i] = 1ll * a[i] * mid + b[i];
    for (int i = 1; i <= n; i++) id[i] = i, id1[i] = id2[i] = i + n;
    sort(id + 1, id + n + 1, cmp2);
    sort(id1 + 1, id1 + n + 1, cmp1);
    sort(id2 + 1, id2 + n + 1, cmp2);
    int pos1 = 1, pos2 = 1, cnt = 0; ll maxn = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && b[id[j]] <= b[id[i]]) {
            maxn = max(maxn, tt[id[j]]);
            ++j;
        }
        while (pos2 <= n && b[id2[pos2]] <= b[id[i]]) {
            maxn = max(maxn, tt[id2[pos2]]);
            if (!vis[id2[pos2]]) vis[id2[pos2]] = 1, ++cnt;
            ++pos2;
        }
        while (pos1 <= n && tt[id1[pos1]] <= maxn) {
            if (!vis[id1[pos1]]) vis[id1[pos1]] = 1, ++cnt;
            ++pos1;
        }
        if (cnt < i) return 0;
    }
    return 1;
}

int dis[N * 2], fr[N * 2], tem[N * 2], hd[N], las[N], nxt[66666], val[66666], tot2;
void push(int x, int y) {
    ++tot2; val[tot2] = y; nxt[tot2] = 0;
    if (!hd[x]) hd[x] = las[x] = tot2;
    else nxt[las[x]] = tot2, las[x] = tot2;
}

void dij() {
    memset(dis, 0x7f, sizeof(dis));
    memset(hd, 0, sizeof(hd));
    tot2 = 0;
    dis[s] = 0; push(0, s);
    for (int _ = 0; _ <= n + 1; _++) {
        for (int __ = hd[_]; __; __ = nxt[__]) {
            int u = val[__];
            if (dis[u] != _) continue;
            for (int i = head[u]; i; i = G[i].nxt) {
                int v = G[i].v;
                if (G[i].flow && dis[v] > dis[u] + G[i].cost + tem[u] - tem[v]) {
                    dis[v] = dis[u] + G[i].cost + tem[u] - tem[v];
                    fr[v] = i;
                    push(dis[v], v);
                }
            }
        }
    }
}

int ans = 0;
void solve() {
    int tmp = t;
    while (tmp != s) {
        int i = fr[tmp];
        --G[i].flow;
        ++G[i ^ 1].flow;
        tmp = G[i ^ 1].v;
    }
    ans += dis[t] + tem[t];
    for (int i = 1; i <= t; i++) tem[i] += dis[i];
}

int main() {
    // freopen("stock.in", "r", stdin);
    // freopen("stock.out", "w", stdout);
    read(n);
    for (int i = 1; i <= n * 2; i++) read(a[i]), read(b[i]);
    int l = 0, r = 1e9, res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (res == -1) {
        print(-1, '\n');
        return 0;
    }
    for (int i = 1; i <= n * 2; i++) tt[i] = 1ll * a[i] * res + b[i];
    for (int i = 1; i <= n; i++) id[i] = i, id1[i] = id2[i] = i + n;
    sort(id + 1, id + n + 1, cmp2);
    sort(id1 + 1, id1 + n + 1, cmp1);
    sort(id2 + 1, id2 + n + 1, cmp2);
    for (int i = 1; i <= n; i++) {
        addedge(i + n * 2, id1[i], 1, 0);
        addedge(i + n * 3, id2[i], 1, 0);
        if (i != 1) {
            addedge(i + n * 2, i + n * 2 - 1, n, 0);
            addedge(i + n * 3, i + n * 3 - 1, n, 0);
        }
    }
    int pos1 = 1, pos2 = 1; ll maxn = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && b[id[j]] <= b[id[i]]) {
            maxn = max(maxn, tt[id[j]]);
            ++j;
        }
        while (pos2 <= n && b[id2[pos2]] <= b[id[i]]) {
            maxn = max(maxn, tt[id2[pos2]]);
            ++pos2;
        }
        while (pos1 <= n && tt[id1[pos1]] <= maxn) ++pos1;
        // fprintf(stderr, "pos1 = %d, pos2 = %d\n", pos1, pos2);
        if (pos1 > 1) addedge(i, pos1 - 1 + n * 2, 1, 2);
        if (pos2 > 1) addedge(i, pos2 - 1 + n * 3, 1, 1);
        int pos = 0;
        for (int k = 1; k <= n; k++) {
            if (tt[id[i]] >= tt[id1[k]]) {
                pos = k;
            } else {
                break;
            }
        }
        // fprintf(stderr, "pos = %d\n", pos);
        if (pos) addedge(i, pos + n * 2, 1, 1);
    }
    s = n * 4 + 1; t = s + 1;
    for (int i = 1; i <= n; i++) {
        addedge(s, i, 1, 0);
        addedge(i + n, t, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        dij();
        solve();
    }
    print(res, ' '); print(ans, '\n');
    return 0;
}