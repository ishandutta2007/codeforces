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
constexpr int N=1e5+5,INF=0x3fffffff;
int n,l,r,ans,ansu,ansv,siz[N],val[N];
bool vis[N];
vector<pair<int,int> > adj[N];
void getsize(int u,int fa)
{
	siz[u]=1;
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(v==fa||vis[v])continue;
		getsize(v,u);
		siz[u]+=siz[v];
	}
}
void getcentroid(int u,int fa,const int &sum,int &c)
{
	int mxc=0;
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(v==fa||vis[v])continue;
		getcentroid(v,u,sum,c);
		mxc=max(mxc,siz[v]);
	}
	if((siz[u]<<1)>=sum&&(mxc<<1)<=sum)c=u;
}
int getht(int u,int fa)
{
	int dep=0;
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(v==fa||vis[v])continue;
		dep=max(dep,getht(v,u));
	}
	return dep+1;
}
int m,ht[N];
void pre(int u)
{
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(vis[v])continue;
		ht[v]=getht(v,u);
	}
	sort(adj[u].begin(),adj[u].end(),[](pair<int,int> a,pair<int,int> b){return ht[a.first]<ht[b.first];});
	m=ht[adj[u].rbegin()->first];
}
int b[N],bb[N],c[N],cc[N],q[N],qf,qr;
void dfs(int u,int fa,int dep,int sum,const int &lim)
{
	++dep;
	if(sum>c[dep])c[dep]=sum,cc[dep]=u;
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(v==fa||vis[v])continue;
		dfs(v,u,dep,sum+(vw.second>=lim?1:-1),lim);
	}
}
bool check(int u,int lim,int &au,int &av)
{
	F(i,0,m+1)b[i]=-INF;
	b[0]=0;bb[0]=u;
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(vis[v])continue;
		int k=min(ht[v],r);
		F(i,0,k+1)c[i]=-INF;
		dfs(v,u,0,vw.second>=lim?1:-1,lim);
		qf=qr=0;
		for(int i=k,j=0;i;--i)
		{
			while(j<=k&&j<=r-i)
			{
				while(qf<qr&&b[q[qr-1]]<=b[j])--qr;
				q[qr++]=j++;
			}
			while(qf<qr&&q[qf]<l-i)++qf;
			if(qf<qr&&b[q[qf]]+c[i]>=0)return au=bb[q[qf]],av=cc[i],true;
		}
		F(i,0,k+1)if(c[i]>b[i])b[i]=c[i],bb[i]=cc[i];
	}
	return false;
}
void solve(int u)
{
	getsize(u,u);
	getcentroid(u,u,siz[u],u);
	vis[u]=true;
	int al=-1,ar=n,au=0,av=0;
	pre(u);m=min(m,r);
	while(ar-al>1)
	{
		int mid=(al+ar)>>1;
		if(check(u,mid,au,av))al=mid;
		else ar=mid;
	}
	if(al>ans)
	{
		check(u,al,au,av);
		ans=al;
		ansu=au,ansv=av;
	}
	for(auto vw:adj[u])
	{
		int &v=vw.first;if(vis[v])continue;
		solve(v);
	}
}
int main()
{
	read(n,l,r);
	F(i,0,n-1)
	{
		int u,v,w;read(u,v,w);--u,--v;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
		val[i]=w;
	}
	sort(val,val+n-1);
	F(u,0,n)for(auto &vw:adj[u])vw.second=(int)(lower_bound(val,val+n-1,vw.second)-val);
	ans=-1;
	solve(0);
	printf("%d %d\n",ansu+1,ansv+1);
	return 0;
}