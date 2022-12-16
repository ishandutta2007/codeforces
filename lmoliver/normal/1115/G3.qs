#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct Edge
{
    int nxt,v,w;
}e[maxn<<1];
long long dis[maxn]; 
int n,tot,head[maxn],a[maxn],ans[maxn],f[maxn][20];
void Add(int u,int v,int w)
{
    e[++tot]=(Edge){head[u],v,w};
    head[u]=tot;
}
void dfs(int u,int fa,int len)
{
    f[u][0]=fa;
    dis[u]=dis[fa]+len;
    for(int i=1;i<=18;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        dfs(v,u,w);
    int now=v,size=a[v];
    for(int i=18;i>=0;i--)
       if(f[now][i]!=0&&dis[now]-dis[f[now][i]]<=size)
           size-=dis[now]-dis[f[now][i]],now=f[now][i];
        // int p=1,now=v,size=a[v];
        // while(p&&now)
        // {
		// 	cerr<<"LOOP"<<endl;
        //     if(dis[now]-dis[f[now][p]]<=size)
        //     {
        //         size-=dis[now]-dis[f[now][p]];
        //         now=f[now][p];
        //         p<<=1;
        //     }
        //     else p>>=1;
        // }
        // if(dis[now]-dis[f[now][0]]<=size)
        //     now=f[now][0];
        ans[f[now][0]]--;
        ans[f[v][0]]++;
    }
    ans[fa]+=ans[u];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        Add(u,i,w);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}