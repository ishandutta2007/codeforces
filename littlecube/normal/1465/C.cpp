#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

stack<int> visit;
vector<int> road[100005];
short visited[100005] = {0};
ll result = 0;

int dfs(int x)
{
    if (!visited[x])
    {
        visited[x] = 1;
        if (!road[x].empty())
        {
            if (!visited[road[x].front()])
                return dfs(road[x].front());
            else
                return road[x].front();
        }
    }
    return 0;
}

int main()
{
    ll t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        result = m;
        visit = {};
        for (int i = 1; i <= n; i++)
        {
            road[i] = {};
            visited[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x != y)
            {
                road[x].emplace_back(y);
                visit.push(x);
            }
            else
            {
                result--;
                visited[x] = 1;
            }
        }
        while (!visit.empty())
        {

            int root = visit.top();
            visit.pop();
            if (root == dfs(root))
                result++;
        }
        cout << result << '\n';
    }
}