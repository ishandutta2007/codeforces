#include <bits/stdc++.h>
using namespace std;
int test, n, a[222222];
long long pre[222222];
bool f;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pre[i] < 0) f = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (pre[i] == 0 && pre[i + 1] != 0) f = 1;
        }
        if (pre[n] != 0) f = 1;
        if (f) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}