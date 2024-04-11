//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
//#include<nmsl.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dp[N][2],l[N],r[N],n;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dp[k][0]=dp[k][1]=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		dp[k][1]+=max(dp[u][1]+abs(l[k]-l[u]),dp[u][0]+abs(l[k]-r[u]));
		dp[k][0]+=max(dp[u][1]+abs(r[k]-l[u]),dp[u][0]+abs(r[k]-r[u]));
	}
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
	writeln(max(dp[1][1],dp[1][0]));
	for (int i=1;i<=n;i++) G[i].clear();
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/