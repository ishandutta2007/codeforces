#include<cstdio>
#include<utility>
#include<map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
namespace dsu
{
	int f[N];
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
}
using dsu::find;
template<typename T>struct BITt
{
	int n;T *c;
	void init(T *c_,int n_){c=c_,n=n_;}
	void add(int x,T y){for(++x;x<=n;x+=x&-x)c[x]=c[x]+y;}
	T sum(int x){T ans=0;for(;x;x-=x&-x)ans=ans+c[x];return ans;}
};
BITt<long long> s[N];BITt<int> c[N];
int intpool[2*N],*intptr=intpool;
long long llpool[2*N],*llptr=llpool;
struct line
{
	int next,to;
}e[2*N];
int hd[N],cnt,h[N],t,w[N];
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
inline void adline2(int u,int v){adline(u,v);adline(v,u);}
int n,m,q,f[N],d[N],siz[N];
int dfs1(int u,int fa)
{
	int ans=0,maxch=-1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		ans=max(ans,dfs1(v,u));
		ans=max(ans,f[v]+maxch+2);
		maxch=max(maxch,f[v]);
		f[u]=max(f[u],f[v]+1);
	}
	ans=max(ans,f[u]);
	return ans;
}
void dfs2(int u,int fa)
{
	f[u]=max(f[u],w[u]);
	t=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		h[t++]=v;
	}
	int now=0;
	F(i,0,t)w[h[i]]=w[u];
	F(i,0,t)
	{
		w[h[i]]=max(w[h[i]],now);
		now=max(now,f[h[i]]+1);
	}
	now=0;
	for(int i=t;~--i;)
	{
		w[h[i]]=max(w[h[i]],now);
		now=max(now,f[h[i]]+1);
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		++w[v];dfs2(v,u);
	}
}
map<pair<int,int>,long long> mem;
int main()
{
	read(n,m,q);
	F(i,0,n)hd[dsu::f[i]=i]=-1;
	F(i,0,m)
	{
		int u,v;--read(u),--read(v);
		adline2(u,v);
		dsu::f[find(u)]=find(v);
	}
	F(i,0,n)++siz[find(i)];
	F(i,0,n)if(find(i)==i)
	{
		d[i]=dfs1(i,i);
		dfs2(i,i);
		c[i].init(intptr,siz[i]),intptr+=siz[i]+1;
		s[i].init(llptr,siz[i]),llptr+=siz[i]+1;
	}
	F(i,0,n)c[find(i)].add(f[i],1),s[find(i)].add(f[i],f[i]);
	while(q--)
	{
		int u,v;--read(u),--read(v);u=find(u),v=find(v);if(u==v){puts("-1");continue;}if(u>v)swap(u,v);
		auto pa=make_pair(u,v);
		if(!mem.count(pa))
		{
			long long ans=0,all;
			int maxd=max(d[u],d[v]),last=0;
			if(siz[u]>siz[v])swap(u,v);
			all=s[v].sum(siz[v]);
			F(i,0,siz[u])
			{
				int delta=c[u].sum(i+1)-last;last+=delta;
				long long lo=c[v].sum(max(maxd-i-1,0)),hi=siz[v]-lo;
				ans+=delta*lo*maxd;
				ans+=delta*hi*(i+1)+delta*(all-s[v].sum(max(maxd-i-1,0)));
			}
			mem[pa]=ans;
		}
		printf("%.9lf\n",(double)mem[pa]/siz[u]/siz[v]);
	}
	return 0;
}