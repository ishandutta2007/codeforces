#include<cstdio>

const int MaxN=55;

int n,k;
int a[MaxN];

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int ans=0;
    for (int i=1;i<=n;++i)
        if (a[i]>=a[k]&&a[i]) ++ans;
    printf("%d\n",ans);
    return 0;
}