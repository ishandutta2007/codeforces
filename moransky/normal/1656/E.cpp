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

const int N = 1e5 + 5;

int n, w[N], du[N], rt;
LL sm[N];

vector<int> g[N];

void dfs(int u, int fa, int o) {
    int s = 1;
    sm[u] = 0;
    LL la = -1;
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u, o * -1);
        s++;
        sm[u] += sm[v];
        if (la != -1) assert(la == sm[v]);
        la = sm[v];
    }
    if (u == rt) w[u] = -1;
    else w[u] = o * s;
    sm[u] += w[u];
    if (u != rt && la != -1) assert(-sm[u] == la);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i < n; i++) {
            int u, v; read(u), read(v);
            g[u].pb(v), g[v].pb(u);
            du[u]++, du[v]++;
        }
        rt = 1;
        while (du[rt] != 1) rt++;
        dfs(rt, 0, -1);
        for (int i = 1; i <= n; i++) printf("%d ", w[i]);
        puts("");
        for (int i = 1; i <= n; i++) g[i].clear(), du[i] = 0;
    }
    return 0;
}