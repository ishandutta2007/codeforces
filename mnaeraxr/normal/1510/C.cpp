#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <queue>
#include <random>
#include <set>

using namespace std;

set<pair<int, int>> tarjan(const vector<vector<int>> &adj)
{
    int n = adj.size(), t;
    vector<int> num(n), low(n), S;
    set<pair<int, int>> bridges;

    function<void(int, int)> dfs = [&](int u, int p) {
        num[u] = low[u] = ++t;
        S.push_back(u);
        for (int v : adj[u])
            if (v != p)
            {
                if (!num[v])
                {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (num[u] < low[v])
                    {
                        bridges.insert({u, v});
                        bridges.insert({v, u});
                    }
                }
                else
                    low[u] = min(low[u], num[v]);
            }
    };

    for (int u = 0; u < n; ++u)
        if (!num[u])
            t = 0, dfs(u, -1);

    return bridges;
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        if (n == 0)
            break;

        vector<vector<int>> adj(n);

        for (int i = 0; i < m; ++i)
        {
            int t;
            cin >> t;

            int u;
            cin >> u;
            --u;

            for (int j = 1; j < t; ++j)
            {
                int v;
                cin >> v;
                --v;

                adj[u].push_back(v);
                adj[v].push_back(u);
                u = v;
            }
        }

        auto b = tarjan(adj);

        for (int i = 0; i < n; ++i)
        {
            int s = adj[i].size();
            for (int j = s - 1; j >= 0; --j)
            {
                int u = i, v = adj[i][j];

                if (b.count({u, v}) == 0)
                {
                    swap(adj[i][j], adj[i][s - 1]);
                    --s;
                }
            }
            adj[i].resize(s);
        }

        // for (int i = 0; i < n; ++i)
        //     for (auto u : adj[i])
        //         cout << i << " " << u << endl;

        vector<bool> seen(n);
        vector<pair<int, int>> answer;

        function<int(int, int)> solve = [&](int s, int p) {
            seen[s] = true;

            if (p == -1)
            {
                int u = solve(adj[s][0], s);
                if (u != adj[s][0])
                    answer.push_back({s, u});
                return -1;
            }
            else
            {
                vector<int> reals, fict;

                for (auto u : adj[s])
                {
                    if (u == p)
                        continue;

                    int v = solve(u, s);

                    if (v == u)
                        reals.push_back(v);
                    else
                        fict.push_back(v);
                }

                while (fict.size() >= 2)
                {
                    int u = fict.back();
                    fict.pop_back();
                    int v = fict.back();
                    fict.pop_back();
                    answer.push_back({u, v});
                }

                if (reals.empty())
                {
                    if (fict.empty())
                        return s;
                    else
                        return fict[0];
                }
                else
                {
                    if ((reals.size() + fict.size()) % 2 == 0)
                        reals.pop_back();

                    if (!fict.empty())
                        reals.push_back(fict[0]);

                    while (reals.size() >= 2)
                    {
                        int u = reals.back();
                        reals.pop_back();
                        int v = reals.back();
                        reals.pop_back();
                        answer.push_back({u, v});
                    }

                    return reals[0];
                }
            }
        };

        for (int i = 0; i < n; ++i)
            if (adj[i].size() == 1 && !seen[i])
                solve(i, -1);

        cout << answer.size() << endl;

        for (auto [u, v] : answer)
            cout << u + 1 << " " << v + 1 << endl;

        // exit(0);
    }
}