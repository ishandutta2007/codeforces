#include <bits/stdc++.h>
using namespace std;
int n, a[222222], x, ans, y, test;
long long c;
bool u[222222];
map<int, int> mp;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        ans = 0;
        for (int i = 1; i <= n; i++) u[i] = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) mp[a[i]] ++;
        ans = n;
        for (int i = 1; i <= n; i++)
        {
            if (!mp[a[i]]) continue;
            c = 1ll * a[i] * x;
            if (c > a[n]) continue;
            if (mp[c])
            {
                mp[c] --;
                ans -= 2;
            }
            mp[a[i]] --;
        }
        printf("%d\n", ans);
    }
    return 0;
}