#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
const int Log=20;
struct R
{
	int to,nxt;
}e[maxn*2+5];
int h[maxn+5],cnt=0;
int n,q,p2[Log+5];
int f[Log+5][maxn+5],dep[maxn+5];
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return;
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[0][u]=fa;
	for(int i=1;p2[i]<=dep[u];i++) f[i][u]=f[i-1][f[i-1][u]];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int dis=dep[u]-dep[v];
	for(int i=Log;i>=0;i--) if(p2[i]&dis) u=f[i][u];
	if(u==v) return u;
	for(int i=Log;i>=0;i--)
	{
		if(f[i][u]==f[i][v]) continue;
		u=f[i][u];
		v=f[i][v];
	}
	return f[0][u];
}
int que(int u,int v)
{
	int lca=LCA(u,v);
	return dep[u]+dep[v]-2*dep[lca];
}
int main()
{
	p2[0]=1;
	for(int i=1;i<=Log;i++) p2[i]=p2[i-1]*2;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dep[0]=-1;
	dfs(1,0);
	scanf("%d",&q);
	int a,b,x,y,k;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int dis=que(a,b);
		int odis=min(que(a,x)+que(b,y),que(a,y)+que(b,x))+1;
		if(dis>k&&odis>k) printf("NO\n");
		else
		{
			if((dis<=k&&dis%2==k%2)||(odis<=k&&odis%2==k%2)) printf("YES\n");
			else printf("NO\n"); 
		}
	}
	return 0;
}