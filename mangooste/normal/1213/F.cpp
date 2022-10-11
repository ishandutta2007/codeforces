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
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    for (auto &el : p) {
        cin >> el, el--;
    }
    for (auto &el : q) {
        cin >> el, el--;
    }
    if (k > n) {
        cout << "NO\n";
        return 0;
    }
    vector<vector<int>> G(n), rev_G(n);
    for (int i = 1; i < n; i++) {
        G[p[i - 1]].pb(p[i]);
        rev_G[p[i]].pb(p[i - 1]);
        G[q[i - 1]].pb(q[i]);
        rev_G[q[i]].pb(q[i - 1]);
    }
    vector<int> top_sort;
    vector<char> used(n, 0);

    function<void(int)> Top_sort = [&](int v) {
        used[v] = 1;
        for (auto u : G[v]) {
            if (!used[u]) {
                Top_sort(u);
            }
        }
        top_sort.pb(v);
    };

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            Top_sort(i);
        }
    }
    reverse(all(top_sort));
    vector<int> num(n, -1);
    int cur_num = 0;
    fill(all(used), 0);

    function<void(int)> Dfs = [&](int v) {
        num[v] = cur_num;
        used[v] = 1;
        for (auto u : rev_G[v]) {
            if (!used[u]) {
                Dfs(u);
            }
        }
    };

    for (auto v : top_sort) {
        if (!used[v]) {
            Dfs(v);
            cur_num++;
        }
    }
    if (cur_num < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (num[i] >= k) {
                ans[i] = 'a' + k - 1;
            } else {
                ans[i] = 'a' + num[i];
            }
        }
        cout << ans << '\n';
    }
}