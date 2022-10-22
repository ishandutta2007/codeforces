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
constexpr int N=3e5+5,LogN=21,MOD=1071363323,bas=7482223;
int pw[N];
namespace seg
{
	struct data
	{
		int ls,rs,hash;
	}s[7000005];
#define ls(p) s[p].ls
#define rs(p) s[p].rs
#define hash(p) s[p].hash
	int ind;
	int build(int l,int r)
	{
		int p=++ind;
		if(r-l==1)return p;
		int mid=(l+r)>>1;
		ls(p)=build(l,mid);
		rs(p)=build(mid,r);
		return p;
	}
	int update(int p,int l,int r,int x)
	{
		int q=++ind;
		if(r-l==1)
		{
			hash(q)=hash(p)^1;
			return q;
		}
		int mid=(l+r)>>1;
		if(x<mid)ls(q)=update(ls(p),l,mid,x),rs(q)=rs(p);
		else ls(q)=ls(p),rs(q)=update(rs(p),mid,r,x);
		hash(q)=(int)((hash(ls(q))+(long long)hash(rs(q))*pw[mid-l])%MOD);
		return q;
	}
	int query(int p,int q,int l,int r,int x,int y)
	{
		int mid=(l+r)>>1;
		if(x<=l&&r<=y)
		{
			if(hash(p)==hash(q))return y;
			if(r-l==1)return l;
			if(hash(ls(p))!=hash(ls(q)))return query(ls(p),ls(q),l,mid,x,y);
			return query(rs(p),rs(q),mid,r,x,y);
		}
		if(y<=mid)return query(ls(p),ls(q),l,mid,x,y);
		if(x>=mid)return query(rs(p),rs(q),mid,r,x,y);
		int res=query(ls(p),ls(q),l,mid,x,y);
		if(res!=y)return res;
		return query(rs(p),rs(q),mid,r,x,y);
	}
#undef ls
#undef rs
#undef hash
}
using seg::build;using seg::update;using seg::query;
int n,logn,q,a[N],s[N],fa[N][LogN],dep[N];
vector<int> adj[N];
void dfs(int u,int f,int rt)
{
	fa[u][0]=f;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	rt=update(rt,0,n,a[u]);
	s[u]=rt;
	for(int v:adj[u])if(v!=f)dep[v]=dep[u]+1,dfs(v,u,rt);
}
int lca(int u,int v)
{
	for(int &c=dep[u]>dep[v]?u:v,k=dep[c]-dep[c^u^v],j=0;k;k>>=1,++j)if(k&1)c=fa[c][j];
	if(u==v)return u;
	for(int i=logn;~--i;)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main()
{
	F(i,pw[0]=1,N)pw[i]=(int)((long long)pw[i-1]*bas%MOD);
	read(n,q);
	while((1<<logn)<n)++logn;
	F(i,0,n)--read(a[i]);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0,build(0,n));
	while(q--)
	{
		int u,v,w,l,r;read(u,v,l,r);--u,--v;--l;
		w=a[lca(u,v)];
		int res=query(s[u],s[v],0,n,l,r);
		if(l<=w&&w<r)
		{
			if(res>w)res=w;
			else if(res==w)
			{
				if(w+1<r)res=query(s[u],s[v],0,n,w+1,r);
				else res=r;
			}
		}
		if(res==r)res=-2;
		printf("%d\n",++res);
	}
	return 0;
}