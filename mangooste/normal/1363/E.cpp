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
    vector<int> a(n), b(n), c(n);
    int bal_zero = 0, bal_one = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    ll ans = 0;
    vector<array<int, 2>> notOk(n, {0, 0});
    Fun<void(int, int)> Calc = [&](int v, int pr) {
        if (b[v] != c[v]) {
            notOk[v][b[v]]++;
        }
        for (auto u : G[v]) {
            if (u != pr) {
                a[u] = min(a[u], a[v]);
                Calc(u, v);
                notOk[v][0] += notOk[u][0];
                notOk[v][1] += notOk[u][1];
            }
        }
        ll cnt = 2ll * min(notOk[v][0], notOk[v][1]);
        ans += cnt * a[v];
        notOk[v][0] -= cnt / 2;
        notOk[v][1] -= cnt / 2;
    };
    Calc(0, 0);
    cout << (notOk[0][0] == 0 && notOk[0][1] == 0 ? ans : (ll)(-1)) << '\n';
}