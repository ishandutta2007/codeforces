#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=400010;
const int MOD=1000000007;
int n,fa[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
LL down[MAXN],up[MAXN],ans[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
void DFS(int x)
{
    down[x]=1;
    for(int i=head[x];i;i=next[i])
    {
        DFS(to[i]);
        down[x]=(down[x]*(down[to[i]]+1))%MOD;
    }
}
int son[MAXN],tot;
LL pre[MAXN],suf[MAXN];
void DFS_2(int x)
{
    tot=0;
    for(int i=head[x];i;i=next[i]) son[++tot]=to[i];
    pre[0]=1,suf[tot+1]=1;
    for(int i=1;i<=tot;i++) pre[i]=(pre[i-1]*(down[son[i]]+1))%MOD;
    for(int i=tot;i>=1;i--) suf[i]=(suf[i+1]*(down[son[i]]+1))%MOD;
    for(int i=1;i<=tot;i++)
    {
        int t=son[i];
        up[t]=up[x]*pre[i-1]%MOD*suf[i+1]%MOD;
        up[t]=(up[t]+1)%MOD;
    }
    for(int i=head[x];i;i=next[i]) DFS_2(to[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) scanf("%d",&fa[i]),adde(fa[i],i);
    DFS(1);
    up[1]=1;
    DFS_2(1);
    for(int i=1;i<=n;i++) ans[i]=down[i]*up[i]%MOD;
    for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
    return 0;
}