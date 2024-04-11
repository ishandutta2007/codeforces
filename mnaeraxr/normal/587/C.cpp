#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int maxa = 10;

vi adj[maxn];

int par[maxn][20];
int h[maxn];
vi mat[maxn][20];

vi merge(vi &a, vi &b, int k){
    vi ans;
    int x = 0, y = 0;

    while (x < (int)a.size() && y < (int)b.size() && x + y < k){
        if (a[x] < b[y]) ans.push_back(a[x++]);
        else ans.push_back(b[y++]);
    }

    while (x < (int)a.size() && x + y < k)
        ans.push_back(a[x++]);

    while (y < (int)b.size() && x + y < k)
        ans.push_back(b[y++]);

    return ans;
}

void build(int s, int p){

    for (int i = 1; i < 20; ++i){
        if (par[s][i - 1] == 0) break;
        par[s][i] = par[ par[s][i - 1] ][i - 1];
        mat[s][i] = merge(mat[s][i - 1], mat[ par[s][i - 1] ][i - 1], maxa);

    }

    for (auto u : adj[s]){
        if (u == p) continue;

        par[u][0] = s;
        h[u] = h[s] + 1;
        build(u, s);
    }
}

void print(vi &a){
    for (auto aa : a) cout << aa << " ";
    cout << endl;
}

vi lca(int u, int v, int k){
    if (h[u] < h[v]) swap(u, v);

    vi ans;

    int d = h[u] - h[v];

    for (int i = 0; d; ++i){
        if (d >> i & 1){
            ans = merge(ans, mat[u][i], k);
            u = par[u][i];
            d ^= 1 << i;
        }
    }

    if (u == v){
        ans = merge(ans, mat[u][0], k);
        return ans;
    }

    for (int i = 19; ~i; --i){
        if (par[u][i] != par[v][i]){
            ans = merge(ans, mat[u][i], k);
            ans = merge(ans, mat[v][i], k);

            u = par[u][i], v = par[v][i];
        }
    }

    ans = merge(ans, mat[u][1], k);
    ans = merge(ans, mat[v][0], k);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= m; ++i){
        int v; cin >> v;

        if (mat[v][0].size() < maxa)
            mat[v][0].push_back(i);
    }

    build(1, -1);

    while (q--){
        int u, v, k;
        cin >> u >> v >> k;

        vi ans = lca(u, v, k);

        cout << ans.size();
        for (auto a : ans) cout << " " << a;
        cout << endl;
    }

    return 0;
}