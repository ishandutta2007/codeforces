#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=500010;
int n,p[MAXN],root,ans[MAXN],res;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
bool used[MAXN],vis[MAXN];
void DFS(int x)
{
    used[x]=true;
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]) DFS(to[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),ans[i]=p[i];
    for(int i=1;i<=n;i++) if(p[i]==i) root=i;
    if(root) res--;
    for(int i=1;i<=n;i++) adde(i,p[i]);
    for(int i=1;i<=n;i++)
    {
        if(p[i]==i) DFS(i),res++;
        if(i!=root&&p[i]==i) ans[i]=root;
    }
    for(int i=1;i<=n;i++) vis[i]=used[i];
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            int x=i;
            while(!vis[p[x]]) vis[p[x]]=true,x=p[x];
            if(root==0) ans[x]=x,root=x;
            else ans[x]=root;
            DFS(i),res++;
        }
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}