//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
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
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,dp[N][5];
int ans;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dp[k][0]=1;
	dp[k][1]=1;
	dp[k][2]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		dp[k][0]=(dp[k][0]*(dp[u][0]+dp[u][1]+dp[u][2])%mod+dp[k][0]*(dp[u][0]+dp[u][1]+dp[u][2]*2)%mod)%mod;
		dp[k][1]=(dp[k][1]*(dp[u][0]+dp[u][1]+dp[u][2])%mod+dp[k][1]*(dp[u][0]+dp[u][2])%mod)%mod;
		dp[k][2]=(dp[k][2]*(dp[u][0]+dp[u][1]+dp[u][2])%mod);
	}
//	if (G[k].size()==1&&k!=1) dp[k][2]=0;
	dp[k][0]=(dp[k][0]-dp[k][2]+mod)%mod;
	dp[k][1]=(dp[k][1]-dp[k][2]+mod)%mod;
//	cout<<k<<" "<<dp[k][0]<<" "<<dp[k][1]<<" "<<dp[k][2]<<endl;
}
signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
//	ans=1;
	writeln(((dp[1][0]+dp[1][1]+dp[1][2])%mod-1+mod)%mod);
}
/*

*/