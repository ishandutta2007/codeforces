#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> slow(int n, int k, vector<pii> edges, vector<int> a) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> res;
    int xr;
    function<void(int, int, int)> dfs = [&](int v, int par, int d) {
        int c = d / k;
        if (c % 2)
            xr ^= a[v];
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v, d + 1);
        }
    };
    for (int r = 1; r <= n; r++) {
        xr = 0;
        dfs(r, -1, 0);
        res.push_back(xr > 0);
    }
    return res;
}

vector<int> fast(int n, int k, vector<pii> edges, vector<int> a) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k2 = 2 * k;
    vector<vector<int>> dp(n + 1, vector<int>(k2));
    function<void(int, int)> dfs = [&](int v, int par) {
        dp[v][0] = a[v];
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
            for (int i = 0; i < k2; i++)
                dp[v][(i + 1) % k2] ^= dp[to][i];
        }
    };
    dfs(1, -1);
    vector<int> res(n);
    function<void(int, int, vector<int>)> go = [&](int v, int par, vector<int> par_dp) {
        vector<int> total_dp = dp[v];
        for (int i = 0; i < k2; i++)
            total_dp[(i + 1) % k2] ^= par_dp[i];
        int xr = 0;
        for (int i = k; i < k2; i++)
            xr ^= total_dp[i];
        res[v - 1] = xr > 0;
        for (int to : g[v]) {
            if (to == par)
                continue;
            vector<int> tmp_dp = total_dp;
            for (int i = 0; i < k2; i++)
                tmp_dp[(i + 1) % k2] ^= dp[to][i];
            go(to, v, tmp_dp);
        }
    };
    go(1, -1, vector<int>(k2, 0));
    return res;
}

void work() {
    int n, k;
    cin >> n >> k;
    vector<pii> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> fs = fast(n, k, edges, a);
    for (auto x : fs)
        cout << x << " ";
    cout << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 10;
    const int MAXX = 1e9;
    while (1) {
        int n, k;
        n = rnd() % MAXN + 3;
        k = rnd() % MAXN + 1;
        vector<pii> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            u = rnd() % (i + 1) + 1;
            v = i + 2;
            edges[i] = {u, v};
        }
        shuffle(edges.begin(), edges.end(), rnd);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % MAXX;
        vector<int> fs = fast(n, k, edges, a);
        vector<int> sl = slow(n, k, edges, a);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << k << "\n";
            for (auto [u, v] : edges)
                cout << u << " " << v << "\n";
            for (int v = 1; v <= n; v++)
                cout << a[v] << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}