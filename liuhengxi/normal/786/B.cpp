#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
using namespace std;
const int N=1e5+5;
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
}e[N<<6];
int n,m,s,outrt,inrt,hd[N<<3],cnt,ls[N<<3],rs[N<<3],out[N],in[N],nd,res[200],len;
int *outin[2]={out,in};
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
long long dis[N<<3];
bool vis[N<<3];
priority_queue<nodedis> q;
void dijkstra(int s)
{
	F(i,0,nd)dis[i]=LLINF,vis[i]=false;
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
int build(int l,int r,int opt)
{
	int mid=(l+r)>>1,p=++nd;hd[p]=-1;
	if(r-l==1)return outin[opt][l]=p;
	lc=build(l,mid,opt);rc=build(mid,r,opt);
	if(opt==0)adline(lc,p,0),adline(rc,p,0);
	else adline(p,lc,0),adline(p,rc,0);
	return p;
}
void query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return res[len++]=p,void();
	query(lc,l,mid,x,y);query(rc,mid,r,x,y);
}
int main()
{
	read(n);read(m);read(s);--s;
	outrt=build(0,n,0);
	inrt=build(0,n,1);
	F(i,0,n)adline(out[i],in[i],0),adline(in[i],out[i],0);
	while(m--)
	{
		int t;read(t);
		if(t==1)
		{
			int u,v,w;read(u);read(v);read(w);--u,--v;
			adline(out[u],in[v],w);
		}
		if(t==2)
		{
			int u,l,r,w;read(u);read(l);read(r);read(w);--u,--l;
			len=0;query(inrt,0,n,l,r);
			F(i,0,len)adline(out[u],res[i],w);
		}
		if(t==3)
		{
			int v,l,r,w;read(v);read(l);read(r);read(w);--v,--l;
			len=0;query(outrt,0,n,l,r);
			F(i,0,len)adline(res[i],in[v],w);
		}
	}
	++nd;hd[0]=-1;
	dijkstra(out[s]);
	F(i,0,n)printf("%lld ",dis[in[i]]==LLINF?-1:dis[in[i]]);
	puts("");
	return 0;
}