#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
typedef long long ll;
int n,b[maxn];
ll a[maxn],tr[maxn];
#define lowbit(x) ((x)&-(x))
inline void update(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        tr[x]+=y;
}
inline ll query(int x)
{
    ll res=0;
    for(;x;x-=lowbit(x))
        res+=tr[x];
    return res;
}
int main()
{
    int i,l,r,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++) tr[i]=0;
    for(i=1;i<=n;i++) update(i,i);
    for(i=n;i>=1;i--)
    {
        l=1,r=n;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(query(mid-1)<=a[i]) l=mid;
            else r=mid-1;
        }
        update(l,-l);
        b[i]=l;
    }
    for(i=1;i<=n;i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}