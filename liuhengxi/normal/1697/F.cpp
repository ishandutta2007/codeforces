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
constexpr int N=4e5+5;
int tt,n,m,k,dfn[N],low[N],ind,sta[N],top,scc[N],scnt,deg[N],q[N],qf,qr,tpn[N],val[N];
bool ins[N];
vector<int> adj[N],pre[N];
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	sta[top++]=u;ins[u]=true;
	for(int v:adj[u])
	{
		if(!~dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		while(sta[--top]!=u)ins[sta[top]]=false,scc[sta[top]]=scnt;
		ins[u]=false;
		scc[u]=scnt++;
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m,k);--k;
		int t=n*k<<1,f=t+1,nc=f+1;
		auto le=[&](int u,int v){return !~v?f:(v==k?t:(u*k+v)<<1);};
		auto gt=[&](int u,int v){return !~v?t:(v==k?f:(u*k+v)<<1|1);};
		adj[f].emplace_back(t);
		F(i,0,n)F(j,0,k-1)adj[le(i,j)].emplace_back(le(i,j+1)),adj[gt(i,j+1)].emplace_back(gt(i,j));
		F(i,0,n-1)F(j,0,k)adj[le(i+1,j)].emplace_back(le(i,j)),adj[gt(i,j)].emplace_back(gt(i+1,j));
		F(_,0,m)
		{
			int opt;read(opt);
			if(opt==1)
			{
				int i,x;read(i,x);--i,--x;
				adj[le(i,x)].emplace_back(le(i,x-1));
				adj[gt(i,x-1)].emplace_back(gt(i,x));
			}
			if(opt==2)
			{
				int i,j,x;read(i,j,x);--i,--j,x-=3;
				F(l,max(x-k,-1),min(x+1,k)+1)
				{
					adj[gt(i,l)].emplace_back(le(j,x-l));
					adj[gt(j,l)].emplace_back(le(i,x-l));
				}
			}
			if(opt==3)
			{
				int i,j,x;read(i,j,x);--i,--j,x-=3;
				F(l,max(x-k,-1),min(x+1,k)+1)
				{
					adj[le(i,l)].emplace_back(gt(j,x-l));
					adj[le(j,l)].emplace_back(gt(i,x-l));
				}
			}
		}
		scnt=ind=0;
		F(i,0,nc)dfn[i]=-1;
		F(i,0,nc)if(!~dfn[i])tarjan(i);
		F(i,0,nc>>1)if(scc[i<<1]==scc[i<<1|1])goto no_sol;
		F(i,0,scnt)deg[i]=0;
		F(u,0,nc)for(int v:adj[u])if(scc[u]!=scc[v])pre[scc[v]].emplace_back(scc[u]),++deg[scc[u]];
		qf=qr=0;
		F(i,0,scnt)if(!deg[i])q[qr++]=i;
		while(qf<qr)
		{
			int u=q[qf];tpn[u]=qf++;
			for(int v:pre[u])if(!--deg[v])q[qr++]=v;
		}
		F(i,0,nc>>1)val[i<<1]=tpn[scc[i<<1]]<tpn[scc[i<<1|1]],val[i<<1|1]=val[i<<1]^1;
		F(u,0,nc)for(int v:adj[u])if(val[u]&&!val[v])goto no_sol;
		F(i,0,n)
		{
			int a=1;
			F(j,0,k)a+=val[gt(i,j)];
			printf("%d ",a);
		}
		puts("");
		if(false){no_sol:puts("-1");}
		F(i,0,nc)adj[i].clear(),adj[i].shrink_to_fit();
		F(i,0,scnt)pre[i].clear();
	}
	return 0;
}