#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=3e5+5;
constexpr long long LLINF=0x3fffffffffffffffll;
namespace left
{
	struct node
	{
		long long tag,val;
		int ls,rs,ht,lim;
	}s[N];
#define tag(x) s[x].tag
#define val(x) s[x].val
#define ls(x) s[x].ls
#define rs(x) s[x].rs
#define ht(x) s[x].ht
#define lim(x) s[x].lim
	int ind;
	int build(long long v,int l)
	{
		int p=++ind;
		val(p)=v;
		s[p].lim=l;
		ht(p)=1;
		return p;
	}
	int merge(int p,int q)
	{
		if(!(p&&q))return p|q;
		if(tag(p)+val(p)>tag(q)+val(q))swap(p,q);
		val(p)+=tag(p);
		if(ls(p))tag(ls(p))+=tag(p);
		if(rs(p))tag(rs(p))+=tag(p);
		tag(p)=0;
		rs(p)=merge(rs(p),q);
		if(ht(ls(p))<ht(rs(p)))swap(ls(p),rs(p));
		ht(p)=ht(rs(p))+1;
		return p;
	}
	int pop(int p)
	{
		val(p)+=tag(p);
		if(ls(p))tag(ls(p))+=tag(p);
		if(rs(p))tag(rs(p))+=tag(p);
		tag(p)=0;
		return merge(ls(p),rs(p));
	}
	long long top(int &p,int l){while(p&&lim(p)>l)p=pop(p);return p?val(p)+tag(p):LLINF;}
	int add(int p,long long x)
	{
		if(p)tag(p)+=x;
		return p;
	}
#undef tag
#undef val
#undef ls
#undef rs
#undef ht
#undef lim
}
using left::build;
using left::merge;
using left::pop;
using left::top;
using left::add;
int n,m,dep[N],rt[N];
long long t[N];
vector<int> adj[N];
vector<pair<int,int>> cov[N];
void dfsa(int u,int fa)
{
	for(auto i=adj[u].begin();i!=adj[u].end();++i)if(*i==fa){adj[u].erase(i);break;}
	for(int v:adj[u])
	{
		dep[v]=dep[u]+1;
		dfsa(v,u);
	}
}
void dfsb(int u)
{
	long long sum=0;
	for(int v:adj[u])
	{
		dfsb(v);
		t[v]=top(rt[v],dep[u]);
		if(t[v]==LLINF)return;
		sum+=t[v];
	}
	for(pair<int,int> a:cov[u])rt[u]=merge(rt[u],build(a.second+sum,a.first));
	for(int v:adj[u])rt[u]=merge(rt[u],add(rt[v],sum-top(rt[v],dep[u])));
}
int main()
{
	read(n,m);
	if(n==1)return puts("0"),0;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfsa(0,0);
	F(i,0,m)
	{
		int x,y,c;read(x,y,c);--x,--y;
		cov[x].emplace_back(dep[y],c);
	}
	dfsb(0);
	long long ans=top(rt[0],0);
	if(ans==LLINF)ans=-1;
	printf("%lld\n",ans);
	return 0;
}