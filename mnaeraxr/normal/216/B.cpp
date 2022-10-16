#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> seen(n);
    bool is_cycle;
    int cur;

    function<void(int)> go = [&](int u) {
        seen[u] = true;
        cur++;

        if (adj[u].size() < 2)
            is_cycle = false;

        for (auto v : adj[u])
        {
            if (!seen[v])
                go(v);
        }
    };

    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        if (seen[i])
            continue;

        is_cycle = true;
        cur = 0;
        go(i);

        if (is_cycle && (cur % 2 == 1))
        {
            cur--;
        }

        total += cur;
    }

    cout << n - 2 * (total / 2) << endl;

    return 0;
}