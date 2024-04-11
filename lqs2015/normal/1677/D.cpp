#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int test, n, k, a[1111111], flg, ans;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &k);
        flg = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > 0 && i > n - k) flg = 1;
        }
        if (flg) 
        {
            printf("0\n");
            continue;
        }
        ans = 1;
        for (int i = 1; i <= n - k; i++)
        {
            if (!a[i]) ans = 1ll * ans * (k + 1) % mod;
            else if (a[i] == -1) ans = 1ll * ans * (k + i) % mod;
        }
		for (int i = 1; i <= k; i++) ans = 1ll * ans * i % mod;
        printf("%d\n", ans);
    }
    return 0;
}