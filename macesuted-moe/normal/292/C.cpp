#include <bits/stdc++.h>
using namespace std;

struct IP
{
    int ip[4];
} s[100005];

int a[15], vis[15], ip[15];
int n, cnt = 0;

void dfs(int pos, int len)
{
    if (pos > (len + 1) / 2)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
            {
                flag = false;
                break;
            }
        if (!flag)
            return;
        int ip1, ip2, ip3, ip4;
        for (int len1 = 1; len1 < 4; len1++)
        {
            ip1 = 0;
            for (int i = 1; i <= len1; i++)
                ip1 = ip1 * 10 + ip[i];
            if (ip1 > 255 || (len1 > 1 && !ip[1]))
                continue;
            for (int len2 = 1; len2 < 4; len2++)
            {
                ip2 = 0;
                for (int i = len1 + 1; i <= len1 + len2; i++)
                    ip2 = ip2 * 10 + ip[i];
                if (ip2 > 255 || (len2 > 1 && !ip[len1 + 1]) || (len1 + len2 >= len))
                    continue;
                for (int len3 = 1; len3 < 4; len3++)
                {
                    ip3 = 0;
                    for (int i = len1 + len2 + 1; i <= len1 + len2 + len3; i++)
                        ip3 = ip3 * 10 + ip[i];
                    if (ip3 > 255 || len1 + len2 + len3 >= len || (len3 > 1 && !ip[len1 + len2 + 1]))
                        continue;
                    ip4 = 0;
                    for (int i = len1 + len2 + len3 + 1; i <= len; i++)
                        ip4 = ip4 * 10 + ip[i];
                    if (ip4 > 255 || (len - len1 - len2 - len3 > 1 && !ip[len1 + len2 + len3 + 1]))
                        continue;
                    s[cnt] = (IP){ip1, ip2, ip3, ip4};
                    cnt++;
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        vis[i]++;
        ip[pos] = a[i];
        ip[len - pos + 1] = a[i];
        dfs(pos + 1, len);
        vis[i]--;
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    for (int len = 4; len <= 12; len++)
    {
        memset(vis, 0, sizeof(vis));
        memset(ip, 0, sizeof(ip));
        dfs(1, len);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d.%d.%d.%d\n", s[i].ip[0], s[i].ip[1], s[i].ip[2], s[i].ip[3]);
    return 0;
}