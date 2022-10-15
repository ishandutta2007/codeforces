//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 2505
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fa[N*N];
int vis[N][N];
int dis[N*N];
int tim;
int siz[N*N];
priority_queue<pa>q;
vector<int>G[N*N];
string st[N];
int n,m;
int id(int x,int y)
{
	return (x-1)*m+y;
}
int chk(int x,int y)
{
	if (x<1||x>n||y<1||y>m) return 0;
	return 1;
}
inline int gf(int x)
{
	return fa[x];
}
void bfs(int x,int y)
{
//	vector<int>g;
	int X=x,Y=y;
	++tim;
	while (chk(x,y)&&!vis[x][y])
	{
		vis[x][y]=tim;
		if (st[x][y]=='R') y++;
		else
		if (st[x][y]=='L') y--;
		else
		if (st[x][y]=='U') x--;
		else x++;
	}
	if (chk(x,y)&&vis[x][y]==tim)
	{
		X=x,Y=y;
		siz[id(X,Y)]--;
		do
		{
			fa[id(x,y)]=fa[id(X,Y)];
			siz[id(X,Y)]++;
			if (st[x][y]=='R') y++;
			else
			if (st[x][y]=='L') y--;
			else
			if (st[x][y]=='U') x--;	
			else x++;
		}while (x!=X||y!=Y);
		if (x==1&&y==1) siz[id(X,Y)]=0;
		dis[id(X,Y)]=siz[id(X,Y)];
		q.push(mp(-siz[id(X,Y)],id(X,Y)));
	}		
}
void ad(int x,int y)
{
	if (x==y) return;
	G[y].push_back(x);
}
void What_will_Diana_eat_today()
{
	cin>>n>>m;
	for (int i=1;i<=n+2;i++)
	{
		for (int j=1;j<=m+3;j++)
			st[i]+=' ';
	}
	for (int i=2;i<=n+1;i++)
		for (int j=2;j<=m+1;j++)
			cin>>st[i][j];
	n+=2;m+=2;
	tim=0;
	for (int i=1;i<m;i++) st[1][i]='R';
	for (int i=1;i<n;i++) st[i][m]='D';
	for (int i=m;i>1;i--) st[n][i]='L';
	for (int i=n;i>1;i--) st[i][1]='U';
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) fa[(i-1)*m+j]=(i-1)*m+j,siz[(i-1)*m+j]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (vis[i][j]) continue;
			bfs(i,j);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (gf(id(i,j))==id(i,j))
			{
				if (chk(i+1,j)&&st[i][j]=='D') ad(gf(id(i,j)),gf(id(i+1,j)));
				if (chk(i-1,j)&&st[i][j]=='U') ad(gf(id(i,j)),gf(id(i-1,j)));
				if (chk(i,j+1)&&st[i][j]=='R') ad(gf(id(i,j)),gf(id(i,j+1)));
				if (chk(i,j-1)&&st[i][j]=='L') ad(gf(id(i,j)),gf(id(i,j-1)));
			}
		while (!q.empty())
		{
			int u=q.top().se;
			q.pop();
			for (auto v:G[u])
			{
				if (!dis[v])
				{
					dis[v]=dis[u]+1;
					q.push(mp(-dis[v],v));
				}
			}
		}
//	}
	int mx=0;
	int anx=2,any=2;
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++)
			if (dis[gf(id(i,j))]>mx)
			{
				mx=dis[gf(id(i,j))];
				anx=i,any=j;
			}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			dis[id(i,j)]=0,vis[i][j]=0,G[id(i,j)].clear();
		st[i]="";
	}
	cout<<anx-1<<" "<<any-1<<" "<<mx<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*
1
1 3
RRL
*/