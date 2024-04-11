#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 2E5 + 5;

queue<int> q;
set<int> pro;
vector<int> adj[N], cur, out;
int m, n, u, v;

int BFS(int st)
{
    int ret = 0;
    for (pro.erase(st), q.push(st); !q.empty(); q.pop())
    {
        ++ret;
        int u = q.front(), pt = 0;
        for (set<int>::iterator it = pro.begin(); it != pro.end(); it++)
        {
            for (; pt < adj[u].size() && adj[u][pt] < *it; pt++)
                continue;
            if (pt < adj[u].size() && adj[u][pt] == *it)
            {
                ++pt;
                continue;
            }
            q.push(*it);
            cur.push_back(*it);
        }
        while (!cur.empty())
        {
            pro.erase(cur.back());
            cur.pop_back();
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        pro.insert(i);
    }
    for (int i = 1; i <= n; i++)
        if (pro.find(i) != pro.end())
            out.push_back(BFS(i));
    sort(out.begin(), out.end());
    printf("%d\n", out.size());
    for (int v : out)
        printf("%d ", v);
}