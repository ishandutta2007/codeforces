//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dfn[N],sta[N],low[N],tp,ID,vis[N],bel[N],g[N],dep[N],cnt;
int n,m,q;
vector<pa>G[N];
void ad(int x,int y,int w)
{
	G[x].push_back({y,w});
}
void tarjan(int x)
{
	dfn[x]=++ID;
	low[x]=dfn[x];
	sta[++tp]=x;
	vis[x]=1;
	for (auto U:G[x])
	{
		int u=U.fi,w=U.se;
		if (!dfn[u])
		{
			tarjan(u);
			low[x]=min(low[x],low[u]);
		} else 
			if (vis[u]) low[x]=min(low[x],dfn[u]);
	}
	if (dfn[x]==low[x])
	{
		++cnt;
		do
		{
			bel[sta[tp]]=cnt;
			vis[sta[tp]]=0;
			tp--;
		}while (sta[tp+1]!=x);
	}
}
void dfs(int k,int col)
{
	vis[k]=1;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (bel[u]!=col) continue;
		if (vis[u])
		{
			g[col]=__gcd(g[col],dep[k]-dep[u]+w);
		} else 
		{
			dep[u]=dep[k]+w;
			dfs(u,col);
		}
	}
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		ad(u,v,w);
//		ad(v,u,w);
	}
	for (int i=1;i<=n;i++)
		if (!bel[i]) tarjan(i);
//		return 0;
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i,bel[i]);
	q=read();
	while (q--)
	{
		int x=read(),y=read(),z=read();
//		cout<<bel[x]<<" "<<g[bel[x]]<<endl;
		if (y%__gcd(g[bel[x]],z)==0) puts("YES");
		else puts("NO");
	}
}
/*

*/