#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 5005, MAX = 10005;

int n, a[N], ans[N], ind[N];
bool vis[MAX];
vector<int> pr, sa;

void init()
{
    for (int i = 2; i < MAX; i++)
        if (!vis[i])
        {
            pr.push_back(i);
            for (int j = i * i; j < MAX; j += i)
                vis[j] = true;
        }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        for (int &v : pr)
        {
            if (abs(a[i]) < v * v)
                break;
            bool vis = false;
            while (a[i] % v == 0)
            {
                a[i] /= v;
                vis ^= true;
            }
            if (vis)
                a[i] *= v;
        }
        sa.push_back(a[i]);
    }
    sort(sa.begin(), sa.end());
    sa.resize(distance(sa.begin(), unique(sa.begin(), sa.end())));
    for (int i = 1; i <= n; i++)
    {
        ind[i] = distance(sa.begin(), lower_bound(sa.begin(), sa.end(), a[i]));
        fill(vis, vis + n, false);
        int cnt = 0;
        for (int j = i; j >= 1; j--)
        {
            if (a[j] != 0 && !vis[ind[j]])
            {
                vis[ind[j]] = true;
                cnt++;
            }
            ans[max(1, cnt)]++;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}