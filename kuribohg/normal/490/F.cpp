#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=20010;
int n,w[MAXN],ans,f[MAXN],a[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
    int tmp=a[f[x]];
    ans=max(ans,f[x]);
    a[f[x]]=min(a[f[x]],w[x]);
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            f[to[i]]=lower_bound(a,a+n+1,w[to[i]])-a;
            DFS(to[i],x);
        }
    a[f[x]]=tmp;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v);
    for(int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        for(int j=1;j<=n;j++) a[j]=1000000000;
        a[0]=0,f[i]=1;
        DFS(i,-1);
    }
    printf("%d\n",ans);
    return 0;
}