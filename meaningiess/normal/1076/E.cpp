#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define ll long long
#define N 300010
using namespace std;
ll c[N],a[N];int n;
struct fck{int a,b;};vector<fck> v[N];
int nxt[N<<1],fir[N<<1],to[N<<1],cnt,dep[N];
void lnk(int u,int v) {nxt[++cnt]=fir[u],fir[u]=cnt,to[cnt]=v;}
void add(int x,int k){for (;x<=n+1;x+=(x&(-x))) c[x]+=k;}
ll qry(int x){ll res=0;for (;x;x-=(x&(-x))) res+=c[x];return res;}
void dfs(int x,int fa)
{
	int i;dep[x]=dep[fa]+1;
	for (i=0;i<v[x].size();i++)
	{
		add(max(1,n+1-dep[x]-v[x][i].a),v[x][i].b);
	}
	a[x]=qry(n+1-dep[x]);
	for (i=fir[x];i;i=nxt[i]) if (to[i]!=fa)
	{
		dfs(to[i],x);
	}
	for (i=0;i<v[x].size();i++)
	{
		add(max(1,n+1-dep[x]-v[x][i].a),-v[x][i].b);
	}
}
int main()
{
	int i,m,u,p,x;scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&u,&p),lnk(u,p),lnk(p,u);
	scanf("%d",&m);
	while (m--) scanf("%d%d%d",&u,&p,&x),v[u].push_back((fck){p,x});
	dfs(1,0);for (i=1;i<=n;i++) printf("%I64d ",a[i]);
}