#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1000000010;
int n,ans[1050],x[1050];
int mask[21][1050];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=10;i++)
        for(int j=0;j<1024;j++)
        {
            int k=(1<<(i-1));
            mask[i][j]=(j/k)&1;
        }
    for(int i=0;i<n;i++) ans[i]=INF;
    for(int i=1;i<=10;i++)
    {
        int tot=0;
        for(int k=0;k<n;k++)
            if(mask[i][k]) tot++;
        if(tot==0) continue;
        printf("%d\n",tot);
        fflush(stdout);
        for(int k=0;k<n;k++)
            if(mask[i][k])
            {
                printf("%d ",k+1);
                fflush(stdout);
            }
        printf("\n");
        fflush(stdout);
        for(int i=0;i<n;i++) scanf("%d",&x[i]);
        for(int k=0;k<n;k++)
            if(!mask[i][k]) ans[k]=min(ans[k],x[k]);
    }
    for(int i=1;i<=10;i++)
        for(int j=0;j<1024;j++)
            mask[i][j]^=1;
    for(int i=1;i<=10;i++)
    {
        int tot=0;
        for(int k=0;k<n;k++)
            if(mask[i][k]) tot++;
        if(tot==0) continue;
        printf("%d\n",tot);
        fflush(stdout);
        for(int k=0;k<n;k++)
            if(mask[i][k])
            {
                printf("%d ",k+1);
                fflush(stdout);
            }
        printf("\n");
        fflush(stdout);
        for(int i=0;i<n;i++) scanf("%d",&x[i]);
        for(int k=0;k<n;k++)
            if(!mask[i][k]) ans[k]=min(ans[k],x[k]);
    }
    printf("-1\n");
    fflush(stdout);
    for(int i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}