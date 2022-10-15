//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e14
#define mod 998244353
#define int ll
#define N 605
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,F[N][N],f[N],g[N][N];
int vis[N];
void LYC_music()
{
	n=read(),m=read();
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			F[i][j]=inf,g[i][j]=inf;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		F[x][y]=-y+z;
		g[x][y]=n-y+z;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<n;j++)
			F[i][j]=min(F[i][j-1],F[i][j]);
		for (int j=n-2;j>=0;j--)
			g[i][j]=min(g[i][j],g[i][j+1]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) f[j]=inf,vis[j]=0;
		f[i]=0;
		for (int j=0;j<n;j++)
		{
			int x=-1;
			for (int k=0;k<n;k++)
				if (!vis[k]&&(x==-1||f[k]<f[x])) x=k;
			vis[x]=1;
			for (int k=0;k<n;k++)
				if (!vis[k])
				{
					int dis=(-f[x]%n+k+n)%n;
					f[k]=min(f[k],f[x]+F[x][dis]+dis);
					f[k]=min(f[k],f[x]+g[x][dis]+dis);
				}
		}
		for (int j=0;j<n;j++) writesp(f[j]);
		puts("");
	}
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/