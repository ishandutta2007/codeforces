#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1000010;
const int INF=1000000000;

int S,T;

int tot;
struct node
{
	int x,c,w;
	node *next,*rev;
}e[MaxN],*v[MaxN];

void addedge(int x,int y,int c,int w)
{
	++tot;
	e[tot]=(node){y,c,w,v[x],e+tot+1};
	v[x]=e+tot;
	++tot;
	e[tot]=(node){x,0,-w,v[y],e+tot-1};
	v[y]=e+tot;
}

int ans;
int u[MaxN];
int dis[MaxN];

void SPFA()
{
	for (int i=1;i<=T;++i)
		dis[i]=INF;
	priority_queue<pii> Q;
	Q.push(pii(dis[S]=0,S));
	while (!Q.empty())
	{
		int x=Q.top().Y,d=-Q.top().X;
		Q.pop();
		if (dis[x]!=d) continue;
		for (node *it=v[x];it;it=it->next)
			if (it->c>0&&dis[it->x]>d+it->w)
				Q.push(pii(-(dis[it->x]=d+it->w),it->x));
	}
	for (int i=1;i<=T;++i)
		dis[i]=dis[T]-dis[i];
}

int find_flow(int x,int flow)
{
	if (x==T)
	{
		ans+=dis[S]*flow;
		return flow;
	}
	u[x]=1;
	int now=flow;
	for (node *it=v[x];it;it=it->next)
		if (it->c&&!u[it->x]&&dis[it->x]+it->w==dis[x])
		{
			int tmp=find_flow(it->x,min(now,it->c));
			it->c-=tmp;
			it->rev->c+=tmp;
			now-=tmp;
			if (!now) break;
		}
	return flow-now;
}

bool modify_label()
{
	int d=INF;
	for (int i=1;i<=T;++i) if (u[i])
		for (node *it=v[i];it;it=it->next)
			if (it->c&&!u[it->x]) d=min(d,dis[it->x]+it->w-dis[i]);
	if (d==INF) return false;
	for (int i=1;i<=T;++i) if (u[i])
		dis[i]+=d;
	return true;
}

void work()
{
	SPFA();
	while (1)
	{
		while (1)
		{
			for (int i=1;i<=T;++i) u[i]=0;
			if (!find_flow(S,INF)) break;
		}
		if (!modify_label()) break;
	}
	cout<<ans<<endl;
}

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int n,m;
int a[110][110];

int place(int x,int y)
{
	return (x-1)*m+y;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	S=n*m+1;
	T=S+1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if ((i+j)&1)
			{
				addedge(S,place(i,j),1,0);
				for (int k=0;k<4;++k)
				{
					int x=i+dx[k],y=j+dy[k];
					if (x>=1&&x<=n&&y>=1&&y<=m)
						addedge(place(i,j),place(x,y),1,a[i][j]!=a[x][y]);
				}
			}
			else
			{
				addedge(place(i,j),T,1,0);
			}
	work();
	return 0;
}