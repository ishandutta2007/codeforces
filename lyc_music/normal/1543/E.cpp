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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,dis[N],vis[N],dis1[N],ru[N],diss[N],dep[N];
queue<int>q;
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
	G[y].push_back(x);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		m=(1<<n);
		vector<int>g;
		for (int i=1;i<=n*m/2;i++)
		{
			int u=read(),v=read();
			ad(u,v);
//			ad(v,u);
		}
		int now=0;
		for (int i=0;i<m;i++) dep[i]=inf;
		diss[0]=0;vis[0]=1;dep[0]=1;
		for (auto u:G[0])
		{
			diss[u]=(1<<now);
			now++;
			q.push(u);
			dep[u]=2;
			vis[u]=1;
		}
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
//			vis[u]=1;
			g.push_back(u);
			for (auto v:G[u])
			{
				if (vis[v]) continue;
//				diss[v]|=diss[u];
//				ru[v]--;
				vis[v]=1;
				dep[v]=min(dep[u]+1,dep[v]);
				q.push(v);
			}
		}
		for (auto i:g)
			for (auto u:G[i])
			{
				if (dep[u]==dep[i]-1)
				{
					diss[i]|=diss[u];
				}
			}
		for (int i=0;i<m;i++) dis[diss[i]]=i;
		for (int i=0;i<m;i++) writesp(dis[i]);
		puts("");
		if ((1<<(int)log2(n))!=n) puts("-1");
		else
		{
			for (int i=0;i<m;i++)
			{
				int now=0;
				for (int j=0;j<n;j++)
					if ((i>>j)%2) now^=j;
				dis1[dis[i]]=now;
			}
			for (int i=0;i<m;i++) writesp(dis1[i]);
			puts("");
		}
		for (int i=0;i<m;i++) vis[i]=0,G[i].clear(),diss[i]=0,dis[i]=0,ru[i]=0;
	}
}
/*
1
4
15 9
4 3
0 13
4 7
5 6
12 15
10 6
13 6
7 5
0 5
3 12
14 10
14 13
0 12
3 8
14 8
8 1
4 14
11 9
3 2
6 9
4 0
13 11
12 11
5 15
10 1
7 2
1 9
7 10
2 1
8 11
2 15
*/