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
int n,m;
pa E[N];
pa Q[N];
int q;
int W[N];
int fa[N];
int vis[N];
int ans[N];
int bl[N];
int siz[N],sz[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	fa[x]=gf(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	fa[x]=y;
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),w=read();
		E[i]=mp(x,y);
		W[i]=w;
	}
	q=read();
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		Q[i]=mp(x,y);
		ans[i]=2;
	}
	for (int k=0;k<30;k++)
	{
		for (int i=1;i<=n;i++)
			fa[i]=i;
		for (int i=1;i<=m;i++)
			if ((W[i]>>k)&1)
			{
				merge(E[i].fi,E[i].se);
			}
			
		for (int i=1;i<=m;i++)
		{
			if (W[i]%2==0)
			{
				bl[gf(E[i].fi)]=1;
				bl[gf(E[i].se)]=1;
			}
		}
		
		for (int i=1;i<=q;i++)
		{
			if (vis[i]) continue;
			if (gf(Q[i].fi)==gf(Q[i].se)) ans[i]=0,vis[i]=1;
			else
			{
				if (k!=0)
				{
					if (bl[gf(Q[i].fi)]) 
					{
						// if (i==3) cout<<"?"<<k<<endl;
						ans[i]=1;
					}
				}
			}
		}
		for (int i=1;i<=m;i++)
		{
			if (W[i]%2==0)
			{
				bl[gf(E[i].fi)]=0;
				bl[gf(E[i].se)]=0;
			}
		}
	}
	
	for (int i=1;i<=q;i++) writeln(ans[i]);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/