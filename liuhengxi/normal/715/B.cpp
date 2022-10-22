#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("NO"),0
using namespace std;
const int N=1005,M=10005,BIG=0x3fffffff;
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
}e[2*M];
int n,m,hd[N],cnt,s,t,ww,pre[N],id[M],un,one;
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
struct nodedis
{
	int id;long long dis;
	nodedis(int a,long long b){id=a;dis=b;}
	bool operator<(nodedis b)const{return dis>b.dis;}
};
long long dis[N];
bool vis[N];
priority_queue<nodedis> q;
void dijkstra(int s,bool record=false)
{
	F(i,0,n)dis[i]=LLINF,vis[i]=false;
	dis[s]=0;if(record)pre[s]=-1;
	q.push(nodedis(s,0));
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,realdis=e[i].dis?e[i].dis:1;
			if(dis[v]>dis[u]+realdis)
			{
				if(record)pre[v]=u;
				dis[v]=dis[u]+realdis;
				q.push(nodedis(v,dis[v]));
			}
		}
	}
}
#define check (dijkstra(s),dis[t]>=ww)
#define assign(i,x) e[(i)<<1].dis=x,e[(i)<<1|1].dis=x;
int main()
{
	long long ori;
	read(n);read(m);read(ww);read(s);read(t);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(u,v,w);adline(v,u,w);
	}
	dijkstra(s,true);if((ori=dis[t])>ww)fail;
	F(i,0,2*m)if(e[i].dis==0)e[i].dis=BIG;
	dijkstra(s);if(dis[t]<ww)fail;
	F(i,0,m)if(e[i<<1].dis==BIG)id[un++]=i;
	for(int inc=16384;inc;inc>>=1)if(one+inc<=un)
	{
		F(i,one,one+inc)assign(id[i],1);
		if(check)one+=inc;
		else F(i,one,one+inc)assign(id[i],BIG);
	}
	if(one!=un)
	{
		int l=0,r=BIG,mid;
		while(r-l>1)
		{
			mid=(l+r)>>1;
			assign(id[one],mid);
			if(check)r=mid;
			else l=mid;
		}
		assign(id[one],r);
	}
	puts("YES");
	F(i,0,m)printf("%d %d %d\n",e[i<<1|1].to,e[i<<1].to,e[i<<1].dis);
	return 0;
}