//QwQcOrZ yyds!!!
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
#define N 605
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,f[N][N],b[N],val[N][N],dis[N][N];
signed main()
{
//	freopen("sayounara.in","r",stdin);
//	freopen("sayounara.out","w",stdout);
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		f[u][v]=f[v][u]=w;
		dis[v][u]=dis[u][v]=w;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (f[i][j]>f[i][k]+f[k][j])
						f[i][j]=f[i][k]+f[k][j];
	for (int s=1;s<=n;s++)
	{
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (dis[j][i])
				{
					if (f[s][j]+dis[j][i]==f[s][i]) b[i]++;
				}
		for (int t=s+1;t<=n;t++)
			for (int i=1;i<=n;i++)
			{
				if (f[s][i]+f[i][t]==f[s][t])
				{
					val[s][t]+=b[i];
				}
			}
	}
	for (int s=1;s<=n;s++)
	{
		for (int t=s+1;t<=n;t++)
			writesp(val[s][t]);
	}
	
		
}
/*

*/