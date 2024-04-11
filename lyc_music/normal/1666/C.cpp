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
pa a[1005];
int cnt;
int p[1005];
pa c[1005];
pa b[1005];
namespace gg
{
	const int MAXN=510;
	int ls[2*MAXN];
	vector<pa>G[MAXN][4200];
	int n,m,k,x,y,z,eg,p[MAXN],hd[MAXN],ver[2*MAXN],vis[MAXN],nx[2*MAXN],edge[2*MAXN],dp[MAXN][4200];
	priority_queue < pair<int,int> > q;
	void add_edge (int x,int y,int z) {
		ver[++eg]=y;
		ls[eg]=x;
		nx[eg]=hd[x],edge[eg]=z;
		hd[x]=eg;
		return;
	}
	void dijkstra (int s) 
	{
		memset(vis,0,sizeof(vis));
		while (!q.empty()) 
		{
			pair <int,int> a=q.top();
			q.pop();
			if (vis[a.second]) {continue;}
			vis[a.second]=1;
			for (int i=hd[a.second];i;i=nx[i]) 
			{
				if (dp[ver[i]][s]>dp[a.second][s]+edge[i]) 
				{
					G[ver[i]][s]=G[a.second][s];
					G[ver[i]][s].push_back(mp(ls[i],ver[i]));
					dp[ver[i]][s]=dp[a.second][s]+edge[i];
					q.push(make_pair(-dp[ver[i]][s],ver[i]));
				}
			}
		}
		return;
	}
	int main () {
		memset(dp,0x3f,sizeof(dp));
		n=cnt;
		for (int i=1;i<=cnt;i++)	
			for (int j=1;j<=cnt;j++)
				if (i!=j)
				{
					if (c[i].fi==c[j].fi)
					add_edge(i,j,abs(c[i].se-c[j].se));
					if (c[i].se==c[j].se)
					add_edge(i,j,abs(c[i].fi-c[j].fi));
				}
					
		k=3;
		// for (int i=1;i<=cnt;i++) cout<<c[i].fi<<" "<<c[i].se<<endl;
		int rt=0;
		for (int i=1;i<=3;i++)
		{
			int x=0;
			for (int j=1;j<=cnt;j++)
				if (c[j]==b[i]) x=j;
			dp[x][(1<<(i-1))]=0;
			rt=x;
		}
		for (int s=1;s<(1<<k);s++) 
		{
			for (int i=1;i<=n;i++) 
			{
				for (int subs=s&(s-1);subs;subs=s&(subs-1))
				{
					if (dp[i][subs]+dp[i][s^subs]<dp[i][s])
					{
						G[i][s]=G[i][subs];
						for (auto u:G[i][s^subs]) G[i][s].push_back(u);
					}
					dp[i][s]=min(dp[i][s],dp[i][subs]+dp[i][s^subs]);
				}
				if (dp[i][s]!=0x3f3f3f3f) {q.push(make_pair(-dp[i][s],i));}
			}
			dijkstra(s);
		}
		// writeln(dp[rt][(1<<k)-1]);
		writeln(G[rt][(1<<k)-1].size());
		for (auto u:G[rt][(1<<k)-1])
			writesp(c[u.fi].fi),writesp(c[u.fi].se),
			writesp(c[u.se].fi),writeln(c[u.se].se);
		return 0;
	}
}
void BellaKira()
{
	for (int i=1;i<=3;i++)
	{
		int x=read(),y=read();
		b[i]=mp(x,y);
	}
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			c[++cnt]=mp(b[i].fi,b[j].se);
	sort(c+1,c+cnt+1);
	cnt=unique(c+1,c+cnt+1)-c-1;
	gg::main();
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/