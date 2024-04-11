//~~
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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],w[N],v[N],f[N];
poly lst[N];
poly G[N];
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		w[i]=y;
		v[i]=z;
		G[x].push_back(i);
	}
	int sm=0;
	int ans=1;
	poly ansg;
	for (int i=1;i<=n;i++)
	{
		f[0]=0;
		for (int j=1;j<=200;j++) f[j]=inf,lst[j].clear();
		for (auto u:G[i])
		{
			for (int j=200;j>=v[u];j--)
			{
				if (f[j-v[u]]+w[u]<f[j])
				{
					f[j]=f[j-v[u]]+w[u];
					lst[j]=lst[j-v[u]];
					lst[j].emplace_back(u);
				}
			}
		}
		int nows=inf;
		int x=0;
		for (int j=100;j<=200;j++)
		{
			if (f[j]<nows)
			{
				nows=f[j];
				x=j;
			}
		}
		if (nows>a[i]-sm)
		{
			ans=0;
			break;
		}
		int now=x;
		poly nowg=lst[x];
		// reverse(nowg.begin(),nowg.end());
		for (auto u:nowg) ansg.push_back(u);
		sm+=nows;
	}
	for (int i=1;i<=n;i++) G[i].clear();
	if (ans)
	{
		writeln(ansg.size());
		for (auto u:ansg) writesp(u);
		puts("");
	} else puts("-1");

}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/