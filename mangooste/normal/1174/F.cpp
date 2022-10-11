#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int n;
vec<vec<int>> g;
vec<int> sz;
vec<int> dep;

inline int ask(int x, char c) {
    cout << c << ' ' << x + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void init(int v, int par) {
    if (v)
        g[v].erase(find(all(g[v]), par));
    sz[v] = 1;
    for (auto u : g[v]) {
        dep[u] = dep[v] + 1;
        init(u, v);
        sz[v] += sz[u];
    }
    sort(all(g[v]), [&](int a, int b) {
        return sz[a] > sz[b];
    });
}

int find(int v, int dist) {
    vec<int> way;
    int u = v;
    while (len(g[u])) {
        way.push_back(u);
        u = g[u][0];
    }
    way.push_back(u);

    int d = ask(way.back(), 'd');
    assert((dist - d + len(way) - 1) % 2 == 0);
    int pos = (dist - d + len(way) - 1) / 2;
    v = way[pos];
    if (dist == pos)
        return v;
    return find(ask(v, 's') - 1, dist - pos - 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    sz.resize(n);
    dep.resize(n);
    init(0, 0);
    int res = find(0, ask(0, 'd'));
    cout << "! " << res + 1 << '\n';
}