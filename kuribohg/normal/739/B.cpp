#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
typedef long long LL;
const int MAXN=400010;
int n;
LL a[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
LL w[MAXN];
inline void adde(int f,int t,LL ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
int anc[MAXN][20],Log[MAXN],dep[MAXN];
LL dis[MAXN][20];
void DFS(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            dep[to[i]]=dep[x]+1;
            anc[to[i]][0]=x;
            dis[to[i]][0]=w[i];
            DFS(to[i],x);
        }
}
int s[MAXN];
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            dfs(to[i],x);
            s[x]+=s[to[i]];
        }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    int x;
    LL y;
    for(int i=1;i<n;i++) scanf("%d%I64d",&x,&y),adde(i+1,x,y);
    DFS(1,-1);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=0;i<=Log[n];i++) dis[1][i]=1000000001;
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
            anc[j][i]=anc[anc[j][i-1]][i-1],dis[j][i]=dis[j][i-1]+dis[anc[j][i-1]][i-1];
    for(int o=1;o<=n;o++)
    {
        int p=o;
        for(int i=Log[n];i>=0;i--)
            if(a[o]>=dis[p][i]) a[o]-=dis[p][i],p=anc[p][i];
        s[o]++,s[anc[p][0]]--;
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++) printf("%d ",s[i]-1);
    return 0;
}