#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,k,dfn[510][510],tot;
char str[510][510];
bool ok;
void DFS(int x,int y)
{
    dfn[x][y]=++tot;
    for(int k=0;k<4;k++)
        if(!dfn[x+dx[k]][y+dy[k]]&&str[x+dx[k]][y+dy[k]]=='.')
            DFS(x+dx[k],y+dy[k]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='.')
            {
                if(ok) break;
                DFS(i,j);
                ok=true;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(dfn[i][j]>tot-k) str[i][j]='X';
    for(int i=1;i<=n;i++) puts(str[i]+1);
    return 0;
}