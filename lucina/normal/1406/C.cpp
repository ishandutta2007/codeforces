#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
vector <int> a[nax];
int sz[nax];
int parent[nax];

void dfs_sz(int node, int parent) {
    sz[node] = 1;
    ::parent[node] = parent;

    for (int i : a[node]) {
        if (i == parent) continue;
        dfs_sz(i, node);
        sz[node] += sz[i];
    }
}

pair <int, int> get_leaf (int node, int parent) {
    if (int(a[node].size()) == 1) {
        return make_pair(node, parent);
    } else {
        for (int j : a[node]) {
            if (j != parent) return get_leaf(j, node);
        }
    }
    assert(false);
    throw;
}

void solve() {
    cin >> n;

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    if (n % 2) {
        for (int i = 0 ; i < 2 ; ++ i)
        cout << "1 " << a[1][0] << '\n';
        return ;
    }

    vector <int> cens;
    dfs_sz(1, 0);
    for (int i = 1 ; i <= n ; ++ i) {
        bool valid = true;

        for (int j : a[i]) {
            if (j != parent[i])
                valid &= (sz[j] * 2 <= n);
            else valid &= ((n - sz[i]) * 2 <= n);
        }
        if (valid) cens.push_back(i);
    }
    if (cens.size() == 1) {
        for (int i = 0 ; i < 2 ; ++ i)
            cout << "1 " << a[1][0] << '\n';
        return ;
    }

    auto [x, y] = get_leaf(cens[1], cens[0]);
    cout << x << ' ' << y << '\n';
    cout << x << ' ' << cens[0] << '\n';


}

int main() {
   // cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
    }
}