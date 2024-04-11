#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, pre[100005], size[100005], dis, order[100005], center;
vector<int> E[100005];
vector<int> subtree[100005];
void dfs(int k)
{

    bool isCenter = true;
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            size[k] += size[i];
            if (size[i] > N / 2)
                isCenter = false;
        }
    size[k]++;
    if (N - size[k] > N / 2)
        isCenter = false;

    if (isCenter)
        center = k;

    for (int i : E[k])
        if (i != pre[k])
            dis += min(size[i], N - size[i]) * 2;
}

void dfs2(int k, int root)
{
    for (int i : E[k])
        if (i != pre[k] && i != center)
        {
            pre[i] = k;
            dfs2(i, root);
            size[k] += size[i];
        }
    size[k]++;

    subtree[root].emplace_back(k);
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
    dfs(1);

    int M = N - 1;

    for (int i = 1; i <= N; i++)
        pre[i] = 0, size[i] = 0, order[i] = i;

    for (int i : E[center])
        dfs2(i, i);

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    for (int i : E[center])
        pq.push(pair<int, int>{size[i], i});

    while (M >= 2)
    {
        pair<int, int> p1, p2;
        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();

        swap(order[subtree[p1.S].back()], order[subtree[p2.S].back()]);
        subtree[p1.S].pop_back();
        subtree[p2.S].pop_back();
        p1.F--;
        p2.F--;
        if (p1.F > 0)
            pq.push(p1);
        if (p2.F > 0)
            pq.push(p2);
        M -= 2;
    }

    if (M == 1)
    {
        pair<int, int> p;
        p = pq.top();
        swap(order[subtree[p.S].back()], order[center]);
    }
    else if (M == 0)
    {
        if (center == 1)
            swap(order[center], order[2]);
        else
            swap(order[center], order[1]);
    }

    cout << dis << '\n';
    for (int i = 1; i <= N; i++)
        cout << order[i] << " \n"[i == N];
}