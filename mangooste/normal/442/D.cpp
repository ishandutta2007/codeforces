#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n++;
    vector<int> par(n);
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;
    }

    vector<set<pair<int, int>, greater<pair<int, int>>>> mxs(n);
    vector<int> res(n, 1);
    auto solve = [&](int v) {
        int ans = 1;
        if (len(mxs[v])) ans = max(ans, mxs[v].begin()->first);
        if (len(mxs[v]) > 1) ans = max(ans, (++mxs[v].begin())->first + 1);
        return ans;
    };

    for (int i = 1; i < n; i++) {
        for (int j = i;; j = par[j]) {
            if (j) mxs[par[j]].erase({res[j], j});
            res[j] = solve(j);
            if (j) mxs[par[j]].insert({res[j], j});
            if (res[par[j]] == solve(par[j]) || !j) break;
        }
        cout << mxs[0].begin()->first << ' ';
    }
    cout << '\n';
}