#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,name[N],col[N],m,ans[N],kk,pos[N];
namespace trie
{
	char s[N];
	int to[N*20][26],ind;
	int hash()
	{
		int j=0;
		scanf("%s",s);
		for(int i=0;s[i];++i)
		{
			int x=s[i]-'a';
			if(!to[j][x])to[j][x]=++ind;
			j=to[j][x];
		}
		return j;
	}
}
namespace segtree
{
	#define lc ls[p]
	#define rc rs[p]
	int ls[N<<5],rs[N<<5],val[N<<5],ind;
	int build(int l,int r,int x)
	{
		int mid=(l+r)>>1,p=++ind;
		val[p]=1;
		if(r-l==1)return p;
		if(x<mid)lc=build(l,mid,x);
		else rc=build(mid,r,x);
		return p;
	}
	int merge(int p,int q)
	{
		if(!p||!q)return p^q;
		if(!ls[p]&&!rs[p])return p;
		lc=merge(ls[p],ls[q]);
		rc=merge(rs[p],rs[q]);
		val[p]=val[lc]+val[rc];
		return p;
	}
	int query(int p,int l,int r,int x,int y)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x||!p)return 0;
		if(x<=l&&r<=y)return val[p];
		return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
	}
	#undef lc
	#undef rc
}
using segtree::build;using segtree::merge;
namespace graph
{
	struct line
	{
		int next,to;
	}e[N];
	int hd[N],cnt,dep[N],dfn[N],time,rt[N];bool isrt[N];
	struct query
	{
		int u,k,id;
		bool operator<(query b)const{return dfn[u]<dfn[b.u];}
	}r[N];
	inline void init(int n){F(i,cnt=0,n)hd[i]=-1,isrt[i]=true;}
	inline void adline(int u,int v)
	{
		isrt[v]=false;
		e[cnt].to=v;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void dfs(int u)
	{
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			dep[v]=dep[u]+1;
			dfs(v);
		}
		dfn[u]=time++;
	}
	void solve(int u)
	{
		rt[u]=build(0,n,col[u]);
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			solve(v);
			rt[u]=merge(rt[u],rt[v]);
		}
		while(kk<m&&r[kk].u==u)
		{
			if(r[kk].k<n)ans[r[kk].id]=segtree::query(rt[u],0,n,pos[r[kk].k],pos[r[kk].k+1]);
			++kk;
		}
	}
}
struct namedep
{
	int name,dep;
	bool operator<(namedep b)const{return dep!=b.dep?dep<b.dep:name<b.name;}
}o[N],v[N];
using graph::init;using graph::adline;using graph::dfs;
using graph::dep;using graph::solve;using graph::r;using trie::hash;
int main()
{
	read(n);init(n);
	F(i,0,n)
	{
		int fa;name[i]=trie::hash();read(fa);--fa;
		if(~fa)adline(fa,i);
	}
	F(i,0,n)if(graph::isrt[i])dfs(i);
	F(i,0,n)o[i].name=name[i],o[i].dep=dep[i],v[i]=o[i],++pos[o[i].dep+1];
	F(i,0,n)pos[i+1]+=pos[i];
	sort(v,v+n);
	F(i,0,n)col[i]=lower_bound(v,v+n,o[i])-v;
	read(m);
	F(i,0,m)read(r[i].u),--r[i].u,read(r[i].k),r[i].k+=dep[r[i].u],r[i].id=i;
	sort(r,r+m);
	F(i,0,n)if(graph::isrt[i])solve(i);
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}