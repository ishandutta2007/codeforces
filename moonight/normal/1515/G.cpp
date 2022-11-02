#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
const int N=200005;
int n,m,cc,tt,cnt,tp,hd[N],dfn[N],low[N],stk[N],vis[N],id[N];ll dis[N],g[N],ans[N];
struct E{int v,nxt,w;}e[N];
inline void adde(int u,int v,int w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
void dfs(int x)
{
	stk[++tp]=x;vis[x]=1;
	dfn[x]=low[x]=++tt;
	for(int i=hd[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(!dfn[y])
		{
			dis[y]=dis[x]+e[i].w;dfs(y);
			low[x]=std::min(low[x],low[y]);
		}
		else if(vis[y])
		{
			low[x]=std::min(low[x],dfn[y]);
			g[x]=gcd(g[x],dis[x]-dis[y]+e[i].w);
		}
	}
	if(low[x]==dfn[x])
	{
		cnt++;int y=-1;
		while(y!=x)
		{
			y=stk[tp--];vis[y]=0;
			id[y]=cnt;ans[cnt]=gcd(ans[cnt],g[y]);
		}
	}
}
int main()
{
	n=rd();m=rd();
	rep(i,1,m){int u=rd(),v=rd(),w=rd();adde(u,v,w);}
	rep(i,1,n)if(!dfn[i])dfs(i);
	int q=rd();
	rep(i,1,q)
	{
		int x=rd(),s=rd(),t=rd();
		s=gcd(s,t);t=gcd(ans[id[x]],t);
		puts(s%t==0?"YES":"NO");
	}
	return 0;
}