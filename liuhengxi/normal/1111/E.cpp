#include<cstdio>
#include<cstring>
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
constexpr int N=1e5+5,MOD=1000000007;
struct BIT
{
	int n,c[N];
	void init(int n_){n=n_;}
	void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
}a;
int n,q,f[305],g[305],x[N],dis[N],logn,fa[N][19],dep[N],dfn[N],siz[N],ind;
bool is[N];
vector<int> adj[N];
void dfs(int u,int ff)
{
	dfn[u]=ind++;
	fa[u][0]=ff;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	for(int v:adj[u])if(v!=ff)
	{
		dep[v]=dep[u]+1;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	++siz[u];
}
int lca(int u,int v)
{
	for(int &c=dep[u]>dep[v]?u:v,k=dep[c]-dep[c^u^v],j=0;k;k>>=1,++j)if(k&1)c=fa[c][j];
	if(u==v)return u;
	for(int j=logn;~j;--j)if(fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
int getdis(int u,int v)
{
	int w=lca(u,v);
	return dep[u]+dep[v]-(dep[w]<<1);
}
int main()
{
	read(n,q);
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	while((1<<logn)<n-1)++logn;
	dfs(0,0);
	a.init(n);
	while(q--)
	{
		int k,m,r,*f0=f,*f1=g;
		read(k,m,r);--r;
		F(i,0,k)
		{
			--read(x[i]);
			dis[x[i]]=getdis(x[i],r);
		}
		sort(x,x+k,[](int u,int v){return dis[u]<dis[v];});
		memset(f0,0,sizeof(int)*(m+1));
		f0[0]=1;
		F(i,0,k)
		{
			int w=lca(x[i],r);
			int h=a.sum(dfn[x[i]]+1)+a.sum(dfn[r]+1)+is[w]-(a.sum(dfn[w]+1)<<1);
			memset(f1,0,sizeof(int)*(m+1));
			F(j,1,m+1)f1[j]=(int)(((long long)f0[j]*max(j-h,0)+f0[j-1])%MOD);
			swap(f0,f1);
			a.add(dfn[x[i]],1);
			a.add(dfn[x[i]]+siz[x[i]],-1);
			is[x[i]]=true;
		}
		F(i,0,k)
		{
			a.add(dfn[x[i]],-1);
			a.add(dfn[x[i]]+siz[x[i]],1);
			is[x[i]]=false;
		}
		int ans=0;
		F(i,1,m+1)ans+=f0[i],(ans>=MOD)&&(ans-=MOD);
		printf("%d\n",ans);
	}
	return 0;
}