#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
int n,a[MAXN],b[MAXN];
LL ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),a[i]-=b[i];
    sort(a+1,a+n+1);
    int r=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0) ans--;
        while(r>1&&a[r-1]+a[i]>0) r--;
        ans+=n+1-r;
    }
    printf("%lld\n",ans/2);
    return 0;
}