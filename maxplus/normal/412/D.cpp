#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

bool vis[30001];
vector<int> e[30001];
deque<int> tans;
queue<int> ans;

void dfs(int a)
{
    vis[a] = 1;
    for (int j = 0; j < e[a].size(); ++j)
        if (!vis[e[a][j]])
            dfs(e[a][j]);
    tans.push_front(a);
}

int main()
{
    int n, m, t1, t2;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> t1 >> t2;
        e[t1].push_back(t2);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            dfs(i);
            while (tans.size())
            {
                ans.push(tans.back());
                tans.pop_back();
            }
        }

    while (ans.size())
    {
        cout << ans.front() << ' ';
        ans.pop();
    }
    return 0;
}