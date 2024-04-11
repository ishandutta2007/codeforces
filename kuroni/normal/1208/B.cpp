#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, cnt = 0, ans = N, a[N];
bool vis[N];
map<int, int> ma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (ma[a[i]] == 0)
            ma[a[i]] = ++cnt;
        a[i] = ma[a[i]];
    }
    for (int i = 0; i <= n; i++)
    {
        bool chk = false;
        fill(vis + 1, vis + n + 1, false);
        for (int j = 1; j <= i; j++)
        {
            if (vis[a[j]])
            {
                ans = min(ans, n - j + 1);
                chk = true;
                break;
            }
            vis[a[j]] = true;
        }
        if (!chk)
        {
            for (int j = n; j >= i; j--)
            {
                if (vis[a[j]])
                {
                    ans = min(ans, j - i);
                    break;
                }
                vis[a[j]] = true;
            }
        }
    }
    cout << ans;
}