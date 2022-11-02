# include <iostream>
# include <cstdio>
# include <queue>
# include <cstring>
using namespace std;
queue<pair<int,int> >q;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int dist[1002][1002];
char a[1002][1002];
int n,m,tx,ty;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=m;j++) if(a[i][j]=='E') tx=i,ty=j;
    q.push(make_pair(tx,ty));
    memset(dist,-1,sizeof(dist)); dist[tx][ty]=0;
    while(!q.empty()){
        pair<int,int>c=q.front(); q.pop();
        int cx = c.first, cy = c.second;
        for(int i=0; i<4; i++)
            if( a[cx+dx[i]][cy+dy[i]]!='T' && a[cx+dx[i]][cy+dy[i]]!=0)
            if( dist[cx+dx[i]][cy+dy[i]]== -1 )
            {
                dist[cx+dx[i]][cy+dy[i]] = dist[cx][cy] + 1;
                q.push(make_pair(cx+dx[i],cy+dy[i]));
            }
    }
    
    int st = 0, ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]=='S') st=dist[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if('1'<= a[i][j] && a[i][j]<='9')
                if(dist[i][j]!=-1 && dist[i][j]<=st) ans+=a[i][j]-'0';
    printf("%d\n",ans);
    return 0;
}