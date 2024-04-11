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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>G[N];
vector<pa>ans,ans1,lian;
int T,n,now[N];
void dfs(int k,int fa)
{
	vector<int>g;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (now[u]==0) continue;
		g.push_back(u);
	}
	if (g.size()<=1) 
	{
		if (g.size()==1) now[k]=now[g[0]];
		if (k==1)
		lian.push_back({now[k],k});
		return;
	}
	if (g.size()==2)
	{
		if (fa)
		{
			ans.push_back({k,fa});
		}
		lian.push_back({now[g[0]],now[g[1]]});
		now[k]=0;
	} else
	{
		int p=now[g[0]];
		if (fa)
		{
			ans.push_back({k,fa});
		}
			lian.push_back({now[g[0]],now[g[1]]});
		for (int i=2;i<g.size();i++)
		{
			int u=g[i];
			ans.push_back({k,u});
			lian.push_back({now[u],u});
		}
		now[k]=0;
	}
}			
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) now[i]=i;
		for (int i=1;i<n;i++)
		{
			int x=read(),y=read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		for (int i=1;i<lian.size();i++)
		{
			ans1.push_back({lian[i-1].se,lian[i].fi});
		}
		writeln(ans1.size());
		for (int i=0;i<ans.size();i++)
		{
			writesp(ans[i].fi),writesp(ans[i].se),writesp(ans1[i].fi)
			,writeln(ans1[i].se);
		}
		ans.clear(),ans1.clear();lian.clear();
		for (int i=1;i<=n;i++) G[i].clear();
	}
}
/*

*/