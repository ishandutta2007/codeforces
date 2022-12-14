#include <bits/stdc++.h>
using namespace std;
int n, a[5555];
long long ans, nw, cur;
int main()
{  
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cur = 0; nw = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            cur += ((-nw + a[j]) / a[j]);
            nw = (-nw + a[j]) / a[j] * (-a[j]);
        }
        nw = 0;
        for (int j = i + 1; j <= n; j++)
        {
            cur += ((nw + a[j]) / a[j]);
            nw = (nw + a[j]) / a[j] * a[j];
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}