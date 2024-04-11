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

const int N = 2e5 + 5;

int n, k;
vector<int> g[N];
int d[N];
int h[N];
int used[N];
int p[N];

void dfs(int v, int par = -1) {
    d[v] = 0;
    p[v] = par;
    h[v] = par == -1 ? 0 : h[par] + 1;
    for (int to : g[v]) {
        if (to == par)
            continue;
        dfs(to, v);
        d[v] += d[to] + 1;
    }
}

int f[N];

void go(int v, int par = -1) {
    for (int to : g[v]) {
        if (to == par)
            continue;
        f[to] = f[v] + used[v];
        go(to, v);
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    k = n - k;

    set<pii> q;
    q.insert({d[1] - h[1], 1});

    for (int it = 0; it < k; it++) {
        int root = (--q.end())->second;
        q.erase(--q.end());
        used[root] = 1;
        for (int to : g[root]) {
            if (to != p[root]) {
                q.insert({d[to] - h[to], to});
            }
        }
    }

    go(1);

//    for (int v = 1; v <= n; v++) {
//        if (used[v])
//            cout << v << " !\n";
//    }

    ll res = 0;

    for (int v = 1; v <= n; v++) {
        if (!used[v])
            res += f[v];
    }

    cout << res << "\n";

    return 0;
}