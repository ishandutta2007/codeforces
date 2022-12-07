#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,k,color,c[510][510],size[250010],ans;
char a[510][510];
bool used[250010];
bool valid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n) return false;
    if(a[x][y]=='X') return false;
    if(c[x][y]) return false;
    return true;
}
bool isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n) return false;
    if(a[x][y]=='X') return false;
    return true;
}
void dfs(int x,int y,int color)
{
    c[x][y]=color,size[color]++;
    for(int k=0;k<4;k++)
        if(valid(x+dx[k],y+dy[k])) dfs(x+dx[k],y+dy[k],color);
}
void update(int x,int y)
{
    int res=0;
    for(int i=0;i<k;i++)
        if(isvalid(x-1,y+i)&&!used[c[x-1][y+i]]) res+=size[c[x-1][y+i]],used[c[x-1][y+i]]=true;
    for(int i=0;i<k;i++)
        if(isvalid(x+i,y-1)&&!used[c[x+i][y-1]]) res+=size[c[x+i][y-1]],used[c[x+i][y-1]]=true;
    for(int i=0;i<k;i++)
        if(isvalid(x+k,y+i)&&!used[c[x+k][y+i]]) res+=size[c[x+k][y+i]],used[c[x+k][y+i]]=true;
    for(int i=0;i<k;i++)
        if(isvalid(x+i,y+k)&&!used[c[x+i][y+k]]) res+=size[c[x+i][y+k]],used[c[x+i][y+k]]=true;
    ans=max(ans,res);
    for(int i=0;i<k;i++)
    {
        if(isvalid(x-1,y+i)) used[c[x-1][y+i]]=false;
        if(isvalid(x+i,y-1)) used[c[x+i][y-1]]=false;
        if(isvalid(x+k,y+i)) used[c[x+k][y+i]]=false;
        if(isvalid(x+i,y+k)) used[c[x+i][y+k]]=false;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!c[i][j]&&a[i][j]=='.') dfs(i,j,++color);
    for(int x=0;x<=n-k;x++)
    {
        int y=0;
        for(int i=x;i<x+k;i++)
            for(int j=y;j<y+k;j++)
                size[c[i][j]]--;
        update(x,y);
        for(y=1;y<=n-k;y++)
        {
            for(int i=x;i<x+k;i++)
                size[c[i][y-1]]++,size[c[i][y+k-1]]--;
            update(x,y);
        }
        for(int i=x;i<x+k;i++)
            for(int j=n-k;j<n;j++)
                size[c[i][j]]++;
    }
    printf("%d\n",ans+k*k);
    return 0;
}