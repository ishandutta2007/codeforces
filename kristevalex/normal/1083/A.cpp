#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<vector<pair<int, long long>>> graph;

long long a, b, k, n, m, tmp, ans = 0;




pair<long long, long long> dfs_max(int cur, int prev)
    {
    pair<long long, long long> _ans = {0, 0};

    long long max1 = 0, max2 = 0, max_f = 0;

    for (int i = 0; i < graph[cur].size(); i++)
        {
        auto next = graph[cur][i];
        if (next.first == prev) continue;
        auto ans_next = dfs_max(next.first, cur);

        _ans.second = max(_ans.second, ans_next.second);

        if (max1 < ans_next.first - next.second)
            {
            max2 = max1;
            max1 = ans_next.first - next.second;


            }
        else if (max2 < ans_next.first - next.second) max2 = ans_next.first - next.second;
        /*if (cur == 1)
                {
                cout << "max1: " << max1 << ", max2: " << max2 << "next:" << next.first << endl;
                } */
        }

    _ans.second = max(_ans.second, max1 + max2 + data[cur]);
    _ans.first = data[cur] + max1;


    //cout << "ver: " << cur << ", _ans.first: " << _ans.first << ", _ans.fsecond: " << _ans.second << endl;


    return _ans;
    }


int main()
    {
    FAST;


    cin >> n;

    data.resize(n);
    graph.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 0; i < n-1; i++)
        {
        cin >> a >> b >> k;
        --a;
        --b;
        graph[a].push_back({b, k});
        graph[b].push_back({a, k});
        }


    cout << dfs_max(0, -1).second;

    return 0;
    }