#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<vector<int>> graph;

long long a, b, k, n, m, tmp, ans = 0;


set<int> availibale;


int main()
    {
    FAST;


    cin >> n >> m;

    graph.resize(n);

    for (int i = 0; i < m; i++)
        {
        cin >> a >> b;
        --a;
        --b;

        graph[a].push_back(b);
        graph[b].push_back(a);
        }

    availibale.insert(0);

    vector<bool> used(n, false);
    used[0] = true;

    while(!availibale.empty())
        {
        int cur = *(availibale.begin());
        availibale.erase(cur);

        for (int i = 0; i < graph[cur].size(); i++)
            {
            int next = graph[cur][i];
            if (!used[next])
                {
                used[next] = true;
                availibale.insert(next);
                }
            }

        cout << cur+1 << " ";
        }





    return 0;
    }