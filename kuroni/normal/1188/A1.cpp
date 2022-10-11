#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v;
vector<int> adj[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 2)
            return cout << "NO", 0;
    cout << "YES";
}