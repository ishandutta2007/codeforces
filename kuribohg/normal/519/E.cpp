#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=200010;
int n,x,y,Q;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int anc[MAXN][20],Log[MAXN];
int dep[MAXN],size[MAXN];
void DFS(int x,int fa)
{
    size[x]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            anc[to[i]][0]=x;
            dep[to[i]]=dep[x]+1;
            DFS(to[i],x);
            size[x]+=size[to[i]];
        }
}
int LCA(int p,int q)
{
    if(dep[p]<dep[q]) swap(p,q);
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) p=anc[p][i];
    for(int i=Log[n];i>=0;i--)
        if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
    if(p!=q) return anc[p][0];
    else return p;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1,-1);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
            anc[j][i]=anc[anc[j][i-1]][i-1];
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d",&x,&y);
        if(x==y) {printf("%d\n",n);continue;}
        int lca=LCA(x,y),D=dep[x]+dep[y]-dep[lca]-dep[lca];
        if(D&1) {puts("0");continue;}
        if(dep[x]<dep[y]) swap(x,y);
        if(dep[x]==dep[y])
        {
            int delta=(D>>1)-1;
            for(int i=Log[delta];i>=0;i--)
                if(delta&(1<<i)) x=anc[x][i],y=anc[y][i];
            printf("%d\n",n-size[x]-size[y]);
        }
        else
        {
            int delta=(D>>1)-1;
            for(int i=Log[delta];i>=0;i--)
                if(delta&(1<<i)) x=anc[x][i];
            printf("%d\n",size[anc[x][0]]-size[x]);
        }
    }
    return 0;
}