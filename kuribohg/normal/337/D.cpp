#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300010;
const int INF=1000000000;
int n,m,D,x,y;
bool key[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int down[MAXN],up[MAXN];
void DFS_down(int x,int fa)
{
    if(!key[x]) down[x]=-INF;
    else down[x]=0;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            DFS_down(to[i],x);
            down[x]=max(down[x],down[to[i]]+1);
        }
}
int a[MAXN],pre[MAXN],suf[MAXN],tot;
void DFS_up(int x,int fa)
{
    tot=0;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa) a[++tot]=to[i];
    pre[0]=-INF,suf[tot+1]=-INF;
    for(int i=1;i<=tot;i++) pre[i]=max(pre[i-1],down[a[i]]+1);
    for(int i=tot;i>=1;i--) suf[i]=max(suf[i+1],down[a[i]]+1);
    for(int i=1;i<=tot;i++)
    {
        up[a[i]]=max(up[x]+1,max(pre[i-1],suf[i+1])+1);
        if(key[a[i]]) up[a[i]]=max(up[a[i]],0);
    }
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa) DFS_up(to[i],x);
}
int ans;
int main()
{
    scanf("%d%d%d",&n,&m,&D);
    for(int i=1;i<=m;i++) scanf("%d",&x),key[x]=true;
    for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS_down(1,0);
    if(key[1]) up[1]=0;
    else up[1]=-INF;
    DFS_up(1,0);
    for(int i=1;i<=n;i++)
        if(down[i]<=D&&up[i]<=D) ans++;
    printf("%d\n",ans);
    return 0;
}