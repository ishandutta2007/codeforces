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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    vector<int> tin(n), tup(n);
    vector<char> used(n, 0);
    int timer = 0;
    vector<pair<int, int>> ans;
    Fun<void(int, int)> Dfs = [&](int v, int pr) {
        used[v] = 1;
        tin[v] = tup[v] = timer++;
        for (auto u : G[v]) {
            if (u == pr) {
                continue;
            }
            if (used[u]) {
                tup[v] = min(tup[v], tin[u]);
                if (tin[u] < tin[v]) {
                    ans.eb(v, u);
                }
            } else {
                Dfs(u, v);
                tup[v] = min(tup[v], tup[u]);
                if (tup[u] > tin[v]) {
                    cout << "0\n";
                    exit(0);
                }
                ans.eb(v, u);
            }
        }
    };
    Dfs(0, 0);
    for (auto el : ans) {
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
    }
}