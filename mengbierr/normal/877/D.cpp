#include<stdio.h>  
#include<string.h>  
#include<queue>  
#include<algorithm>  
using namespace std;  
struct node  
{  
    int x,y,step;  
}now,nex;  
char a[1050][1050];  
int dist[1050][1050];  
int vis[1050][1050];  
int n,m,k;  
int sx,sy,ex,ey;  
int fx[4]={0,0,1,-1};  
int fy[4]={1,-1,0,0};  
void Slove()  
{  
    sx--;sy--;ex--;ey--;  
    for(int i=0;i<n;i++)  
    {  
        for(int j=0;j<m;j++)  
        {  
            dist[i][j]=0x3f3f3f3f;  
            vis[i][j]=0;  
        }  
    }  
    queue<node>s;  
    now.x=sx,now.y=sy,now.step=0;  
    dist[sx][sy]=0;  
    s.push(now);  
    while(!s.empty())  
    {  
        now=s.front();s.pop();  
        vis[now.x][now.y]=0;  
        for(int i=0;i<4;i++)  
        {  
            for(int j=1;j<=k;j++)  
            {  
                nex.x=now.x+fx[i]*j;  
                nex.y=now.y+fy[i]*j;  
                nex.step=now.step+1;  
                if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m||a[nex.x][nex.y]=='#'||(dist[nex.x][nex.y]!=0x3f3f3f3f&&dist[nex.x][nex.y]<now.step+1))break;  
                else  
                {  
                    if(nex.step<dist[nex.x][nex.y]&&vis[nex.x][nex.y]==0)  
                    {  
                        vis[nex.x][nex.y]=1;  
                        dist[nex.x][nex.y]=nex.step;  
                        s.push(nex);  
                    }  
                }  
            }  
        }  
    }  
    if(dist[ex][ey]==0x3f3f3f3f)dist[ex][ey]=-1;  
    printf("%d\n",dist[ex][ey]);  
}  
int main()  
{  
    while(~scanf("%d%d%d",&n,&m,&k))  
    {  
        for(int i=0;i<n;i++)scanf("%s",a[i]);  
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);  
        Slove();  
    }  
}