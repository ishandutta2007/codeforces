#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
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
namespace seg1
{
	template<typename T,T e(),T f(T,T),int N,T d()=e>struct segtree
	{
	#define lc (p<<1)
	#define rc (p<<1|1)
	private:
		int n;T seg[N<<2];
		void build(int p,int l,int r)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=d(),void();
			build(lc,l,mid);build(rc,mid,r);
			seg[p]=f(seg[lc],seg[rc]);
		}
		void build(int p,int l,int r,T (*const &dd)(int))
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=dd(l),void();
			build(lc,l,mid,dd);build(rc,mid,r,dd);
			seg[p]=f(seg[lc],seg[rc]);
		}
		void update(int p,int l,int r,const int &x,const T &v)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=v,void();
			if(x<mid)update(lc,l,mid,x,v);
			else update(rc,mid,r,x,v);
			seg[p]=f(seg[lc],seg[rc]);
		}
		T get(int p,int l,int r,const int &x)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p];
			if(x<mid)return get(lc,l,mid,x);
			else return get(rc,mid,r,x);
		}
		T query(int p,int l,int r,const int &x,const int &y)
		{
			int mid=(l+r)>>1;
			if(y<=l||r<=x)return e();
			if(x<=l&&r<=y)return seg[p];
			return f(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
		}
	public:
		void build(int n_){build(1,0,n=n_);}
		void build(int n_,T dd(int)){build(1,0,n=n_,dd);}
		void update(int x,T v){update(1,0,n,x,v);}
		T get(int x){return get(1,0,n,x);}
		T query(int x,int y){return query(1,0,n,x,y);}
	#undef lc
	#undef rc
	};
	int e(){return 0;}
	int f(int x,int y){return max(x,y);}
	segtree<int,e,f,N> s1;
}
using seg1::s1;
namespace seg2
{
	template<typename S,typename T,S e(),T o(),S f(S,S),S g(T,S),T h(T,T),int N,S d()=e>struct lazysegtree
	{
	#define lc (p<<1)
	#define rc (p<<1|1)
	private:
		int n;S seg[N<<2];T tag[N<<2];
		void build(int p,int l,int r)
		{
			int mid=(l+r)>>1;
			tag[p]=o();
			if(r-l==1)return seg[p]=d(),void();
			build(lc,l,mid);build(rc,mid,r);
			seg[p]=f(seg[lc],seg[rc]);
		}
		void build(int p,int l,int r,S (*const &dd)(int))
		{
			int mid=(l+r)>>1;
			tag[p]=o();
			if(r-l==1)return seg[p]=dd(l),void();
			build(lc,l,mid,dd);build(rc,mid,r,dd);
			seg[p]=f(seg[lc],seg[rc]);
		}
		inline void update(int p,const T &v){seg[p]=g(v,seg[p]);tag[p]=h(v,tag[p]);}
		inline void pushdown(int p){update(lc,tag[p]);update(rc,tag[p]);tag[p]=o();}
		void update(int p,int l,int r,const int &x,const int &y,const T &v)
		{
			int mid=(l+r)>>1;
			if(y<=l||r<=x)return;
			if(x<=l&&r<=y)return update(p,v);
			pushdown(p);
			update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
			seg[p]=f(seg[lc],seg[rc]);
		}
		S query(int p,int l,int r,const int &x,const int &y)
		{
			int mid=(l+r)>>1;
			if(y<=l||r<=x)return e();
			if(x<=l&&r<=y)return seg[p];
			pushdown(p);
			return f(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
		}
	public:
		void build(int n_){build(1,0,n=n_);}
		void build(int n_,S dd(int)){build(1,0,n=n_,dd);}
		void update(int x,int y,T v){update(1,0,n,x,y,v);}
		S query(int x,int y){return query(1,0,n,x,y);}
	#undef lc
	#undef rc
	};
	int e(){return INF;}
	int f(int x,int y){return min(x,y);}
	lazysegtree<int,int,e,e,f,f,f,N> s2;
}
using seg2::s2;
struct edge
{
	int u,v,w,id;
	bool operator<(edge b)const{return w<b.w;}
}d[N];
struct line
{
	int next,to,val,id;
}e[2*N];
int n,m,f[N],hd[N],cnt,siz[N],dfn[N],ind,hc[N],fa[N],top[N],dep[N],ans[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v,int w,int id)
{
	e[cnt].to=v;
	e[cnt].val=w;
	e[cnt].id=id;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f_)
{
	fa[u]=f_;siz[u]=1;hc[u]=-1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f_)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(!~hc[u]||siz[v]>siz[hc[u]])hc[u]=v;
		siz[u]+=siz[v];
	}
}
void dfs(int u)
{
	dfn[u]=ind++;
	if(~hc[u])top[hc[u]]=top[u],dfs(hc[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u]||v==hc[u])continue;
		dfs(top[v]=v);
	}
}
int main()
{
	read(n,m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)read(d[i].u,d[i].v,d[i].w),--d[i].u,--d[i].v,d[i].id=i;
	sort(d,d+m);
	F(i,0,n)f[i]=i;
	F(i,0,m)
	{
		if(find(d[i].u)!=find(d[i].v))
		{
			f[f[d[i].u]]=f[d[i].v];
			adline(d[i].u,d[i].v,d[i].w,d[i].id);
			adline(d[i].v,d[i].u,d[i].w,d[i].id);
			d[i].w=-1;
		}
	}
	dfs(0,0);
	dfs(0);
	s1.build(n);
	F(u,1,n)
		for(int i=hd[u];~i;i=e[i].next)if(dep[e[i].to]<dep[u])
			s1.update(dfn[u],e[i].val);
	s2.build(n);
	F(i,0,m)if(~d[i].w)
	{
		int u=d[i].u,v=d[i].v,w=d[i].w,&a=ans[d[i].id];
		a=0;
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			s2.update(dfn[top[u]],dfn[u]+1,w);
			a=max(a,s1.query(dfn[top[u]],dfn[u]+1)-1);
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])swap(u,v);
		s2.update(dfn[u]+1,dfn[v]+1,w);
		a=max(a,s1.query(dfn[u]+1,dfn[v]+1)-1);
	}
	F(u,1,n)
		for(int i=hd[u];~i;i=e[i].next)if(dep[e[i].to]<dep[u])
			ans[e[i].id]=s2.query(dfn[u],dfn[u]+1)-1;
	F(i,0,m)printf("%d ",ans[i]>1e9?-1:ans[i]);
	puts("");
	return 0;
}