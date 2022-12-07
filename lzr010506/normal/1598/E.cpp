#include<bits/stdc++.h>
using namespace std;
int vis[1010][1010];
int n, m, q;
int f(int x, int y, int d1, int d2)
{
    int ans = 0;
    x += d1;
    y += d2;
    swap(d1, d2);
    while(x <= n && x >= 1 && y <= m && y >= 1 && vis[x][y] != 1)
    {
        x += d1;
        y += d2;
        ans++;
        swap(d1, d2);
    }
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    int ans = 0;
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            int r = m - j + 1;
            int d = n - i + 1;
            if(r == d) ans += 2 * r - 1;
            else if(r > d) ans += d * 2;
            else ans += 2 * r - 1;
            if(r == d) ans += 2 * d - 1;
            else if(r > d) ans += 2 * d - 1;
            else ans += 2 * r;
            ans--;
            // cout << "zheshi ans: " << ans << endl;
        }
    }
    while(q--)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        if(vis[x][y] == 1)
        {
            int s1 = f(x, y, -1, 0);
            int s2 = f(x, y, 0, 1);
            // cout << s1 << " " << s2 << endl;
            ans += (s1 + 1) * (s2 + 1) - 1;
            s1 = f(x, y, 0, -1);
            s2 = f(x, y, 1, 0);
            // cout << s1 << " " << s2 << endl;
            ans += (s1 + 1) * (s2 + 1) - 1;
            ans++;
        }
        else
        {
            int s1 = f(x, y, -1, 0);
            int s2 = f(x, y, 0, 1);
            ans -= (s1 + 1) * (s2 + 1) - 1;
            s1 = f(x, y, 0, -1);
            s2 = f(x, y, 1, 0);
            ans -= (s1 + 1) * (s2 + 1) - 1;
            ans--;
        }
        if(vis[x][y] == 1) vis[x][y] = 0;
        else vis[x][y] = 1;
        printf("%d\n", ans);
    }
    return 0;
}