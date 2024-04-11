#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 50005;

vector<int> adj[N];
int u, v, n, k, cnt[N], sub[N];
long long ans = 0;
bool chk[N];

int DFS(int u, int p = 0)
{
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p && !chk[v])
            sub[u] += DFS(v, u);
    return sub[u];
}

void find_ans(int u, int p, int h)
{
    if (h <= k)
        ans += cnt[k - h];
    for (int &v : adj[u])
        if (v != p && !chk[v])
            find_ans(v, u, h + 1);
}

void save_ans(int u, int p, int h, int val = 1)
{
    cnt[h] += val;
    for (int &v : adj[u])
        if (v != p && !chk[v])
            save_ans(v, u, h + 1, val);
}

void solve(int u, int sz)
{
    DFS(u);
    int pre = 0;
    bool cen = false;
    while (!cen)
    {
        cen = true;
        for (int &v : adj[u])
            if (v != pre && !chk[v] && sub[v] > sz / 2)
            {
                cen = false;
                pre = u;
                u = v;
                break;
            }
    }
    cnt[0] = 1;
    for (int &v : adj[u])
        if (!chk[v])
        {
            find_ans(v, u, 1);
            save_ans(v, u, 1);
        }
    for (int &v : adj[u])
        if (!chk[v])
            save_ans(v, u, 1, -1);
    cnt[0] = 0;
    chk[u] = true;
    for (int &v : adj[u])
        if (!chk[v])
            solve(v, v == pre ? sz - sub[u] : sub[v]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1, n);
    printf("%lld", ans);
}