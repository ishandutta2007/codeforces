// O(n * log^2 n)   may tle
#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,LogN=22;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to;
}e[N<<1];
int n,q,hd[N],cnt,f[N],fa[N][LogN],c[N],logn,dfn[N],ind,siz[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void add(int x){for(++x;x<=n;x+=x&-x)++c[x];}
int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
int sub(int x){return sum(dfn[x]+siz[x])-sum(dfn[x]);}
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	dfn[u]=ind++;
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		siz[u]+=siz[v];
	}
}
int main()
{
	read(n,q);
	while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;--read(u);--read(v);
		adline(u,v);adline(v,u);
	}
	F(i,0,n)f[i]=i;
	for(int u=n-1;~u;--u)
	{
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(v>u&&find(u)!=find(v))
			{
				fa[f[v]][0]=f[u];
				f[f[v]]=f[u];
			}
		}
	}
	F(i,cnt=0,n)hd[i]=-1;
	F(i,1,n)adline(fa[i][0],i);
	dfs(0);
	for(int ans=0;q--;)
	{
		int t,x;read(t,x);(x+=ans)%=n;
		if(t==1)add(dfn[x]);
		if(t==2)
		{
			int all=sub(0);
			for(int i=logn;~i;--i)if(sub(fa[x][i])<all)x=fa[x][i];
			if(sub(x)<all)x=fa[x][0];
			ans=x+1;
			printf("%d\n",ans);
		}
	}
	return 0;
}