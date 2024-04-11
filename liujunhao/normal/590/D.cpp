#include <stdio.h>
#include <string.h>
#define INF 99999999;
int n,k,s,ans;
int a[151],f[151][150*150];
int min(int a,int b){return a<b?a:b;}
int main()
{
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=k-1;i>=0;i--)
        {
            for(int j=0;j<=k*i;j++)
            {
                if(f[i][j]!=0x3f3f3f3f)
                {
                    f[i+1][j+k-(i+1)]=min(f[i+1][j+k-(i+1)],f[i][j]+a[k]);
                }
            }
        }
    }
    memset(&ans,127,sizeof(int));
    for(int j=0;j<=min(s,(n*(n)));j++)
    {
        ans=min(ans,f[k][j]);
    }
    printf("%d\n",ans);
    return 0;
}