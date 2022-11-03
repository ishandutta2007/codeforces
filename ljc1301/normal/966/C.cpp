#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int maxlog=60;
int n;
ll b[maxlog][maxn],m[maxlog],a,ans[maxn];
int main()
{
    int i,j;
    ll x;
    scanf("%d",&n);
    for(i=0;i<maxlog;i++) m[i]=0;
    for(i=0,a=0;i<n;i++)
    {
        scanf("%lld",&x),a^=x;
        for(j=0;x>>j;j++);
        b[j-1][m[j-1]++]=x;
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<maxlog;j++)
            if(((a>>j)&1) && m[j])
            {
                a^=ans[i]=b[j][--m[j]];
                break;
            }
        if(j>=maxlog) return printf("No\n"),0;
    }
    printf("Yes\n");
    for(i=0;i<n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}