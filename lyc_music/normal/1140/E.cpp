//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],b[N];
vector<int>g[2];
int ans;
int dp[N][2];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	n=read();m=read();
	int nn=n;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		g[i%2].push_back(a[i]);
	}
	ans=1;
	for (int i=0;i<=1;i++)
	{
		for (int j=0;j<g[i].size();j++) b[j+1]=g[i][j];
//		dp[0]=1;
		int lst=0;
		int nowans=1;
		for (int j=1;j<=g[i].size();j++)
		{
			dp[j][0]=dp[j][1]=0;
			if (b[j]==-1&&!lst)
			{
				nowans=nowans*(m-(j!=1))%mod;
			} else
			{
				if (b[j]==-1)
				{
					dp[j][0]=dp[j-1][1]*(m-1)%mod;
					dp[j][1]=(dp[j-1][0]+dp[j-1][1]*(m-2)%mod)%mod;
				}
				else
				{
					if (!lst)
					{
						if (j==1) dp[j][0]=nowans;
						else dp[j][0]=nowans*quickPower(m,mod-2)%mod*(m-1)%mod;
					}
					else
					{
						if (b[j]==b[lst])
						{
							dp[j][0]=dp[j-1][1]*(m-1)%mod;
						} else
						{
							dp[j][0]=(dp[j-1][1]*(m-2)%mod+dp[j-1][0])%mod;
						}
					}
					lst=j;
				}
			}
//			cout<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
			
		}
		if (!lst)ans=ans*nowans%mod;
		else
		ans=ans*(dp[g[i].size()][0]+dp[g[i].size()][1]*(m-1)%mod)%mod;
	}
	writeln(ans);
			
}
/*

*/