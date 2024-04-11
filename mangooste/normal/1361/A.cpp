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

void solve();
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
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
    vector<int> want(n);
    for (auto &el : want) {
        cin >> el, el--;
    }
    bool chk = true;
    for (int i = 0; i < n; i++) {
        for (auto j : G[i]) {
            if (want[i] == want[j]) {
                chk = false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        set<int> st;
        for (auto j : G[i]) {
            if (want[j] < want[i]) {
                st.insert(want[j]);
            }
        }
        if (st.size() != want[i]) {
            chk = false;
        }
    }
    if (!chk) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    iota(all(ans), 0);
    sort(all(ans), [&](int v, int u) {
        return want[v] < want[u];
    });
    for (auto el : ans) {
        cout << el + 1 << ' ';
    }
    cout << '\n';
}