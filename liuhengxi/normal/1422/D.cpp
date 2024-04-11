#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+7,INF=0x7fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to,dis;
}e[6*N];
int n,sx,sy,tx,ty,s,t,x[N],y[N],id[N],hd[N],cnt;
bool cmpx(int u,int v){return x[u]<x[v];}
bool cmpy(int u,int v){return y[u]<y[v];}
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
inline void adline2(int u,int v,int w){adline(u,v,w);adline(v,u,w);}
struct nodedis
{
	int id,dis;
	nodedis(int a,int b){id=a;dis=b;}
	bool operator<(nodedis b)const{return dis>b.dis;}
};
int dis[N];
bool vis[N];
priority_queue<nodedis> q;
void dijkstra(int s)
{
	F(i,0,n+2)dis[i]=INF,vis[i]=false;
	dis[s]=0;
	q.push(nodedis(s,0));
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].dis)
			{
				dis[v]=dis[u]+e[i].dis;
				q.push(nodedis(v,dis[v]));
			}
		}
	}
}
int main()
{
	read(n);read(n);s=n,t=n+1;
	read(sx);read(sy);read(tx);read(ty);
	F(i,0,n)read(x[i]),read(y[i]),id[i]=i;
	F(i,0,n+2)hd[i]=-1;
	sort(id,id+n,cmpx);
	F(i,0,n-1)adline2(id[i],id[i+1],x[id[i+1]]-x[id[i]]);
	sort(id,id+n,cmpy);
	F(i,0,n-1)adline2(id[i],id[i+1],y[id[i+1]]-y[id[i]]);
	F(i,0,n)adline(s,i,min(abs(x[i]-sx),abs(y[i]-sy)));
	F(i,0,n)adline(i,t,abs(x[i]-tx)+abs(y[i]-ty));
	adline(s,t,abs(sx-tx)+abs(sy-ty));
	dijkstra(s);
	printf("%d\n",dis[t]);
	return 0;
}