//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define maxn 1010
int a[maxn][maxn];
int n,m,totw,totb;
int ans[maxn][maxn];
int q[maxn][maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char ch=getchar();
            while (ch!='.' && ch!='b' && ch!='w')   ch=getchar();
            if (ch=='w')    a[i][j]=1,totw++;
            if (ch=='b')    a[i][j]=2,totb++;
            if (ch=='.')    a[i][j]=0;
        }
    if (totw!=2*totb)   {printf("NO\n");return 0;}
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (a[i][j]!=0 && ans[i][j]==0)
        {
            if (a[i][j]==2) {printf("NO\n");return 0;}
            if (a[i][j]==1)
            {
                if (j<=m-2 && a[i][j+1]==2 && a[i][j+2]==1)
                {
                    cnt++;
                    ans[i][j]=cnt,ans[i][j+1]=cnt,ans[i][j+2]=cnt;
                    a[i][j]=0,a[i][j+1]=0,a[i][j+2]=0;
                    continue;
                }
                if (i<=n-2 && a[i+1][j]==2 && a[i+2][j]==1)
                {
                    cnt++;
                    ans[i][j]=cnt,ans[i+1][j]=cnt,ans[i+2][j]=cnt;
                    a[i][j]=0,a[i+1][j]=0,a[i+2][j]=0;
                    continue;
                }
                printf("NO\n");
                return 0;
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (ans[i][j]!=0 && q[i][j]==0)
        {
            if (i<=n-2 && ans[i+1][j]==ans[i][j])
            {
                if (q[i-1][j]!=1 && q[i][j-1]!=1 && q[i][j+1]!=1 && q[i+1][j-1]!=1 && q[i+1][j+1]!=1 && q[i+2][j-1]!=1 && q[i+2][j+1]!=1 && q[i+3][j]!=1)
                {
                    q[i][j]=1;q[i+1][j]=1;q[i+2][j]=1;
                    ans[i][j]=0,ans[i+1][j]=0,ans[i+2][j]=0;
                    continue;
                }
                if (q[i-1][j]!=2 && q[i][j-1]!=2 && q[i][j+1]!=2 && q[i+1][j-1]!=2 && q[i+1][j+1]!=2 && q[i+2][j-1]!=2 && q[i+2][j+1]!=2 && q[i+3][j]!=2)
                {
                    q[i][j]=2;q[i+1][j]=2;q[i+2][j]=2;
                    ans[i][j]=0,ans[i+1][j]=0,ans[i+2][j]=0;
                    continue;
                }
                if (q[i-1][j]!=3 && q[i][j-1]!=3 && q[i][j+1]!=3 && q[i+1][j-1]!=3 && q[i+1][j+1]!=3 && q[i+2][j-1]!=3 && q[i+2][j+1]!=3 && q[i+3][j]!=3)
                {
                    q[i][j]=3;q[i+1][j]=3;q[i+2][j]=3;
                    ans[i][j]=0,ans[i+1][j]=0,ans[i+2][j]=0;
                    continue;
                }
                if (q[i-1][j]!=4 && q[i][j-1]!=4 && q[i][j+1]!=4 && q[i+1][j-1]!=4 && q[i+1][j+1]!=4 && q[i+2][j-1]!=4 && q[i+2][j+1]!=4 && q[i+3][j]!=4)
                {
                    q[i][j]=4;q[i+1][j]=4;q[i+2][j]=4;
                    ans[i][j]=0,ans[i+1][j]=0,ans[i+2][j]=0;
                    continue;
                }
            }
            if (j<=m-2 && ans[i][j+1]==ans[i][j])
            {
                if (q[i][j-1]!=1 && q[i-1][j]!=1 && q[i+1][j]!=1 && q[i-1][j+1]!=1 && q[i+1][j+1]!=1 && q[i-1][j+2]!=1 && q[i+1][j+2]!=1 && q[i][j+3]!=1)
                {
                    q[i][j]=1,q[i][j+1]=1,q[i][j+2]=1;
                    ans[i][j]=0,ans[i][j+1]=0,ans[i][j+2]=0;
                    continue;
                }
                if (q[i][j-1]!=2 && q[i-1][j]!=2 && q[i+1][j]!=2 && q[i-1][j+1]!=2 && q[i+1][j+1]!=2 && q[i-1][j+2]!=2 && q[i+1][j+2]!=2 && q[i][j+3]!=2)
                {
                    q[i][j]=2,q[i][j+1]=2,q[i][j+2]=2;
                    ans[i][j]=0,ans[i][j+1]=0,ans[i][j+2]=0;
                    continue;
                }
                if (q[i][j-1]!=3 && q[i-1][j]!=3 && q[i+1][j]!=3 && q[i-1][j+1]!=3 && q[i+1][j+1]!=3 && q[i-1][j+2]!=3 && q[i+1][j+2]!=3 && q[i][j+3]!=3)
                {
                    q[i][j]=3,q[i][j+1]=3,q[i][j+2]=3;
                    ans[i][j]=0,ans[i][j+1]=0,ans[i][j+2]=0;
                    continue;
                }
                if (q[i][j-1]!=4 && q[i-1][j]!=4 && q[i+1][j]!=4 && q[i-1][j+1]!=4 && q[i+1][j+1]!=4 && q[i-1][j+2]!=4 && q[i+1][j+2]!=4 && q[i][j+3]!=4)
                {
                    q[i][j]=4,q[i][j+1]=4,q[i][j+2]=4;
                    ans[i][j]=0,ans[i][j+1]=0,ans[i][j+2]=0;
                    continue;
                }
            }
        }
    printf("YES\n");
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (q[i][j]==0) printf(".");
            if (q[i][j]==1) printf("a");
            if (q[i][j]==2) printf("b");
            if (q[i][j]==3) printf("c");
            if (q[i][j]==4) printf("d");
        }
        printf("\n");
    }
    return 0;
}