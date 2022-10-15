//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dp[35][2];
void BellaKira()
{
	vector<pa>G;
	string st;
	cin>>st;
	int now=0;
	int lst=0;
	int ans=0;
	for (auto u:st)
	{
		if (u!=lst)
		{
			G.push_back(mp(u,1));
			lst=u;
		} else
		{
			G.back().se++;
		}
	}
	for (int i=0;i<35;i++)dp[i][1]=-inf;
	for (int i=0;i<G.size();i++)
	{
		int x=G[i].se;
		int ff=G[i].fi-'a'+1;
		int g[2];
		g[0]=0,g[1]=0;
		for (int j=0;j<2;j++)
		{
			g[(j+x)%2]=max(g[(j+x)%2],dp[ff][j]+x);
			g[(j+x-1)%2]=max(g[(j+x-1)%2],dp[ff][j]+x-1);
		}
		if (i!=0)
		{
			g[0]=max(g[0],dp[G[i-1].fi-'a'+1][0]+(x-(x%2==1)));
			g[1]=max(g[1],dp[G[i-1].fi-'a'+1][0]+(x-(x%2==0)));
		}
		dp[ff][0]=g[0],dp[ff][1]=g[1];
		// cout<<"?"<<dp[ff][0]<<" "<<dp[ff][1]<<" "<<x<<" "<<(x*((x+1)%2))<<" "<<ff<<endl;
	}
	cout<<st.size()-dp[G.back().fi-'a'+1][0]<<endl;
	memset(dp,0,sizeof(dp));
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/