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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        int par;
        cin >> par;
        par--;
        if (par != -1) {
            G[par].pb(i);
            G[i].pb(par);
        }
    }
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        deg[i] = G[i].size();
    }
    vector<int> died(n, 0);
    Fun<void(int, int)> dfs2 = [&](int v, int pr) {
        assert(deg[v] % 2 == 0);
        died[v] = 1;
        cout << v + 1 << '\n';
        for (auto u : G[v]) {
            if (u != pr && !died[u]) {
                deg[u]--;
                dfs2(u, v);
            }
        }
    };
    Fun<void(int, int)> dfs1 = [&](int v, int pr) {
        for (auto u : G[v]) {
            if (u != pr) {
                dfs1(u, v);
            }
        }
        if (deg[v] % 2 == 0) {
            dfs2(v, pr);
            deg[pr]--;
        }
    };
    dfs1(0, 0);
}