#include<stdio.h>
int main(void)
{
    int i,n,m,a[105],max=0,ans=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(((a[i]-1)/m+1)>=max)
        {
            max=(a[i]-1)/m+1;
            ans=i;
        }
    }
    printf("%d",ans);
}