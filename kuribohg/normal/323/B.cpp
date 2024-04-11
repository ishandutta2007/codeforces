#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1010;
int n,G[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    if(n==4) {puts("-1");return 0;}
    if(n%2==1)
    {
        G[1][2]=1;
        G[2][3]=1;
        G[3][1]=1;
        for(int i=5;i<=n;i+=2)
        {
            for(int j=1;j<=i-2;j++)
                G[j][i-1]=1;
            G[i-1][i]=1;
            for(int j=1;j<=i-2;j++)
                G[i][j]=1;
        }
    }
    else
    {
        G[1][2]=1;
        G[2][3]=1;
        G[3][1]=1;
        G[4][5]=1;
        G[5][6]=1;
        G[6][4]=1;
        G[1][4]=1;
        G[2][6]=1;
        G[3][5]=1;
        G[4][2]=1;
        G[4][3]=1;
        G[6][1]=1;
        G[6][3]=1;
        G[5][1]=1;
        G[5][2]=1;
        for(int i=8;i<=n;i+=2)
        {
            for(int j=1;j<=i-2;j++)
                G[j][i-1]=1;
            G[i-1][i]=1;
            for(int j=1;j<=i-2;j++)
                G[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
            printf("%d ",G[i][j]);
        printf("%d\n",G[i][n]);
    }
    return 0;
}