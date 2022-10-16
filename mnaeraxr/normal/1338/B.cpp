#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bool odd = false;
    int total = 0;

    int r = 0;

    function<int(int,int,int)> dfs = [&](int s, int p, int par) {
        if (s != r && tree[s].size() == 1) {
            if (par)
                odd = true;
            return 0;
        }

        int ans = 1000000000;

        for (auto u : tree[s]) {
            if (u == p) {
                continue;
            }

            int cur = dfs(u, s, par ^ 1) + 1;

            if (cur < ans)
                swap(ans, cur);

            if (cur > 1 && cur < 1000000000){
                total += cur;
            }
        }

        return ans;
    };

    while (tree[r].size() > 1)
        ++r;

    auto res = dfs(r, -1, 0);

    if (res == 2)
        total++;
    else
        total += res;

    cout << (odd ? 3 : 1) << " " << total << endl;

    return 0;
}