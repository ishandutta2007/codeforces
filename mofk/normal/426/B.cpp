#include<stdio.h>
int main(void)
{
    int i,j,k,n,m,ans=1,a[105][105],wrong=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    for(ans=n;ans%2==0;ans/=2);
    while(ans<n)
    {
        wrong=0;
        for(i=1;i<=ans;i++)
        {
            for(j=1;j<=m;j++)
            {
                 if(a[i][j]!=a[ans*2-i+1][j]) wrong=1;
            }
        }
        for(i=1;i<=ans*2;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=1;k<n/ans/2;k++)
                {
                    if(a[i][j]!=a[i+2*k*ans][j]) wrong=1;
                }
            }
        }
        if(wrong==1) ans*=2;
        if(wrong==0)
        {
            printf("%d",ans);
            break;
        }
    }
    if(ans==n) printf("%d",n);
}