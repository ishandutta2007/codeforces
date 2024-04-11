#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c1[200010], c2[200010];
int to[200010], d[200010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&to[i],&d[i]);
            c1[to[i]]++;
            c2[d[i]]++;
        }
        ll ans = 0;
        ans = (ll)n * (n - 1LL) * (n - 2LL) / 6LL;
        for(i=1; i<=n; i++)
        {
            ans -= (ll)(c1[to[i]] - 1LL) * (ll)(c2[d[i]] - 1LL);
        }
        printf("%lld\n", ans);
        for(i=0; i<=n; i++)
        {
            c1[i] = 0;
            c2[i] = 0;
        }
    }
    return 0;
}