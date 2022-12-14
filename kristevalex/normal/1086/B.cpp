#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<vector<int>> graph;

long long a, b, n, m, tmp, ans = 0;
long double k;





int main()
    {
    FAST;


    cin >> n >> k;
    k*= 2;

    graph.resize(n);

    long double counter = 0;

    for (int i = 0; i < n-1; i++)
        {
        cin >> a >> b;
        --a;
        --b;

        graph[a].push_back(b);
        graph[b].push_back(a);
        }


    for (int i = 0; i < n; i++)
        {
        if (graph[i].size() == 1) counter++;
        }

    k/= counter;

    cout << setprecision(15) << k;

    return 0;
    }