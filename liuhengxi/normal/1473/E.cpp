#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=8e5+5;
const long long LLINF=0x3fffffffffffffffll;
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
}e[4*N];
int n,m,hd[N],cnt,nd;long long dis[N];
bool vis[N];
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
constexpr int none(int u){return u<<2;}
constexpr int min(int u){return u<<2|1;}
constexpr int max(int u){return u<<2|2;}
constexpr int all(int u){return u<<2|3;}
void adline8(int u,int v,int w)
{
	adline(none(u),none(v),w);
	adline(min(u),min(v),w);
	adline(max(u),max(v),w);
	adline(all(u),all(v),w);
	adline(none(u),min(v),2*w);
	adline(max(u),all(v),2*w);
	adline(none(u),max(v),0);
	adline(min(u),all(v),0);
}
struct nodedis
{
	int id;long long dis;
	nodedis(int a,long long b){id=a,dis=b;}
	bool operator<(nodedis b)const{return b.dis<dis;}
};
priority_queue<nodedis> q;
void dijkstra(int s)
{
	F(i,0,nd)dis[i]=LLINF/*,vis[i]=false*/;
	dis[s]=0;q.push(nodedis(s,0));
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
	read(n);read(m);
	F(i,0,nd=n<<2)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);--u,--v;
		adline8(u,v,w);adline8(v,u,w);
	}
	dijkstra(none(0));
	F(i,1,n)printf("%lld ",min(dis[none(i)],dis[all(i)]));
	puts("");
	return 0;
}