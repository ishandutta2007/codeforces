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

int n;
vector<int> g[N];

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void read() {
    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        add_edge(u, v);
    }
}

void dfs(int v, int par, vector<pii> &path, int k, int D) {
    int cur = k;
    int cnt = 0;
    for (int to : g[v])
        if (to != par)
            cnt++;
    for (int to : g[v]) {
        if (to == par)
            continue;
        if (k - 1 - cnt >= 0) {
            path.emplace_back(v, k - 1 - cnt);
            cur = k - 1 - cnt;
        }
        path.emplace_back(to, cur + 1);
        dfs(to, v, path, cur + 1, D);
        cnt--;
        cur++;
        path.emplace_back(v, cur);
    }
    if (k > 0 && cur != k - 1)
        path.emplace_back(v, k - 1);
}

vector<pii> fast() {
    vector<pii> path;
    int D = 0;
    for (int v = 1; v <= n; v++)
        D = max(D, (int) g[v].size());
    path.emplace_back(1, 0);
    dfs(1, -1, path, 0, D);
    path.erase(unique(path.begin(), path.end()), path.end());
    return path;
}

void work() {
    read();
    vector<pii> fs = fast();
    cout << (int) fs.size() << "\n";
    for (pii p : fs)
        cout << p.first << " " << p.second << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}