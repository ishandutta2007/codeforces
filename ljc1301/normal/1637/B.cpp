#include <bits/stdc++.h>
using namespace std;
// mex{S}<=|S|
// 1+mex{b[l~r]}<=r-l+2 "="=>b[i]=0
// => [l,l]...[r,r] >=r-l+2
const int maxn=105;
int n,a[maxn],s[maxn];
int main()
{
    int T,i;
    long long ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans+=(a[i]?1:2)*i*(n-i+1ll);
        }
        printf("%lld\n",ans);
    }
    return 0;
}