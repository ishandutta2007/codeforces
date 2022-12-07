#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,Q,x[100010],y[100010];
int col[1010][1010],tot,ans[1000010];
char map[1010][1010];
bool valid(int x,int y)
{
    if(x<=0||x>n) return false;
    if(y<=0||y>m) return false;
    if(map[x][y]=='*') return false;
    return true;
}
void DFS(int x,int y,int c)
{
    col[x][y]=c;
    for(int k=0;k<4;k++)
        if(valid(x+dx[k],y+dy[k])&&!col[x+dx[k]][y+dy[k]])
            DFS(x+dx[k],y+dy[k],c);
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
    for(int i=1;i<=Q;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!col[i][j]&&valid(i,j))
                DFS(i,j,++tot);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(map[i][j]=='*')
                for(int k=0;k<4;k++)
                    if(valid(i+dx[k],j+dy[k]))
                        ans[col[i+dx[k]][j+dy[k]]]++;
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[col[x[i]][y[i]]]);
    return 0;
}