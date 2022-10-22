// LUOGU_RID: 90674470
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
constexpr int N=1e5+5,LogN=20;
int n,m,logn,dep[N],fa[N][LogN],inc[N][LogN],dec[N][LogN],dn[N],up[N],mx[N][3];
vector<int> adj[N];
void dfs1(int u,int ff)
{
	for(int v:adj[u])if(v!=ff)
	{
		dep[v]=dep[u]+1;
		dfs1(v,u);
		dn[u]=max(dn[u],dn[v]+1);
	}
}
void dfs2(int u,int ff)
{
	fa[u][0]=ff;
	F(i,0,logn)
	{
		fa[u][i+1]=fa[fa[u][i]][i];
		inc[u][i+1]=max(inc[u][i],inc[fa[u][i]][i]+(1<<i));
		dec[u][i+1]=max(dec[u][i],dec[fa[u][i]][i]-(1<<i));
	}
	for(int v:adj[u])if(v!=ff)
	{
		if(dn[v]+1>mx[u][0])mx[u][2]=mx[u][1],mx[u][1]=mx[u][0],mx[u][0]=dn[v]+1;
		else if(dn[v]+1>mx[u][1])mx[u][2]=mx[u][1],mx[u][1]=dn[v]+1;
		else if(dn[v]+1>mx[u][2])mx[u][2]=dn[v]+1;
	}
	for(int v:adj[u])if(v!=ff)
	{
		inc[v][0]=mx[u][dn[v]+1==mx[u][0]]+1;
		dec[v][0]=mx[u][dn[v]+1==mx[u][0]]-1;
	}
	if(up[u]>mx[u][0])mx[u][2]=mx[u][1],mx[u][1]=mx[u][0],mx[u][0]=up[u];
	else if(up[u]>mx[u][1])mx[u][2]=mx[u][1],mx[u][1]=up[u];
	else if(up[u]>mx[u][2])mx[u][2]=up[u];
	for(int v:adj[u])if(v!=ff)
	{
		up[v]=mx[u][dn[v]+1==mx[u][0]]+1;
		dfs2(v,u);
	}
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
	read(n);
	while((1<<logn)<n)++logn;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs1(0,0);
	dfs2(0,0);
	read(m);
	while(m--)
	{
		int u,v;read(u,v);--u,--v;
		if(dep[u]>dep[v])swap(u,v);
		int w=lca(u,v),ans;
		if(w==u)
		{
			ans=dn[v];
			int cd=0;
			for(int k=(dep[v]-dep[u])>>1,j=0;k;k>>=1,++j)if(k&1)ans=max(ans,inc[v][j]+cd),v=fa[v][j],cd+=1<<j;
			cd=dep[v]-dep[u];
			for(int k=dep[v]-dep[u]-1,j=0;k;k>>=1,++j)if(k&1)ans=max(ans,dec[v][j]+cd),v=fa[v][j],cd-=1<<j;
			ans=max(ans,mx[u][mx[u][0]==dn[v]+1]);
		}
		else
		{
			ans=max(dn[u],dn[v]);
			int cd=0;
			for(int k=(dep[u]+dep[v]-2*dep[w]-1)>>1,j=0;k;k>>=1,++j)if(k&1)ans=max(ans,inc[v][j]+cd),v=fa[v][j],cd+=1<<j;
			cd=dep[u]+dep[v]-2*dep[w];
			for(int k=dep[v]-dep[w]-1,j=0;k;k>>=1,++j)if(k&1)ans=max(ans,dec[v][j]+cd),v=fa[v][j],cd-=1<<j;
			cd=0;
			for(int k=dep[u]-dep[w]-1,j=0;k;k>>=1,++j)if(k&1)ans=max(ans,inc[u][j]+cd),u=fa[u][j],cd+=1<<j;
			++cd;
			if(mx[w][0]==dn[u]+1)ans=max(ans,mx[w][1+(mx[w][1]==dn[v]+1)]+cd);
			else if(mx[w][0]==dn[v]+1)ans=max(ans,mx[w][1+(mx[w][1]==dn[u]+1)]+cd);
			else ans=max(ans,mx[w][0]+cd);
		}
		printf("%d\n",ans);
	}
	return 0;
}