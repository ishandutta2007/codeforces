//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
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
#define N 2000005
#define M 1005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],nx[N],hd[N],dp[N],f[M][M],cnt;
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++) 
	{
		int x=read();
		if (x==a[cnt]) continue;
		a[++cnt]=x;
	}
	if (cnt>2*n) return puts("0"),0;
	m=cnt;
	swap(n,m);
	for (int i=1;i<=n;i++)
		nx[i]=hd[a[i]],hd[a[i]]=i;
	for (int i=1;i-1<=n;i++) f[i][i-1]=1;
	for (int now=n;now>=1;now--)
	{
		int p=hd[now],s=1;
		while (p!=0)
		{
			int x=nx[p];
			if (x==0) break;
			s=s*f[x+1][p-1];
			s%=mod;
			p=x;
		}
		int r=hd[now],l=p;
//		cout<<l<<" "<<r<<endl;
		for (int j=l;j>=1;j--)
		{
			if (a[j]<now) break;
			dp[j]=0;
			for (int k=j;k<=l;k++)
				dp[j]=(dp[j]+f[j][k-1]*f[k][l-1]%mod)%mod;
		}
		for (int j=r;j<=n;j++)
		{
			if (a[j]<now) break;
			dp[j]=0;
			for (int k=r;k<=j;k++)
				dp[j]=(dp[j]+f[r+1][k]*f[k+1][j]%mod)%mod;
		}
		dp[l]=dp[r]=1;
		for (int j=l;j>=1;j--)
		{
			if (a[j]<now) break;
			for (int k=r;k<=n;k++)
			{
				if (a[k]<now) break;
					f[j][k]=dp[j]*dp[k]%mod*s%mod;
			}
		}
	}
	writeln(f[1][n]);
	
}
/*

*/