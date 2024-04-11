#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn],pre[maxn],suf[maxn];
int main()
{
    int i,maxx=-1,k=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    pre[0]=suf[n+1]=0x7fffffff;
    for(i=1;i<=n;i++)
        pre[i]=pre[i-1]&~a[i];
    for(i=n;i;i--)
        suf[i]=suf[i+1]&~a[i];
    for(i=1;i<=n;i++)
        if((pre[i-1]&suf[i+1]&a[i])>maxx)
            maxx=pre[i-1]&suf[i+1]&a[i],k=i;
    printf("%d",a[k]);
    for(i=1;i<=n;i++)
        if(i!=k)
            printf(" %d",a[i]);
    printf("\n");
    return 0;
}