#include<cstdio>
#include<algorithm>
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
constexpr int N=2e5+5,LogN=20;
int n,q,fa[N];
vector<int> adj[N];
namespace LCA
{
	constexpr int log2(int x){return 31-__builtin_clz(x);}
	int m,dfn[N],dep[N];
	long long seq[2*N],st[LogN][2*N];
	void dfs(int u)
	{
		dfn[u]=m;
		seq[m++]=(long long)dep[u]<<20|u;
		for(int v:adj[u])
		{
			dep[v]=dep[u]+1;
			dfs(v);
			seq[m++]=seq[dfn[u]];
		}
	}
	void build()
	{
		F(i,0,m)st[0][i]=seq[i];
		F(i,0,log2(m))F(j,0,m+1-(2<<i))st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);
	}
	inline int lca(int u,int v)
	{
		if(u==v)return u;
		u=dfn[u];v=dfn[v];
		if(u>v)swap(u,v);
		++v;
		int k=log2(v-u);
		return min(st[k][u],st[k][v-(1<<k)])&((1<<20)-1);
	}
	inline int dis(int u,int v){return dep[u]+dep[v]-(dep[lca(u,v)]<<1);}
}
using LCA::lca;
using LCA::dis;
int perm[N],ip[N],v1[(1<<19)+5],v2[(1<<19)+5];
#define lc (p<<1)
#define rc (p<<1|1)
inline void merge(int a1,int a2,int a3,int a4,int &b1,int &b2)
{
	int d12=dis(a1,a2),d13=dis(a1,a3),d14=dis(a1,a4),d23=dis(a2,a3),d24=dis(a2,a4),d34=dis(a3,a4);
	int &d21=d12,&d31=d13,&d41=d14,&d32=d23,&d42=d24,&d43=d34;
	#define fu(x,y,z1,z2) if(d##x##z1+d##y##z1==d##x##y&&d##x##z2+d##y##z2==d##x##y)return b1=a##x,b2=a##y,void()
	fu(1,2,3,4);fu(1,3,2,4);fu(1,4,2,3);fu(2,3,1,4);fu(2,4,1,3);fu(3,4,1,2);
	#undef f
	b1=-1;
}
inline void pushup(int p)
{
	if(~v1[lc]&&~v1[rc])merge(v1[lc],v2[lc],v1[rc],v2[rc],v1[p],v2[p]);
	else v1[p]=-1;
}
void build(int p,int l,int r)
{
	if(r-l==1)return v1[p]=v2[p]=ip[l],void();
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid,r);
	pushup(p);
}
void update(int p,int l,int r,int x)
{
	if(r-l==1)return v1[p]=v2[p]=ip[l],void();
	int mid=(l+r)>>1;
	if(x<mid)update(lc,l,mid,x);
	else update(rc,mid,r,x);
	pushup(p);
}
int query(int p,int l,int r,int x1,int x2)
{
	if(r-l==1)
	{
		merge(x1,x2,v1[p],v2[p],x1,x2);
		return ~x1?r:l;
	}
	int mid=(l+r)>>1,y1,y2;
	if(~v1[lc])merge(x1,x2,v1[lc],v2[lc],y1,y2);
	else y1=-1;
	if(!~y1)return query(lc,l,mid,x1,x2);
	else return query(rc,mid,r,y1,y2);
}
#undef lc
#undef rc
int main()
{
	read(n);
	F(i,0,n)ip[read(perm[i])]=i;
	F(i,1,n)adj[--read(fa[i])].emplace_back(i);
	LCA::dfs(0);
	LCA::build();
	build(1,0,n);
	read(q);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int x,y;read(x,y);--x,--y;
			swap(perm[x],perm[y]);
			swap(ip[perm[x]],ip[perm[y]]);
			update(1,0,n,perm[x]);update(1,0,n,perm[y]);
		}
		if(opt==2)
		{
			int x1=ip[0],x2=ip[0];
			printf("%d\n",query(1,0,n,x1,x2));
		}
	}
	return 0;
}