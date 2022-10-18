#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define _INFINITY 9223372036854775807
using namespace std;

int n, m, x, y, pre[300005], low[300005], dis[300005], ans[300005], res, first, second;
vector<int> e[300005];
stack<int> s;

void dfs(int n)
{
    for (auto i : e[n])
    {
        if (!pre[i])
        {
            pre[i] = n;
            dis[i] = dis[n] + 1;
            low[i] = dis[i];
            dfs(i);
            low[n] = min(low[n], low[i]);
        }
        else if (pre[n] != i)
            low[n] = min(low[n], dis[i]);
    }
}

void dfs2(int n)
{
    vector<int> v;
    for (auto i : e[n])
        if (pre[i] == n)
        {
            dfs2(i);
            v.emplace_back(ans[i]);
        }
    sort(v.begin(), v.end(), greater<int>());
    if(v.size() >= 2)
        res = max(res, v[0] + v[1]);
    if(!v.empty())
        ans[n] += v[0];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    pre[1] = -1;
    dfs(1);
    for (int i = 1; i <= n; i++)
        for (int j : e[i])
            if (pre[j] == i)
                if (low[j] > dis[i])
                    ans[j]++;
    dfs2(1);
    cout << max(res, ans[1]);
}