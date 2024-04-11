// Lynkcat.
// Problem: C. Sanae and Giant Robot
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[1<<21],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
// #define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
queue<int>q;
int n,m,sa[N],sb[N];
int vs[N];
int l[N],r[N];
int a[N],b[N];
int vis[N];
int s[N];
poly G[N];
int fa[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void work(int k)
{
	int L=l[k],R=r[k];
	for (int i=gf(L);i<=R;i=gf(i+1))
	{
		vs[i]=1;
		fa[i]=i+1;
		for (auto u:G[i])
		{
			if (vs[l[u]]&&vs[r[u]]) work(u);
		}
	}
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),sa[i]=sa[i-1]+a[i];
	for (int i=1;i<=n;i++)
		b[i]=read(),sb[i]=sb[i-1]+b[i];
	for (int i=1;i<=m;i++)
	{
		l[i]=read(),r[i]=read();
		l[i]--;
		G[l[i]].push_back(i);
		G[r[i]].push_back(i);
		vis[i]=0;
	}
	for (int i=0;i<=n+1;i++) fa[i]=i;
	for (int i=0;i<=n;i++)
	{
		if (sa[i]==sb[i]) vs[i]=1,fa[i]=i+1;
		else vs[i]=0;
	}
	for (int i=1;i<=m;i++)
		if (vs[l[i]]&&vs[r[i]])
			work(i);
	for (int i=0;i<=n;i++) G[i].clear();
	int ans=1;
	for (int i=0;i<=n;i++)
		if (!vs[i]) ans=0;
	if (ans) puts("YES");
	else puts("NO");
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}