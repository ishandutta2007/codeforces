#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=1e5+5,K=55;
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
struct graph
{
	struct line{int next,to;}e[M];
	struct iter
	{
		line *e;int i;
		iter(line *f,int j){e=f;i=j;}
		operator int(){return e[i].to;}
		void operator++(){i=e[i].next;}
		bool operator~(){return ~i;}
	};
	int hd[N],cnt;
	inline void init(int n){F(i,cnt=0,n)hd[i]=-1;}
	inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
	inline void adline2(int u,int v){adline(u,v);adline(v,u);}
	inline void readline(){static int u,v;--read(u),--read(v);adline(u,v);}
	iter adj(int u){return iter(e,hd[u]);}
};
struct graph_w
{
	static const int M=M*K;
	struct line{int next,to,dis;}e[M];
	struct iter
	{
		line *e;int i;
		iter(line *f,int j){e=f;i=j;}
		operator int(){return e[i].to;}
		dis(){return e[i].dis;}
		void operator++(){i=e[i].next;}
		bool operator~(){return ~i;}
	};
	int hd[N],cnt;
	inline void init(int n){F(i,cnt=0,n)hd[i]=-1;}
	inline void adline(int u,int v,int w){e[cnt].to=v;e[cnt].dis=w;e[cnt].next=hd[u];hd[u]=cnt++;}
	inline void adline2(int u,int v,int w){adline(u,v,w);adline(v,u,w);}
	inline void readline(){static int u,v,w;--read(u),--read(v),read(w);adline(u,v,w);}
	iter adj(int u){return iter(e,hd[u]);}
};
graph ori,in;graph_w out;
int n,m,d,dfn[N],low[N],ind,scc[N],stk[N],top,scnt,mn[N],per[N],q[N*K],qf,qr,dis[N],g[N][K],f[N][K];
int gcdt[K][K],siz[N],tmp[K];
bool ins[N],vis[N][K];
char str[N][K];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	stk[top++]=u;ins[u]=true;
	for(auto v=ori.adj(u);~v;++v)
	{
		if(!~dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		while(stk[--top]!=u)ins[stk[top]]=false,scc[stk[top]]=scnt,++siz[scnt];
		++siz[scnt];
		ins[mn[scc[u]=scnt++]=u]=false;
	}
}
inline int bfs(int s)
{
	int ans=d;
	qf=qr=0;
	q[qr++]=s<<6;
	vis[s][0]=true;
	while(qf<qr)
	{
		int u=q[qf]>>6,t=((q[qf]&63)+1)%d;++qf;
		for(auto v=in.adj(u);~v;++v)if(!vis[v][t])vis[v][t]=true,q[qr++]=v<<6|t;
	}
	F(i,1,d)if(vis[s][i])ans=i,i=d;
	return ans;
}
int dfs(int u,int t)
{
	if(vis[u][t])return f[u][t];
	vis[u][t]=true;
	f[u][t]=g[u][t];
	for(auto v=out.adj(u);~v;++v)
		f[u][t]=max(f[u][t],dfs(v,(t+v.dis())%d)+g[u][t]);
	return f[u][t];
}
int main()
{
	F(i,0,K)F(j,0,K)gcdt[i][j]=gcd(i,j);
	read(n,m,d);
	ori.init(n);
	F(i,0,m)ori.readline();
	F(i,0,n)scanf("%s",str[i]);
	F(i,0,n)dfn[i]=-1;
	F(i,0,n)if(!~dfn[i])tarjan(i);
	in.init(n);out.init(scnt);
	F(u,0,n)for(auto v=ori.adj(u);~v;++v)if(scc[u]==scc[v])in.adline(u,v);
	F(i,0,scnt)per[i]=bfs(mn[i]);
	F(i,0,n)while(!vis[i][dis[i]])++dis[i];
	F(i,0,n)
	{
		F(j,0,per[scc[i]])tmp[j]=0;
		F(j,0,d)tmp[(j-dis[i]+per[scc[i]])%per[scc[i]]]|=str[i][j]-'0';
		F(j,0,per[scc[i]])g[scc[i]][j]+=tmp[j];
	}
	F(i,0,scnt)F(j,per[i],d)g[i][j]=g[i][j-per[i]];
	F(i,0,n)F(j,0,d)vis[i][j]=false;
	F(u,0,n)for(auto v=ori.adj(u);~v;++v)if(scc[u]!=scc[v])F(w,0,d)
	{
		int k=gcdt[per[scc[u]]][per[scc[v]]];
		if((w-dis[u]-1)%k==0)out.adline(scc[u],scc[v],w);
	}
	printf("%d\n",dfs(scc[0],(d-dis[0])%d));
	return 0;
}