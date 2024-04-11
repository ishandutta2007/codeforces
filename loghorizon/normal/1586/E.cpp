// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

typedef pair<int, int> PII;

int n, m, f[N], q, pre[N], pe[N], ans, cnt[N];

vector<PII> g[N];
vector<int> p[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void dfs1(int u, int fa) {
    for (PII v: g[u]) {
        if (v.fi == fa) continue;
        pre[v.fi] = u, pe[v.fi] = v.se; 
        dfs1(v.fi, u);
    }
}

int dfs2(int u, int fa, int la) {
    int s = 0;
    for (PII v: g[u]) {
        if (v.fi == fa) continue;
        int t = dfs2(v.fi, u, v.se);
        if ((cnt[v.se] & 1)) {
            if (s) {
                s = 0;
                if (t) ans--;
            } else {
                s = 1;
                if (!t) ans++;
            }
        }
    }
    return s;
}
int main() { 
    read(n), read(m);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y; read(x), read(y);
        if (find(x) != find(y)) {
            f[find(x)] = find(y);
            g[x].pb(mp(y, i));
            g[y].pb(mp(x, i));
        }
    }
    read(q);
    for (int i = 1; i <= q; i++) {
        int a, b; read(a), read(b);
        dfs1(a, 0);
        int x = b;
        while (x != a) {
            p[i].pb(x);
            cnt[pe[x]]++;
            x = pre[x];
        }
        p[i].pb(a);
        reverse(p[i].begin(), p[i].end());
    }
    bool o = 0;
    for (int i = 1; i <= m; i++)
        if (cnt[i] & 1) o = 1;
    if (!o) {
        puts("YES");
        for (int i = 1; i <= q; i++) {
            printf("%lu\n", p[i].size());
            for (int v: p[i]) printf("%d ", v); puts("");
        }
    } else {
        puts("NO");
        dfs2(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}