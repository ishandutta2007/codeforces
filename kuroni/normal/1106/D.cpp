#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;

int u, v, n, m;
bool vis[N];
vector<int> adj[N];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pq.push(1); vis[1] = true;
    while (!pq.empty())
    {
        int u = pq.top(); pq.pop();
        printf("%d ", u);
        for (int &v : adj[u])
            if (!vis[v])
            {
                pq.push(v);
                vis[v] = true;
            }
    }
}