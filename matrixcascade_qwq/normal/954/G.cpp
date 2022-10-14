#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn =5e6 + 10;
int a[maxn], sum[maxn];
int k[maxn];
int n, sr, kk;
int rmax;
int check(int pos)
{
    int ks = 0;
    for (int i = 1; i <= n; ++i)
    {
        k[i] = sum[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        k[i] += k[i - 1];
        if (k[i] < pos)
        {
            int del = pos - k[i];
            ks += del;
            if (ks > kk)
                return 0;
            k[i + 2 * sr + 1] -= del;
            k[i] += del;
        }
    }
    return 1;
}
signed main()
{
    scanf("%lld%lld%lld", &n, &sr, &kk);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        sum[i] += a[i];
        sum[i + sr + 1] -= a[i];
        int p = i - sr;
        if (p < 1)
            p = 1;
        sum[p] += a[i];
        sum[i] -= a[i];
        rmax += a[i];
        rmax += kk;
    }
    int l = 0, r = rmax;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld", r);
    return 0;
}//