#include<cstdio>

const int MaxN=4010;
const int MAXNUM=86400;

int F[MaxN][MaxN];
int n,k;
int t[MaxN],d[MaxN];

int max(int a,int b)
{
    return (a>b)?a:b;
}

int min(int a,int b)
{
    return (a<b)?a:b;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&t[i],&d[i]);
    for (int i=1;i<=n;++i)
    {
        F[i][0]=max(F[i-1][0],t[i]-1)+d[i];
        for (int j=1;j<=k;++j)
            F[i][j]=min(F[i-1][j-1],max(F[i-1][j],t[i]-1)+d[i]);
    }
    int ans=0;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=k;++j)
        {
            if (F[i][j]>=MAXNUM) continue;
            if (i+k-j+1>n)
                ans=max(ans,MAXNUM-F[i][j]);
            else
                ans=max(ans,t[i+k-j+1]-1-F[i][j]);
        }
    printf("%d\n",ans);
    return 0;
}