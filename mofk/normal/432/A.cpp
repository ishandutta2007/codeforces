#include<stdio.h>
int main(void)
{
    int n,k,y[2005],i,ans=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&y[i]);
    for(i=1;i<=n;i++) if(y[i]+k<=5) ans++;
    printf("%d",ans/3);
}