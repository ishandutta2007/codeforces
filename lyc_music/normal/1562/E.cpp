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
#define N 5005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,dp[N],f[N][N],ans;
string st;
bool cmp(int x,int y)
{
	if (x+f[x][y]>n+1) return 0;
	return st[x+f[x][y]]>st[y+f[x][y]];
}
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n>>st;
		st=' '+st;st=st+' ';
		for (int i=1;i<=n;i++) f[n][i]=(st[n]==st[i]);
		for (int i=n-1;i>=1;i--)
			for (int j=i;j>=1;j--)
				if (st[i]==st[j])
				f[i][j]=f[i+1][j+1]+1;
				else f[i][j]=0;
		ans=n;dp[1]=n;
		for (int i=2;i<=n;i++)
		{
			dp[i]=n-i+1;
			for (int j=1;j<i;j++)
				if (cmp(i,j))
				dp[i]=max(dp[i],dp[j]+n-i+1-f[i][j]);
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) f[i][j]=0;
	}
		
}
/*

*/