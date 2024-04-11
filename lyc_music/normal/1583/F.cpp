#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N][N];
int ans;
int n,m;
vector<int>g;
void work(vector<int>g,int dp)
{
	if (g.size()<=m)
	{
		for (auto u:g)
		{
			for (auto v:g) f[u][v]=dp;
		}
		return;
	}
	int x=(g.size()/m)+((g.size()%m)>0),p=0;
	vector<int>G[N];
	for (int i=0;i<g.size();i++)
	{
		G[p].push_back(g[i]);
		if (G[p].size()>=x)
		{
			work(G[p],dp+1);
			p++;
		}
	}
	if (G[p].size())
	{
		work(G[p],dp+1);
		p++;
	}
	for (int i=0;i<p;i++)
		for (int j=i+1;j<p;j++)
		{
			for (auto u:G[i])
				for (auto v:G[j])
					f[u][v]=dp;
		}
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) g.push_back(i);
	work(g,1);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) ans=max(ans,f[i][j]);
	writeln(ans);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) writesp(f[i][j]);
}
/*

*/