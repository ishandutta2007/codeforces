#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

int n;
vector<vector<int>> G, c;

int get(pair<int, int> p) {
    vector<char> used(3, 0);
    used[p.first] = used[p.second] = 1;
    for (int i = 0; i < 3; i++)
        if (!used[i])
            return i;
    return -1;
}

void dfs(int v, pair<int, int> used, vector<int> &ans, ll &mn) {
    for (auto u : G[v]) {
        if (ans[u] != -1)
            continue;
        ans[u] = get(used);
        mn += c[ans[u]][u];
        dfs(u, {ans[u], used.first}, ans, mn);
    }
}

pair<vector<int>, ll> solve(int fir, int sec) {
    vector<int> ans(n, -1);
    ll mn = c[fir][0] + c[sec][G[0][0]];
    ans[0] = fir, ans[G[0][0]] = sec;
    dfs(0, {fir, sec}, ans, mn);
    dfs(G[0][0], {sec, fir}, ans, mn);
    return {ans, mn};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    c.resize(3, vector<int>(n));
    for (auto &i : c)
        for (auto &j : i)
            cin >> j;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
        if (G[i].size() >= 3)
            return cout << "-1\n", 0;
    ll mn = 1e18;
    vector<int> ans(n, -1);
    for (int fir = 0; fir < 3; fir++) {
        for (int sec = 0; sec < 3; sec++) {
            if (fir == sec)
                continue;
            pair<vector<int>, ll> cur = solve(fir, sec);
            if (cur.second < mn)
                mn = cur.second, ans = cur.first;
        }
    }
    cout << mn << '\n';
    for (auto i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}