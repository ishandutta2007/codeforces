#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const int LOG = 20;
const ll mod = inf + 7;

int n;
ll x[N];
vector<int> g[N];
int parent[LOG][N];
ll cost[LOG][N];
int depth[N];

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

void dfs(int v, int par = -1) {
    parent[0][v] = par;
    cost[0][v] = par == -1 ? 1ll : gcd(x[v], x[par]);
    depth[v] = par == -1 ? 1 : depth[par] + 1;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int j = 0; j < LOG; j++) {
        for (int v = 1; v <= n; v++) {
            cost[j][v] = 1;
            parent[j][v] = -1;
        }
    }

    dfs(1);

    for (int j = 1; j < LOG; j++) {
        for (int v = 1; v <= n; v++) {
            int pv = parent[j - 1][v];
            if (pv == -1) {
                parent[j][v] = -1;
            } else {
                parent[j][v] = parent[j - 1][pv];
                cost[j][v] = gcd(cost[j - 1][v], cost[j - 1][pv]);
            }
        }
    }

    ll res = 0;

    for (int v = 1; v <= n; v++) {
        int q = v;
        ll cur = x[v];
        ll tmp = 0;
        while (q != -1) {
            if (cur == 1) {
                tmp += depth[q];
                tmp %= mod;
                break;
            }
            int mem_q = q;
            for (int j = LOG - 1; j >= 0; j--) {
                int qq = parent[j][q];
                if (qq == -1) continue;
                if (gcd(cost[j][q], cur) != cur) {
                    continue;
                }
                q = qq;
            }
            ll next_cur = gcd(cur, cost[0][q]);
            q = parent[0][q];
            tmp += (depth[mem_q] - (q == -1 ? 0 : depth[q])) * cur % mod;
            tmp %= mod;
            cur = next_cur;
        }
        res = (res + tmp) % mod;
    }

    cout << res << "\n";

    return 0;
}