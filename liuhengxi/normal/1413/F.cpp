#include<cstdio>
#include<vector>
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
constexpr int N=5e5+5;
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
struct S{int m0,m1;};
struct T{int flip;};
S e(){return {0,0};}
T o(){return {0};}
S f(S a,S b){return {max(a.m0,b.m0),max(a.m1,b.m1)};}
S g(T a,S b){return a.flip?S({b.m1,b.m0}):b;}
T h(T a,T b){return {a.flip^b.flip};}
int n,x[N],y[N],w[N],v0,v1,dfn[N],ind,siz[N],dep[2][N],l[2][N],r[2][N],idfn[N],id;
vector<int> adj[N];
void dfsa(int u,int fa)
{
	for(int i:adj[u])
	{
		int v=x[i]^u;if(v==fa)continue;
		dep[0][v]=dep[0][u]+1;
		dfsa(v,u);
	}
}
void dfsb(int u,int fa)
{
	idfn[dfn[u]=ind++]=u;siz[u]=1;
	for(int i:adj[u])
	{
		int v=x[i]^u;if(v==fa)continue;
		dep[id][v]=dep[id][u]+1;
		dfsb(v,u);
		l[id][i]=dfn[v];
		r[id][i]=dfn[v]+siz[v];
		siz[u]+=siz[v];
	}
}
S d0(int i){return {dep[0][idfn[i]],0};}
S d1(int i){return {dep[1][idfn[i]],0};}
lazysegtree<S,T,e,o,f,g,h,N> seg[2];
int main()
{
	read(n);
	F(i,0,n-1)
	{
		read(x[i],y[i],w[i]);--x[i],--y[i];
		adj[x[i]].emplace_back(i);
		adj[y[i]].emplace_back(i);
		x[i]^=y[i];
	}
	dfsa(0,0);
	F(i,1,n)if(dep[0][i]>dep[0][v0])v0=i;
	dfsa(v0,v0);               
	F(i,1,n)if(dep[0][i]>dep[0][v1])v1=i;
	dep[0][v0]=0;
	ind=0;id=0;dfsb(v0,v0);seg[0].build(n,d0);
	ind=0;id=1;dfsb(v1,v1);seg[1].build(n,d1);
	int q;read(q);
	F(i,0,n-1)if(w[i])
	{
		seg[0].update(l[0][i],r[0][i],{1});
		seg[1].update(l[1][i],r[1][i],{1});
	}
	while(q--)
	{
		int e;--read(e);
		seg[0].update(l[0][e],r[0][e],{1});
		seg[1].update(l[1][e],r[1][e],{1});
		printf("%d\n",max(seg[0].query(0,n).m0,seg[1].query(0,n).m0));
	}
	return 0;
}