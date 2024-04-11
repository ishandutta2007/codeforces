#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 3005
#define S n+1
#define T n+4
#define inf 0x3f3f3f3f
using namespace std;
int n,p,s,a[N],b[N];
int sta[N],tota,stb[N],totb,sum;
struct edge{int next,to,v,f;}e[N*20];
int tot,head[N],dis[N],pre[N],ans;
bool vis[N];
void add(int u,int v,int w,int f)
{
	e[tot]=(edge){head[u],v,w,f};
	head[u]=tot++;
	e[tot]=(edge){head[v],u,0,-f};
	head[v]=tot++;
}
bool spfa()
{
	for(int i=1;i<=T;i++)
	dis[i]=-1e9;
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(S);
	dis[S]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();vis[now]=0;
		for(int i=head[now];i!=-1;i=e[i].next)
		if(e[i].v&&dis[e[i].to]<dis[now]+e[i].f)
		{
			dis[e[i].to]=dis[now]+e[i].f;
			pre[e[i].to]=i;
			if(!vis[e[i].to])
			vis[e[i].to]=1,q.push(e[i].to);
		}
	}
	return dis[T]!=-1e9;
}
void end()
{
	int t=inf;
	for(int i=T;i!=S;i=e[pre[i]^1].to)
	t=min(t,e[pre[i]].v);
	for(int i=T;i!=S;i=e[pre[i]^1].to)
	e[pre[i]].v-=t,e[pre[i]^1].v+=t;
	ans+=dis[T]*t;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&p,&s);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		add(S,i,1,0);
		add(i,T-2,1,a[i]);
		add(i,T-1,1,b[i]);
	}
	add(T-2,T,p,0);
	add(T-1,T,s,0);
	while(spfa())end();
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	for(int j=head[i];j!=-1;j=e[j].next)
	if(e[j].to==T-2&&e[j].v==0)
	sta[++tota]=i;
	else if(e[j].to==T-1&&e[j].v==0)
	stb[++totb]=i;
	for(int i=1;i<=p;i++)
	printf("%d ",sta[i]);puts("");
	for(int i=1;i<=s;i++)
	printf("%d ",stb[i]);puts("");
}