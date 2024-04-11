#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct dsu
{
	int f[N],d[N],su[N],ss[N],t;
	void init(int n){F(i,t=0,n)f[i]=-1,d[i]=0;}
	void findroot(int x,int &rt,int &dis)
	{
		for(;~(f[x]>>31);x=f[x])dis^=d[x];
		rt=x;
	}
	void rollback()
	{
		--t;
		int u=su[t];
		f[f[u]]-=ss[t];
		f[u]=ss[t];
		d[u]=0;
	}
	bool merge(int x,int y,int w)
	{
		findroot(x,x,w);findroot(y,y,w);
		if(f[x]>f[y])swap(x,y);
		if(x!=y)
		{
			ss[t]=f[y];su[t++]=y;
			f[x]+=f[y];
			f[y]=x;d[y]=w;
			return true;
		}
		return false;
	}
}d;
struct event{int x,y,d,t,lt;}e[N<<1];
struct edge{int u,v,w;edge(){};edge(event a):u(a.x),v(a.y),w(a.d){}};
bool operator==(event u,event v){return u.x==v.x&&u.y==v.y;}
bool operator<(event u,event v){return u.x!=v.x?u.x<v.x:u.y!=v.y?u.y<v.y:u.lt<v.lt;}
void insert(int *b,int x)
{
	for(int i=30;~--i;)if(x>>i&1)
	{
		if(b[i])x^=b[i];
		else return b[i]=x,void();
	}
}
int n,m,q,t,s,qu[N],qv[N],b[N][32],su[N<<1],sb[N<<1][32],st,ans[N];
vector<edge> seg[N<<2];
void connect(int u,int v,int w)
{
	if(d.merge(u,v,w))
	{
		u=d.su[d.t-1];v=d.f[u];
		memcpy(sb[st],b[v],sizeof sb[st]);
		su[st++]=u;
		F(i,0,30)insert(b[v],b[u][i]);
		return;
	}
	d.findroot(u,u,w);
	d.findroot(v,v,w);
	memcpy(sb[st],b[u],sizeof sb[st]);
	su[st++]=u;
	insert(b[u],w);
}
void rollback()
{
	int u=su[--st];
	if(~(d.f[u]>>31))
	{
		int v=d.f[u];
		memcpy(b[v],sb[st],sizeof sb[st]);
		d.rollback();
	}
	else memcpy(b[u],sb[st],sizeof sb[st]);
}
#define lc (p<<1)
#define rc (p<<1|1)
void update(int p,int l,int r,int x,int y,edge z)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return seg[p].push_back(z);
	update(lc,l,mid,x,y,z);
	update(rc,mid,r,x,y,z);
}
void dfs(int p,int l,int r)
{
	int mid=(l+r)>>1;
	for(edge o:seg[p])connect(o.u,o.v,o.w);
	if(r-l==1)
	{
		d.findroot(qu[l],qu[l],ans[l]);
		d.findroot(qv[l],qv[l],ans[l]);
		int u=qu[l];
		for(int i=30;~--i;)if((ans[l]^b[u][i])<ans[l])ans[l]^=b[u][i];
	}
	else dfs(lc,l,mid),dfs(rc,mid,r);
	for(edge o:seg[p])rollback();
}
#undef lc
#undef rc
int main()
{
	read(n,m);
	d.init(n);
	F(i,0,m)--read(e[i].x),--read(e[i].y),read(e[i].d),e[i].lt=-1;
	s=m;
	read(q);
	F(i,0,q)
	{
		int opt;
		read(opt);
		if(opt==1)--read(e[s].x),--read(e[s].y),read(e[s].d),e[s].t=t,e[s++].lt=i;
		if(opt==2)--read(e[s].x),--read(e[s].y),e[s].d=-1,e[s].t=t,e[s++].lt=i;
		if(opt==3)--read(qu[t]),--read(qv[t]),++t;
	}
	sort(e,e+s);
	for(int i=0,j=0;i<s;i=j)
	{
		while(j<s&&e[j]==e[i])++j;
		for(int k=i;k<j;k+=2)update(1,0,t,e[k].t,k+1<j?e[k+1].t:t,e[k]);
	}
	dfs(1,0,t);
	F(i,0,t)printf("%d\n",ans[i]);
	return 0;
}