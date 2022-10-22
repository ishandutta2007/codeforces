#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;

int n;
vector<int> g[N];
int sz[N], centroid = -1;

void dfs(int v, int par = -1) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

void fnd_centroid(int v, int par = -1) {
    int mx = n - sz[v];
    for (int to : g[v]) {
        if (to == par) continue;
        fnd_centroid(to, v);
        if (centroid != -1) return;
        mx = max(mx, sz[to]);
    }
    if (2 * mx <= n) {
        centroid = v;
    }
}

ll value[N];
ll cur_value, shift;

void go(int v, int par) {
    value[v] = cur_value;
    cout << v << " " << par << " " << value[v] - value[par] << "\n";
    cur_value += shift;
    for (int to : g[v]) {
        if (to == par) continue;
        go(to, v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    mt19937 rnd(time(NULL));

    cin >> n;
//    n = rnd() % 1000 + 1;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
//        u = i + 1;
//        v = rnd() % i + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        return 0;
    }

    dfs(1);
    fnd_centroid(1);

    dfs(centroid);

    for (int i = 1; i < (int) g[centroid].size(); i++) {
        if (sz[g[centroid][i]] > sz[g[centroid][0]]) {
            swap(g[centroid][i], g[centroid][0]);
        }
    }

    int sep = 0, cur_sz = 1;

    while (3 * cur_sz < n) {
        cur_sz += sz[g[centroid][sep++]];
    }

    int k = cur_sz;
    int l = n - k;

    assert(k * l >= 2 * n * n / 9);

    cur_value = l;
    shift = l;
    for (int i = 0; i < sep; i++) {
        go(g[centroid][i], centroid);
    }

    cur_value = 1;
    shift = 1;
    for (int i = sep; i < (int) g[centroid].size(); i++) {
        go(g[centroid][i], centroid);
    }

    return 0;
}