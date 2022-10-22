#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
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
constexpr int N=2e5+5,LogN=20,INF=0x3fffffff;
int n,q,logn,fa[N][LogN],dep[N],dfn[N],s[N],p[N],y[N],ca[2*N],ind,sta[N],top,a[N];
struct dist
{
	int col,turn,rem;
	friend bool operator<(dist u,dist v)
	{
		if(u.turn!=v.turn)return u.turn<v.turn;
		if(u.col!=v.col)return u.col<v.col;
		return u.rem<v.rem;
	}
	dist operator+(int b)const
	{
		static int d;
		dist c=*this;
		c.rem+=b;
		c.turn+=d=c.rem/p[c.col];
		c.rem-=d*p[c.col];
		return c;
	}
}d[N];
struct cmp
{
	bool operator()(pair<dist,int> u,pair<dist,int> v){return v.first<u.first;}
};
priority_queue<pair<dist,int>,vector<pair<dist,int>>,cmp> pq;
vector<int> adj[N],e[N];
bool done[N];
void dfs(int u,int f)
{
	fa[u][0]=f;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	dfn[u]=ind++;
	for(int v:adj[u])if(v!=f)dep[v]=dep[u]+1,dfs(v,u);
}
bool isanc(int u,int v)
{
	if(dep[v]>dep[u])return false;
	for(int k=dep[u]-dep[v],j=0;k;k>>=1,++j)if(k&1)u=fa[u][j];
	return u==v;
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
	dfs(0,0);
	read(q);
	while(q--)
	{
		int cn=0,an=0,k,m;read(k,m);
		F(i,0,k)read(s[i],p[i]),ca[cn++]=--s[i];
		F(i,0,m)read(y[i]),ca[cn++]=--y[i];
		ca[cn++]=0;
		sort(ca,ca+cn,[](int u,int v){return dfn[u]<dfn[v];});
		top=0;
		sta[top++]=0;
		a[an++]=0;
		F(i,1,cn)if(ca[i]!=ca[i-1])
		{
			bool li=isanc(ca[i],sta[top-1]);
			if(!li)while(true)
			{
				li=isanc(ca[i],sta[(--top)-1]);
				if(li)
				{
					int w=lca(ca[i],sta[top]);
					e[w].emplace_back(sta[top]);
					e[sta[top]].emplace_back(w);
					if(w!=sta[top-1])sta[top++]=w,a[an++]=w;
					break;
				}
				e[sta[top-1]].emplace_back(sta[top]);
				e[sta[top]].emplace_back(sta[top-1]);
			}
			sta[top++]=ca[i];
			a[an++]=ca[i];
		}
		while(top>1)--top,e[sta[top-1]].emplace_back(sta[top]),e[sta[top]].emplace_back(sta[top-1]);
		F(i,0,an)d[a[i]].turn=INF,done[a[i]]=false;
		F(i,0,k)d[s[i]].turn=0,d[s[i]].rem=p[i]-1,d[s[i]].col=i,pq.emplace(d[s[i]],s[i]);
		while(!pq.empty())
		{
			auto du=pq.top();pq.pop();
			int u=du.second;
			if(done[u])continue;
			dist dd=du.first;
			done[u]=true;
			for(int v:e[u])
			{
				int w=abs(dep[v]-dep[u]);
				dist ddd=dd+w;
				if(ddd<d[v])
				{
					d[v]=ddd;
					pq.emplace(d[v],v);
				}
			}
		}
		F(i,0,an)e[a[i]].clear();
		F(i,0,m)printf("%d ",d[y[i]].col+1);
		puts("");
	}
	return 0;
}