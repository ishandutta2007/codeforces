//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;struct edge{int to,nxt;}e[600005];int et=1,head[N],n,m,rs=0,dg[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
namespace tarjan
{
	int low[N],dfn[N],dt=0,cl[N],clt,cn[N];char bd[600005];vector<int>cc[N];
	inline void dfs(int x,int fa)
	{
		low[x]=dfn[x]=++dt;for(int i=head[x];i;i=e[i].nxt)
			if(!dfn[e[i].to])
			{
				dfs(e[i].to,x),low[x]=min(low[x],low[e[i].to]);
				if(low[e[i].to]>dfn[x]) bd[i]=bd[i^1]=1;
			}else if(e[i].to^fa) low[x]=min(low[x],dfn[e[i].to]);
	}
	inline void color(int x,int col)
	{
		if(cl[x]) return;else cl[x]=col,cn[col]++,cc[col].push_back(x);
		for(int i=head[x];i;i=e[i].nxt) if(!bd[i]) color(e[i].to,col);
	}
	inline void init() {dfs(1,0);for(int i=1;i<=n;i++) if(!cl[i]) color(i,++clt);}
}using tarjan::cc;using tarjan::cl;
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),adde(x,y),adde(y,x);
	if(m==0) return puts("0 0"),0;else tarjan::init();
	if(tarjan::clt==1) return printf("1 %d\n",m),0;
	for(int i=1;i<=n;i++) rs+=dg[i]&1;
	rs>>=1;for(int i=1;i<=tarjan::clt;i++)
	{
		int r=0;for(auto x:cc[i]) r+=dg[x]>=3;
		if((int)cc[i].size()!=1&&r<=1) rs++;
	}
	return printf("%d %d\n",rs,m),0;
}