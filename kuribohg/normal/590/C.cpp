#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int INF=500000000;
int n,m,d12=INF+10,d23=INF+10,d13=INF+10,ans=INF;
int dis[4][1010][1010];
char a[1010][1010];
bool used[1010][1010];
queue<pair<int,int> > q;
bool valid(int x,int y)
{
    if(x<=0||x>n) return false;
    if(y<=0||y>m) return false;
    if(a[x][y]=='#') return false;
    if(used[x][y]) return false;
    return true;
}
void BFS(int o)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='#') dis[o][i][j]=-1;
            else dis[o][i][j]=INF+10;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            used[i][j]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==o+'0') q.push(make_pair(i,j)),used[i][j]=true,dis[o][i][j]=0;
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
            if(valid(x+dx[k],y+dy[k]))
            {
                dis[o][x+dx[k]][y+dy[k]]=dis[o][x][y]+1;
                q.push(make_pair(x+dx[k],y+dy[k]));
                used[x+dx[k]][y+dy[k]]=true;
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    BFS(1);
    BFS(2);
    BFS(3);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='2') d12=min(d12,dis[1][i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='3') d23=min(d23,dis[2][i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='3') d13=min(d13,dis[1][i][j]);
    d12--,d23--,d13--;
    ans=min(ans,d12+d23);
    ans=min(ans,d12+d13);
    ans=min(ans,d13+d23);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.') ans=min(ans,dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-2);
    if(ans==INF) puts("-1");
    else printf("%d\n",ans);
    return 0;
}