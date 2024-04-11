#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
const int INF=1000000000;
int n,m,dis[410][410];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) dis[i][j]=INF;
    for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),dis[x][y]=dis[y][x]=1;
    if(dis[1][n]==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                {
                    if(dis[i][j]==INF) dis[i][j]=1;
                    else dis[i][j]=INF;
                }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
    if(dis[1][n]==INF) puts("-1");
    else printf("%d\n",dis[1][n]);
    return 0;
}