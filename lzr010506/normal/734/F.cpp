#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll a[N], b[N], c[N], cnt[60];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%I64d", &b[i]);
    for(int i = 1; i <= n; i ++)
        scanf("%I64d", &c[i]);
    ll s = 0;
    for(int i = 1; i <= n; i ++)
        s += b[i] + c[i];
    if(s % (2 * n))return 0*printf("-1");
    s /= 2 * n;
    for(int i = 1; i <= n; i ++)
    {
        if(b[i] + c[i] - s < 0 || (b[i] + c[i] - s) % n)return 0 * printf("-1");
        a[i] = (b[i] + c[i] - s) / n;
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < 60; j ++)
            cnt[j] += (a[i] >> j & 1);
    for(int i = 1; i <= n; i ++)
    {
        ll tb = 0, tc = 0;
        for(int j = 0; j < 60; j ++)
            if((a[i] >> j & 1))
            {
                tb += cnt[j] * (1LL << j);
                tc += n * (1LL << j);
            }
            else tc += cnt[j] * (1LL << j);
        if(tb != b[i] || tc != c[i])return 0 * printf("-1");
    }
    for(int i = 1; i <= n; i ++)
        printf("%I64d ",a[i]);
    return 0;
}