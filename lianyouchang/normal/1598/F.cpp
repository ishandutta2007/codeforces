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
#define N  21
#define B 8000000
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
unordered_map<int,int>f[N];
int dp[(1<<N)];
int n;
int s[N];
int mn[N];
string st;
vector<int>g[N];
int ans;
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		int x=0;
		for (auto u:st)
		{
			if (u=='(') x++;
			else x--;
			g[i].push_back(x);
		}
		int p=0;
		for (auto u:g[i])
		{
			if (p>=u) f[i][u]++;
			p=min(p,u);
			mn[i]=min(mn[i],u);
		}
		s[i]=g[i][g[i].size()-1];
	}
	memset(dp,0xc0,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<(1<<n);i++)
	{
		int nowsm=0;
		for (int j=0;j<n;j++)
			if ((i>>j)&1) nowsm+=s[j+1];
		for (int j=0;j<n;j++)
			if ((i>>j)&1)
			{
				nowsm-=s[j+1];
				if (mn[j+1]+nowsm<0)
				{
					ans=max(ans,dp[i^(1<<j)]+f[j+1][-nowsm]);
				} else
					dp[i]=max(dp[i],dp[i^(1<<j)]+f[j+1][-nowsm]);
				nowsm+=s[j+1];
			}
	}
	ans=max(ans,dp[(1<<n)-1]);
	writeln(ans);
}
/*
2
))
(
*/