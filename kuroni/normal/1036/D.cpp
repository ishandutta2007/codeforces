#include <iostream>
#include <stdio.h>
using namespace std;

int n, m, a[300005], b[300005], ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    int x = 1, y = 1;
    long long s1 = 0, s2 = 0;
    while (x <= n && y <= m)
    {
        if (s1 == 0) s1 += a[x];
        if (s2 == 0) s2 += b[y];
        if (s1 == s2)
        {
            x++;
            y++;
            s1 = 0;
            s2 = 0;
            ans++;
            continue;
        }
        else if (s1 < s2)
        {
            x++;
            s1 += a[x];
            continue;
        }
        else if (s1 > s2);
        {
            y++;
            s2 += b[y];
        }
    }
    if (s1 != 0 || s2 != 0 || x <= n || y <= m) printf("-1");
    else printf("%d", ans);
	return 0;
}