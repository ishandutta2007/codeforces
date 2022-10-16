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

const int N = 2e5 + 5, P = 998244353;

int n;

bool st[N], vis[N];

int inv[N], mx[N], mn[N], cnt[N], ans;

vector<int> d[N];

void inline prework(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            for (int j = i + i; j <= n; j += i) st[j] = 1;
            for (int j = i; j <= n; j += i) d[j].pb(i);
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (P - (LL)P / i) * inv[P % i] % P;
}

struct E{
    int v, x, y;
};

vector<E> g[N];

void inline clr() {
    for (int i = 1; i <= n; i++) g[i].clear(), vis[i] = mx[i] = 0;
}

int fa[N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}


void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int inline get(int x, int y) {
    int c = 0;
    while (x % y == 0) x /= y, c++;
    return c;
}

void dfs(int u) {
    for (auto o: g[u]) {
        int v = o.v;
        if (v == fa[u]) continue;
        fa[v] = u;
        for (int w: d[o.y]) {
            cnt[w] += get(o.y, w);
            chkMax(mx[w], cnt[w]);
        }
        dfs(v);
        for (int w: d[o.y]) {
            cnt[w] -= get(o.y, w);
        }
    }
}

void dfs1(int u, int w) {
    add(ans, w);
    for (auto o: g[u]) {
        int v = o.v;
        if (v == fa[u]) continue;
        fa[v] = u;
        int nw = w;
        for (int w: d[o.x]) {
            cnt[w] += get(o.x, w);
        }
        nw = 1ll * nw * o.x % P;
        for (int w: d[o.y]) {
            cnt[w] -= get(o.y, w);
            chkMin(mn[w], cnt[w]);
        }
        nw = 1ll * nw * inv[o.y] % P;
        dfs1(v, nw);
        for (int w: d[o.x]) {
            cnt[w] -= get(o.x, w);
        }
        for (int w: d[o.y]) {
            cnt[w] += get(o.y, w);
        }
    }
}


int main() {
    prework(2e5);
    int T; read(T);
    while (T--) {
    	read(n); ans = 0;
        for (int i = 1; i < n; i++) {
            int u, v, x, y; read(u), read(v), read(x), read(y);
            swap(x, y);
            g[u].pb((E) { v, x, y });
            g[v].pb((E) { u, y, x });
        }
        dfs(1);
        int val = 1;
        for (int i = 1; i <= n; i++) {
            if (!st[i]) {
                cnt[i] = mx[i], mn[i] = cnt[i]; 
                val = 1ll * val * power(i, mx[i]) % P;

            }
        }
        dfs1(1, val);
        int wal = 1;
        for (int i = 1; i <= n; i++) wal = 1ll * wal * power(i, mn[i]) % P;
        ans = 1ll * ans * power(wal, P - 2) % P;
        printf("%d\n", ans);
        clr();
    }
    return 0;
}