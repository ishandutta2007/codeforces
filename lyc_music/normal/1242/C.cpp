//QwQcOrZ yyds!!!
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
#define N 205
#define M 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
vector<int>G[N];
int sm,s[N];
map<int,int>Mp;
int vis[N],ansx[N],ansy[N];
pa w[M];
int dp[M],dp1[M],pre[M];
int ans;
void work(int sta)
{
	if (dp1[sta])
	{
		int x=w[sta].fi,y=w[sta].se;
		for (int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
//			cout<<"?"<<x<<","<<y<<endl;
			vis[x]=1;
			ansx[x]=y;
			y=sm-(s[x]-y);
			ansy[Mp[y]]=x;
			if (vis[Mp[y]]) break;
			x=Mp[y];
		}
//		cout<<"!!!"<<endl;
		return;
	}
	work(pre[sta]);
	work(sta^pre[sta]);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		m=read();
		for (int j=1;j<=m;j++) G[i].push_back(read());
	}
	for (int i=1;i<=n;i++)
		for (auto u:G[i]) 
		{
			sm+=u;
			Mp[u]=i;
			s[i]+=u;
		}
	if (sm%n!=0) return puts("No"),0;
	sm/=n;
	for (int i=1;i<=n;i++)
	{
		if (ans) break;
		for (auto u:G[i])
		{
			for (int j=1;j<=n;j++) vis[j]=0;
			int x=i,y=u,bl=1,sta=0;
			for (int j=1;j<=n;j++)
			{
				int xx=0,yy=0;
				sta|=(1<<(x-1));
				vis[x]=1;
				ansx[x]=y;
				y=sm-(s[x]-y);
				if (!Mp.count(y)) 
				{
					bl=0;
					break;
				}
				if (vis[Mp[y]])
				{
					if (Mp[y]==i) 
					{
						if (y==u)
							bl=2;
					}
					else bl=0;
					break;
				}
//				if (M
				ansy[Mp[y]]=x;
				x=Mp[y];
			}
			if (bl==2) 
			{
//				cout<<"?"<<i<<" "<<u<<" "<<sta<<endl;
				w[sta]={i,u};
				dp[sta]=1;
				dp1[sta]=1;
			}
		}
	}
	for (int i=0;i<(1<<n);i++)
	{
		if (dp[i]) continue;
		for (int j=i;j;j=(j-1)&i)
		{
			if (j==i) continue;
			int x=dp[j]&dp[i^j];
			if (x)
			{
				dp[i]=1;
				pre[i]=j;
				break;
			}
		}
	}
	if (!dp[(1<<n)-1]) puts("No");
	else 
	{
		work((1<<n)-1);
		puts("Yes");
		for (int i=1;i<=n;i++) writesp(ansx[i]),writeln(ansy[i]);
	}
}
/*

*/