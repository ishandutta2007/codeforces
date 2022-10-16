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
#include <random>

using namespace std;

pair<int, int> query(vector<int> q)
{
    if (q.empty())
    {
        return make_pair(0, 0);
    }

    cout << "? " << q.size();
    for (auto u : q)
    {
        cout << " " << u;
    }
    cout << endl;
    cout.flush();

    int u, sum_dist;
    cin >> u >> sum_dist;
    return make_pair(u, sum_dist);
}

vector<int> find_distance(int s, vector<vector<int>> &tree)
{
    vector<int> dist(tree.size());

    function<void(int, int)> go = [&](int s, int p) {
        for (auto u : tree[s])
        {
            if (u == p)
                continue;

            dist[u] = dist[s] + 1;
            go(u, s);
        }
    };

    go(s, -1);

    return dist;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i + 1 < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> q(n);
    iota(q.begin(), q.end(), 1);
    int center, length;
    tie(center, length) = query(q);

    auto dist = find_distance(center, tree);

    int node0 = center, target, _length;

    int lo = (length + 1) / 2 - 1;
    int hi = length + 1;

    while (lo + 1 < hi)
    {
        int m = (lo + hi) / 2;

        q.clear();
        for (int i = 1; i <= n; ++i)
            if (dist[i] == m)
                q.push_back(i);
        tie(target, _length) = query(q);

        if (_length == length)
        {
            node0 = target;
            lo = m;
        }
        else
        {
            hi = m;
        }
    }

    dist = find_distance(node0, tree);
    q.clear();
    for (int i = 1; i <= n; ++i)
        if (dist[i] == length)
            q.push_back(i);
    int node1;
    tie(node1, _length) = query(q);
    // assert(_length == length);

    cout << "! " << node0 << " " << node1 << endl;
    cout.flush();

    string flag;
    cin >> flag;
    assert(flag == "Correct");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}