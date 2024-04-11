//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],c[N],d[N];
int ans;
int dp[2][N][2];
#define chk(x,y) (x=min(x,y))
void What_will_Diana_eat_today()
{
	n=read();
	int sm=0;
	for (int i=1;i<=n;i++)
		b[i]=read(),sm+=b[i];
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=0;i<=n;i++)
			for (int k=0;k<2;k++)
				for (int j=0;j<2;j++)
					dp[j][i][k]=inf;
//	memset(dp,0x3f,sizeof(dp));
	ans=dp[0][0][0];
	dp[0][0][0]=0;
	dp[1][0][1]=b[1];
	for (int i=1;i<n;i++)
			for (int k=0;k<2;k++)
			{
				chk(dp[k][i][1],dp[k][i-1][1]+b[i%n+1]);
				chk(dp[k][i][1],dp[k][i-1][0]+a[i]+b[i%n+1]);
				chk(dp[k][i][0],dp[k][i-1][0]+a[i]);
				chk(dp[k][i][0],dp[k][i-1][1]+a[i]);
//				cout<<dp[k][i][1]<<" "<<dp[k][i][0]<<" "<<k<<" "<<i<<endl;
			}
	for (int j=0;j<2;j++)
	{
		if (j==1) ans=min({ans,dp[j][n-1][1],dp[j][n-1][0]+a[n]});
		else ans=min({ans,dp[j][n-1][1]+a[n],dp[j][n-1][0]+a[n]});
	}
//	cout<<ans<<" "<<sm<<endl;
	if (ans==sm) puts("YES");
	else puts("NO");
//	writeln(ans);
}
signed main()
{
	int T=read();
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/