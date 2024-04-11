#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000005;
int n,num[maxn<<1],*a,sta[maxn],top,maxx;
bool ok[maxn];
long long ans;
int main()
{
    int i;
    scanf("%d",&n);
    a=num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        num[i+n]=num[i];
        if(num[i]>*a)
            a=&num[i];
    }
    top=0;
    for(i=1;i<n;i++)
    {
        ans+=min(top-(lower_bound(sta,sta+top,-a[i])-sta)+1,top);
        sta[(top=upper_bound(sta,sta+top,-a[i])-sta+1)-1]=-a[i];
    }
    for(i=1;i<n;i++)
        ok[i]=false;
    maxx=0x80000000;
    for(i=1;i<n;i++)
        if(a[i]>=maxx)
            ok[i]=true,maxx=a[i];
    maxx=0x80000000;
    for(i=n-1;i>0;i--)
        if(a[i]>=maxx)
            ok[i]=true,maxx=a[i];
    for(i=1;i<n;i++)
        if(ok[i])
            ans++;
    printf("%I64d\n",ans);
    return 0;
}