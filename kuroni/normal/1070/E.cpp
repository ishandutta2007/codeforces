#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

int q, n, m, a[N], ind[N];
long long t;
priority_queue<int> le;
priority_queue<int, vector<int>, greater<int>> ri;

int find_ans(int u)
{
    long long sum = 0, cur = 0;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= u)
        {
            sum += a[i];
            cur += a[i];
            if (sum > t)
                return ans;
            cnt++;
            ans++;
            if (cnt == m)
            {
                sum += cur;
                cur = 0;
                cnt = 0;
            }
        }
    return ans;
}

void solve()
{
    while (!le.empty())
        le.pop();
    while (!ri.empty())
        ri.pop();
    scanf("%d%d%lld", &n, &m, &t);
    long long sum = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, [](const int &x, const int &y) { return a[x] < a[y]; });
    for (int i = 1; i <= n; i++)
    {
        int u = ind[i];
        sum += a[u];
        ri.push(u);
        if (!le.empty() && le.top() > ri.top())
        {
            int v = le.top();
            le.pop();
            ri.pop();
            le.push(u);
            ri.push(v);
            sum += a[u] - a[v];
        }
        if (sum > t)
        {
            if (find_ans(min(1LL * a[u], t)) > cur)
                printf("%d %lld\n", find_ans(a[u]), min(1LL * a[u], t));
            else
                printf("%d %lld\n", cur, min(t, 1LL * a[u] - 1));
            return;
        }
        if (ri.size() == m)
            while (!ri.empty())
            {
                sum += a[ri.top()];
                le.push(ri.top());
                ri.pop();
            }
        if (a[ind[i + 1]] != a[ind[i]])
            cur = i;
    }
    printf("%d %lld\n", n, t);
}

int main()
{
    scanf("%d", &q);
    while (q--)
        solve();
}