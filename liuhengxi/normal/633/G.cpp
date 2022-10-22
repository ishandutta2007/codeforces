// LUOGU_RID: 90554508
#include<cstdio>
#include<bitset>
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
constexpr int N=1e5+5,M=1024;
int m;
bitset<M> mm,pri;
namespace seg
{
	struct data
	{
		bitset<M> b;
		int tag;
	}s[(1<<18)+5];
#define b(p) s[p].b
#define tag(p) s[p].tag
#define lc (p<<1)
#define rc (p<<1|1)
	inline void shift(int p,int v)
	{
		b(p)=b(p)<<v|b(p)>>(m-v);
		b(p)&=mm;
		(tag(p)+=v)%=m;
	}
	inline void pushdown(int p)
	{
		if(!tag(p))return;
		shift(lc,tag(p));shift(rc,tag(p));
		tag(p)=0;
	}
	inline void pushup(int p)
	{
		b(p)=b(lc)|b(rc);
	}
	void build(int p,int l,int r,int f(int))
	{
		if(r-l==1)return b(p).set(f(l)),void();
		int mid=(l+r)>>1;
		build(lc,l,mid,f);build(rc,mid,r,f);
		pushup(p);
	}
	void shift(int p,int l,int r,int x,int y,int v)
	{
		if(x==l&&r==y)return shift(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)shift(lc,l,mid,x,y,v);
		else if(mid<=x)shift(rc,mid,r,x,y,v);
		else shift(lc,l,mid,x,mid,v),shift(rc,mid,r,mid,y,v);
		pushup(p);
	}
	void query(int p,int l,int r,int x,int y,bitset<M> &ans)
	{
		if(x==l&&r==y)return ans|=b(p),void();
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)return query(lc,l,mid,x,y,ans);
		if(mid<=x)return query(rc,mid,r,x,y,ans);
		query(lc,l,mid,x,mid,ans);query(rc,mid,r,mid,y,ans);
	}
#undef lc
#undef rc
#undef b
#undef tag
}
using seg::build;
using seg::shift;
using seg::query;
int n,a[N],idfn[N],dfl[N],dfr[N],ind;
bool isp[M];
vector<int> adj[N];
void dfs(int u,int fa)
{
	idfn[dfl[u]=ind++]=u;
	for(int v:adj[u])if(v!=fa)dfs(v,u);
	dfr[u]=ind;
}
int init(int id){return a[idfn[id]];}
bitset<M> ans;
int main()
{
	read(n,m);
	F(i,2,m)isp[i]=true;
	F(i,2,m)F(j,2,m/i+1)isp[i*j]=false;
	F(i,0,m)mm.set(i);
	F(i,2,m)if(isp[i])pri.set(i);
	F(i,0,n)read(a[i])%=m;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0,0);
	build(1,0,n,init);
	int q;
	read(q);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int v,x;read(v,x);--v;
			shift(1,0,n,dfl[v],dfr[v],x%m);
		}
		if(opt==2)
		{
			int v;--read(v);
			ans.reset();
			query(1,0,n,dfl[v],dfr[v],ans);
			ans&=pri;
			printf("%d\n",(int)ans.count());
		}
	}
	return 0;
}