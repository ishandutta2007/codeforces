#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

int n;
vector<vector<int>> g;
vector<int> par;
vector<char> used;
vector<int> way;

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            par[u] = v;
            dfs(u);
        } else if (used[u] == 1 && way.empty()) {
            for (; v != u; v = par[v]) {
                way.push_back(v);
            }
            way.push_back(u);
            return;
        }
    }
    used[v] = 2;
}

void solve() {
    cin >> n;
    g = vector<vector<int>>(n);
    forn (i, 0, n) {
        int a;
        cin >> a;
        g[i].push_back(i - a);
    }

    par = vector<int>(n, -1);
    used = vector<char>(n, 0);

    way.clear();
    forn (i, 0, n) {
        if (!used[i]) dfs(i);
        if (len(way)) break;
    }

    assert(len(way));
    cout << len(way) << '\n';
    forn (i, 0, len(way)) cout << way[i] + 1 << " \n"[i == len(way) - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    forn (_, 0, t) solve();
}