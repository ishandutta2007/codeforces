#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=200010;
const int INF=1000000000;
int n,L,W,x,y;
int head[MAXN],to[MAXN],next[MAXN],w[MAXN],cnt=1;
inline void adde(int f,int t,int ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
int BIT[MAXN];
inline void Change(int x,int tar)
{
    for(int i=x;i<=L+1;i+=(i&(-i)))
        BIT[i]+=tar;
}
inline int Query(int x)
{
    int con=0;
    for(int i=x;i;i^=(i&(-i)))
        con+=BIT[i];
    return con;
}
bool used[MAXN];
int size[MAXN],G[MAXN],K,root;
int dep[MAXN],dis[MAXN];
pair<int,int> minu[MAXN];
pair<int,int> add[MAXN];
int tot_minu,tot_add;
LL ans;
void getroot(int x,int fa)
{
    size[x]=1,G[x]=0;
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]&&to[i]!=fa)
        {
            getroot(to[i],x);
            size[x]+=size[to[i]];
            G[x]=max(G[x],size[to[i]]);
        }
    G[x]=max(G[x],K-size[x]);
    if(G[root]>G[x]) root=x;
}
void DFS_add(int x,int fa)
{
    add[++tot_add]=make_pair(dis[x],dep[x]);
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]&&to[i]!=fa)
        {
            dep[to[i]]=dep[x]+1;
            dis[to[i]]=dis[x]+w[i];
            DFS_add(to[i],x);
        }
}
void DFS_minu(int x,int fa)
{
    minu[++tot_minu]=make_pair(dis[x],dep[x]);
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]&&to[i]!=fa)
        {
            dep[to[i]]=dep[x]+1;
            dis[to[i]]=dis[x]+w[i];
            DFS_minu(to[i],x);
        }
}
LL calc(pair<int,int> a[],int tot)
{
    LL res=0;
    sort(a+1,a+tot+1);
    for(int i=1;i<=tot;i++) Change(a[i].second+1,1);
    int R=tot;
    for(int i=1;i<=tot;i++)
    {
        while(R>0&&a[i].first+a[R].first>W) Change(a[R].second+1,-1),R--;
        if(a[i].second<=L) res+=(LL)Query(L-a[i].second+1);
    }
    for(int i=1;i<=R;i++) Change(a[i].second+1,-1);
    return res;
}
void work(int x)
{
    root=0;
    getroot(x,-1);
    int rt=root;
    used[rt]=true;
    tot_add=0;
    for(int i=head[rt];i;i=next[i])
        if(!used[to[i]])
        {
            dep[to[i]]=1,dis[to[i]]=w[i];
            DFS_add(to[i],rt);
            tot_minu=0;
            DFS_minu(to[i],rt);
            ans-=calc(minu,tot_minu);
        }
    add[++tot_add]=make_pair(0,0);
    ans+=calc(add,tot_add);
    if(!used[x]) K=size[x]-size[rt],work(x);
    for(int i=head[rt];i;i=next[i])
        if(!used[to[i]]) K=size[to[i]],work(to[i]);
}
int main()
{
    scanf("%d%d%d",&n,&L,&W);
    for(int i=2;i<=n;i++) scanf("%d%d",&x,&y),adde(i,x,y);
    G[0]=INF,K=n;
    work(1);
    ans=(ans-(LL)n)>>1;
    printf("%I64d\n",ans);
    return 0;
}