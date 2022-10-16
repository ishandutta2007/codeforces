#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

#define endl '\n'

using namespace std;

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

    vector<int> value(n), order(n), seen(n);

    for (int i = 0; i < n; ++i)
        cin >> value[i];

    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int u, int v) {
        return value[u] < value[v];
    });

    for (auto u : order)
    {
        seen[u] = true;

        set<int> s;

        for (auto v : adj[u])
        {
            if (seen[v])
                s.insert(value[v]);
        }

        int p = 1;

        while (s.count(p))
            ++p;

        if (p != value[u])
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto u : order)
    {
        cout << u + 1 << " ";
    }

    cout << endl;

    return 0;
}