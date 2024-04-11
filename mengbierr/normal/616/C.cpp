#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q1;
queue<int> q2;
int read()
{
    char ch=getchar();int f=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
    return f;
}
int n,m,sum,temp;
char mp[1005][1005];bool a[1005][1005],vis[1005][1005],vis2[1005][1005];
int cnt[1005][1005],tar[1005][1005];
int movex[7]={0,0,0,1,-1};
int movey[7]={0,1,-1,0,0};
void bfs()
{
    while(!q1.empty())
    {
        int x=q1.front(),y=q2.front();
        q1.pop();q2.pop();
        for(int i=1;i<=4;i++)
        {
            if(a[x+movex[i]][y+movey[i]]&&!vis[x+movex[i]][y+movey[i]])
            {
                vis[x+movex[i]][y+movey[i]]=1;
                sum++;
                q1.push(x+movex[i]);
                q2.push(y+movey[i]);
            }
        }
    }
}
void bfs2()
{
    while(!q1.empty())
    {
        int x=q1.front(),y=q2.front();
        q1.pop();q2.pop();
        cnt[x][y]=sum;
        tar[x][y]=temp;
        for(int i=1;i<=4;i++)
        {
            if(a[x+movex[i]][y+movey[i]]&&!vis2[x+movex[i]][y+movey[i]])
            {
                vis2[x+movex[i]][y+movey[i]]=1;
                q1.push(x+movex[i]);
                q2.push(y+movey[i]);
            }
        }
    }
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",mp[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='.')
            a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j]&&a[i][j])
            {
                sum=0;
                q1.push(i);
                q2.push(j);
                vis[i][j]=1;
                sum++;
                bfs();
                temp++;
                q1.push(i);
                q2.push(j);
                vis2[i][j]=1;
                bfs2();
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            putchar('.');
            else
            {
                int ans=0;
                for(int k=1;k<=4;k++)
                {
                    bool ac=1;
                    if(a[i+movex[k]][j+movey[k]])
                    for(int l=1;l<k;l++)
                    {
                        if(tar[i+movex[k]][j+movey[k]]==tar[i+movex[l]][j+movey[l]])
                        {
                            ac=0;
                            break;
                        }
                    }
                    else ac=0;
                    if(ac)
                    {
                        ans+=cnt[i+movex[k]][j+movey[k]];
                    }
                }
                printf("%d",(ans+1)%10);
            }
        }
        putchar('\n');
    }
}