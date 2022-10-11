#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        edges.pb({v, u, w});
    }
    sort(all(edges), [](array<int, 3> &a, array<int, 3> &b) {
        return a[2] < b[2];
    });
    vector<int> sz(n, 1), parent(n);
    iota(all(parent), 0);

    function<int(int)> Parent = [&](int v) {
        return parent[v] == v ? v : parent[v] = Parent(parent[v]);
    };

    auto Merge = [&](int v, int u) {
        v = Parent(v);
        u = Parent(u);
        if (v == u) {
            return 0ll;
        }
        ll delta = 1ll * sz[v] * sz[u];
        if (sz[v] > sz[u]) {
            parent[u] = v;
            sz[v] += sz[u];
        } else {
            parent[v] = u;
            sz[u] += sz[v];
        }
        return delta;
    };

    vector<pair<int, ll>> precalc;
    ll cur_ans = 0;
    for (int i = 0; i < n - 1;) {
        int j = i;
        while (j < n - 1 && edges[j][2] == edges[i][2]) {
            cur_ans += Merge(edges[j][0], edges[j][1]);
            j++;
        }
        precalc.eb(edges[i][2], cur_ans);
        i = j;
    }
    for (int i = 0; i < m; i++) {
        int cur_w;
        cin >> cur_w;
        int pos = upper_bound(all(precalc), mp(cur_w, (ll)(1e18))) - precalc.begin() - 1;
        if (pos == -1) {
            cout << "0 ";
        } else {
            cout << precalc[pos].second << ' ';
        }
    }
    cout << '\n';
}