#include<stdio.h>
int main(void)
{
    int i,j,n,k[105],m[105][105],sum[105]={0},ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&k[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k[i];j++) {
            scanf("%d",&m[i][j]);
            sum[i]+=m[i][j]*5+15;
        }
    }
    ans=sum[1];
    for(i=2;i<=n;i++) if(sum[i]<ans) ans=sum[i];
    printf("%d",ans);
}