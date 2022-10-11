#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int t, n, a[N], f[N], tr[N];
bool chk[N];
vector<int> ve[N];
vector<vector<int>> ans;

void solve(int u)
{
    if (u == 0)
        return;
    int len = 0;
    for (int i = 1; i <= n; i++)
        if (!chk[a[i]])
        {
            int pos = distance(f, upper_bound(f + 1, f + len + 1, a[i]));
            len = max(len, pos);
            f[pos] = a[i];
            tr[a[i]] = f[pos - 1];
            ve[pos].push_back(a[i]);
        }
    if (1LL * len * (len + 1) / 2 >= u)
    {
        ans.push_back({});
        for (int t = ve[len].back(); t != 0; t = tr[t])
        {
            ans.back().push_back(t);
            chk[t] = true;
        }
        reverse(ans.back().begin(), ans.back().end());
        for (int i = 1; i <= len; i++)
            ve[i].clear();
        solve(u - len);
    }
    else
    {
        for (int i = 1; i <= len; i++)
        {
            ans.push_back(ve[i]);
            ve[i].clear();
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ans.clear();
        fill(chk + 1, chk + n + 1, false);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        solve(n);
        printf("%d\n", ans.size());
        for (vector<int> &ve : ans)
        {
            printf("%d ", ve.size());
            for (int &v : ve)
                printf("%d ", v);
            printf("\n");
        }
    }
}