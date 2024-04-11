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
#define N 405
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,a[N][N],b[N][N],c[N][N],f[N][N];
int ans;
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		ans=inf;
		for (int i=1;i<=n;i++)
		{
			cin>>st;
			for (int j=1;j<=m;j++)
				a[i][j]=st[j-1]-'0';
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				f[i][j]=a[i][j],a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				b[i][j]=(b[i-1][j]+(f[i][j]^1));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				c[i][j]=(c[i][j-1]+(f[i][j]^1));
		for (int i=1;i<=m;i++)
			for (int j=i+4-1;j<=m;j++)
			{
				int l=1,p=inf;
				for (int k=1;k<=n;k++)
				{
					while (l<=k-4)
					{
						p=min(p,-(a[l][j-1]-a[l][i])-(b[l][j]+b[l][i])+c[l][j-1]-c[l][i]);
						l++;
					}
					ans=min(ans,a[k-1][j-1]-a[k-1][i]+p+b[k-1][j]+b[k-1][i]+c[k][j-1]-c[k][i]);
				}
			}
		writeln(ans);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				c[i][j]=b[i][j]=a[i][j]=f[i][j]=0;
	}
						
					
}
/*

*/