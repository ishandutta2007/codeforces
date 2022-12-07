#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=4000010;
const int MAXM=20000010;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,d[MAXN];
char a[2010][2010];
int head[MAXN],to[MAXM],next[MAXM],cnt=1;
int q[MAXN],l=1,r;
bool used[MAXN];
inline int Hash(int i,int j){return i*m+j+1;}
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
void SetBlock(int x,int y)
{
    int x1,y1,x2,y2;
    x--,y--;
    x1=x/m,y1=x%m,x2=y/m,y2=y%m;
    if(x2==x1+1) a[x1][y1]='^',a[x2][y2]='v';
    else if(x1==x2+1) a[x1][y1]='v',a[x2][y2]='^';
    else if(y2==y1+1) a[x1][y1]='<',a[x2][y2]='>';
    else a[x1][y1]='>',a[x2][y2]='<';
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='.')
                for(int k=0;k<4;k++)
                    if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m&&a[i+dx[k]][j+dy[k]]=='.')
                        adde(Hash(i,j),Hash(i+dx[k],j+dy[k])),d[Hash(i+dx[k],j+dy[k])]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.'&&d[Hash(i,j)]==1)
                q[++r]=Hash(i,j);
            else if(a[i][j]=='.'&&d[Hash(i,j)]==0)
                {puts("Not unique");return 0;}
        }
    while(l<=r)
    {
        int x=q[l++],y=-1;
        if(used[x]) continue;
        used[x]=true;
        for(int i=head[x];i;i=next[i])
            if(!used[to[i]]) y=to[i],used[to[i]]=true;
        if(y==-1) {puts("Not unique");return 0;}
        SetBlock(x,y);
        for(int i=head[y];i;i=next[i])
            if(!used[to[i]])
            {
                d[to[i]]--;
                if(d[to[i]]==1) q[++r]=to[i];
            }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='.') {puts("Not unique");return 0;}
    for(int i=0;i<n;i++)
        puts(a[i]);
    return 0;
}