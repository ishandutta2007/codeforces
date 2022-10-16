/*input
10 11
1 2
2 3
3 4
1 4
3 5
5 6
8 6
8 7
7 6
7 9
9 10
6
1 2
3 5
6 9
9 2
9 3
9 10
*/
#ifdef UncleGrandpa
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if constexpr(LOCAL)cout << "[" << #x << "] ="; print(x);}
void print() {if constexpr(LOCAL)cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if constexpr(LOCAL)cout << value << ' ', print(values...);}
const int N = 1e5 + 5;

const int lgx = 20;
int par[lgx][N], depth[N];
int n, m, p2[N];
vector<vector<int> > a(N);
vector<vector<int> > b(N);
int sta[N], Time = 0;
int lab[N], cost[N], costR[N], peak = 0;

void dfs(int u, int p) {
    sta[u] = ++Time;
    for (auto v : a[u]) {
        if (v == p) continue;
        if (sta[v] == 0) {
            par[0][v] = u;
            dfs(v, u);
        }
        else if (sta[v] < sta[u]) {
            int x = u; ++peak;
            cost[peak] = 1;
            while (x) {
                lab[x] = peak;
                if (x == v) break;
                x = par[0][x];
            }
        }
    }
}

void pdfs(int u, int p) {
    par[0][u] = p; costR[u] += cost[u];
    for (auto v : a[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            costR[v] += costR[u];
            pdfs(v, u);
        }
    }
}

int lca(int p, int q) {
    if (depth[p] < depth[q]) swap(p, q);
    rloop(i, lgx - 1, 0) {
        if (depth[par[i][p]] >= depth[q])
            p = par[i][p];
    }
    if (p == q) return p;
    rloop(i, lgx - 1, 0) {
        if (par[i][p] != par[i][q])
            p = par[i][p], q = par[i][q];
    }
    return par[0][p];
}

int distance(int u, int v) {
    int p = lca(u, v);
    return costR[u] - costR[p] + costR[v] - costR[p] + cost[p];
}

void makelca() {
    pdfs(1, 1);
    loop(i, 1, lgx - 1) {
        loop(j, 1, n) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    p2[0] = 1; loop(i, 1, n) p2[i] = p2[i - 1] * 2 % mod;
    dfs(1, 1);
    loop(i, 1, n) if (lab[i] == 0) lab[i] = ++peak;
    loop(i, 1, n) {
        for (auto it : a[i]) {
            if (lab[it] == lab[i]) continue;
            b[lab[i]].push_back(lab[it]), b[lab[it]].push_back(lab[i]);
        }
    }
    loop(i, 1, n) sort(b[i].begin(), b[i].end()), b[i].resize(distance(b[i].begin(), unique(b[i].begin(), b[i].end())));
    a.swap(b);
    // loop(i, 1, n) {
    //     for (auto v : a[i]) print(i, v);
    //     // print(a[i]);
    // }
    n = peak;
    makelca();
    int q; cin >> q;
    loop(i, 1, q) {
        int u, v; cin >> u >> v;
        u = lab[u]; v = lab[v];
        auto rec = distance(u, v);
        cout << p2[rec] << endl;
    }
}