#include <cstdio>
const int maxx=1000005;
int f[maxx],g[maxx],ans[maxx][10];
int main()
{
    int q,i,j;
    for(i=0;i<10;i++)
        g[i]=f[i]=i;
    for(i=10;i<maxx;i++)
    {
        f[i]=f[i/10]*((i%10)?i%10:1);
        g[i]=g[f[i]];
    }
    for(i=0;i<10;i++)
        ans[0][i]=0;
    for(i=1;i<maxx;i++)
    {
        for(j=0;j<10;j++)
            ans[i][j]=ans[i-1][j];
        ans[i][g[i]]++;
    }
    scanf("%d",&q);
    while(q--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",ans[r][k]-ans[l-1][k]);
    }
    return 0;
}