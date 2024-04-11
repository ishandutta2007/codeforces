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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    map<int, vector<int>> primes;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        for (int div = 2; div * div <= val; div++) {
            if (val % div == 0) {
                primes[div].pb(i);
                while (val % div == 0) {
                    val /= div;
                }
            }
        }
        if (val != 1) {
            primes[val].pb(i);
        }
    }
    int ans = 0;
    if (*max_element(all(a)) != 1) {
        ans = 1;
    }
    vector<int> used(n, 0);
    int used_num = 1;
    for (auto val : primes) {
        function<pii(int, int, int)> Dfs = [&](int v, int pr, int depth) {
            used[v] = used_num;
            pii cur = mp(depth, v);
            for (auto u : G[v]) {
                if (u != pr && a[u] % val.first == 0) {
                    cur = max(cur, Dfs(u, v, depth + 1));
                }
            }
            return cur;
        };

        for (auto v : val.second) {
            if (used[v] != used_num) {
                ans = max(ans, Dfs(Dfs(v, -1, 0).second, -1, 0).first + 1);
            }
        }
        used_num++;
    }
    cout << ans << '\n';
}