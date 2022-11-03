#include <bits/stdc++.h>
using namespace std;
// c[i]+max(0,a[j]-(a[i]+c[i]))
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn=100005;
int n;
pii x[maxn];
ll ans;
int main()
{
    int i;
    ll r;
    scanf("%d",&n);
    for(ans=0,i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i].first,&x[i].second);
        ans+=x[i].second,x[i].second+=x[i].first;
    }
    sort(x,x+n);
    for(i=1,r=x[0].second;i<n;i++)
        if(r<x[i].first)
            ans+=x[i].first-r,r=x[i].second;
        else r=max(r,x[i].second);
    printf("%lld\n",ans);
    return 0;
}