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

const int N = 1e6 + 5;

int n, m;
vector<int> g[N], gr[N];
int tops[N], sz;
int color[N];
int used[N];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to]) {
            continue;
        }
        dfs(to);
    }
    tops[sz++] = v;
}

void go(int v, int cl) {
    color[v] = cl;
    for (int to : gr[v]) {
        if (!color[to]) go(to, cl);
    }
}

void solve() {
    cin >> n >> m;
    vector<pii> edges(m);
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        gr[i].clear();
        used[i] = 0;
        color[i] = 0;
    }
    sz = 0;
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
        if (u != v) {
            g[u].push_back(v);
            gr[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(tops, tops + sz);
    int cl = 0;
    for (int i = 0; i < sz; i++) {
        int v = tops[i];
        if (color[v]) continue;
        cl++;
        go(v, cl);
    }
    if (cl == 1) {
        cout << "No\n";
        return;
    }
    vector<int> deg(cl + 1);
    for (pii e : edges) {
        int u, v;
        tie(u, v) = e;
        u = color[u];
        v = color[v];
        if (u == v) continue;
        deg[v]++;
    }
    for (int c = 1; c <= cl; c++) {
        if (deg[c]) continue;
        vector<int> a, b;
        for (int i = 1; i <= n; i++) {
            if (color[i] == c) {
                b.push_back(i);
            } else {
                a.push_back(i);
            }
        }
        cout << "Yes\n";
        cout << (int) a.size() << " " << (int) b.size() << "\n";
        for (int x : a) cout << x << " ";
        cout << "\n";
        for (int x : b) cout << x << " ";
        cout << "\n";
        break;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}