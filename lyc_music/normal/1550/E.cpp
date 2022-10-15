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
#define M 25
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[M][N],dp[N],nx[N];
char st[N];
int n,m,l,r,mid,ans;
int check(int len)
{
	for (int j=1;j<=m;j++)
	{
		int now=n+1;
		f[j][n+1]=inf;
		for (int i=n;i>=1;i--)
		{
			if (st[i]!=st[now]&&st[i]!='?') now=i;
			if ((nx[i]>=len-1&&(st[i]=='a'+j-1||st[i]=='?'))||(st[now]=='a'+j-1&&now+nx[now]>=i+len-1)) f[j][i]=i+len;
			 else f[j][i]=f[j][i+1];
		}
	}
	for (int stat=0;stat<(1<<m);stat++) dp[stat]=inf;
	dp[0]=1;
	for (int stat=0;stat<(1<<m);stat++)
	{
		if (dp[stat]>n+1) continue;
		for (int i=0;i<m;i++)
		{
			if ((stat>>i)%2) continue;
			dp[stat|(1<<i)]=min(dp[stat|(1<<i)],f[i+1][dp[stat]]);
		}
	}
	return dp[(1<<m)-1]!=inf;
}
signed main()
{
	n=read(),m=read();
	scanf("%s",st+1);
	st[n+1]='6';
	int now=0;
	for (int i=n;i>=1;i--)
	{
		nx[i]=now;
		if (st[i]=='?') now++;else now=0;
	}
	
//	check(4);
//	return 0;
	
	l=1,r=n/m;
	while (l<=r)
	{
		mid=l+(r-l)/2;
		if (check(mid))
		{
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	writeln(ans);
}
/*

*/