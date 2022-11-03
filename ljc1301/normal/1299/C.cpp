#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,ne[maxn],sta[maxn],top;
long long a[maxn],pre[maxn];
int main()
{
    int i,j;
    scanf("%d",&n),pre[0]=0;
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]),pre[i]=pre[i-1]+a[i];
    top=-1;
    for(ne[n]=n,sta[++top]=n,i=n-1;i>=1;i--)
    {
        sta[++top]=i;
        while(top>=1 && (pre[sta[top]]-pre[i-1])*(sta[top-1]-i+1)>=(pre[sta[top-1]]-pre[i-1])*(sta[top]-i+1)) top--;
        ne[i]=sta[top];
    }
    // for(i=1;i<=n;i++) printf("%d ",ne[i]);
    // printf("\n");
    for(i=1;i<=n;i=ne[i]+1)
        for(j=i;j<=ne[i];j++)
            printf("%.15lf\n",(pre[ne[i]]-pre[i-1])/(double)(ne[i]-i+1));
    return 0;
}