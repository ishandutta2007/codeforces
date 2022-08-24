#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}


const int BLOCK = 700;
const int LG = 19;
const int maxN = 15 * 10000 + 10;
int h[maxN];
int up[LG][maxN];
int n, q;
vector < int > g[maxN];
int tin[maxN];
int tout[maxN];
int timer = 0;
int sz[maxN];
int invn;
int his_batya[maxN];

void dfs(int v, int p) {
    tin[v] = timer++;
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        his_batya[to] = v;
        up[0][to] = v;
        dfs(to, v);
        sz[v] += sz[to];
    }
    tout[v] = timer++;
}

bool is_anc(int who, int batya) {
    return tin[batya] <= tin[who] && tout[who] <= tout[batya];
}

int parent(int v, int batya) {
    for (int i = LG - 1; i >= 0; i--) {
        if (h[v] - (1 << i) > h[batya]) {
            v = up[i][v];
        }
    }
    return v;
}

ll getval(int u, int v, int d) {
    if (u == v) return 1LL * d * n;
    if (!is_anc(u, v)) {
        int coef = n - sz[v];
        return (1LL * d * (n - coef));
    }
    else {
        int par = parent(u, v);
        int coef = sz[par];
        return (1LL * d * (n - coef));
    }
}

ll has_now[maxN];
ll coef[maxN];
ll to_add[maxN];
ll cur_val[maxN];
void process(int v, int p) {
    cur_val[v] = cur_val[v] + 1LL * coef[v] * (sz[v]);
    for (int to : g[v]) {
        if (to == p) continue;
        to_add[to] = to_add[v];
        to_add[to] += 1LL * coef[v] * (n - sz[to]);
        cur_val[to] += cur_val[v];
        process(to, v);
    }
}

int tit = 0;
int id[maxN];
vector < int > gg[maxN];
void dfs_start(int v, int p) {
    tit++;
    id[v] = tit;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs_start(to, v);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    invn = pw(n, mod - 2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs_start(1, -1);
    for (int i = 1; i <= n; i++) {
        for (int to : g[i]) {
            gg[id[i]].emplace_back(id[to]);
        }
    }
    for (int i = 1; i <= n; i++) {
        swap(gg[i], g[i]);
    }

    dfs(1, -1);
    for (int i = 0; i + 1 < LG; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
    for (int it = 0;  ; it++) {
        int l = it * BLOCK;
        int r = min(it * BLOCK + BLOCK - 1, q - 1);
        if (l > r) break;
        vector < pair < int, int > > add;
        memset(to_add, 0, sizeof to_add);
        for (int i = l; i <= r; i++) {
            int tp;
            cin >> tp;
            if (tp == 2) {
                int v;
                cin >> v;
                v = id[v];
                ll val = has_now[v];
                for (auto s : add) {
                    val += getval(v, s.first, s.second);
                }
                cout << mult(val % mod, invn) << '\n';
            }
            else {
                int v, d;
                cin >> v >> d;
                v = id[v];
                coef[v] += d;
                add.emplace_back(v, d);
            }
        }

        process(1, -1);
        ll all_sum = 0;
        for (int i = 1; i <= n; i++) all_sum += 1LL * coef[i] * (sz[i]);
        for (int i = 1; i <= n; i++) {
            has_now[i] += all_sum - cur_val[i];
            has_now[i] += 1LL * n * coef[i];
            has_now[i] += to_add[i];
            to_add[i] = 0;
            cur_val[i] = 0;
            coef[i] = 0;
        }
    }
    return 0;
}