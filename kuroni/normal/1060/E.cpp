#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005;

int n, u, v;
long long ans = 0, sum[N][2], cnt[N][2];
vector<int> adj[N];

void DFS(int u, int p = 0)
{
    cnt[u][0] = 1;
    for (int &v : adj[u])
        if (v != p)
        {
            DFS(v, u);
            ans += (cnt[v][0] + cnt[v][1]) * (sum[u][0] + sum[u][1]) + (cnt[u][0] + cnt[u][1]) * (sum[v][0] + sum[v][1] + cnt[v][0] + cnt[v][1]);
            ans += cnt[u][0] * cnt[v][0] + cnt[u][1] * cnt[v][1];
            sum[u][0] += sum[v][1] + cnt[v][1];
            sum[u][1] += sum[v][0] + cnt[v][0];
            cnt[u][0] += cnt[v][1];
            cnt[u][1] += cnt[v][0];
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    printf("%lld\n", ans / 2);
}