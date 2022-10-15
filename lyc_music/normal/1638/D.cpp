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
//#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int a[N][N];
int b[N][N];
queue<pa>q;
vector<pair<pa,int>>G;
int chk(int x,int y)
{
	if (!(x>=1&&x<n&&y>=1&&y<m)) return 0;
	if (b[x][y]&&b[x][y+1]&&b[x+1][y]&&b[x+1][y+1]) return 0;
	int p=0;
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
		{
			if (!b[x+i][y+j]) p=a[x+i][y+j];
		}
	// cout<<"?"<<x<<" "<<y<<" "<<p<<endl;
	int res=1;
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
		{
			res&=(a[x+i][y+j]==p||b[x+i][y+j]);
		}
		if (res) return p;
	return 0;
}
void col(int x,int y)
{
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
		{
			b[x+i][y+j]=1;
		}
	}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=read();
			b[i][j]=0;
		}
	}
	int ans=0;
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
		{
			if (chk(i,j))
			{
				q.push(mp(i,j));
				ans=1;
			}
		}
	// cout<<ans<<endl;
	// return;
	while (!q.empty())
	{
		pa u=q.front();
		q.pop();
		int x=u.fi,y=u.se;
		if (!chk(x,y)) continue;
		G.push_back(mp(mp(x,y),chk(x,y)));
		col(x,y);
		// cout<<x<<" "<<y<<endl;
		if (chk(x-1,y))
		{
			q.push(mp(x-1,y));
			// G.push_back(mp(mp(x-1,y),chk(x-1,y)));
		}
		if (chk(x-1,y+1))
		{
			q.push(mp(x-1,y+1));
			// G.push_back(mp(mp(x-1,y+1),chk(x-1,y+1)));
			// b[x-1][y+1]=1;
		}
		if (chk(x,y+1))
		{
			q.push(mp(x,y+1));
			// G.push_back(mp(mp(x,y+2),chk(x,y+2)));
			// b[x][y+2]=1;
			// col(x,y+2);
		}
		if (chk(x+1,y+1))
		{
			q.push(mp(x+1,y+1));
			// G.push_back(mp(mp(x+1,y+2),chk(x+1,y+2)));
			// b[x+1][y+2]=1;
			// col(x+1,y+2);
		}
		if (chk(x+1,y))
		{
			q.push(mp(x+1,y));
			// G.push_back(mp(mp(x+2,y),chk(x+2,y)));
			// b[x+2][y]=1;
			// col(x+2,y);
		}
		if (chk(x+1,y-1))
		{
			q.push(mp(x+1,y-1));
			// G.push_back(mp(mp(x+2,y+1),chk(x+2,y+1)));
			// b[x+2][y+1]=1;
			// col(x+2,y+1);
		}
		if (chk(x,y-1))
		{
			q.push(mp(x,y-1));
			// G.push_back(mp(mp(x,y-1),chk(x,y-1)));
			// b[x][y-1]=1;
			// col(x,y-1);
		}
		if (chk(x-1,y-1))
		{
			q.push(mp(x-1,y-1));
			// G.push_back(mp(mp(x+1,y-1),chk(x+1,y-1)));
			// b[x+1][y-1]=1;
			// col(x+1,y-1);
		}
	}
	ans=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!b[i][j]) ans=0;
	reverse(G.begin(),G.end());
	if (!ans) puts("-1");
	else 
	{
		writeln(G.size());
		for (auto u:G) writesp(u.fi.fi),writesp(u.fi.se),writeln(u.se);
	} 
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