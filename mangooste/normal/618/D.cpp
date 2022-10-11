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

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n;
ll x, y;
vector<vector<int>> G;
int min_ways = 0;

bool dfs(int v, int pr) {
    int cnt = 0;
    for (auto u : G[v]) {
        if (u != pr) {
            cnt += dfs(u, v);
        }
    }
    min_ways += (cnt >= 2) + (cnt >= 1);
    return (cnt < 2);
}

void Main() {
    cin >> n >> x >> y;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    if (x >= y) {
        bool any = false;
        for (int i = 0; i < n; i++) {
            if ((int)G[i].size() == n - 1) {
                any = true;
                break;
            }
        }
        if (!any) {
            cout << y * (n - 1) << '\n';
        } else {
            cout << x + y * (n - 2) << '\n';
        }
        return;
    }
    dfs(0, 0);
    cout << min_ways * x + (n - 1 - min_ways) * y << '\n';
}