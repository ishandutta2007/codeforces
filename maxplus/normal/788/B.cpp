#include <iostream>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;

constexpr int N = 1000000;
int am, vis[N], n, m, a, b;
vector<int> nei[N];
queue<int> q;
int64_t adj, lo, lps[N];

void bfs()
{
    int v = q.front();
    q.pop();
    am -= nei[v].size();
    for (int i: nei[v])
        if (!vis[i])
            vis[i] = 1,
            q.push(i);
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b, nei[--a].pb(--b), am++;
        if (a != b)
            nei[b].pb(a), am++;
        else
            lps[a]++;
    }
    for (int i = 0; i < n; ++i)
        lo += lps[i],
        adj += (nei[i].size() - lps[i]) * (nei[i].size() - lps[i] - 1) / 2;
    vis[a] = 1;
    q.push(a);
    while (!q.empty())
        bfs();
    if (am)
        return cout << 0, 0;
    cout << adj + lo * (lo - 1) / 2 + (m - lo) * lo;
    return 0;
}