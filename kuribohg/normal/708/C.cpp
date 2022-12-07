#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define next next2
using namespace std;
const int MAXN=1000010;
int n,k,ans[MAXN],q[MAXN],dfn_clock;
int fa[MAXN],size[MAXN],s[MAXN],who[MAXN],cut[MAXN],f[MAXN],up[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int tmp[MAXN];
void DFS(int x)
{
    q[++dfn_clock]=x;
    size[x]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x])
        {
            fa[to[i]]=x;
            DFS(to[i]);
            size[x]+=size[to[i]];
            if(size[to[i]]>s[x]) s[x]=size[to[i]],who[x]=to[i];
            tmp[to[i]]=f[to[i]];
            if(size[to[i]]<=k) tmp[to[i]]=max(tmp[to[i]],size[to[i]]);
            f[x]=max(f[x],f[to[i]]);
            if(size[to[i]]<=k) f[x]=max(f[x],size[to[i]]);
        }
    int cur=0,res=0;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&tmp[to[i]]>tmp[cur]) cur=to[i];
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&to[i]!=cur) up[to[i]]=f[x],res=max(res,tmp[to[i]]);
    if(cur) up[cur]=res;
    if(n-size[x]>s[x]) s[x]=n-size[x],who[x]=fa[x];
}
int main()
{
    scanf("%d",&n);
    k=n/2;
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1);
    for(int i=2;i<=n;i++) if(n-size[fa[i]]<=k) up[i]=max(up[i],n-size[fa[i]]);
    for(int i=2;i<=n;i++) up[q[i]]=max(up[fa[q[i]]],up[q[i]]);
    for(int x=1;x<=n;x++)
    {
        if(s[x]<=k) ans[x]=1;
        else
        {
            if(who[x]!=fa[x]&&s[x]-f[who[x]]<=k) ans[x]=1;
            else if(who[x]==fa[x]&&s[x]-up[x]<=k) ans[x]=1; 
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}