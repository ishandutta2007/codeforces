#include <bits/stdc++.h>//
using namespace std;

int n, m;
int a[37];
int mp[1010101];
int mp2[1010101];
int tot = 0, tot2 = 0;
void dfs1(int step, int full, int ans)
{
    if (step > full)
    {
        mp[++tot] = ans;
        return;
    }
    dfs1(step + 1, full, (ans + a[step]) % m);
    dfs1(step + 1, full, ans);
}
void dfs2(int step, int full, int ans)
{
    if (step > full)
    {
        mp2[++tot2] = ans;
        return;
    }
    dfs2(step + 1, full, (ans + a[step]) % m);
    dfs2(step + 1, full, ans);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    dfs1(1, n / 2, 0);
    dfs2(n / 2 + 1, n, 0);
    sort(mp + 1, mp + tot + 1);
    int ans = -1;
    for (int i = 1; i <= tot2; ++i)
    {
        int w = m - mp2[i];
        int pos = lower_bound(mp + 1, mp + tot + 1, w) - mp - 1;
        ans = max(ans, mp2[i] + mp[pos]);
    }
    cout << ans << endl;
    return 0;
}