#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, pre[100005], dis, order[100005];
vector<int> E[100005];

void dfs(int k)
{

    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
        }
        
    int cnt = 0;
    vector<int> v;
    for (int i : E[k])
        if (i != pre[k])
            if (order[i] == i)
            {
                cnt++;
                v.emplace_back(i);
            }
    
    if (cnt == 0 && k == 1)
    {
        swap(order[E[k].back()], order[k]);
        dis += 2;
    }
    if (cnt == 2)
    {
        for (int i = 0; i < cnt; i++)
            order[v[i]] = v[(i + 1) % cnt];
        swap(order[k], order[v.back()]);
        dis += 4;
        cnt = 0;
    }
    if (cnt > 0 && cnt != 2)
    {
        cnt--;
        swap(order[k], order[v.back()]);
        dis += 2;
        v.pop_back();
    }
    if (cnt > 0)
    {
        for (int i = 0; i < cnt; i++)
            order[v[i]] = v[(i + 1) % cnt];
        dis += cnt * 2;
    }
}

signed main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        E[x].emplace_back(y);
        E[y].emplace_back(x);
    }
    for (int i = 1; i <= N; i++)
        order[i] = i;
    dfs(1);
    cout << dis << '\n';
    for (int i = 1; i <= N; i++)
        cout << order[i] << " \n"[i == N];
}