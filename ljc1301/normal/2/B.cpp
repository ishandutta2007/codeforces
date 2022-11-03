#include <cstdio>
const int maxn=1005;
const int p[2]={2,5};
int n,num[2][maxn][maxn],f[2][maxn][maxn];
inline int min(int a,int b) { return (a<b)?a:b; }
int cnt(int x,int y)
{
    int res=0;
    while(!(x%y))
        res++,x/=y;
    return res;
}
int main()
{
    int i,j,k,x=-1,y=-1,ansk=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            int t;
            scanf("%d",&t);
            if(!t)
            {
                x=i,y=j;
                for(k=0;k<2;k++)
                    num[k][i][j]=100;
            }
            else
                for(k=0;k<2;k++)
                    num[k][i][j]=cnt(t,p[k]);
        }
    for(k=0;k<2;k++)
    {
        f[k][n-1][n-1]=(num[k][n-1][n-1]==100)?0x3fffffff:num[k][n-1][n-1];
        for(i=n-2;i>=0;i--)
            f[k][n-1][i]=(num[k][n-1][i]==100)?0x3fffffff:(num[k][n-1][i]+f[k][n-1][i+1]);
        for(i=n-2;i>=0;i--)
            f[k][i][n-1]=(num[k][i][n-1]==100)?0x3fffffff:(num[k][i][n-1]+f[k][i+1][n-1]);
        for(i=n-2;i>=0;i--)
            for(j=n-2;j>=0;j--)
                f[k][i][j]=(num[k][i][j]==100)?0x3fffffff:(num[k][i][j]+min(f[k][i+1][j],f[k][i][j+1]));
        if(ansk==-1 || f[ansk][0][0]>f[k][0][0])
            ansk=k;
    }
    if((x==-1 && y==-1) || f[ansk][0][0]<1)
    {
        printf("%d\n",f[ansk][0][0]);
        for(i=0,j=0;!(i>=n-1 && j>=n-1);)
            if(i>=n-1)
            {
                printf("R");
                j++;
            }
            else if(j>=n-1)
            {
                printf("D");
                i++;
            }
            else if(f[ansk][i+1][j]<f[ansk][i][j+1])
            {
                printf("D");
                i++;
            }
            else
            {
                printf("R");
                j++;
            }
    }
    else
    {
        printf("1\n");
        for(i=0;i<x;i++)
            printf("D");
        for(j=0;j<y;j++)
            printf("R");
        for(;i<n-1;i++)
            printf("D");
        for(;j<n-1;j++)
            printf("R");
    }
    printf("\n");
    return 0;
}