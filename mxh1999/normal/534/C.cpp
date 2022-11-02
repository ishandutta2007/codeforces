#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
typedef long long ll;
ll n,m,s;
ll a[maxn];

int main()
{
    scanf("%I64d%I64d",&n,&m);
    for (int i=1;i<=n;i++)  scanf("%I64d",&a[i]),s+=a[i];
    for (int i=1;i<=n;i++)
    {
        ll minx=max(1LL,m-(s-a[i]));
        ll maxx=min(a[i],m-(n-1));
        printf("%I64d ",minx-1+a[i]-maxx);
    }
    return 0;
}