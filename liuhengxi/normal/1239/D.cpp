#include<cstdio>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
int tt,n,m,dfn[N],low[N],ind,sta[N],top,scc[N],scnt;
bool ins[N],ok[N];
vector<int> adj[N];
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	ins[sta[top++]=u]=true;
	for(int v:adj[u])
	{
		if(!~dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		while(sta[--top]!=u)ins[sta[top]]=false,scc[sta[top]]=scnt;
		ins[u]=false,scc[u]=scnt++;
	}
}
int main()
{
	for(read(tt);tt--;)
	{
		read(n,m);
		F(i,0,m)
		{
			int u,v;--read(v),--read(u);
			if(u!=v)adj[u].emplace_back(v);
		}
		ind=scnt=0;
		F(i,0,n)dfn[i]=-1;
		F(i,0,n)if(!~dfn[i])tarjan(i);
		if(scnt==1)puts("No");
		else
		{
			int c=-1;
			F(i,0,scnt)ok[i]=true;
			F(u,0,n)for(int v:adj[u])if(scc[u]!=scc[v])ok[scc[u]]=false;
			F(i,0,scnt)if(ok[i])c=i,i=scnt;
			if(~c)
			{
				int j=0,p=0;
				F(i,0,n)if(scc[i]==c)++p;else ++j;
				puts("Yes");
				printf("%d %d\n",j,p);
				F(i,0,n)if(scc[i]!=c)printf("%d ",i+1);
				puts("");
				F(i,0,n)if(scc[i]==c)printf("%d ",i+1);
				puts("");
			}
			else puts("No");
		}
		F(i,0,n)adj[i].clear(),adj[i].shrink_to_fit();
	}
	return 0;
}