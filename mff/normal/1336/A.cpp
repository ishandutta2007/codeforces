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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> tree(n);
    vector<int> par(n), val(n);

    for (int i = 0; i + 1 < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    function<int(int, int)> dfs = [&](int s, int p) {
        int tot = 0;
        par[s] = p;
        for (auto u : tree[s])
        {
            if (u == p)
                continue;

            val[u] = val[s] + 1;
            tot += dfs(u, s);
        }
        val[s] -= tot;
        return tot + 1;
    };

    dfs(0, -1);

    sort(val.begin(), val.end());
    reverse(val.begin(), val.end());

    long long answer = 0;
    for (int i = 0; i < k; ++i)
        answer += val[i];
    cout << answer << endl;

    return 0;
}