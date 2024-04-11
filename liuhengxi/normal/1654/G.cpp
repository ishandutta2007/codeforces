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
constexpr int N=2e5+5,INF=0x3fffffff;
int n,l[N],h[N],q[N],qf,qr,ans[N],ff[N],f[N];
vector<int> adj[N],ver[N];
vector<pair<int,int>> rlx[N];
bool ex[N],fl[N];
int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}
void merge(int x,int y){ff[find(x)]=find(y);}
void dfs(int u,int fa)
{
	for(int v:adj[u])if(v!=fa&&h[v]==h[u])dfs(v,u),rlx[h[u]].emplace_back(u,v);
}
void solve(int dis)
{
	F(i,0,n)f[i]=INF;
	F(i,0,n)if(fl[i]&&h[i]==dis)f[i]=0;
	F(i,dis,n)
	{
		for(auto e:rlx[i])f[e.first]=min(f[e.first],f[e.second]+1);
		for(auto j=rlx[i].rbegin(),jend=rlx[i].rend();j!=jend;++j)f[j->second]=min(f[j->second],f[j->first]+1);
		for(int u:ver[i])for(int v:adj[u])if(h[v]>h[u])f[v]=min(f[v],max(f[u]-1,0));
	}
	F(i,0,n)if(f[i]==0)ans[i]=min(ans[i],dis);
}
int main()
{
	read(n);
	F(i,0,n)if(read(l[i]))q[qr++]=i;else h[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	while(qf<qr)
	{
		int u=q[qf++];
		for(int v:adj[u])if(!~h[v])h[q[qr++]=v]=h[u]+1;
	}
	F(i,0,n)ff[i]=i;
	F(u,0,n)
	{
		ver[ans[u]=h[u]].emplace_back(u);
		for(int v:adj[u])if(h[u]==h[v])ex[h[u]]=true,fl[u]=true,merge(u,v);
	}
	F(i,0,n)if(ff[i]==i)dfs(i,i);
	F(i,0,n)if(ex[i])solve(i);
	F(i,0,n)printf("%d ",2*h[i]-ans[i]);
	puts("");
	return 0;
}