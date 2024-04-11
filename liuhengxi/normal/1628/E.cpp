#include<cstdio>
#include<algorithm>
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
constexpr int N=6e5+5,INF=0x3fffffff;
namespace data
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
			if(x==l&&r==y)return update(p,v);
			pushdown(p);
			if(y<=mid)update(lc,l,mid,x,y,v);
			else if(mid<=x)update(rc,mid,r,x,y,v);
			else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
			seg[p]=f(seg[lc],seg[rc]);
		}
		S query(int p,int l,int r,const int &x,const int &y)
		{
			int mid=(l+r)>>1;
			if(x==l&&r==y)return seg[p];
			pushdown(p);
			if(y<=mid)return query(lc,l,mid,x,y);
			if(mid<=x)return query(rc,mid,r,x,y);
			return f(query(lc,l,mid,x,mid),query(rc,mid,r,mid,y));
		}
	public:
		void build(int n_){build(1,0,n=n_);}
		void build(int n_,S dd(int)){build(1,0,n=n_,dd);}
		void update(int x,int y,T v){if(x<y)update(1,0,n,x,y,v);}
		S query(int x,int y){return x<y?query(1,0,n,x,y):e();}
	#undef lc
	#undef rc
	};
	struct S{int omin,omax,min,max;};
	struct T{int ap;};
	S e(){return {INF,-INF,INF,-INF};}
	T o(){return {-1};}
	S f(S a,S b){return {min(a.omin,b.omin),max(a.omax,b.omax),min(a.min,b.min),max(a.max,b.max)};}
	S g(T a,S b){return ~a.ap?(a.ap?S({b.omin,b.omax,b.omin,b.omax}):S({b.omin,b.omax,INF,-INF})):b;}
	T h(T a,T b){return ~a.ap?T({a.ap}):b;}
	lazysegtree<S,T,e,o,f,g,h,N> seg;
}
using data::seg;
struct edge
{
	int u,v,w;
	friend bool operator<(edge a,edge b){return a.w<b.w;}
}e[N>>1];
int n,q,f[N],dfn[N],idfn[N],w[N],logn,fa[N][21],ch[N][2],ind,siz[N],dep[N];
data::S dd(int id){return {dfn[id],dfn[id],INF,-INF};}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u)
{
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	idfn[dfn[u]=ind++]=u;
	if(u>=n)
	{
		dep[ch[u][0]]=dep[u]+1;
		dfs(ch[u][0]);
		dep[ch[u][1]]=dep[u]+1;
		dfs(ch[u][1]);
	}
	siz[u]=ind-dfn[u];
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
	read(n,q);
	while((1<<logn)<n)++logn;
	F(i,0,n-1)read(e[i].u,e[i].v,e[i].w),--e[i].u,--e[i].v;
	sort(e,e+n-1);
	F(i,0,2*n-1)f[i]=i;
	int m=n;
	F(i,0,n)w[i]=-1;
	F(i,0,n-1)
	{
		int u=find(e[i].u),v=find(e[i].v);
		f[ch[m][0]=u]=fa[u][0]=f[ch[m][1]=v]=fa[v][0]=m;
		w[m++]=e[i].w;
	}
	int rt=m-1;
	fa[rt][0]=rt;
	dfs(rt);
	seg.build(n,dd);
	while(q--)
	{
		int opt;read(opt);
		if(opt!=3)
		{
			int l,r;read(l,r);--l;
			seg.update(l,r,{2-opt});
		}
		if(opt==3)
		{
			int x;--read(x);
			data::S res=seg.query(0,n);
			if(res.min==INF)puts("-1");
			else
			{
				int l=idfn[res.min],r=idfn[res.max];
				l=dfn[lca(l,r)];
				for(int i=logn;~--i;)
				{
					int ll=dfn[fa[x][i]];
					int rr=ll+siz[fa[x][i]];
					if(l<ll||l>=rr)x=fa[x][i];
				}
				if(dfn[x]!=l)x=fa[x][0];
				printf("%d\n",w[x]);
			}
		}
	}
	return 0;
}