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
#define N 505
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,f[N][N][5];
int cnt;
int dis[N*N];
int idx[N*N],idy[N*N];
int id[N][N];
priority_queue<pa>q;
void BellaKira()
{
	n=read();m=read();
	for (int i=1;i<=m+1;i++)
		for (int j=1;j<=m+1;j++)
			for (int k=0;k<4;k++) f[i][j][k]=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read(),u=read(),v=read();
		if (x>u) swap(x,u);
		if (y>v) swap(y,v);
		if (x==u)
		{
			f[x+1][v][0]++;
			f[x][v][2]++;
			f[m-x+2][m-y+1][0]++;
			f[m-x+1][m-y+1][2]++;
		} else
		{
			f[u][y+1][3]++;
			f[u][y][1]++;
			f[m-x+1][m-y+2][3]++;
			f[m-x+1][m-y+1][1]++;
//			cout<<x<<" "<<y<<" "<<f[m-x+1][m-y+1][1]<<endl;
		}
	}
	cnt=0;
	for (int i=1;i<=m+1;i++)
		for (int j=1;j<=m+1;j++)
			id[i][j]=++cnt,dis[cnt]=inf,idx[cnt]=i,idy[cnt]=j;
	dis[id[m/2+1][m/2+1]]=0;
	q.push(mp(0,id[m/2+1][m/2+1]));
	while (!q.empty())
	{
		int u=q.top().se,w=-q.top().fi;
		q.pop();
		if (w!=dis[u]) continue;
		int x=idx[u],y=idy[u];
//		cout<<u<<" "<<x<<" "<<y<<" "<<dis[u]<<endl;
		if (x-1>=1)
		{
			int v=id[x-1][y];
			if (dis[v]>dis[u]+f[x][y][0])
			{
				dis[v]=dis[u]+f[x][y][0];
				q.push(mp(-dis[v],v));
			}
		}
		if (x+1<=m+1)
		{
			int v=id[x+1][y];
			if (dis[v]>dis[u]+f[x][y][2])
			{
				dis[v]=dis[u]+f[x][y][2];
				q.push(mp(-dis[v],v));
			}
		}
		if (y-1>=1)
		{
			int v=id[x][y-1];
			if (dis[v]>dis[u]+f[x][y][3])
			{
				dis[v]=dis[u]+f[x][y][3];
				q.push(mp(-dis[v],v));
			}
		}
		if (y+1<=m+1)
		{
			int v=id[x][y+1];
			if (dis[v]>dis[u]+f[x][y][1])
			{
				dis[v]=dis[u]+f[x][y][1];
				q.push(mp(-dis[v],v));
			}
		}
	}
	int ans=inf;
	for (int i=1;i<=m+1;i++)
	{
		ans=min(ans,dis[id[1][i]]),ans=min(ans,dis[id[i][1]]),ans=min(ans,dis[id[m+1][i]]),ans=min(ans,dis[id[i][m+1]]);
	}
	writeln(n-ans);
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/